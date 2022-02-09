# MySQL 5.7 RTFSC

Version: 5.7.32.

## Tools and Conventions

Extract definitions:

```
$ grep -E "(enum|struct|class)" *.h
```

Remove comments:

```
/\*([a-zA-Z0-9'",;:\.!~%&_@=/\|\-\>\<\*\s\r\n\(\)\[\]\{\}])+\*/
```

Structure of notes for codes:

```
### data structures
### values
### operations
```

## Options

### -DUNIV_*

UNIV_INNOCHECKSUM [^1]: for innochecksum tool.

UNIV_HOTBACKUP[^2]: for ibbackup.

[^1]: https://bugs.mysql.com/bug.php?id=75855
[^2]: https://stackoverflow.com/questions/28916804/what-does-univ-hotbackup-mean-in-innodb-source


```
// extra/CMakeLists.txt
ADD_DEFINITIONS("-DUNIV_INNOCHECKSUM")

// innode.cmake
# OS tests
ADD_DEFINITIONS("-DUNIV_LINUX -D_GNU_SOURCE=1")
ADD_DEFINITIONS("-DUNIV_SOLARIS")

# Enable InnoDB's UNIV_DEBUG in debug builds
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DUNIV_DEBUG")

OPTION(WITH_INNODB_EXTRA_DEBUG "Enable extra InnoDB debug checks" OFF)
IF(WITH_INNODB_EXTRA_DEBUG)
  IF(NOT WITH_DEBUG)
    MESSAGE(FATAL_ERROR "WITH_INNODB_EXTRA_DEBUG can be enabled only when WITH_DEBUG is enabled")
  ENDIF()

  SET(EXTRA_DEBUG_FLAGS "")
  SET(EXTRA_DEBUG_FLAGS "${EXTRA_DEBUG_FLAGS} -DUNIV_AHI_DEBUG")
  SET(EXTRA_DEBUG_FLAGS "${EXTRA_DEBUG_FLAGS} -DUNIV_DDL_DEBUG")
  SET(EXTRA_DEBUG_FLAGS "${EXTRA_DEBUG_FLAGS} -DUNIV_DEBUG_FILE_ACCESSES")
  SET(EXTRA_DEBUG_FLAGS "${EXTRA_DEBUG_FLAGS} -DUNIV_ZIP_DEBUG")

  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${EXTRA_DEBUG_FLAGS}")
  SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${EXTRA_DEBUG_FLAGS}")
ENDIF()
```

## Code Structure

- [Appendix A MySQL Source Code Distribution](https://dev.mysql.com/doc/internals/en/files-in-mysql-sources.html)

|L1|L2|Description|
|:---|:---|:---|
| Docs | -                                         | documentation files. |
| client | -                                       | Client library. |
| - | base                                         ||
| - | check                                        ||
| - | dump                                         ||
| - | upgrade                                      ||
| cmd-line-utils | -                               | Command-line utilities (`libedit` and `readline`). |
| - | libedit                                      ||
| dbug | -                                         | Fred Fish's dbug library. |
| extra | -                                        | Some minor standalone utility programs. |
| - | libevent                                     ||
| - | lz4                                          ||
| - | protobuf                                     ||
| - | rapidjson                                    ||
| include | -                                      | Header (*.h) files for most libraries; includes all header files distributed with the MySQL binary distribution. |
| - | atomic                                       ||
| - | boost_1_59_0                                 ||
| - | mysql                                        ||
| libbinlogevents | -                              ||
| - | export                                       ||
| - | include                                      ||
| - | src                                          ||
| libbinlogstandalone | -                          ||
| - | src                                          ||
| libmysql | -                                     | For producing MySQL as a library (for example, a Windows .DLL). |
| - | authentication_ldap                          ||
| - | authentication_win                           ||
| libmysqld | -                                    | The MySQL Server as an embeddable library. |
| - | examples                                     ||
| libservices | -                                  ||
| mysql-test | -                                   | A test suite for mysqld. |
| - | collections                                  | collections of test runs during integration and release testing. |
| - | extra                                        ||
| - | include                                      | included by test case files using `source` command. |
| - | lib                                          | library file used by `mysql-test-run.pl` and database initialization SQL code. |
| - | r                                            | test case result files. |
| - | std_data                                     | data files used by tests|
| - | suite                                        | named test suites|
| - | t                                            | test case input files. |
| mysys | -                                        | MySQL system library (Low level routines for file access etc.). |
| mysys_ssl | -                                    | SSL facility tools. |
| packaging | -                                    ||
| - | WiX                                          ||
| - | deb-in                                       ||
| - | rpm-common                                   ||
| - | rpm-docker                                   ||
| - | rpm-fedora                                   ||
| - | rpm-oel                                      ||
| - | rpm-sles                                     ||
| - | solaris                                      ||
| plugin | -                                       | plugins. |
| - | audit_null                                   ||
| - | auth                                         ||
| - | connection_control                           ||
| - | daemon_example                               ||
| - | fulltext                                     ||
| - | innodb_memcached                             ||
| - | keyring                                      ||
| - | password_validation                          ||
| - | replication_observers_example                ||
| - | rewrite_example                              ||
| - | rewriter                                     ||
| - | semisync                                     ||
| - | test_service_sql_api                         ||
| - | test_services                                ||
| - | udf_services                                 ||
| - | version_token                                ||
| rapid | -                                        ||
| - | plugin                                       ||
| - | unittest                                     ||
| regex | -                                        | Henry Spencer's Regular Expression library for support of `REGEXP` function. |
| scripts | -                                      | SQL batches, for example, `mysqlbug` and `mysql_install_db`. |
| - | sys_schema                                   ||
| - | systemd                                      ||
| source_downloads | -                             ||
| sql | -                                          | 处理SQL命令. |
| - | auth                                         ||
| - | conn_handler                                 ||
| - | examples                                     ||
| - | partitioning                                 ||
| - | share                                        ||
| sql-common | -                                   | Some .c files related to `sql` directory. |
| storage | -                                      ||
| - | archive                                      ||
| - | blackhole                                    ||
| - | csv                                          ||
| - | example                                      ||
| - | federated                                    ||
| - | heap                                         | The HEAP table handler. |
| - | innobase                                     | The Innobase (InnoDB) table handler. |
| - | myisam                                       | The MyISAM table handler. |
| - | myisammrg                                    | The MyISAM Merge table handler. |
| - | ndb                                          | MySQL Cluster. |
| - | partition                                    ||
| - | perfschema                                   ||
| strings | -                                      | Library for C string routines, for example, `atof`, `strchr`. |
| support-files | -                                | Files used to build MySQL on different systems. |
| - | MacOSX                                       ||
| - | dtrace                                       ||
| testclients | -                                  ||
| unittest | -                                     ||
| - | examples                                     ||
| - | gunit                                        ||
| - | mytap                                        ||
| vio | -                                          | Virtual I/O Library. |
| - | docs                                         ||
| win | -                                          ||
| zlib | -                                         | Data compression library, used on Windows. |
| - | amiga                                        ||
| - | msdos                                        ||
| - | nintendods                                   ||
| - | old                                          ||
| - | os400                                        ||
| - | qnx                                          ||
| - | test                                         ||
| - | watcom                                       ||
| - | win32                                        ||


### Storage Code Structure

|L1|Description|
|:---|:---|
|archive    | Archive |
|blackhole  | Blackhole |
|csv        | CSV |
|example    | Example |
|federated  | Federated |
|heap       | Memory |
|innobase   | InnoDB |
|myisam     | MyISAM |
|myisammrg  | Merge |
|ndb        | NDB(Network DataBase) Cluster |
|partition  | |
|perfschema | |

## MySQL Architecture and Core Modules

> Sasha Pachev. Understanding MySQL Internals. O’Reilly Media, 2007.

### Architecture

see `mysql-modules.uxf`.

### Server Initialization Module

- entry point: `main()` sql/main.cc, `mysqld_main()` sql/mysqld.cc
- `init_common_variables()` sql/mysqld.cc
- `init_thread_environment()` sql/mysqld.cc
- `init_server_components()` sql/mysqld.cc
- `grant_init()` sql/sql_acl.cc
- `init_slave()`  sql/slave.cc
- `get_options()` sql/mysqld.cc

### Connection Manager

- `handle_connections_sockets()` sql/mysqld.cc

### Thread Manager

- entry point: `create_new_thread()` sql/mysqld.cc
- `start_cached_thread()` sql/mysqld.cc

### Connection Thread

- `handle_one_connection()` sql/sql_parse.cc

### User Authentication Module

- entry point: `check_connection()` sql/sql_parse.cc
- `acl_check_host()` sql/sql_acl.cc
- `create_random_string()` sql/password.cc
- `check_user()` sql/sql_parse.cc
- `acl_getroot()` sql/sql_acl.cc

### Access Control Module

- `check_access()` sql/sql_parse.cc
- `check_grant()` sql/sql_parse.cc
- `check_table_access()` sql/sql_parse.cc
- `check_grant_column()` sql/sql_parse.cc
- `acl_get()` sql/sql_parse.cc

### Parser

- entry point: `mysql_parse()` sql/sql_parse.cc: `yyparse()` sql/sql_yacc.cc sql/sql_yacc.yy
- sql/gen_lex_hash.cc
- sql/lex.h
- sql/lex_symbol.h
- sql/lex_hash.h (生成的文件)
- sql/sql_lex.h
- sql/sql_lex.cc
- sql/item_*.h/cc

### Command Dispatcher

- `do_command()` sql/sql_parse.cc
- `dispatch_command()` sql/sql_parse.cc

### Query Cache Module

- `Query_cache::store_query()` sql/sql_cache.cc
- `Query_cache::send_result_to_client()` sql/sql_cache.cc

### Optimizer

- entry point: `mysql_select()` sql/sql_select.cc
- `JOIN::prepare()` sql/sql_select.cc
- `JOIN::optimize()` sql/sql_select.cc
- `JOIN::exec()` sql/sql_select.cc
- `make_join_statistics()` sql/sql_select.cc
- `find_best_combination()` sql/sql_select.cc
- `optimize_cond()` sql/sql_select.cc

### Table Manager

- `openfrm()` sql/table.cc
- `mysql_create_frm()` sql/unireg.cc
- `open_table()` sql/sql_base.cc
- `open_tables()` sql/sql_base.cc
- `open_ltable()` sql/sql_base.cc
- `mysql_lock_table()` sql/lock.cc

### Table Modification Modules

- `mysql_update()`, `mysql_multi_update()` sql/sql_update.cc
- `mysql_insert()` sql/sql_insert.cc
- `mysql_create_table()` sql/sql_table.cc
- `mysql_alter_table()` sql/sql_table.cc
- `mysql_rm_table()` sql/sql_table.cc
- `mysql_delete()` sql/sql_delete.cc

### Table Maintenance Module

- `mysql_admin_table()` sql/sql_table.cc
- `mysql_check_table()` sql/sql_table.cc
- `mysql_repair_table()` sql/sql_table.cc
- `mysql_backup_table()` sql/sql_table.cc
- `mysql_restore_table()` sql/sql_table.cc
- `mysql_optimize_table()` sql/sql_table.cc
- `mysql_analyze_table()` sql/sql_table.cc

### Status Reporting Module

- `mysqld_list_processes()` sql/sql_show.cc
- `mysqld_show()` sql/sql_show.cc
- `mysqld_show_create()` sql/sql_show.cc
- `mysqld_show_fields()` sql/sql_show.cc
- `mysqld_show_open_tables()` sql/sql_show.cc
- `mysqld_show_warnings()` sql/sql_show.cc
- `show_master_info()` sql/slave.cc
- `show_binlog_info()` sql/sql_repl.cc

### Abstracted Storage Engine Interface: Table Handler

- `class handler`, `struct handlerton` sql/handler.h
- `innobase`

### Storage Engine Implementations

- sql/ha_innodb.h, sql/ha_innodb.cc

### Logging Module

- `class MYSQL_LOG` sql/log.h
- sql/log_event.h

### Replication Master Module

- `mysql_binlog_send()` sql/sql_repl.cc

### Replication Slave Module

- `handle_slave_io()`, `handle_slave_sql()` sql/slave.cc

### Client/Server Protocol API

- `class Protocol`, `class Protocol_simple`, `class Protocol_prep`, `class Protocol_cursor` sql/protocol.h
- `my_net_read()` sql/net_serv.cc
- `my_net_write()` sql/net_serv.cc
- `net_store_data()` sql/protocol.cc
- `send_ok()` sql/protocol.cc
- `send_error()` sql/protocol.cc

### Low-Level Network I/O API

- `vio`
- `vio_*()`

### Core API

- `mysys
- `strings`
- `my_*()`
