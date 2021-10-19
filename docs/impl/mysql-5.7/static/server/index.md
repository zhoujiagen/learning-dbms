# MySQL Architecture and Core Modules

> Sasha Pachev. Understanding MySQL Internals. O’Reilly Media, 2007.

## Architecture

```
                    +----------------------------------+
client requests --> |       Connection Manager         |
                    +----------------------------------+
                                     |
                                     v
                    +----------------------------------+
                    |           Thread Manager         |
                    +----------------------------------+
                                     |
                                     v
                    +----------------------------------+
                    |         Connection Thread        |
                    +----------------------------------+
                                     |
                                     v
                    +----------------------------------+
                    |   User Authentication Module     |
                    +----------------------------------+
                                     |
                                     v                                
                    +----------------------------------+
                    |       Command Dispatcher         |
                    +----------------------------------+
                                     |
                -------------------------------------------
                |                    |                    |
                v                    |                    v
+----------------------------------+ |  +----------------------------------+
|       Query Cache Module         | |  |            Logging Module        |
+----------------------------------+ |  +----------------------------------+
                                     v        
                    +----------------------------------+
                    |             Parser               |
                    +----------------------------------+
                                     |
                                     |      +----------------------------------+
                                     | -->  |            Optimizer             |
                                     |      +----------------------------------+
                                     |                              
                                     |      +----------------------------------+
                                     | -->  |    Table Modification Module     |
                                     |      +----------------------------------+
                                     |
                                     |      +----------------------------------+
                                     | -->  |    Table Maintenance Module      |
                                     |      +----------------------------------+
                                     |
                                     |      +----------------------------------+
                                     | -->  |      Replication Module          |
                                     |      +----------------------------------+
                                     |
                                     |      +----------------------------------+
                                     | -->  |    Status Reporting Module       |
                                            +----------------------------------+
                                            |||||
                                              v
                    +----------------------------------+
                    |      Access Control Module       |
                    +----------------------------------+
                                     |
                                     v
                    +----------------------------------+
                    |           Table Manager          |
                    +----------------------------------+
                                     |
                                     v
                    +-----------------------------------+
                    |Abstracted Storage Engine Interface|
                    +-----------------------------------+
                                     |
                                     v
                    +----------------------------------+
                    |  Storage Engine Implementations  |
                    +----------------------------------+
```

## Server Initialization Module

- entry point: `main()` sql/mysqld.cc
- `init_common_variables()` sql/mysqld.cc
- `init_thread_environment()` sql/mysqld.cc
- `init_server_components()` sql/mysqld.cc
- `grant_init()` sql/sql_acl.cc
- `init_slave()`  sql/slave.cc
- `get_options()` sql/mysqld.cc

## Connection Manager

- `handle_connections_sockets()` sql/mysqld.cc

## Thread Manager

- entry point: `create_new_thread()` sql/mysqld.cc
- `start_cached_thread()` sql/mysqld.cc

## Connection Thread

- `handle_one_connection()` sql/sql_parse.cc

## User Authentication Module

- entry point: `check_connection()` sql/sql_parse.cc
- `acl_check_host()` sql/sql_acl.cc
- `create_random_string()` sql/password.cc
- `check_user()` sql/sql_parse.cc
- `acl_getroot()` sql/sql_acl.cc

## Access Control Module

- `check_access()` sql/sql_parse.cc
- `check_grant()` sql/sql_parse.cc
- `check_table_access()` sql/sql_parse.cc
- `check_grant_column()` sql/sql_parse.cc
- `acl_get()` sql/sql_parse.cc

## Parser

- entry point: `mysql_parse()` sql/sql_parse.cc: `yyparse()` sql/sql_yacc.cc sql/sql_yacc.yy
- sql/gen_lex_hash.cc
- sql/lex.h
- sql/lex_symbol.h
- sql/lex_hash.h (生成的文件)
- sql/sql_lex.h
- sql/sql_lex.cc
- sql/item_*.h/cc

## Command Dispatcher

- `do_command()` sql/sql_parse.cc
- `dispatch_command()` sql/sql_parse.cc

## Query Cache Module

- `Query_cache::store_query()` sql/sql_cache.cc
- `Query_cache::send_result_to_client()` sql/sql_cache.cc

## Optimizer

- entry point: `mysql_select()` sql/sql_select.cc
- `JOIN::prepare()` sql/sql_select.cc
- `JOIN::optimize()` sql/sql_select.cc
- `JOIN::exec()` sql/sql_select.cc
- `make_join_statistics()` sql/sql_select.cc
- `find_best_combination()` sql/sql_select.cc
- `optimize_cond()` sql/sql_select.cc

## Table Manager

- `openfrm()` sql/table.cc
- `mysql_create_frm()` sql/unireg.cc
- `open_table()` sql/sql_base.cc
- `open_tables()` sql/sql_base.cc
- `open_ltable()` sql/sql_base.cc
- `mysql_lock_table()` sql/lock.cc

## Table Modification Modules

- `mysql_update()`, `mysql_multi_update()` sql/sql_update.cc
- `mysql_insert()` sql/sql_insert.cc
- `mysql_create_table()` sql/sql_table.cc
- `mysql_alter_table()` sql/sql_table.cc
- `mysql_rm_table()` sql/sql_table.cc
- `mysql_delete()` sql/sql_delete.cc

## Table Maintenance Module

- `mysql_admin_table()` sql/sql_table.cc
- `mysql_check_table()` sql/sql_table.cc
- `mysql_repair_table()` sql/sql_table.cc
- `mysql_backup_table()` sql/sql_table.cc
- `mysql_restore_table()` sql/sql_table.cc
- `mysql_optimize_table()` sql/sql_table.cc
- `mysql_analyze_table()` sql/sql_table.cc

## Status Reporting Module

- `mysqld_list_processes()` sql/sql_show.cc
- `mysqld_show()` sql/sql_show.cc
- `mysqld_show_create()` sql/sql_show.cc
- `mysqld_show_fields()` sql/sql_show.cc
- `mysqld_show_open_tables()` sql/sql_show.cc
- `mysqld_show_warnings()` sql/sql_show.cc
- `show_master_info()` sql/slave.cc
- `show_binlog_info()` sql/sql_repl.cc

## Abstracted Storage Engine Interface: Table Handler

- `class handler`, `struct handlerton` sql/handler.h
- innobase/

## Storage Engine Implementations

- sql/ha_innodb.h, sql/ha_innodb.cc

## Logging Module

- `class MYSQL_LOG` sql/log.h
- sql/log_event.h

## Replication Master Module

- `mysql_binlog_send()` sql/sql_repl.cc

## Replication Slave Module

- `handle_slave_io()`, `handle_slave_sql()` sql/slave.cc

## Client/Server Protocol API

- `class Protocol`, `class Protocol_simple`, `class Protocol_prep`, `class Protocol_cursor` sql/protocol.h
- `my_net_read()` sql/net_serv.cc
- `my_net_write()` sql/net_serv.cc
- `net_store_data()` sql/protocol.cc
- `send_ok()` sql/protocol.cc
- `send_error()` sql/protocol.cc

## Low-Level Network I/O API

- vio/
- `vio_*()`

## Core API

- mysys/
- strings/
- `my_*()`
