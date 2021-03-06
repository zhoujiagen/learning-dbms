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
| 7 | `foreign_key_checks`                        | ????????????????????????. |
| 8 | `ignore_builtin_innodb`                     | ??????InnoDB??????, ???5.7????????????. |
| 9 | `--innodb`                                  | ??????InnoDB?????????????????????. `--skip-innodb`??????InnoDB????????????. |
| 10 | `innodb_adaptive_flushing`                 | ??????????????????????????????flush buffer pool??????????????????. |
| 11 | `innodb_adaptive_flushing_lwm`             |  `innodb_adaptive_flushing`?????????, redo log?????????????????????. |
| 12 | `innodb_adaptive_hash_index`               | ????????????InnoDB???????????????. |
| 13 | `innodb_adaptive_hash_index_parts`         | ??????????????????????????????????????????, ??????????????????????????????????????????, ????????????????????????latch??????. |
| 14 | `innodb_adaptive_max_sleep_delay`          | ????????????????????????`innodb_thread_sleep_delay`??????. |
| 15 | `innodb_api_bk_commit_interval`            | - |
| 16 | `innodb_api_disable_rowlock`               | - |
| 17 | `innodb_api_enable_binlog`                 | - |
| 18 | `innodb_api_enable_mdl`                    | - |
| 19 | `innodb_api_trx_level`                     | - |
| 20 | `innodb_autoextend_increment`              | ?????????????????????InnoDB????????????????????????????????????, ??????MB. |
| 21 | `innodb_autoinc_lock_mode`                 | ?????????????????????????????????: 0 traditional, 1 consecutive, 2 interleaved. |
| 22 | `Innodb_available_undo_logs`               | ?????????rollback segments????????????. |
| 23 | `innodb_background_drop_list_empty`        | ????????????, ?????????????????????????????????drop????????????, ???????????????????????????. |
| 24 | `Innodb_buffer_pool_bytes_data`            | buffer pool???????????????????????????, ????????????????????????. |
| 25 | `Innodb_buffer_pool_bytes_dirty`           | buffer pool??????????????????????????????. |
| 26 | `innodb_buffer_pool_chunk_size`            | buffer pool?????????????????????chunk??????. |
| 27 | `innodb_buffer_pool_dump_at_shutdown`      | server?????????????????????buffer pool???????????????, ????????????????????????warmup??????. |
| 28 | `innodb_buffer_pool_dump_now`              | ????????????buffer pool???????????????. |
| 29 | `innodb_buffer_pool_dump_pct`              | ??????buffer pool???dump????????????????????????????????????. |
| 30 | `Innodb_buffer_pool_dump_status`           | ??????buffer pool?????????????????????. |
| 31 | `innodb_buffer_pool_filename`              | ?????????`innodb_buffer_pool_dump_at_shutdown`???`innodb_buffer_pool_dump_now`???????????????tablespace ID???page ID?????????????????????, ?????????`ib_buffer_pool`. |
| 32 | `innodb_buffer_pool_instances`             | buffer pool?????????region/instance?????????. |
| 33 | `innodb_buffer_pool_load_abort`            | ?????????`innodb_buffer_pool_load_at_startup`???`innodb_buffer_pool_load_now`???????????????buffer pool?????????. |
| 34 | `innodb_buffer_pool_load_at_startup`       | ????????????server?????????, buffer pool???????????????????????????????????????. |
| 35 | `innodb_buffer_pool_load_now`              | ?????????server??????, ????????????????????????????????????buffer pool. |
| 36 | `Innodb_buffer_pool_load_status`           | ??????buffer pool???????????????. |
| 37 | `Innodb_buffer_pool_pages_data`            | buffer pool????????????????????????, ??????dirty page???clean page. |
| 38 | `Innodb_buffer_pool_pages_dirty`           | buffer pool???dirty page?????????. |
| 39 | `Innodb_buffer_pool_pages_flushed`         | buffer pool???flush page????????????. |
| 40 | `Innodb_buffer_pool_pages_free`            | buffer pool???free page?????????. |
| 41 | `Innodb_buffer_pool_pages_latched`         | buffer pool???latched page?????????. |
| 42 | `Innodb_buffer_pool_pages_misc`            | buffer pool??????????????????????????????????????????(????????????????????????????????????). |
| 43 | `Innodb_buffer_pool_pages_total`           | buffer pool????????????. |
| 44 | `Innodb_buffer_pool_read_ahead`            | read-ahead??????????????????buffer pool???????????????. |
| 45 | `Innodb_buffer_pool_read_ahead_evicted`    | read-ahead??????????????????buffer pool???, ?????????evicted???????????????. |
| 46 | `Innodb_buffer_pool_read_ahead_rnd`        | InnoDB???????????????read-ahead?????????. |
| 47 | `Innodb_buffer_pool_read_requests`         | ??????????????????????????????. |
| 48 | `Innodb_buffer_pool_reads`                 | ?????????buffer pool????????????????????????????????????????????????????????????. |
| 49 | `Innodb_buffer_pool_resize_status`         | ????????????buffer pool????????????????????????. |
| 50 | `innodb_buffer_pool_size`                  | buffer pool?????????, ????????????. |
| 51 | `Innodb_buffer_pool_wait_free`             | ???buffer pool???clean page?????????, flush dirty page?????????????????????; ?????????????????????. |
| 52 | `Innodb_buffer_pool_write_requests`        | ???????????????buffer pool???????????????. |
| 53 | `innodb_change_buffer_max_size`            | change buffer???buffer pool??????????????????. |
| 54 | `innodb_change_buffering`                  | ????????????change buffering. ???: `none`???`inserts`???`deletes`???`changes`???`purges`???`all`. |
| 55 | `innodb_change_buffering_debug`            | change buffering????????????. |
| 56 | `innodb_checksum_algorithm`                | ??????tablespace?????????????????????????????????. |
| 57 | `innodb_checksums`                         | ?????????????????????. |
| 58 | `innodb_cmp_per_index_enabled`             | ????????????????????????????????????????????????, ??????`INFORMATION_SCHEMA.INNODB_CMP_PER_INDEX `. |
| 59 | `innodb_commit_concurrency`                | ????????????commit??????????????????. |
| 60 | `innodb_compress_debug`                    | ????????????, ????????????????????????????????????????????????. |
| 61 | `innodb_compression_failure_threshold_pct` | ?????????????????????????????????. |
| 62 | `innodb_compression_level`                 | ?????????????????????zlib????????????. |
| 63 | `innodb_compression_pad_pct_max`           | ????????????????????????????????????????????????????????????. |
| 64 | `innodb_concurrency_tickets`               | ??????????????????InnoDB??????????????????. |
| 65 | `innodb_data_file_path`                    | ??????????????????????????????????????????????????????. |
| 66 | `Innodb_data_fsyncs`                       | `fsync()`???????????????. |
| 67 | `innodb_data_home_dir`                     | ??????????????????????????????????????????????????????. |
| 68 | `Innodb_data_pending_fsyncs`               | ??????pending `fsync()` ???????????????. |
| 69 | `Innodb_data_pending_reads`                | ??????pending????????????. |
| 70 | `Innodb_data_pending_writes`               | ??????pending????????????. |
| 71 | `Innodb_data_read`                         | ???server??????????????????????????????. |
| 72 | `Innodb_data_reads`                        | ?????????????????????(OS?????????). |
| 73 | `Innodb_data_writes`                       | ?????????????????????. |
| 74 | `Innodb_data_written`                      | ???????????????????????????. |
| 75 | `Innodb_dblwr_pages_written`               | ?????????doublewrite buffer???????????????. |
| 76 | `Innodb_dblwr_writes`                      | ????????????doulewrite???????????????. |
| 77 | `innodb_deadlock_detect`                   | ????????????????????????. |
| 78 | `innodb_default_row_format`                | ????????????????????????????????????????????????: `DYNAMIC`???`COMPACT`???`REDUNDANT`. |
| 79 | `innodb_disable_resize_buffer_pool_debug`  | ????????????, ??????????????????buffer pool??????. |
| 80 | `innodb_disable_sort_file_cache`           | merge-sort???????????????????????????OS??????????????????. |
| 81 | `innodb_doublewrite`                       | ????????????doublewrite, ???????????????????????????: ??????doublewrite buffer, ????????????????????????. |
| 82 | `innodb_fast_shutdown`                     | shutdown??????. |
| 83 | `innodb_fil_make_page_dirty_debug`         | ????????????, ??????????????????????????????tablespace ID. |
| 84 | `innodb_file_format`                       | file-per-table????????????????????????: `Antelope`???`Barracuda`. |
| 85 | `innodb_file_format_check`                 | server???????????????????????????tablespace????????????????????????. |
| 86 | `innodb_file_format_max`                   | server?????????????????????tablespace?????????????????????. |
| 87 | `innodb_file_per_table`                    | ????????????file-per-table tablespace?????????. |
| 88 | `innodb_fill_factor`                       | sorted index build?????????B-tree page???????????????????????????. |
| 89 | `innodb_flush_log_at_timeout`              | ???N???write???flush??????. |
| 90 | `innodb_flush_log_at_trx_commit`           | ????????????ACID????????????commit?????????IO???????????????: 1 ????????????????????????write flush???????????????; 0 ??????write flush???????????????; 2 ????????????????????????write flush???????????????. |
| 91 | `innodb_flush_method`                      | flush?????????InnoDB????????????????????????????????????:<br/><br/> `fsync` ??????`fsync()`????????????flush ?????????????????????;<br/> `O_DSYNC` ??????`O_SYNC`?????????flush????????????, ??????`fsync()` flush????????????;<br/> `littlesync` ???????????????????????????;<br/> `nosync` ???????????????????????????;<br/> `O_DIRECT` ??????`O_DIRECT`??????????????????, ??????`fsync()` flush?????????????????????;<br/> `O_DIRECT_NO_FSYNC` ???flush?????????`O_DIRECT`, ??????????????????????????????`fsync()`????????????. |
| 92 | `innodb_flush_neighbors`                   | ???buffer pool???flush??????, ?????????flush??????extent??????dirty???. |
| 93 | `innodb_flush_sync`                        | ?????????, ???checkpoint????????????IO???????????????`innodb_io_capacity`??????. |
| 94 | `innodb_flushing_avg_loops`                | ????????????????????????????????????flushing??????????????????????????????. |
| 95 | `innodb_force_load_corrupted`              | ??????????????????????????????corrupted??????. |
| 96 | `innodb_force_recovery`                    | creash recovery??????. |
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
| 109 | `Innodb_have_atomic_builtins`             | ??????????????????????????????. |
| 110 | `innodb_io_capacity`                      | ?????????????????????IOPS(IO operations per second)??????, ??????flush buffer pool???page, ??????change buffer?????????. |
| 111 | `innodb_io_capacity_max`                  | ???????????????????????????IOPS. |
| 112 | `innodb_large_prefix`                     | ???????????????`DYNAMIC`???`COMPRESSED`???????????????????????????????????????767??????(??????3072??????). |
| 113 | `innodb_limit_optimistic_insert_debug`    | ????????????, ????????????B-tree?????????????????????. |
| 114 | `innodb_lock_wait_timeout`                | ????????????????????????row lock?????????. |
| 115 | `innodb_locks_unsafe_for_binlog`          | ?????????. ??????????????????????????????????????????gap locking.  0 ??????gap locking. 1 ?????????gap locking.|
| 116 | `innodb_log_buffer_size`                  | log buffer?????????, ????????????. |
| 117 | `innodb_log_checkpoint_now`               | ????????????, ?????????checkpoint. |
| 118 | `innodb_log_checksums`                    | ????????????redo log???????????????. |
| 119 | `innodb_log_compressed_pages`             | re-compressed??????image????????????redo log. |
| 120 | `innodb_log_file_size`                    | log group?????????log???????????????, ????????????. |
| 121 | `innodb_log_files_in_group`               | log group???log???????????????. |
| 122 | `innodb_log_group_home_dir`               | redo log?????????????????????. |
| 123 | `Innodb_log_waits`                        | log buffer??????, ????????????flush?????????. |
| 124 | `innodb_log_write_ahead_size`             | redo log???write-ahead block??????, ????????????. |
| 125 | `Innodb_log_write_requests`               | redo log??????????????????. |
| 126 | `Innodb_log_writes`                       | ?????????redo log???????????????. |
| 127 | `innodb_lru_scan_depth`                   | ?????????buffer pool instance, page cleaner?????????buffer pool LUR page list????????????flush???dirty page?????????. |
| 128 | `innodb_max_dirty_pages_pct`              | buffer pool???dirty page??????????????????. |
| 129 | `innodb_max_dirty_pages_pct_lwm`          | ???flush buffer pool???dirty page????????????. |
| 130 | `innodb_max_purge_lag`                    | ?????????purge lag. |
| 131 | `innodb_max_purge_lag_delay`              | ???`innodb_max_purge_lag`???????????????????????????, ????????????. |
| 132 | `innodb_max_undo_log_size`                | undo????????????????????????, ????????????. |
| 133 | `innodb_merge_threshold_set_all_debug`    | ????????????dictionary cache????????????`MERGE_THRESHOLD`?????????. |
| 134 | `innodb_monitor_disable`                  | ??????metrics couters. |
| 135 | `innodb_monitor_enable`                   | ??????metrics counters. |
| 136 | `innodb_monitor_reset`                    | ??????metrics counters????????????. |
| 137 | `innodb_monitor_reset_all`                | ??????metrics counters????????????. |
| 138 | `Innodb_num_open_files`                   | ???????????????????????????. |
| 139 | `innodb_numa_interleave`                  | ?????????InnoDB buffer pool??????NUMA interleave memory policy.|
| 140 | `innodb_old_blocks_pct`                   | buffer pool?????????old block sublist??????????????????. |
| 141 | `innodb_old_blocks_time`                  | ????????????old sublist???block????????????????????????, ????????????new sublist??????????????????????????????. |
| 142 | `innodb_online_alter_log_max_size`        | ????????????inline DDL????????????????????????log????????????????????????. |
| 143 | `innodb_open_files`                       | ?????????????????????`.idb`?????????????????????. |
| 144 | `innodb_optimize_fulltext_only`           | - |
| 145 | `Innodb_os_log_fsyncs`                    | redo log?????????`fsync()`???????????????. |
| 146 | `Innodb_os_log_pending_fsyncs`            | redo log?????????pending `fsync()`???????????????. |
| 147 | `Innodb_os_log_pending_writes`            | redo log?????????pending ???????????????. |
| 148 | `Innodb_os_log_written`                   | ??????redo log??????????????????. |
| 149 | `innodb_page_cleaners`                    | flush???buffer pool instance???dirty page???page cleaner???????????????.|
| 150 | `Innodb_page_size`                        | ?????????, ??????16KB. |
| 151 | `innodb_page_size`                        | tablespace???????????????. ???: 16384, 16KB, 16k. |
| 152 | `Innodb_pages_created`                    | ?????????????????????????????????. |
| 153 | `Innodb_pages_read`                       | ???????????????buffer pool????????????????????????. |
| 154 | `Innodb_pages_written`                    | ?????????????????????????????????. |
| 155 | `innodb_print_all_deadlocks`              | ?????????mysqld error log?????????????????????????????????????????????. |
| 156 | `innodb_purge_batch_size`                 | purge???????????????????????????history list?????????????????????undo log????????????. |
| 157 | `innodb_purge_rseg_truncate_frequency`    | purge????????????purge?????????????????????free rollback segment?????????. |
| 158 | `innodb_purge_threads`                    | ?????????purge??????????????????????????????. |
| 159 | `innodb_random_read_ahead`                | ??????????????????IO???read-ahead??????. |
| 160 | `innodb_read_ahead_threshold`             | ????????????prefetch page???buffer pool????????????read-ahead????????????. |
| 161 | `innodb_read_io_threads`                  | ??????????????????IO???????????????. |
| 162 | `innodb_read_only`                        | ????????????????????????. |
| 163 | `innodb_replication_delay`                | ??????`innodb_thread_concurrency`???replica server???replication?????????????????????. |
| 164 | `innodb_rollback_on_timeout`              | ?????????????????????abort???roll back????????????. |
| 165 | `innodb_rollback_segments`                | ?????????????????????undo?????????rollback segment?????????. |
| 166 | `Innodb_row_lock_current_waits`           | ??????????????????????????????row lock??????. |
| 167 | `Innodb_row_lock_time`                    | ??????????????????row lock????????????, ????????????. |
| 168 | `Innodb_row_lock_time_avg`                | ??????????????????row lock???????????????, ????????????. |
| 169 | `Innodb_row_lock_time_max`                | ??????????????????row lock???????????????, ????????????. |
| 170 | `Innodb_row_lock_waits`                   | ????????????row lock?????????????????????. |
| 171 | `Innodb_rows_deleted`                     | ???????????????????????????. |
| 172 | `Innodb_rows_inserted`                    | ???????????????????????????. |
| 173 | `Innodb_rows_read`                        | ???????????????????????????. |
| 174 | `Innodb_rows_updated`                     | ???????????????????????????. |
| 175 | `innodb_saved_page_number_debug`          | ????????????. ??????????????????. ??????`innodb_fil_make_page_dirty_debug`????????????`innodb_saved_page_number_debug`??????????????????dirty. |
| 176 | `innodb_sort_buffer_size`                 | ??????index????????????????????????sort buffer?????????. |
| 177 | `innodb_spin_wait_delay`                  | poll spin lock???????????????. |
| 178 | `innodb_stats_auto_recalc`                | ?????????????????????????????????????????????persistent statistics. |
| 179 | `innodb_stats_include_delete_marked`      | ??????persistent optimizer statistics???????????????delete-marked??????. |
| 180 | `innodb_stats_method`                     | ??????????????????????????????????????????, ????????????`NULL`???. |
| 181 | `innodb_stats_on_metadata`                | ??????metadata??????(`SHOW TABLE STATUS`)????????????`INFORMATION_SCHEMA.TABLES`/`INFORMATION_SCHEMA.STATISTICS`??????, ??????non-persistent statistics. |
| 182 | `innodb_stats_persistent`                 | ?????????index statistics??????????????????. |
| 183 | `innodb_stats_persistent_sample_pages`    | ?????????????????????????????????????????????????????????. ????????????`innodb_stats_persistent`?????????.|
| 184 | `innodb_stats_sample_pages`               | ?????????. |
| 185 | `innodb_stats_transient_sample_pages`     | ?????????????????????????????????????????????????????????. ????????????`innodb_stats_persistent`?????????. |
| 186 | `--innodb-status-file`                    | ????????????????????????????????????`innodb_status.pid`??????, ??????15s??????`SHOW ENGINE INNODB STATUS`?????????. |
| 187 | `innodb_status_output`                    | ????????????Monitor??????????????????. |
| 188 | `innodb_status_output_locks`              | ????????????Lock Monitor. |
| 189 | `innodb_strict_mode`                      | ????????????????????????. |
| 190 | `innodb_support_xa`                       | ?????????XA???????????????2PC. |
| 191 | `innodb_sync_array_size`                  | mutex/lock?????????????????????. |
| 192 | `innodb_sync_debug`                       | ????????????, ?????????????????????????????????????????????. |
| 193 | `innodb_sync_spin_loops`                  | ??????????????????mutex???????????????. |
| 194 | `innodb_table_locks`                      | `autocommit=0`, ??????????????????, `LOCK TABLES`??????????????????. |
| 195 | `innodb_temp_data_file_path`              | Temporary tablespace data file??????????????????????????????????????????. |
| 196 | `innodb_thread_concurrency`               | InnoDB?????????????????????. |
| 197 | `innodb_thread_sleep_delay`               | ?????????InnoDB queue??????sleep????????????. |
| 198 | `innodb_tmpdir`                           | online `ALTER TABLE`????????????????????????temporary sort file?????????. |
| 199 | `Innodb_truncated_status_writes`          | `SHOW ENGINE INNODB STATUS`?????????????????????????????????. |
| 200 | `innodb_trx_purge_view_update_only_debug` | ????????????, ??????purge delete-marked??????, ??????????????????purge view. |
| 201 | `innodb_trx_rseg_n_slots_debug`           |  |
| 202 | `innodb_undo_directory`                   | ??????undo tablespace?????????. |
| 203 | `innodb_undo_log_truncate`                | ?????????, ???undo tablespace?????????`innodb_max_undo_log_size`??????????????????, ????????????????????????. |
| 204 | `innodb_undo_logs`                        | rollback segment?????????. |
| 205 | `innodb_undo_tablespaces`                 | undo tablespace?????????. |
| 206 | `innodb_use_native_aio`                   | ????????????Linux ??????IO?????????. |
| 207 | `innodb_version`                          | ?????????. |
| 208 | `innodb_write_io_threads`                 | ??????????????????IO????????????. |
| 209 | `unique_checks`                           | ???????????????????????????. |

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
