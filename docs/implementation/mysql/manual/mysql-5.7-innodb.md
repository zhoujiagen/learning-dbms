# 14 The InnoDB Storage Engine - MySQL 5.7

## 14.1 Introduction to InnoDB
### 14.1.1 Benefits of Using InnoDB Tables
### 14.1.2 Best Practices for InnoDB Tables
### 14.1.3 Verifying that InnoDB is the Default Storage Engine
### 14.1.4 Testing and Benchmarking with InnoDB
### 14.1.5 Turning Off InnoDB

## 14.2 InnoDB and the ACID Model

## 14.3 InnoDB Multi-Versioning

## 14.4 InnoDB Architecture

## 14.5 InnoDB In-Memory Structures
### 14.5.1 Buffer Pool
### 14.5.2 Change Buffer
### 14.5.3 Adaptive Hash Index
### 14.5.4 Log Buffer

## 14.6 InnoDB On-Disk Structures
### 14.6.1 Tables
### 14.6.2 Indexes
### 14.6.3 Tablespaces
### 14.6.4 InnoDB Data Dictionary
### 14.6.5 Doublewrite Buffer

The doublewrite buffer is a storage area where InnoDB **writes pages flushed from the buffer pool before writing the pages to their proper positions in the InnoDB data files**. If there is an operating system, storage subsystem, or unexpected mysqld process exit in the middle of a page write, InnoDB can find a good copy of the page from the doublewrite buffer during crash recovery.

Although data is written twice, the doublewrite buffer does not require twice as much I/O overhead or twice as many I/O operations. Data is **written to the doublewrite buffer in a large sequential chunk, with a single fsync() call to the operating system** (except in the case that `innodb_flush_method` is set to `O_DIRECT_NO_FSYNC`).

### 14.6.6 Redo Log

The redo log is a disk-based data structure **used during crash recovery to correct data written by incomplete transactions**.

During normal operations, the redo log **encodes requests to change table data that result from SQL statements or low-level API calls**. Modifications that did not finish updating the data files before an unexpected shutdown are **replayed** automatically during initialization, and before the connections are accepted.

By default, the redo log is physically represented on disk by two files named `ib_logfile0` and `ib_logfile1`. MySQL writes to the redo log files in a circular fashion.

Data in the redo log is **encoded in terms of records affected**; this data is collectively referred to as **redo**. The passage of data through the redo log is represented by an ever-increasing **LSN** value.

### 14.6.7 Undo Logs

An undo log is a collection of undo log records associated with a single read-write transaction.

An undo log record contains information about how to **undo the latest change by a transaction to a clustered index record**. If another transaction needs to see the original data as part of a consistent read operation, the unmodified data is retrieved from undo log records.

Undo logs exist within **undo log segments**, which are contained within **rollback segments**.

Rollback segments reside in the system tablespace, in undo tablespaces, and in the temporary tablespace.

Undo logs that reside **in the temporary tablespace** are used for transactions that modify data **in user-defined temporary tables**. These undo logs are **not redo-logged**, as they are not required for crash recovery. They are used only for rollback while the server is running.

## 14.7 InnoDB Locking and Transaction Model
### 14.7.1 InnoDB Locking
### 14.7.2 InnoDB Transaction Model
### 14.7.3 Locks Set by Different SQL Statements in InnoDB
### 14.7.4 Phantom Rows
### 14.7.5 Deadlocks in InnoDB

## 14.8 InnoDB Configuration
### 14.8.1 InnoDB Startup Configuration
### 14.8.2 Configuring InnoDB for Read-Only Operation
### 14.8.3 InnoDB Buffer Pool Configuration
### 14.8.4 Configuring the Memory Allocator for InnoDB
### 14.8.5 Configuring Thread Concurrency for InnoDB
### 14.8.6 Configuring the Number of Background InnoDB I/O Threads


### 14.8.7 Using Asynchronous I/O on Linux
### 14.8.8 Configuring InnoDB I/O Capacity
### 14.8.9 Configuring Spin Lock Polling
### 14.8.10 Purge Configuration
### 14.8.11 Configuring Optimizer Statistics for InnoDB
### 14.8.12 Configuring the Merge Threshold for Index Pages

## 14.9 InnoDB Table and Page Compression
### 14.9.1 InnoDB Table Compression
### 14.9.2 InnoDB Page Compression

## 14.10 InnoDB File-Format Management
### 14.10.1 Enabling File Formats
### 14.10.2 Verifying File Format Compatibility
### 14.10.3 Identifying the File Format in Use
### 14.10.4 Modifying the File Format

## 14.11 InnoDB Row Formats

## 14.12 InnoDB Disk I/O and File Space Management
### 14.12.1 InnoDB Disk I/O
### 14.12.2 File Space Management
### 14.12.3 InnoDB Checkpoints
### 14.12.4 Defragmenting a Table
### 14.12.5 Reclaiming Disk Space with TRUNCATE TABLE

## 14.13 InnoDB and Online DDL
### 14.13.1 Online DDL Operations
### 14.13.2 Online DDL Performance and Concurrency
### 14.13.3 Online DDL Space Requirements
### 14.13.4 Simplifying DDL Statements with Online DDL
### 14.13.5 Online DDL Failure Conditions
### 14.13.6 Online DDL Limitations

## 14.14 InnoDB Data-at-Rest Encryption

## 14.15 InnoDB Startup Options and System Variables

|# | Name | Description |
|:---|:---|:---|
| 1 | `daemon_memcached_enable_binlog`            | - |
| 2 | `daemon_memcached_engine_lib_name`          | - |
| 3 | `daemon_memcached_engine_lib_path`          | - |
| 4 | `daemon_memcached_option`                   | - |
| 5 | `daemon_memcached_r_batch_size`             | - |
| 6 | `daemon_memcached_w_batch_size`             | - |
| 7 | `foreign_key_checks`                        | 是否检查外键约束. |
| 8 | `ignore_builtin_innodb`                     | 开启InnoDB插件, 在5.7中被忽略. |
| 9 | `--innodb`                                  | 控制InnoDB存储引擎的加载. `--skip-innodb`关闭InnoDB存储引擎. |
| 10 | `innodb_adaptive_flushing`                 | 是否基于负载动态调整flush buffer pool中脏页的比例. |
| 11 | `innodb_adaptive_flushing_lwm`             |  `innodb_adaptive_flushing`开启时, redo log比例的低水位线. |
| 12 | `innodb_adaptive_hash_index`               | 是否开启InnoDB自适应哈希. |
| 13 | `innodb_adaptive_hash_index_parts`         | 将自适应哈希索引检索系统分区, 每个索引对应到一个特定的分区, 每个分区用独立的latch保护. |
| 14 | `innodb_adaptive_max_sleep_delay`          | 根据负载自动调整`innodb_thread_sleep_delay`的值. |
| 15 | `innodb_api_bk_commit_interval`            | - |
| 16 | `innodb_api_disable_rowlock`               | - |
| 17 | `innodb_api_enable_binlog`                 | - |
| 18 | `innodb_api_enable_mdl`                    | - |
| 19 | `innodb_api_trx_level`                     | - |
| 20 | `innodb_autoextend_increment`              | 扩展自动扩展的InnoDB系统表空间文件的增量大小, 单位MB. |
| 21 | `innodb_autoinc_lock_mode`                 | 生成自增值使用的锁模式: 0 traditional, 1 consecutive, 2 interleaved. |
| 22 | `Innodb_available_undo_logs`               | 可用的rollback segments的总数量. |
| 23 | `innodb_background_drop_list_empty`        | 调试选项, 通过延迟表创建直到背景drop列表为空, 以避免测试案例失败. |
| 24 | `Innodb_buffer_pool_bytes_data`            | buffer pool中包含数据的字节数, 包括脏页和干净页. |
| 25 | `Innodb_buffer_pool_bytes_dirty`           | buffer pool中脏页持有的字节数量. |
| 26 | `innodb_buffer_pool_chunk_size`            | buffer pool调整大小操作的chunk大小. |
| 27 | `innodb_buffer_pool_dump_at_shutdown`      | server关闭时是否记录buffer pool中缓存的页, 以加速下次重启时warmup处理. |
| 28 | `innodb_buffer_pool_dump_now`              | 立即记录buffer pool中缓存的页. |
| 29 | `innodb_buffer_pool_dump_pct`              | 每个buffer pool在dump时最近经常使用的页的比例. |
| 30 | `Innodb_buffer_pool_dump_status`           | 记录buffer pool中持有页的进展. |
| 31 | `innodb_buffer_pool_filename`              | 指定由`innodb_buffer_pool_dump_at_shutdown`或`innodb_buffer_pool_dump_now`生成的包含tablespace ID和page ID列表的文件名称, 默认为`ib_buffer_pool`. |
| 32 | `innodb_buffer_pool_instances`             | buffer pool拆分成region/instance的数量. |
| 33 | `innodb_buffer_pool_load_abort`            | 中断由`innodb_buffer_pool_load_at_startup`或`innodb_buffer_pool_load_now`触发的填充buffer pool的过程. |
| 34 | `innodb_buffer_pool_load_at_startup`       | 开启后再server启动时, buffer pool通过加载早时的页来自动预热. |
| 35 | `innodb_buffer_pool_load_now`              | 不等待server重启, 立即加载一组数据页来预热buffer pool. |
| 36 | `Innodb_buffer_pool_load_status`           | 预热buffer pool操作的进展. |
| 37 | `Innodb_buffer_pool_pages_data`            | buffer pool中包含数据的页数, 包括dirty page和clean page. |
| 38 | `Innodb_buffer_pool_pages_dirty`           | buffer pool中dirty page的数量. |
| 39 | `Innodb_buffer_pool_pages_flushed`         | buffer pool的flush page请求数量. |
| 40 | `Innodb_buffer_pool_pages_free`            | buffer pool中free page的数量. |
| 41 | `Innodb_buffer_pool_pages_latched`         | buffer pool中latched page的数量. |
| 42 | `Innodb_buffer_pool_pages_misc`            | buffer pool中分配用于管理性成本的页数量(例如行锁或自适应哈希索引). |
| 43 | `Innodb_buffer_pool_pages_total`           | buffer pool的总页数. |
| 44 | `Innodb_buffer_pool_read_ahead`            | read-ahead背景线程读入buffer pool的页的数量. |
| 45 | `Innodb_buffer_pool_read_ahead_evicted`    | read-ahead背景线程读入buffer pool中, 后续被evicted的页的数量. |
| 46 | `Innodb_buffer_pool_read_ahead_rnd`        | InnoDB开启的随机read-ahead的数量. |
| 47 | `Innodb_buffer_pool_read_requests`         | 逻辑读请求操作的数量. |
| 48 | `Innodb_buffer_pool_reads`                 | 无法从buffer pool中满足而必须从磁盘读取的逻辑读操作的数量. |
| 49 | `Innodb_buffer_pool_resize_status`         | 动态调整buffer pool大小的操作的状态. |
| 50 | `innodb_buffer_pool_size`                  | buffer pool的大小, 单位字节. |
| 51 | `Innodb_buffer_pool_wait_free`             | 当buffer pool无clean page可用时, flush dirty page并等待操作完成; 记录等待的数量. |
| 52 | `Innodb_buffer_pool_write_requests`        | 完成的写入buffer pool的操作数量. |
| 53 | `innodb_change_buffer_max_size`            | change buffer在buffer pool中的最大比例. |
| 54 | `innodb_change_buffering`                  | 是否使用change buffering. 值: `none`、`inserts`、`deletes`、`changes`、`purges`、`all`. |
| 55 | `innodb_change_buffering_debug`            | change buffering调试选项. |
| 56 | `innodb_checksum_algorithm`                | 用在tablespace中磁盘块中的校验和算法. |
| 57 | `innodb_checksums`                         | 是否使用校验和. |
| 58 | `innodb_cmp_per_index_enabled`             | 是否开启每个索引压缩相关的统计量, 见表`INFORMATION_SCHEMA.INNODB_CMP_PER_INDEX `. |
| 59 | `innodb_commit_concurrency`                | 可以同时commit的线程的数量. |
| 60 | `innodb_compress_debug`                    | 调试选项, 在所有表上使用一个特定的压缩算法. |
| 61 | `innodb_compression_failure_threshold_pct` | 表上压缩失败百分比阈值. |
| 62 | `innodb_compression_level`                 | 压缩表和索引的zlib压缩等级. |
| 63 | `innodb_compression_pad_pct_max`           | 在每个压缩页中预留为空闲空间的最大百分比. |
| 64 | `innodb_concurrency_tickets`               | 可以并发进入InnoDB的线程的数量. |
| 65 | `innodb_data_file_path`                    | 系统表空间数据文件的名称、大小和属性. |
| 66 | `Innodb_data_fsyncs`                       | `fsync()`操作的数量. |
| 67 | `innodb_data_home_dir`                     | 系统表空间数据文件的目录路径公用部分. |
| 68 | `Innodb_data_pending_fsyncs`               | 当前pending `fsync()` 操作的数量. |
| 69 | `Innodb_data_pending_reads`                | 当前pending读的数量. |
| 70 | `Innodb_data_pending_writes`               | 当前pending写的数量. |
| 71 | `Innodb_data_read`                         | 自server启动读取数据的字节数. |
| 72 | `Innodb_data_reads`                        | 读取数据的数量(OS文件读). |
| 73 | `Innodb_data_writes`                       | 写入数据的数量. |
| 74 | `Innodb_data_written`                      | 已写入数据的字节数. |
| 75 | `Innodb_dblwr_pages_written`               | 已写入doublewrite buffer的页的数量. |
| 76 | `Innodb_dblwr_writes`                      | 已执行的doulewrite操作的数量. |
| 77 | `innodb_deadlock_detect`                   | 是否开启死锁检测. |
| 78 | `innodb_default_row_format`                | 表和用户创建的临时表的默认行格式: `DYNAMIC`、`COMPACT`、`REDUNDANT`. |
| 79 | `innodb_disable_resize_buffer_pool_debug`  | 调试选项, 是否关闭调整buffer pool大小. |
| 80 | `innodb_disable_sort_file_cache`           | merge-sort临时文件时是否关闭OS文件系统缓存. |
| 81 | `innodb_doublewrite`                       | 是否开启doublewrite, 开启时存储数据两次: 写入doublewrite buffer, 写入实际数据文件. |
| 82 | `innodb_fast_shutdown`                     | shutdown模式. |
| 83 | `innodb_fil_make_page_dirty_debug`         | 调试选项, 立即将第一页置为脏的tablespace ID. |
| 84 | `innodb_file_format`                       | file-per-table表空间的文件格式: `Antelope`、`Barracuda`. |
| 85 | `innodb_file_format_check`                 | server启动时是否检查系统tablespace中的文件格式标记. |
| 86 | `innodb_file_format_max`                   | server启动时设置系统tablespace中文件格式标记. |
| 87 | `innodb_file_per_table`                    | 表是否在file-per-table tablespace中创建. |
| 88 | `innodb_fill_factor`                       | sorted index build时每个B-tree page中可用的空间百分比. |
| 89 | `innodb_flush_log_at_timeout`              | 每N秒write和flush日志. |
| 90 | `innodb_flush_log_at_trx_commit`           | 平衡严格ACID符合性与commit相关的IO操作的性能: 1 在每次事务提交时write flush日志到磁盘; 0 每秒write flush日志到磁盘; 2 在每次事务提交后write flush日志到磁盘. |
| 91 | `innodb_flush_method`                      | flush数据到InnoDB数据文件和日志文件的方法:<br/><br/> `fsync` 使用`fsync()`系统调用flush 数据和日志文件;<br/> `O_DSYNC` 使用`O_SYNC`打开和flush日志文件, 使用`fsync()` flush数据文件;<br/> `littlesync` 只用于内部性能测试;<br/> `nosync` 只用于内部性能测试;<br/> `O_DIRECT` 使用`O_DIRECT`打开数据文件, 使用`fsync()` flush数据和日志文件;<br/> `O_DIRECT_NO_FSYNC` 在flush时使用`O_DIRECT`, 在每次写操作之后跳过`fsync()`系统调用. |
| 92 | `innodb_flush_neighbors`                   | 从buffer pool中flush页时, 是否也flush同一extent种的dirty页. |
| 93 | `innodb_flush_sync`                        | 开启时, 当checkpoint产生大量IO活动时忽略`innodb_io_capacity`设置. |
| 94 | `innodb_flushing_avg_loops`                | 在迭代中保持之前计算出的flushing状态的快照的迭代数量. |
| 95 | `innodb_force_load_corrupted`              | 启动时是否加载标记为corrupted的表. |
| 96 | `innodb_force_recovery`                    | creash recovery模式. |
| 97 | `innodb_ft_aux_table`                      | - |
| 98 | `innodb_ft_cache_size`                     | - |
| 99 | `innodb_ft_enable_diag_print`              | - |
| 100 | `innodb_ft_enable_stopword`               | - |
| 101 | `innodb_ft_max_token_size`                | - |
| 102 | `innodb_ft_min_token_size`                | - |
| 103 | `innodb_ft_num_word_optimize`             | - |
| 104 | `innodb_ft_result_cache_limit`            | - |
| 105 | `innodb_ft_server_stopword_table`         | - |
| 106 | `innodb_ft_sort_pll_degree`               | - |
| 107 | `innodb_ft_total_cache_size`              | - |
| 108 | `innodb_ft_user_stopword_table`           | - |
| 109 | `Innodb_have_atomic_builtins`             | 是否内建有原子性指令. |
| 110 | `innodb_io_capacity`                      | 背景任务可用的IOPS(IO operations per second)数量, 例如flush buffer pool中page, 合并change buffer中数据. |
| 111 | `innodb_io_capacity_max`                  | 背景任务最大可用的IOPS. |
| 112 | `innodb_large_prefix`                     | 开启时允许`DYNAMIC`或`COMPRESSED`行格式的索引键前缀长度超过767字节(最大3072字节). |
| 113 | `innodb_limit_optimistic_insert_debug`    | 调试选项, 限制每个B-tree页中记录的数量. |
| 114 | `innodb_lock_wait_timeout`                | 事务在放弃前等待row lock的秒数. |
| 115 | `innodb_locks_unsafe_for_binlog`          | 已废弃. 控制搜索和索引扫描时如何使用gap locking.  0 使用gap locking. 1 不使用gap locking.|
| 116 | `innodb_log_buffer_size`                  | log buffer的大小, 单位字节. |
| 117 | `innodb_log_checkpoint_now`               | 调试选项, 强制写checkpoint. |
| 118 | `innodb_log_checksums`                    | 是否开启redo log页的校验和. |
| 119 | `innodb_log_compressed_pages`             | re-compressed页的image是否写入redo log. |
| 120 | `innodb_log_file_size`                    | log group中每个log文件的大小, 单位字节. |
| 121 | `innodb_log_files_in_group`               | log group中log文件的数量. |
| 122 | `innodb_log_group_home_dir`               | redo log文件的目录路径. |
| 123 | `Innodb_log_waits`                        | log buffer过小, 需要等待flush的次数. |
| 124 | `innodb_log_write_ahead_size`             | redo log的write-ahead block大小, 单位字节. |
| 125 | `Innodb_log_write_requests`               | redo log写请求的数量. |
| 126 | `Innodb_log_writes`                       | 物理写redo log文件的数量. |
| 127 | `innodb_lru_scan_depth`                   | 对每个buffer pool instance, page cleaner线程在buffer pool LUR page list中查找需flush的dirty page的位置. |
| 128 | `innodb_max_dirty_pages_pct`              | buffer pool中dirty page的最大百分比. |
| 129 | `innodb_max_dirty_pages_pct_lwm`          | 预flush buffer pool中dirty page的百分比. |
| 130 | `innodb_max_purge_lag`                    | 最大的purge lag. |
| 131 | `innodb_max_purge_lag_delay`              | 由`innodb_max_purge_lag`阈值产生的最大延迟, 单位毫秒. |
| 132 | `innodb_max_undo_log_size`                | undo表空间的最大大小, 单位字节. |
| 133 | `innodb_merge_threshold_set_all_debug`    | 覆盖当前dictionary cache中索引的`MERGE_THRESHOLD`的配置. |
| 134 | `innodb_monitor_disable`                  | 关闭metrics couters. |
| 135 | `innodb_monitor_enable`                   | 开启metrics counters. |
| 136 | `innodb_monitor_reset`                    | 重置metrics counters的计数值. |
| 137 | `innodb_monitor_reset_all`                | 重置metrics counters的所有值. |
| 138 | `Innodb_num_open_files`                   | 当前打开的文件数量. |
| 139 | `innodb_numa_interleave`                  | 为分配InnoDB buffer pool开启NUMA interleave memory policy.|
| 140 | `innodb_old_blocks_pct`                   | buffer pool中用于old block sublist的近似百分比. |
| 141 | `innodb_old_blocks_time`                  | 指定插入old sublist的block在其首次被访问后, 在被移入new sublist之前需要等待的毫秒数. |
| 142 | `innodb_online_alter_log_max_size`        | 在表执行inline DDL操作时使用的临时log文件的最大字节数. |
| 143 | `innodb_open_files`                       | 可以同时打开的`.idb`文件的最大数量. |
| 144 | `innodb_optimize_fulltext_only`           | - |
| 145 | `Innodb_os_log_fsyncs`                    | redo log文件上`fsync()`调用的次数. |
| 146 | `Innodb_os_log_pending_fsyncs`            | redo log文件上pending `fsync()`调用的次数. |
| 147 | `Innodb_os_log_pending_writes`            | redo log文件上pending 写入的次数. |
| 148 | `Innodb_os_log_written`                   | 写入redo log文件的字节数. |
| 149 | `innodb_page_cleaners`                    | flush各buffer pool instance中dirty page的page cleaner线程的数量.|
| 150 | `Innodb_page_size`                        | 页大小, 默认16KB. |
| 151 | `innodb_page_size`                        | tablespace中的页大小. 例: 16384, 16KB, 16k. |
| 152 | `Innodb_pages_created`                    | 表上操作创建的页的数量. |
| 153 | `Innodb_pages_read`                       | 表上操作从buffer pool中读取的页的数量. |
| 154 | `Innodb_pages_written`                    | 表上操作写入的页的数量. |
| 155 | `innodb_print_all_deadlocks`              | 是否在mysqld error log中显示用户事务中出现的所有死锁. |
| 156 | `innodb_purge_batch_size`                 | purge操作在一个批次中从history list中解析和处理的undo log页的数量. |
| 157 | `innodb_purge_rseg_truncate_frequency`    | purge系统基于purge被调用的次数来free rollback segment的频率. |
| 158 | `innodb_purge_threads`                    | 专用于purge操作的背景线程的数量. |
| 159 | `innodb_random_read_ahead`                | 是否开启优化IO的read-ahead技术. |
| 160 | `innodb_read_ahead_threshold`             | 控制用于prefetch page到buffer pool中的线性read-ahead的敏感度. |
| 161 | `innodb_read_io_threads`                  | 用于读操作的IO线程的数量. |
| 162 | `innodb_read_only`                        | 是否开启只读模式. |
| 163 | `innodb_replication_delay`                | 达到`innodb_thread_concurrency`时replica server上replication线程延迟毫秒数. |
| 164 | `innodb_rollback_on_timeout`              | 事务超时时是否abort和roll back整个事务. |
| 165 | `innodb_rollback_segments`                | 用于事务中生成undo记录的rollback segment的数量. |
| 166 | `Innodb_row_lock_current_waits`           | 当前在等待表上操作的row lock数量. |
| 167 | `Innodb_row_lock_time`                    | 用于获取表上row lock的总时间, 单位毫秒. |
| 168 | `Innodb_row_lock_time_avg`                | 用于获取表上row lock的平均时间, 单位毫秒. |
| 169 | `Innodb_row_lock_time_max`                | 用于获取表上row lock的最大时间, 单位毫秒. |
| 170 | `Innodb_row_lock_waits`                   | 需要等待row lock的表上操作数量. |
| 171 | `Innodb_rows_deleted`                     | 表中删除的行的数量. |
| 172 | `Innodb_rows_inserted`                    | 表中插入的行的数量. |
| 173 | `Innodb_rows_read`                        | 表中读取的行的数量. |
| 174 | `Innodb_rows_updated`                     | 表中更新的行的数量. |
| 175 | `innodb_saved_page_number_debug`          | 调试选项. 保存一个页号. 设置`innodb_fil_make_page_dirty_debug`选项将由`innodb_saved_page_number_debug`定义的页置为dirty. |
| 176 | `innodb_sort_buffer_size`                 | 创建index时用于排序数据的sort buffer的大小. |
| 177 | `innodb_spin_wait_delay`                  | poll spin lock的最大延迟. |
| 178 | `innodb_stats_auto_recalc`                | 表中数据改变后是否自动重新计算persistent statistics. |
| 179 | `innodb_stats_include_delete_marked`      | 计算persistent optimizer statistics时是否包含delete-marked记录. |
| 180 | `innodb_stats_method`                     | 收集表的索引值分布的统计量时, 如何处理`NULL`值. |
| 181 | `innodb_stats_on_metadata`                | 只在metadata语句(`SHOW TABLE STATUS`)时或访问`INFORMATION_SCHEMA.TABLES`/`INFORMATION_SCHEMA.STATISTICS`表时, 更新non-persistent statistics. |
| 182 | `innodb_stats_persistent`                 | 是否将index statistics持久化到硬盘. |
| 183 | `innodb_stats_persistent_sample_pages`    | 估计索引列的统计量时使用的索引页的数量. 只在开启`innodb_stats_persistent`时有效.|
| 184 | `innodb_stats_sample_pages`               | 已废弃. |
| 185 | `innodb_stats_transient_sample_pages`     | 估计索引列的统计量时使用的索引页的数量. 只在关闭`innodb_stats_persistent`时有效. |
| 186 | `--innodb-status-file`                    | 控制是否在数据目录下创建`innodb_status.pid`文件, 并每15s写入`SHOW ENGINE INNODB STATUS`的输出. |
| 187 | `innodb_status_output`                    | 是否开启Monitor周期性的输出. |
| 188 | `innodb_status_output_locks`              | 是否开启Lock Monitor. |
| 189 | `innodb_strict_mode`                      | 是否开启严格模式. |
| 190 | `innodb_support_xa`                       | 是否在XA事务中开启2PC. |
| 191 | `innodb_sync_array_size`                  | mutex/lock等待数组的长度. |
| 192 | `innodb_sync_debug`                       | 调试选项, 是否开启存储引擎的同步调试检查. |
| 193 | `innodb_sync_spin_loops`                  | 在暂停前等待mutex释放的时间. |
| 194 | `innodb_table_locks`                      | `autocommit=0`, 开启该选项时, `LOCK TABLES`导致内部锁表. |
| 195 | `innodb_temp_data_file_path`              | Temporary tablespace data file的相对路径、名称、大小和属性. |
| 196 | `innodb_thread_concurrency`               | InnoDB中最大线程数量. |
| 197 | `innodb_thread_sleep_delay`               | 在加入InnoDB queue之前sleep的毫秒数. |
| 198 | `innodb_tmpdir`                           | online `ALTER TABLE`操作重建表时创建temporary sort file的目录. |
| 199 | `Innodb_truncated_status_writes`          | `SHOW ENGINE INNODB STATUS`语句的输出被截断的次数. |
| 200 | `innodb_trx_purge_view_update_only_debug` | 调试选项, 暂停purge delete-marked记录, 同时允许更新purge view. |
| 201 | `innodb_trx_rseg_n_slots_debug`           |  |
| 202 | `innodb_undo_directory`                   | 创建undo tablespace的路径. |
| 203 | `innodb_undo_log_truncate`                | 开启时, 放undo tablespace超出由`innodb_max_undo_log_size`定义的阈值后, 被标记为需要截断. |
| 204 | `innodb_undo_logs`                        | rollback segment的数量. |
| 205 | `innodb_undo_tablespaces`                 | undo tablespace的数量. |
| 206 | `innodb_use_native_aio`                   | 是否使用Linux 异步IO子系统. |
| 207 | `innodb_version`                          | 版本号. |
| 208 | `innodb_write_io_threads`                 | 用于写操作的IO线程数量. |
| 209 | `unique_checks`                           | 是否开启唯一性检查. |

## 14.16 InnoDB INFORMATION_SCHEMA Tables
### 14.16.1 InnoDB INFORMATION_SCHEMA Tables about Compression
### 14.16.2 InnoDB INFORMATION_SCHEMA Transaction and Locking Information
### 14.16.3 InnoDB INFORMATION_SCHEMA System Tables
### 14.16.4 InnoDB INFORMATION_SCHEMA FULLTEXT Index Tables
### 14.16.5 InnoDB INFORMATION_SCHEMA Buffer Pool Tables
### 14.16.6 InnoDB INFORMATION_SCHEMA Metrics Table
### 14.16.7 InnoDB INFORMATION_SCHEMA Temporary Table Info Table
### 14.16.8 Retrieving InnoDB Tablespace Metadata from INFORMATION_SCHEMA.FILES

## 14.17 InnoDB Integration with MySQL Performance Schema
### 14.17.1 Monitoring ALTER TABLE Progress for InnoDB Tables Using Performance Schema
### 14.17.2 Monitoring InnoDB Mutex Waits Using Performance Schema

## 14.18 InnoDB Monitors
### 14.18.1 InnoDB Monitor Types
### 14.18.2 Enabling InnoDB Monitors
### 14.18.3 InnoDB Standard Monitor and Lock Monitor Output

## 14.19 InnoDB Backup and Recovery
### 14.19.1 InnoDB Backup
### 14.19.2 InnoDB Recovery

## 14.20 InnoDB and MySQL Replication

## 14.21 InnoDB memcached Plugin
### 14.21.1 Benefits of the InnoDB memcached Plugin
### 14.21.2 InnoDB memcached Architecture
### 14.21.3 Setting Up the InnoDB memcached Plugin
### 14.21.4 Security Considerations for the InnoDB memcached Plugin
### 14.21.5 Writing Applications for the InnoDB memcached Plugin
### 14.21.6 The InnoDB memcached Plugin and Replication
### 14.21.7 InnoDB memcached Plugin Internals
### 14.21.8 Troubleshooting the InnoDB memcached Plugin

## 14.22 InnoDB Troubleshooting
### 14.22.1 Troubleshooting InnoDB I/O Problems
### 14.22.2 Forcing InnoDB Recovery
### 14.22.3 Troubleshooting InnoDB Data Dictionary Operations
### 14.22.4 InnoDB Error Handling

## 14.23 InnoDB Limits

## 14.24 InnoDB Restrictions and Limitations
