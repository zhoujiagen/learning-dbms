# MySQL InnoDB Locks

## 封锁

四种锁粒度:

- S: 共享锁/读锁;
- X: 排他锁/写锁;
- IS: 意向共享锁/意向读锁;
- IX: 意向排他锁/意向写锁.

兼容性: S-S, IS-IS, IX-IX, IS-IX, IS-S.

封锁机制:

- 符合SS2PL(Strong Stric 2 Phase Locking)协议; 第一阶段加锁, 第二阶段释放锁, 读写锁都保持到事务结束, 事务的结束(提交或回滚)在解锁前完成.
- 在SERIALIZABLE隔离级别下, 严格遵守SS2PL协议, MVCC机制不发生作用; 在其他隔离级别下, MVCC解禁封锁协议锁禁止的读-写、写-读并发操作.
- `SELECT`操作在REPEATBALE READ和READ COMMITTED隔离级别下, 使用MVCC的快照做一致性无锁读, 读数据时不加锁; 在SERIALIZABLE隔离级别下, 读数据加锁(使用MVCC获取一个可串行化的快照判断元组的可见性).

## 锁的种类

MySQL Server支持表级锁, InnoDB存储引擎支持行级锁.

InnnoDB实现的锁:

- **自增锁(AUTO-INC Lock)**: 类似于序列对象.
- **记录锁(Record Locks)**: 行级锁, 因为InnoDB的表组织结构是索引组织表, 在实际的元组之上存在主键上的B+树. 记录锁是针对索引加锁, 而不是针对物理记录加锁.

- **间隙锁(Gap Locks)**: 将两个索引项之间的间隔视为一个对象, 在该对象上加锁. 第一个索引项之前和最后一个索引项之后的间隙, 也可以施加间隙锁.

在READ COMMITTED隔离级别下, 间隙锁在这些情况下有效: (1) 外键约束(foreign-key constraint)检查, (2) 重复键(duplicate-key)检查, (3) 半一致性读 (semi-consistent) [^1] [^2]: 执行`UPDATE`语句时, InnoDB返回处于已经提交状态的最新元组给MySQL Server, 由MySQL Server决定得到的元组是否满足`UPDATE`的`WHERE`条件, 使用半一致性读时, 间隙锁边被使用边被释放; 在这些情况下不起作用: 搜索(search)、索引扫描(index scan).

[^1]: A **consistent read** means that InnoDB uses multi-versioning to present to a query a snapshot of the database at a point in time. The query sees the changes made by transactions that committed before that point of time, and no changes made by later or uncommitted transactions. The exception to this rule is that the query sees the changes made by earlier statements within the same transaction. This exception causes the following anomaly: If you update some rows in a table, a SELECT sees the latest version of the updated rows, but it might also see older versions of any rows. If other sessions simultaneously update the same table, the anomaly means that you might see the table in a state that never existed in the database.

[^2]: For UPDATE statements, if a row is already locked, InnoDB performs a “**semi-consistent**” read, returning the latest committed version to MySQL so that MySQL can determine whether the row matches the WHERE condition of the UPDATE. If the row matches (must be updated), MySQL reads the row again and this time InnoDB either locks it or waits for a lock on it.

间隙锁与记录锁组合成Next-Key锁, 在REPEATBALE READ隔离级别下, 解决幻象异常问题.

- **Next-Key Locks**: 由记录锁和该记录锁前的间隙上的间隙锁组成.
- **插入意向锁(Insert Intention Locks)**: 专用于`INSERT`, 在一个Next-Key锁的范围内, 允许不产生冲突的`INSERT`操作的执行.
- **空间索引的谓词锁(Predicate Locks for Spatial Indexes)**: 空间索引建立在MBR(Minimum Bounding Rectangle)上, InnoDB为索引项上的MBR增加了一个谓词锁.

## 锁的施加规则

- `INSERT`: 在被插入的索引项上施加 **记录锁**( **插入意向锁** ).
- `INSERT ... ON DUPLICATED KEY UPDATE`: 在被插入的索引项上施加 **排他Next-Key锁**.
- `INSERT INTO T SELECT ... FROM S WHERE ...`: (1) 在被插入表T中的元组对应的索引项上施加 **排他记录锁**. (2) 如果在READ COMMITTED隔离级别下, 在表S中元组对应的索引项上 **不加锁** (一致性读); 否则施加 **共享Next-Key锁**.
- `SELECT ... FROM`: 通常是一致性读, **不加锁**. 在SERIALIZABLE隔离级别下, 需要在索引项上施加 **共享Next-Key锁**.
- `SELECT ... LOCK IN SHARE MODE`, `SELECT ... FROM ... FOR UPDATE`: 对扫描过的行对应的索引 **施加锁**, 如果扫描过的行不满足`WHERE`条件则 **释放锁**. (`UNION`操作下被扫描过的行可能放在临时表中, 这是锁在查询结束后才被释放)<br/> (1)`SELECT ... LOCK IN SHARED MODE`: 在索引项上施加 **共享Next-Key锁**. <br/> (2) `SELECT ... FROM ... FOR UPDATE`: 在索引项上施加 **排他Next-Key锁**. 阻塞`SELECT ... LOCK IN SHARED MODE`操作, 不阻塞`SELECT ... FROM`一致性读操作.
- `REPLACE`: 如果不会存在唯一性键冲突, 则施加的锁与`INSERT`相同( **插入意向锁** ); 否则, 发生冲突时对被替换的对象对应的索引项施加 **排他Next-Key锁**.
- `REPLACE INFO t SELECT ... FROM s WHERE ...`, `UPDATE t ... WHERE col IN (SELECT ... FROM s ...)`: `SELECT`语句作为子查询出现, 对表`s`中的数据对应的索引项上施加 **共享Next-Key锁**.
- `UPADTE ... WHERE ...`: 在索引项上施加 **排他Next-Key锁**.
- `DELETE FROM ... WHERE ...`: 在索引项上施加 **排他Next-Key锁**.
- `ALTER TABLE ... LOCK [=] {DEFAULT|NONE|SHARED|EXCLUSIVE}`: 在指定的表上施加 **读锁** 或 **排他锁**.
- `CHECKSUM TABLE`, `ANALYZE`, `CHECK TABLE`, `OPTIMIZE TABLE`, `REPAIRT TABLE`: 在指定的表上施加 **读锁**. 读取操作符合一致性读.
- `CREATE TABLE ... SELECT ...`: `SELECT`部分与`SELECT`语句加锁规则相同.
- `HANDLER tbl_name OPEN/READ`: 直接访问InnoDB表, **不加锁**, 不能确保数据的一致性.
- `FLUSH TABLES WITH READ LOCK`: 关闭所有表后, 对所有表施加一个 **全局的读锁**.
- `FLUSH TABLES tbl_name[,tbl_name] ... WITH READ LOCK`: 在指定的表上获取 **表级的读锁**.
- `LOCK TABLES t1,...,tn [READ [LOCAL] | [LOW_PRIORITY] WRITE]`: (1) `READ` 施加 **表级读锁**; (2) `READ LOCAL` 施加 **表级读锁** 时还允许并发插入操作(对InnoDB不适用); (3) `WRITE` 施加 **表级写锁**, 排斥其他SESSION并发访问被加锁的表; (4) `LOW_PRIORITY WRITE` 兼容目的, 无效果. `LOCK TABLES`会在MySQL Server层设置 **表级锁**, 如果`innodb_table_locks=1`, 则InnoDB会知道MySQL Server层设置了 **表级锁**.

外键约束: 出发约束条件被检查的元组对应的索引上均会施加 **共享Next-Key锁**, 不管是`INSERT`/`UPDATE`/`DELETE`哪种操作, 也不管约束检查是否成功.

## Observability

### 查看行锁的争用情况

```
show status like 'innodb_row_lock%';
```

- `Innodb_row_lock_current_waits`: 等待的行锁的数量;
- `Innodb_row_lock_time`: 花费在获取行锁的总时间, 单位为毫秒;
- `Innodb_row_lock_time_avg`: 获取行锁的平均时间, 单位为毫秒;
- `Innodb_row_lock_time_max`: 获取行锁的最大时间, 单位为毫秒;
- `Innodb_row_lock_waits`: 需要等待行锁的次数.

### 查看InnoDB引擎中事务中锁状态和死锁

```
set global innodb_status_output=ON;
set global innodb_status_output_locks=ON;
show engine innodb status;
```

- TRANSACTIONS

### 查看死锁

使用`innodb_deadlock_detect`选项开启死锁检测, 如果关闭该选项则依赖`innodb_lock_wait_timeout`设置在出现死锁时回滚事务.

使用`innodb_print_all_deadlocks`选项在error日志中查看所有死锁警告.
