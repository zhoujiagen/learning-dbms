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
### 14.6.6 Redo Log
### 14.6.7 Undo Logs

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
| 115 | `innodb_locks_unsafe_for_binlog`          | 已废弃. 控制搜索和索引扫描时如何使用gap locking. |
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
| 128 | `innodb_max_dirty_pages_pct`              |  |
| 129 | `innodb_max_dirty_pages_pct_lwm`          |  |
| 130 | `innodb_max_purge_lag`                    |  |
| 131 | `innodb_max_purge_lag_delay`              |  |
| 132 | `innodb_max_undo_log_size`                |  |
| 133 | `innodb_merge_threshold_set_all_debug`    |  |
| 134 | `innodb_monitor_disable`                  |  |
| 135 | `innodb_monitor_enable`                   |  |
| 136 | `innodb_monitor_reset`                    |  |
| 137 | `innodb_monitor_reset_all`                |  |
| 138 | `Innodb_num_open_files`                   |  |
| 139 | `innodb_numa_interleave`                  |  |
| 140 | `innodb_old_blocks_pct`                   |  |
| 141 | `innodb_old_blocks_time`                  |  |
| 142 | `innodb_online_alter_log_max_size`        |  |
| 143 | `innodb_open_files`                       |  |
| 144 | `innodb_optimize_fulltext_only`           |  |
| 145 | `Innodb_os_log_fsyncs`                    |  |
| 146 | `Innodb_os_log_pending_fsyncs`            |  |
| 147 | `Innodb_os_log_pending_writes`            |  |
| 148 | `Innodb_os_log_written`                   |  |
| 149 | `innodb_page_cleaners`                    |  |
| 150 | `Innodb_page_size`                        |  |
| 151 | `innodb_page_size`                        |  |
| 152 | `Innodb_pages_created`                    |  |
| 153 | `Innodb_pages_read`                       |  |
| 154 | `Innodb_pages_written`                    |  |
| 155 | `innodb_print_all_deadlocks`              |  |
| 156 | `innodb_purge_batch_size`                 |  |
| 157 | `innodb_purge_rseg_truncate_frequency`    |  |
| 158 | `innodb_purge_threads`                    |  |
| 159 | `innodb_random_read_ahead`                |  |
| 160 | `innodb_read_ahead_threshold`             |  |
| 161 | `innodb_read_io_threads`                  |  |
| 162 | `innodb_read_only`                        |  |
| 163 | `innodb_replication_delay`                |  |
| 164 | `innodb_rollback_on_timeout`              |  |
| 165 | `innodb_rollback_segments`                |  |
| 166 | `Innodb_row_lock_current_waits`           |  |
| 167 | `Innodb_row_lock_time`                    |  |
| 168 | `Innodb_row_lock_time_avg`                |  |
| 169 | `Innodb_row_lock_time_max`                |  |
| 170 | `Innodb_row_lock_waits`                   |  |
| 171 | `Innodb_rows_deleted`                     |  |
| 172 | `Innodb_rows_inserted`                    |  |
| 173 | `Innodb_rows_read`                        |  |
| 174 | `Innodb_rows_updated`                     |  |
| 175 | `innodb_saved_page_number_debug`          |  |
| 176 | `innodb_sort_buffer_size`                 |  |
| 177 | `innodb_spin_wait_delay`                  |  |
| 178 | `innodb_stats_auto_recalc`                |  |
| 179 | `innodb_stats_include_delete_marked`      |  |
| 180 | `innodb_stats_method`                     |  |
| 181 | `innodb_stats_on_metadata`                |  |
| 182 | `innodb_stats_persistent`                 |  |
| 183 | `innodb_stats_persistent_sample_pages`    |  |
| 184 | `innodb_stats_sample_pages`               |  |
| 185 | `innodb_stats_transient_sample_pages`     |  |
| 186 | `--innodb-status-file`                    | 控制是否在数据目录下创建`innodb_status.pid`文件, 并每15s写入`SHOW ENGINE INNODB STATUS`的输出. |
| 187 | `innodb_status_output`                    |  |
| 188 | `innodb_status_output_locks`              |  |
| 189 | `innodb_strict_mode`                      |  |
| 190 | `innodb_support_xa`                       |  |
| 191 | `innodb_sync_array_size`                  |  |
| 192 | `innodb_sync_debug`                       |  |
| 193 | `innodb_sync_spin_loops`                  |  |
| 194 | `innodb_table_locks`                      |  |
| 195 | `innodb_temp_data_file_path`              |  |
| 196 | `innodb_thread_concurrency`               |  |
| 197 | `innodb_thread_sleep_delay`               |  |
| 198 | `innodb_tmpdir`                           |  |
| 199 | `Innodb_truncated_status_writes`          |  |
| 200 | `innodb_trx_purge_view_update_only_debug` |  |
| 201 | `innodb_trx_rseg_n_slots_debug`           |  |
| 202 | `innodb_undo_directory`                   |  |
| 203 | `innodb_undo_log_truncate`                |  |
| 204 | `innodb_undo_logs`                        |  |
| 205 | `innodb_undo_tablespaces`                 |  |
| 206 | `innodb_use_native_aio`                   |  |
| 207 | `innodb_version`                          |  |
| 208 | `innodb_write_io_threads`                 |  |
| 209 | `unique_checks`                           |  |

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
