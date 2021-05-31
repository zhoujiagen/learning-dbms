# include目录

|File|Line|Description|Progress|
|:---|--:|:---|:---|
| api0api.h         | 1022 |||
| api0misc.h        |   58 |||
| btr0btr.h         |  683 |||
| btr0btr.ic        |  285 |||
| btr0bulk.h        |  378 |||
| btr0cur.h         | 1022 |||
| btr0cur.ic        |  217 |||
| btr0pcur.h        |  545 |||
| btr0pcur.ic       |  642 |||
| btr0sea.h         |  340 |||
| btr0sea.ic        |  205 |||
| btr0types.h       |   72 |||
| buf0block_hint.h  |   56 |||
| buf0buddy.h       |   76 |||
| buf0buddy.ic      |  120 |||
| buf0buf.h         | 2441 |||
| buf0buf.ic        | 1361 |||
| buf0checksum.h    |   67 |||
| buf0dblwr.h       |  144 |||
| buf0dump.h        |   51 |||
| buf0flu.h         |  419 |||
| buf0flu.ic        |  133 |||
| buf0lru.h         |  279 |||
| buf0lru.ic        |    7 |||
| buf0rea.h         |  141 |||
| buf0types.h       |  133 |||
| data0data.h       |  678 |||
| data0data.ic      |  805 |||
| data0type.h       |  569 |||
| data0type.ic      |  666 |||
| data0types.h      |   18 |||
| db0err.h          |  181 |见[db0err.h](#db0err.h)||
| dict0boot.h       |  342 |||
| dict0boot.ic      |   78 |||
| dict0crea.h       |  361 |||
| dict0crea.ic      |  128 |||
| dict0dict.h       | 2133 |||
| dict0dict.ic      | 1997 |||
| dict0load.h       |  427 |||
| dict0load.ic      |    8 |||
| dict0mem.h        | 1875 |||
| dict0mem.ic       |   64 |||
| dict0priv.h       |   47 |||
| dict0priv.ic      |  109 |||
| dict0stats.h      |  201 |||
| dict0stats.ic     |  217 |||
| dict0stats_bg.h   |  132 |||
| dict0stats_bg.ic  |   27 |||
| dict0types.h      |  108 |||
| dyn0buf.h         |  487 | 动态分配的缓冲区实现, 见[dyn0buf.h](#dyn0buf.h) ||
| dyn0types.h       |   21 | 动态分配的缓冲区类型和常量, 见[dyn0types.h](#dyn0types.h) ||
| eval0eval.h       |   94 |||
| eval0eval.ic      |  235 |||
| eval0proc.h       |   80 |||
| eval0proc.ic      |   70 |||
| fil0fil.h         | 1658 |||
| fsp0file.h        |  576 | 表空间中数据文件控制信息, 见[fsp](fsp.md) ||
| fsp0fsp.h         |  742 | 文件空间管理, 见[fsp](fsp.md) ||
| fsp0fsp.ic        |  306 | - ||
| fsp0space.h       |  220 | 通用共享表空间实现, 见[fsp](fsp.md) ||
| fsp0sysspace.h    |  302 | 多文件的共享的系统表空间实现, 见[fsp](fsp.md) ||
| fsp0types.h       |  349 | 文件空间管理中类型, 见[fsp](fsp.md) ||
| fts0ast.h         |  358 |||
| fts0blex.h        |  349 |||
| fts0fts.h         | 1055 |||
| fts0opt.h         |   18 |||
| fts0pars.h        |   52 |||
| fts0plugin.h      |   32 |||
| fts0priv.h        |  614 |||
| fts0priv.ic       |  116 |||
| fts0tlex.h        |  349 |||
| fts0tokenize.h    |  170 |||
| fts0types.h       |  387 |||
| fts0types.ic      |  216 |||
| fts0vlc.ic        |  124 |||
| fut0fut.h         |   41 | 基于文件的工具 ||
| fut0fut.ic        |   48 | - ||
| fut0lst.h         |  169 | 基于文件的列表工具 ||
| fut0lst.ic        |  151 | - ||
| gis0geo.h         |  143 |||
| gis0rtree.h       |  571 |||
| gis0rtree.ic      |  256 |||
| gis0type.h        |  150 |||
| ha0ha.h           |  231 | 有外部链的哈希表 ||
| ha0ha.ic          |  224 | - ||
| ha0storage.h      |  121 |||
| ha0storage.ic     |  128 |||
| ha_prototypes.h   |  537 |见[ha_prototypes.h](#ha_prototypes.h)||
| handler0alter.h   |  105 |||
| hash0hash.h       |  559 | 哈希表工具, 见[ha](ha.md) ||
| hash0hash.ic      |  261 | - ||
| ib0mutex.h        | 1148 |见[ib0mutex.h](#ib0mutex.h)||
| ibuf0ibuf.h       |  444 |||
| ibuf0ibuf.ic      |  325 |||
| ibuf0types.h      |   13 |||
| lock0iter.h       |   49 |||
| lock0lock.h       | 1117 |||
| lock0lock.ic      |  113 |||
| lock0prdt.h       |  207 |||
| lock0priv.h       | 1180 |||
| lock0priv.ic      |  407 |||
| lock0types.h      |   60 |||
| log0log.h         |  805 |||
| log0log.ic        |  476 |||
| log0recv.h        |  402 |||
| log0recv.ic       |   20 |||
| log0types.h       |   32 |||
| mach0data.h       |  380 |||
| mach0data.ic      |  933 |||
| mem0mem.h         |  498 | 内存管理, 见[mem](mem.md) ||
| mem0mem.ic        |  596 | - ||
| mtr0log.h         |  241 |||
| mtr0log.ic        |  239 |||
| mtr0mtr.h         |  597 |||
| mtr0mtr.ic        |  268 |||
| mtr0types.h       |  270 |||
| os0atomic.h       |  352 |||
| os0atomic.ic      |  206 |||
| os0event.h        |  125 |||
| os0file.h         | 2153 |||
| os0file.ic        |  591 |||
| os0once.h         |  105 |||
| os0proc.h         |   56 |||
| os0proc.ic        |    9 |||
| os0thread.h       |  180 |||
| os0thread.ic      |    7 |||
| page0cur.h        |  395 |||
| page0cur.ic       |  328 |||
| page0page.h       | 1169 |||
| page0page.ic      | 1268 |||
| page0size.h       |  184 |||
| page0types.h      |  185 |||
| page0zip.h        |  556 |||
| page0zip.ic       |  427 |||
| pars0grm.h        |  241 |||
| pars0opt.h        |   56 |||
| pars0opt.ic       |    6 |||
| pars0pars.h       |  753 |||
| pars0pars.ic      |    6 |||
| pars0sym.h        |  231 |||
| pars0sym.ic       |    6 |||
| pars0types.h      |   32 |||
| que0que.h         |  499 |||
| que0que.ic        |  290 |||
| que0types.h       |   39 |||
| read0read.h       |  107 |||
| read0types.h      |  313 |||
| rem0cmp.h         |  243 |||
| rem0cmp.ic        |  124 |||
| rem0rec.h         | 1080 |||
| rem0rec.ic        | 1747 |||
| rem0types.h       |   56 |||
| row0ext.h         |   87 |||
| row0ext.ic        |   69 |||
| row0ftsort.h      |  265 |||
| row0import.h      |   69 |||
| row0import.ic     |    7 |||
| row0ins.h         |  237 |||
| row0ins.ic        |    8 |||
| row0log.h         |  244 |||
| row0log.ic        |   64 |||
| row0merge.h       |  409 |||
| row0mysql.h       |  996 |||
| row0mysql.ic      |    6 |||
| row0purge.h       |  117 |||
| row0purge.ic      |    7 |||
| row0quiesce.h     |   53 |||
| row0quiesce.ic    |    8 |||
| row0row.h         |  359 |||
| row0row.ic        |  157 |||
| row0sel.h         |  520 |||
| row0sel.ic        |  127 |||
| row0trunc.h       |  411 |||
| row0types.h       |   37 |||
| row0uins.h        |   36 |||
| row0uins.ic       |    7 |||
| row0umod.h        |   33 |||
| row0umod.ic       |    6 |||
| row0undo.h        |  127 |||
| row0undo.ic       |    6 |||
| row0upd.h         |  598 |||
| row0upd.ic        |  205 |||
| row0vers.h        |  136 |||
| row0vers.ic       |   12 |||
| sess0sess.h       |  128 | 见[sess0sess.h](#sess0sess.h)||
| srv0conc.h        |   76 |||
| srv0mon.h         |  853 |||
| srv0mon.ic        |   95 |||
| srv0srv.h         |  960 |||
| srv0srv.ic        |    6 |||
| srv0start.h       |  163 |||
| sync0arr.h        |  118 |||
| sync0arr.ic       |   67 |||
| sync0debug.h      |   87 |||
| sync0policy.h     |  532 |||
| sync0policy.ic    |   82 |||
| sync0rw.h         |  911 |||
| sync0rw.ic        |  982 |||
| sync0sync.h       |  142 |||
| sync0types.h      | 1259 |||
| trx0i_s.h         |  276 |INFORMATION SCHEMA中表innodb_trx、innodb_locks、innodb_lock_waits的缓存结构和功能, 见[trx](trx.md) ||
| trx0purge.h       |  491 | 清除旧版本, 见[trx](trx.md) ||
| trx0purge.ic      |   45 | - ||
| trx0rec.h         |  363 | 事务undo日志记录, 见[trx](trx.md) ||
| trx0rec.ic        |   91 | - ||
| trx0roll.h        |  224 | 事务回滚, 见[trx](trx.md) ||
| trx0roll.ic       |   44 | - ||
| trx0rseg.h        |  238 | 回滚段, 见[trx](trx.md) ||
| trx0rseg.ic       |  155 | - ||
| trx0sys.h         |  651 | 事务系统, 见[trx](trx.md) ||
| trx0sys.ic        |  483 | - ||
| trx0trx.h         | 1571 | 事务, 见[trx](trx.md) ||
| trx0trx.ic        |  376 | - ||
| trx0types.h       |  304 | 事务系统全局类型定义, 见[trx](trx.md) ||
| trx0undo.h        |  608 | 事务undo日志, 见[trx](trx.md) ||
| trx0undo.ic       |  344 | - ||
| trx0xa.h          |   43 | 事务标识符大小和X/Open XA分布式事务状态码, 见[trx](trx.md) ||
| univ.i            |  637 | 数据库版本控制, 通用定义和包含文件, 见[univ.i](#univ.i) ||
| usr0sess.h        |   54 |||
| usr0sess.ic       |    6 |||
| usr0types.h       |   13 |||
| ut0byte.h         |  101 | 字节操作工具 ||
| ut0byte.ic        |  155 | - ||
| ut0counter.h      |  195 |||
| ut0crc32.h        |   42 |||
| ut0dbg.h          |  168 | 调试工具 ||
| ut0list.h         |  155 | 双向链表 ||
| ut0list.ic        |   42 | - ||
| ut0lst.h          |  488 | 列表工具 ||
| ut0mem.h          |  161 | 内存原语 ||
| ut0mem.ic         |  299 | - ||
| ut0mutex.h        |  207 |||
| ut0mutex.ic       |   90 |||
| ut0new.h          |  909 |||
| ut0pool.h         |  348 |||
| ut0rbt.h          |  285 |||
| ut0rnd.h          |  123 | 随机数和哈希 ||
| ut0rnd.ic         |  223 | - ||
| ut0sort.h         |   88 | 排序工具 ||
| ut0stage.h        |  555 |||
| ut0ut.h           |  617 | 各种工具 ||
| ut0ut.ic          |  125 | - ||
| ut0vec.h          |  270 |||
| ut0vec.ic         |  332 |||
| ut0wqueue.h       |   74 |||


## db0err.h
<span id="db0err.h" />

## dyn0buf.h
<span id="dyn0buf.h" />

## dyn0types.h
<span id="dyn0types.h" />

## ha_prototypes.h
<span id="ha_prototypes.h" />

## ib0mutex.h
<span id="ib0mutex.h" />

## sess0sess.h
<span id="sess0sess.h" />

## univ.i
<span id="univ.i" />

`*.ic`定义内联函数: 宏`UNIV_INLINE`

``` c++
#ifndef UNIV_MUST_NOT_INLINE
/* Definition for inline version */

#define UNIV_INLINE static inline

#else /* !UNIV_MUST_NOT_INLINE */
/* If we want to compile a noninlined version we use the following macro
definitions: */

#define UNIV_NONINL
#define UNIV_INLINE

#endif /* !UNIV_MUST_NOT_INLINE */
```
