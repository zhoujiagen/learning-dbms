# `include`

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [base64.h](#base64h)                                                        |    42 | base64 encoding. ||
| [big_endian.h](#big_endianh)                                                |    95 | Data in big-endian format. ||
| [byte_order_generic.h](#byte_order_generich)                                |    78 | Endianness-independent definitions for architectures other  than the x86 architecture. ||
| [byte_order_generic_x86.h](#byte_order_generic_x86h)                        |    42 | Optimized functions for the x86 architecture (`_WIN32` included). ||
| [caching_sha2_passwordopt-longopts.h](#caching_sha2_passwordopt-longoptsh)  |    32 | - ||
| [caching_sha2_passwordopt-vars.h](#caching_sha2_passwordopt-varsh)          |    15 | - ||
| [crypt_genhash_impl.h](#crypt_genhash_implh)                                |    31 | Generate hash. ||
| [decimal.h](#decimalh)                                                      |   118 | Decimal utility. ||
| [dur_prop.h](#dur_proph)                                                    |    13 | `enum durability_properties`. ||
| [errmsg.h](#errmsgh)                                                        |    94 | Error messages for MySQL clients . ||
| [ft_global.h](#ft_globalh)                                                  |   113 | some definitions for full-text indices. ||
| [hash.h](#hashh)                                                            |   106 | Dynamic hashing of record with different key-length. ||
| [heap.h](#heaph)                                                            |   231 | This file should be included when using heap_database_functions. ||
| [i_callable.h](#i_callableh)                                                |    21 | Interface for functors. ||
| [instance_callback.h](#instance_callbackh)                                  |    81 | Instance method based callback. ||
| [keycache.h](#keycacheh)                                                    |   137 | Key cache variable structures . ||
| [lf.h](#lfh)                                                                |   193 | wait-free data structures. ||
| [little_endian.h](#little_endianh)                                          |    79 | Data in little-endian format. ||
| [m_ctype.h](#m_ctypeh)                                                      |   787 | A better inplementation of the UNIX ctype(3) library. ||
| [m_string.h](#m_stringh)                                                    |   322 | String utility. ||
| [mutex_lock.h](#mutex_lockh)                                                |    28 | A simple wrapper around a mutex. ||
| [my_aes.h](#my_aesh)                                                        |   112 | Wrapper to give simple interface for MySQL to AES standard encryption. ||
| [my_alloc.h](#my_alloch)                                                    |    64 | Data structures for `mysys/my_alloc.c` (root memory allocator). ||
| [my_atomic.h](#my_atomich)                                                  |    58 | atomic operations. ||
| [my_base.h](#my_baseh)                                                      |   629 | This file includes constants used with all databases. ||
| [my_bit.h](#my_bith)                                                        |   105 | Some useful bit functions. ||
| [my_bitmap.h](#my_bitmaph)                                                  |   125 | bitmap utility. ||
| [my_byteorder.h](#my_byteorderh)                                            |   199 | Functions for reading and storing in machine independent format (low byte first). ||
| [my_check_opt.h](#my_check_opth)                                            |    50 | definitions needed for MyISAM and MySQL parser. ||
| [my_command.h](#my_commandh)                                                |    50 | `enum enum_server_command`. ||
| [my_compare.h](#my_compareh)                                                |   108 | comparing keys. ||
| [my_compiler.h](#my_compilerh)                                              |   164 | Header for compiler-dependent features. ||
| [my_dbug.h](#my_dbugh)                                                      |   231 | DBUG utility. ||
| [my_default.h](#my_defaulth)                                                |    36 | default values. ||
| [my_dir.h](#my_dirh)                                                        |    74 | directory abstraction. ||
| [my_getopt.h](#my_getopth)                                                  |   130 | Option values. ||
| [my_global.h](#my_globalh)                                                  |   778 | This include file should be included first in every header file.. ||
| [my_icp.h](#my_icph)                                                        |    29 | `enum icp_result`: Values returned by index_cond_func_xxx functions. ||
| [my_list.h](#my_listh)                                                      |    31 | list utility. ||
| [my_md5.h](#my_md5h)                                                        |    31 | MD5 utility. ||
| [my_md5_size.h](#my_md5_sizeh)                                              |     8 | `#define MD5_HASH_SIZE 16 /* Hash size in bytes */`. ||
| [my_murmur3.h](#my_murmur3h)                                                |     8 | `murmur3_32`. ||
| [my_openssl.h](#my_opensslh)                                                |    39 | openssl utility. ||
| [my_rdtsc.h](#my_rdtsch)                                                    |   111 | elapsed time timer. ||
| [my_rnd.h](#my_rndh)                                                        |    19 | A wrapper to use OpenSSL PRNGs. ||
| [my_sqlcommand.h](#my_sqlcommandh)                                          |   160 | `enum enum_sql_command`. ||
| [my_stacktrace.h](#my_stacktraceh)                                          |    95 | stack trace utility. ||
| [my_sys.h](#my_sysh)                                                        |   966 | mysys utility. ||
| [my_thread.h](#my_threadh)                                                  |   173 | Defines to make different thread packages compatible. ||
| [my_thread_local.h](#my_thread_localh)                                      |    88 | thread local variable. ||
| [my_thread_os_id.h](#my_thread_os_idh)                                      |    79 | Portable wrapper for gettid(). ||
| [my_time.h](#my_timeh)                                                      |   225 | a private header of `sql-common` library. ||
| [my_timer.h](#my_timerh)                                                    |    56 | timer. ||
| [my_tree.h](#my_treeh)                                                      |    78 | RedBlack tree. ||
| [my_uctype.h](#my_uctypeh)                                                  |  1465 | Unicode ctype data. ||
| [my_user.h](#my_userh)                                                      |    16 | This is a header for libraries containing functions used in both server and only some of clients (but not in libmysql). ||
| [my_xml.h](#my_xmlh)                                                        |    77 | xml parser. ||
| [myisam.h](#myisamh)                                                        |   452 | This file should be included when using myisam_funktions. ||
| [myisammrg.h](#myisammrgh)                                                  |   105 | This file should be included when using merge_isam_funktions . ||
| [myisampack.h](#myisampackh)                                                |   215 | Storing of values in high byte first order. ||
| [mysql.h](#mysqlh)                                                          |   715 | This file defines the client API to MySQL and also the ABI of the dynamically linked libmysqlclient.. ||
| [mysql.h.pp](#mysql.hpp)                                                    |   718 | - ||
| [mysql_com.h](#mysql_comh)                                                  |   606 | Common definition between mysql server & client. ||
| [mysql_com_server.h](#mysql_com_serverh)                                    |    22 | Definitions private to the server, used in the networking layer to notify specific events. ||
| [mysql_embed.h](#mysql_embedh)                                              |    10 | Defines that are unique to the embedded version of MySQL. ||
| [mysql_time.h](#mysql_timeh)                                                |    41 | Time declarations shared between the server and client API. ||
| [mysql_version.h.in](#mysql_version.hin)                                    |    30 | Version numbers for protocol & mysqld. ||
| [mysys_err.h](#mysys_errh)                                                  |    76 | Error message numbers. ||
| [nullable.h](#nullableh)                                                    |    73 | Class for storing value or NULL value. ||
| [password.h](#passwordh)                                                    |    15 | password utility. ||
| [pfs_file_provider.h](#pfs_file_providerh)                                  |    73 | Performance schema instrumentation (declarations). ||
| [pfs_idle_provider.h](#pfs_idle_providerh)                                  |    29 | - ||
| [pfs_memory_provider.h](#pfs_memory_providerh)                              |    38 | - ||
| [pfs_metadata_provider.h](#pfs_metadata_providerh)                          |    48 | - ||
| [pfs_socket_provider.h](#pfs_socket_providerh)                              |    52 | - ||
| [pfs_stage_provider.h](#pfs_stage_providerh)                                |    33 | - ||
| [pfs_statement_provider.h](#pfs_statement_providerh)                        |    99 | - ||
| [pfs_table_provider.h](#pfs_table_providerh)                                |    64 | - ||
| [pfs_thread_provider.h](#pfs_thread_providerh)                              |   151 | - ||
| [pfs_transaction_provider.h](#pfs_transaction_providerh)                    |    60 | - ||
| [prealloced_array.h](#prealloced_arrayh)                                    |   467 | A typesafe replacement for DYNAMIC_ARRAY. The purpose is to pre-allocate enough elements to cover normal use cases, thus saving `malloc()`/`free()` overhead. ||
| [priority_queue.h](#priority_queueh)                                        |   500 | a priority queue using a vector-based max-heap. ||
| [probes_mysql.d.base](#probes_mysql.dbase)                                  |   184 | DTrace probes. ||
| [probes_mysql.h](#probes_mysqlh)                                            |    10 | - ||
| [probes_mysql_nodtrace.h](#probes_mysql_nodtraceh)                          |   127 | - ||
| [queues.h](#queuesh)                                                        |    74 | Code for handling of priority Queues. ||
| [service_versions.h](#service_versionsh)                                    |    19 | - ||
| [sha1.h](#sha1h)                                                            |    19 | SHA1. ||
| [sha2.h](#sha2h)                                                            |    10 | `#include <openssl/sha.h>`. ||
| [sql_chars.h](#sql_charsh)                                                  |    56 | Char classes for lexical scanners. ||
| [sql_common.h](#sql_commonh)                                                |   191 | common utility. ||
| [sql_string.h](#sql_stringh)                                                |   647 | `class String`. ||
| [sslopt-case.h](#sslopt-caseh)                                              |    39 | - ||
| [sslopt-longopts.h](#sslopt-longoptsh)                                      |    44 | - ||
| [sslopt-vars.h](#sslopt-varsh)                                              |    56 | - ||
| [template_utils.h](#template_utilsh)                                        |    79 | C++ template utility. ||
| [thr_cond.h](#thr_condh)                                                    |   182 | thread condition variable. ||
| [thr_lock.h](#thr_lockh)                                                    |   143 | `typedef struct st_thr_lock { ... } THR_LOCK;`. ||
| [thr_mutex.h](#thr_mutexh)                                                  |   208 | MySQL mutex implementation. ||
| [thr_rwlock.h](#thr_rwlockh)                                                |   195 | MySQL rwlock implementation. ||
| [typelib.h](#typelibh)                                                      |    40 | type utility. ||
| [violite.h](#violiteh)                                                      |   318 | vio interface . ||

## `include`

### base64.h
### big_endian.h
### byte_order_generic.h
### byte_order_generic_x86.h
### caching_sha2_passwordopt-longopts.h
### caching_sha2_passwordopt-vars.h
### crypt_genhash_impl.h
### decimal.h
### dur_prop.h
### errmsg.h
### ft_global.h
### hash.h
### heap.h
### i_callable.h
### instance_callback.h
### keycache.h
### lf.h
### little_endian.h
### m_ctype.h
### m_string.h
### mutex_lock.h
### my_aes.h
### my_alloc.h
### my_atomic.h
### my_base.h
### my_bit.h
### my_bitmap.h
### my_byteorder.h
### my_check_opt.h
### my_command.h
### my_compare.h
### my_compiler.h
### my_dbug.h
### my_default.h
### my_dir.h
### my_getopt.h
### my_global.h
### my_icp.h
### my_list.h
### my_md5.h
### my_md5_size.h
### my_murmur3.h
### my_openssl.h
### my_rdtsc.h
### my_rnd.h
### my_sqlcommand.h
### my_stacktrace.h
### my_sys.h
### my_thread.h
### my_thread_local.h
### my_thread_os_id.h
### my_time.h
### my_timer.h
### my_tree.h
### my_uctype.h
### my_user.h
### my_xml.h
### myisam.h
### myisammrg.h
### myisampack.h
### mysql.h
### mysql.h.pp
### mysql_com.h
### mysql_com_server.h
### mysql_embed.h
### mysql_time.h
### mysql_version.h.in
### mysys_err.h
### nullable.h
### password.h
### pfs_file_provider.h
### pfs_idle_provider.h
### pfs_memory_provider.h
### pfs_metadata_provider.h
### pfs_socket_provider.h
### pfs_stage_provider.h
### pfs_statement_provider.h
### pfs_table_provider.h
### pfs_thread_provider.h
### pfs_transaction_provider.h
### prealloced_array.h
### priority_queue.h
### probes_mysql.d.base
### probes_mysql.h
### probes_mysql_nodtrace.h
### queues.h
### service_versions.h
### sha1.h
### sha2.h
### sql_chars.h
### sql_common.h
### sql_string.h
### sslopt-case.h
### sslopt-longopts.h
### sslopt-vars.h
### template_utils.h
### thr_cond.h
### thr_lock.h
### thr_mutex.h
### thr_rwlock.h
### typelib.h
### violite.h


## `include/atomic`

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [gcc_atomic.h](#gcc_atomich)      |    75 | New GCC `__atomic` builtins introduced in GCC 4.7. ||
| [gcc_sync.h](#gcc_synch)          |    87 | Old GCC `__sync` builtins introduced in GCC 4.1. ||
| [generic-msvc.h](#generic-msvch)  |   116 | - ||
| [solaris.h](#solarish)            |    98 | - ||

### gcc_atomic.h
### gcc_sync.h
### generic-msvc.h
### solaris.h

## `include/mysql`

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [client_authentication.h](#client_authenticationh)                          |    12 | auth client. ||
| [client_plugin.h](#client_pluginh)                                          |   188 | MySQL Client Plugin API. ||
| [client_plugin.h.pp](#client_plugin.hpp)                                    |    39 | - ||
| [com_data.h](#com_datah)                                                    |   106 | Definition of `COM_DATA` to be used with the Command service as data input structure. ||
| [get_password.h](#get_passwordh)                                            |    17 | Ask for a password from tty. ||
| [group_replication_priv.h](#group_replication_privh)                        |   180 | group replication utility. ||
| [innodb_priv.h](#innodb_privh)                                              |    36 | Declaring server-internal functions that are used by InnoDB. ||
| [mysql_lex_string.h](#mysql_lex_stringh)                                    |    14 | `MYSQL_LEX_STRING`, `MYSQL_LEX_CSTRING`. ||
| [plugin.h](#pluginh)                                                        |   726 | Plugin API. ||
| [plugin_audit.h](#plugin_audith)                                            |   539 | . ||
| [plugin_audit.h.pp](#plugin_audit.hpp)                                      |   514 | . ||
| [plugin_auth.h](#plugin_authh)                                              |   159 | Authentication Plugin API. ||
| [plugin_auth.h.pp](#plugin_auth.hpp)                                        |   153 | - ||
| [plugin_auth_common.h](#plugin_auth_commonh)                                |   129 | - ||
| [plugin_ftparser.h](#plugin_ftparserh)                                      |   195 | API for Full-text parser plugin. ||
| [plugin_ftparser.h.pp](#plugin_ftparser.hpp)                                |   160 | - ||
| [plugin_group_replication.h](#plugin_group_replicationh)                    |   133 | API for Group Peplication plugin. ||
| [plugin_keyring.h](#plugin_keyringh)                                        |   165 | API for keyring plugin. ||
| [plugin_keyring.h.pp](#plugin_keyring.hpp)                                  |   127 | - ||
| [plugin_trace.h](#plugin_traceh)                                            |   330 | `MYSQL_CLIENT_TRACE_PLUGIN`. ||
| [plugin_validate_password.h](#plugin_validate_passwordh)                    |    27 | API for validate_password plugin. ||
| [service_command.h](#service_commandh)                                      |   416 | Header file for the Command service. This service is to provide means of executing different commands, like `COM_QUERY`, `COM_STMT_PREPARE`, in the server.. ||
| [service_locking.h](#service_lockingh)                                      |    95 | These locks are implemented using the metadata lock (MDL) subsystem. ||
| [service_my_plugin_log.h](#service_my_plugin_logh)                          |    44 | This service provides functions to report error conditions and log to mysql error log. ||
| [service_my_snprintf.h](#service_my_snprintfh)                              |    82 | Portable and limited vsnprintf() implementation. ||
| [service_mysql_alloc.h](#service_mysql_alloch)                              |    62 | memory allocation for PSI_memory_key. ||
| [service_mysql_keyring.h](#service_mysql_keyringh)                          |    43 | securely store sensitive information for later retrieval. ||
| [service_mysql_password_policy.h](#service_mysql_password_policyh)          |    47 | This service provides functions to validatete password, check for strength of password based on common policy. ||
| [service_mysql_string.h](#service_mysql_stringh)                            |   114 | This service provides functions to parse mysql String . ||
| [service_parser.h](#service_parserh)                                        |   266 | Plugin service that provides access to the parser and some operations on the parse tree. ||
| [service_rpl_transaction_ctx.h](#service_rpl_transaction_ctxh)              |    62 | This service provides a function for plugins to report if a transaction of a given `THD` should continue or be aborted. ||
| [service_rpl_transaction_write_set.h](#service_rpl_transaction_write_seth)  |    61 | This service provides a function for plugins to get the write set of a given transaction. ||
| [service_rules_table.h](#service_rules_tableh)                              |   172 | Plugin service that provides access to the rewrite rules table that is used by the Rewriter plugin. ||
| [service_security_context.h](#service_security_contexth)                    |    76 | This service provides functions for plugins and storage engines to manipulate the thread's security context. ||
| [service_srv_session.h](#service_srv_sessionh)                              |   153 | Header file for the Server session service. This service is to provide of creating sessions with the server. These sessions can be furtherly used together with the Command service to execute commands in the server. ||
| [service_srv_session_info.h](#service_srv_session_infoh)                    |   154 | Service providing setters and getters for some properties of a session. ||
| [service_ssl_wrapper.h](#service_ssl_wrapperh)                              |   154 | SSL wrapper service. ||
| [service_thd_alloc.h](#service_thd_alloch)                                  |   113 | This service provdes functions to allocate memory in a connection local memory pool. ||
| [service_thd_engine_lock.h](#service_thd_engine_lockh)                      |    28 | This service provides functions for storage engines to report lock related activities. ||
| [service_thd_wait.h](#service_thd_waith)                                    |    95 | This service provides functions for plugins and storage engines to report when they are going to sleep/stall. ||
| [service_thread_scheduler.h](#service_thread_schedulerh)                    |    66 | Instantiates `Plugin_connection_handler`. ||
| [services.h](#servicesh)                                                    |    40 | collect service header files. ||
| [services.h.pp](#services.hpp)                                              |   506 | - ||
| [thread_pool_priv.h](#thread_pool_privh)                                    |   166 | thread pool utility. ||
| [thread_type.h](#thread_typeh)                                              |    25 | Defines to make different thread packages compatible. ||

### client_authentication.h
### client_plugin.h
### client_plugin.h.pp
### com_data.h
### get_password.h
### group_replication_priv.h
### innodb_priv.h
### mysql_lex_string.h
### plugin.h
### plugin_audit.h
### plugin_audit.h.pp
### plugin_auth.h
### plugin_auth.h.pp
### plugin_auth_common.h
### plugin_ftparser.h
### plugin_ftparser.h.pp
### plugin_group_replication.h
### plugin_keyring.h
### plugin_keyring.h.pp
### plugin_trace.h
### plugin_validate_password.h
### service_command.h
### service_locking.h
### service_my_plugin_log.h
### service_my_snprintf.h
### service_mysql_alloc.h
### service_mysql_keyring.h
### service_mysql_password_policy.h
### service_mysql_string.h
### service_parser.h
### service_rpl_transaction_ctx.h
### service_rpl_transaction_write_set.h
### service_rules_table.h
### service_security_context.h
### service_srv_session.h
### service_srv_session_info.h
### service_ssl_wrapper.h
### service_thd_alloc.h
### service_thd_engine_lock.h
### service_thd_wait.h
### service_thread_scheduler.h
### services.h
### services.h.pp
### thread_pool_priv.h
### thread_type.h

### `include/mysql/psi`

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [mysql_file.h](#mysql_fileh)                |  1417 | . ||
| [mysql_idle.h](#mysql_idleh)                |    77 | . ||
| [mysql_mdl.h](#mysql_mdlh)                  |   102 | . ||
| [mysql_memory.h](#mysql_memoryh)            |    43 | . ||
| [mysql_ps.h](#mysql_psh)                    |    84 | . ||
| [mysql_socket.h](#mysql_socketh)            |  1235 | . ||
| [mysql_sp.h](#mysql_sph)                    |    78 | . ||
| [mysql_stage.h](#mysql_stageh)              |   179 | . ||
| [mysql_statement.h](#mysql_statementh)      |   216 | . ||
| [mysql_table.h](#mysql_tableh)              |   123 | . ||
| [mysql_thread.h](#mysql_threadh)            |  1304 | . ||
| [mysql_transaction.h](#mysql_transactionh)  |   194 | . ||
| [psi.h](#psih)                              |  2985 | . ||
| [psi_abi_v0.h](#psi_abi_v0h)                |     5 | . ||
| [psi_abi_v0.h.pp](#psi_abi_v0.hpp)          |   100 | . ||
| [psi_abi_v1.h](#psi_abi_v1h)                |     7 | . ||
| [psi_abi_v1.h.pp](#psi_abi_v1.hpp)          |   859 | . ||
| [psi_abi_v2.h](#psi_abi_v2h)                |     7 | . ||
| [psi_abi_v2.h.pp](#psi_abi_v2.hpp)          |   283 | . ||
| [psi_base.h](#psi_baseh)                    |   141 | . ||
| [psi_memory.h](#psi_memoryh)                |   141 | . ||

### mysql_file.h
### mysql_idle.h
### mysql_mdl.h
### mysql_memory.h
### mysql_ps.h
### mysql_socket.h
### mysql_sp.h
### mysql_stage.h
### mysql_statement.h
### mysql_table.h
### mysql_thread.h
### mysql_transaction.h
### psi.h
### psi_abi_v0.h
### psi_abi_v0.h.pp
### psi_abi_v1.h
### psi_abi_v1.h.pp
### psi_abi_v2.h
### psi_abi_v2.h.pp
### psi_base.h
### psi_memory.h

## `include/boost_1_59_0`

> skip
