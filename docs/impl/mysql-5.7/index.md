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

|L1|L2|Description|
|:---|:---|:---|
| Docs | -                                         ||
| client | -                                       ||
| - | base                                         ||
| - | check                                        ||
| - | dump                                         ||
| - | upgrade                                      ||
| cmd-line-utils | -                               ||
| - | libedit                                      ||
| dbug | -                                         ||
| extra | -                                        ||
| - | libevent                                     ||
| - | lz4                                          ||
| - | protobuf                                     ||
| - | rapidjson                                    ||
| include | -                                      ||
| - | atomic                                       ||
| - | boost_1_59_0                                 ||
| - | mysql                                        ||
| libbinlogevents | -                              ||
| - | export                                       ||
| - | include                                      ||
| - | src                                          ||
| libbinlogstandalone | -                          ||
| - | src                                          ||
| libmysql | -                                     ||
| - | authentication_ldap                          ||
| - | authentication_win                           ||
| libmysqld | -                                    ||
| - | examples                                     ||
| libservices | -                                  ||
| mysql-test | -                                   ||
| - | collections                                  ||
| - | extra                                        ||
| - | include                                      ||
| - | lib                                          ||
| - | r                                            ||
| - | std_data                                     ||
| - | suite                                        ||
| - | t                                            ||
| mysys | -                                        ||
| mysys_ssl | -                                    ||
| packaging | -                                    ||
| - | WiX                                          ||
| - | deb-in                                       ||
| - | rpm-common                                   ||
| - | rpm-docker                                   ||
| - | rpm-fedora                                   ||
| - | rpm-oel                                      ||
| - | rpm-sles                                     ||
| - | solaris                                      ||
| plugin | -                                       ||
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
| regex | -                                        ||
| scripts | -                                      ||
| - | sys_schema                                   ||
| - | systemd                                      ||
| source_downloads | -                             ||
| sql | -                                          ||
| - | auth                                         ||
| - | conn_handler                                 ||
| - | examples                                     ||
| - | partitioning                                 ||
| - | share                                        ||
| sql-common | -                                   ||
| storage | -                                      ||
| - | archive                                      ||
| - | blackhole                                    ||
| - | csv                                          ||
| - | example                                      ||
| - | federated                                    ||
| - | heap                                         ||
| - | innobase                                     ||
| - | myisam                                       ||
| - | myisammrg                                    ||
| - | ndb                                          ||
| - | partition                                    ||
| - | perfschema                                   ||
| strings | -                                      ||
| support-files | -                                ||
| - | MacOSX                                       ||
| - | dtrace                                       ||
| testclients | -                                  ||
| unittest | -                                     ||
| - | examples                                     ||
| - | gunit                                        ||
| - | mytap                                        ||
| vio | -                                          ||
| - | docs                                         ||
| win | -                                          ||
| zlib | -                                         ||
| - | amiga                                        ||
| - | msdos                                        ||
| - | nintendods                                   ||
| - | old                                          ||
| - | os400                                        ||
| - | qnx                                          ||
| - | test                                         ||
| - | watcom                                       ||
| - | win32                                        ||


## Storage Code Structure

|L1|Description|
|:---|:---|
|archive||
|blackhole||
|csv||
|example||
|federated||
|heap||
|innobase|InnoDB存储引擎|
|myisam||
|myisammrg||
|ndb||
|partition||
|perfschema||

### InnoDB Storage Code Structure

|L1|Description|Progress|
|:---|:---|:--|
|[include](static/innobase/include.md)    |include目录                         ||
|[ut](static/innobase/ut.md)              |工具类                              ||
|[os](static/innobase/os.md)              |操作系统相关操作的封装: <br/>event<br/>file<br/>process<br/> thread|<br/><br/>DONE<br/><br/>|
|[ha](static/innobase/ha.md)              |哈希算法实现                         ||
|[api](static/innobase/api.md)            |本地API实现                         ||
|[srv](static/innobase/srv.md)            |服务器主程序                     |DONE|
|[handler](static/innobase/handler.md)    |插件式存储引擎的实现                  ||
|[usr](static/innobase/usr.md)            |用户会话实现                         ||
||||
|[fil](static/innobase/fil.md)            |文件数据结构和文件操作             |DONE|
|[fut](static/innobase/fut.md)            |File-based Utilities: 文件工具   |DONE|
|[fsp](static/innobase/fsp.md)            |File Space物理文件管理: 区、页、段等|DONE|
|[page](static/innobase/page.md)          |页的实现                            ||
|[rem](static/innobase/rem.md)            |记录管理器实现                       ||
|[mach](static/innobase/mach.md)          |机器数据格式工具                  |DONE|
|[data](static/innobase/data.md)          |数据字段和元组                   |DONE|
|[row](static/innobase/row.md)            |行操作的实现                         ||
|[btr](static/innobase/btr.md)            |B+树的实现                          ||
|[dict](static/innobase/dict.md)          |数据字典的实现                       ||
|[fts](static/innobase/fts.md)            |Full Text实现                       ||
|[gis](static/innobase/gis.md)            |R树实现                             ||
||||
|[mem](static/innobase/mem.md)            |内存管理                        |DONE|
|[buf](static/innobase/buf.md)            |缓冲池的实现                         ||
|[ibuf](static/innobase/ibuf.md)          |插入缓冲的实现                       ||
|[log](static/innobase/log.md)            |日志缓冲和日志文件的实现               ||
||||
|[pars](static/innobase/pars.md)          |SQL解析器                           ||
|[que](static/innobase/que.md)            |查询图实现                           ||
|[eval](static/innobase/eval.md)          |SQL求值器                           ||
|[read](static/innobase/read.md)          |游标读实现                           ||
||||
|[sync](static/innobase/sync.md)          |基础同步原语Mutex的实现               ||
|[lock](static/innobase/lock.md)          |锁的实现                            ||
|[mtr](static/innobase/mtr.md)            |Mini事务实现                        ||
|[trx](static/innobase/trx.md)            |事务的实现                           ||

### Performance Schema Structure

|L1|Description|Progress|
|:---|:---|:--|
|[cursor](static/perfschema/cursor.md)                |Cursor||
|[ha_perfschema](static/perfschema/ha_perfschema.md)  |Performance schema storage engine||
|[pfs](static/perfschema/pfs.md)                      |Performance schema instrumentation||
|[table](static/perfschema/table.md)                  |Performance schema tables||
