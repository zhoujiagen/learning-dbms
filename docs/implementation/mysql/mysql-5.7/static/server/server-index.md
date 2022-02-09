# MySQL Server Overview


## `include`

[include](include.md)

## `strings`

[strings](strings-index.md)

## `mysys`

[mysys](mysys-index.md)


Utility API Calls:

- `mysys/my_malloc.c`
- `mysys/mulalloc.c`
- `mysys/my_alloc.c`
- `mysys/my_open.c`
- `mysys/my_read.c`
- `mysys/my_write.c`
- `mysys/mf_iocache.c`
- `mysys/mf_format.c`
- `mysys/hash.c`
- `mysys/array.c`
- `strings/strmov.c`
- `strings/strxmov.c`
- `strings/my_vsnprintf.c`
- `sql/thr_malloc.c`
- `sql/hostname.c`



## `sql`


### Global Variables

- `sql/mysqld.cc`
- `sql/log.cc`
- `sql/binlog.cc`

``` c++
// sql/mysqld.cc

char *mysql_data_home= const_cast<char*>(".");
 /**/

// sql/log.cc

Query_logger query_logger;

// sql/binlog.cc

MYSQL_BIN_LOG mysql_bin_log(&sync_binlog_period, WRITE_CACHE);

```

### Preprocessor Macros

- `include/my_global.h`
- `sql/mysqld.h`

``` c++
// include/my_global.h

typedef unsigned char	uchar;	/* Short for unsigned char */
typedef signed char int8;       /* Signed integer >= 8  bits */
typedef unsigned char uint8;    /* Unsigned integer >= 8  bits */
typedef short int16;
typedef unsigned short uint16;

#ifdef _WIN32
#define IF_WIN(A,B) A
#else
#define IF_WIN(A,B) B
#endif
 /**/

// sql/mysqld.h

#define current_thd _current_thd()

```

### `THD`: thread descriptor

```
// ql/sql_class.h


/**
  @class THD
  For each client connection we create a separate thread with THD serving as
  a thread/connection descriptor
*/

class THD :public MDL_context_owner,
           public Query_arena,
           public Open_tables_state { /**/ };
```


### `NET`: network connection descriptor


``` c++
// include/mysql_com.h

typedef struct st_net {
  Vio *vio;
  unsigned char *buff,*buff_end,*write_pos,*read_pos;
  my_socket fd;					/* For Perl DBI/dbd */
   /**/
} NET;

```

### `TABLE`: database table descriptor


``` c++
// sql/table.h

struct TABLE { /**/ };
```


### `Field`: field descriptor

``` c++
// sql/field.h
class Field: public Proto_field { /**/ };
```

### `Item`: thingamabob

Each instance of `Item` class has: an analogue in the sql language, a value, and a data type descriptor.

Examples: literals, column references, session or global variables, procedure variables, parameters, and SQL functions.


``` shell
# find Item_* classes in sql/

grep "^class Item_" *.h | grep -v "friend" |grep -v ";" > Item.txt
# or search "public Item"
```

``` c++
// sql/item.h

class Item : public Parse_tree_node { /**/ };

class Item_basic_constant :public Item { /**/ };
class Item_sp_variable :public Item { /**/ };
class Item_name_const : public Item { /**/ };
class Item_ident :public Item { /**/ };
class Item_ident_for_show :public Item { /**/ };
class Item_param :public Item, private Settable_routine_parameter { /**/ };
class Item_result_field :public Item	/* Item with result field */ { /**/ };
class Item_copy :public Item { /**/ };
class Item_type_holder: public Item { /**/ };

// sql/item_func.h

class Item_user_var_as_out_param :public Item { /**/ };

//

class Item_row: public Item { /**/ };

// sql/procedure.h

class Item_proc :public Item { /**/ };

```

### filesort

- `sql/filesort.h`

### caches

- key cache: `mysql/mf_keycache.c`
- record cache: `mysql/mf_iocache.c`
- table cache: `sql/sql_base.cc table_def_cache`
- hostname cache: `sql/hostname.cc hostname_cache`
- privilege cache: `sql/auth/sql_auth_cache.cc acl_cache`
- heap table cache: `include/heap.h`
- join buffer cache: `sql/sql_join_buffer.h class JOIN_CACHE`

### threads

``` c++
// sql/mysqld.cc

static PSI_thread_info all_server_threads[]=
{
#if defined (_WIN32) && !defined (EMBEDDED_LIBRARY)
  { &key_thread_handle_con_namedpipes, "con_named_pipes", PSI_FLAG_GLOBAL},
  { &key_thread_handle_con_sharedmem, "con_shared_mem", PSI_FLAG_GLOBAL},
  { &key_thread_handle_con_sockets, "con_sockets", PSI_FLAG_GLOBAL},
  { &key_thread_handle_shutdown, "shutdown", PSI_FLAG_GLOBAL},
#endif /* _WIN32 && !EMBEDDED_LIBRARY */
  { &key_thread_timer_notifier, "thread_timer_notifier", PSI_FLAG_GLOBAL},
  { &key_thread_bootstrap, "bootstrap", PSI_FLAG_GLOBAL},
  { &key_thread_handle_manager, "manager", PSI_FLAG_GLOBAL},
  { &key_thread_main, "main", PSI_FLAG_GLOBAL},
  { &key_thread_one_connection, "one_connection", 0},
  { &key_thread_signal_hand, "signal_handler", PSI_FLAG_GLOBAL},
  { &key_thread_compress_gtid_table, "compress_gtid_table", PSI_FLAG_GLOBAL},
  { &key_thread_parser_service, "parser_service", PSI_FLAG_GLOBAL},
};


// include/mysql/psi/mysql_thread.h

#ifdef HAVE_PSI_THREAD_INTERFACE
  #define mysql_thread_create(K, P1, P2, P3, P4) \
    inline_mysql_thread_create(K, P1, P2, P3, P4)
#else
  #define mysql_thread_create(K, P1, P2, P3, P4) \
    my_thread_create(P1, P2, P3, P4)
#endif
```


- main thread

``` c++
// sql/mysqld.cc

static my_thread_t main_thread_id;
```

- bootstrap thread

```
mysqld_main // sql/mysqld.cc
|-- bootstrap // sql/bootstrap.h


client/mysql_install_db.cc
```

- maintance thread: handle manager

```
mysqld_main // sql/mysqld.cc
|-- start_handle_manager // sql/sql_manager.cc
```

- signal handler thread

```
start_signal_handler // sql/mysqld.cc
```

- network threads

```
network_init // sql/mysqld.cc
```

- compress gtid table thread

```
mysqld_main // sql/mysqld.cc
|-- create_compress_gtid_table_thread // sql/rpl_gtid_persist.cc
```


#### innobase threads

``` c++
// storage/innobase/include/os0thread.h

#define DECLARE_THREAD(func)	func
```

``` shell
$ grep "DECLARE_THREAD" storage/innobase/**/*.cc
storage/innobase/buf/buf0buf.cc:DECLARE_THREAD(buf_resize_thread)(
storage/innobase/buf/buf0dump.cc:DECLARE_THREAD(buf_dump_thread)(
storage/innobase/buf/buf0flu.cc:DECLARE_THREAD(buf_flush_page_cleaner_coordinator)(
storage/innobase/buf/buf0flu.cc:DECLARE_THREAD(buf_flush_page_cleaner_worker)(
storage/innobase/dict/dict0stats_bg.cc:DECLARE_THREAD(dict_stats_thread)(
storage/innobase/lock/lock0wait.cc:DECLARE_THREAD(lock_wait_timeout_thread)(
storage/innobase/log/log0recv.cc:DECLARE_THREAD(recv_writer_thread)(
storage/innobase/srv/srv0srv.cc:DECLARE_THREAD(srv_monitor_thread)(
storage/innobase/srv/srv0srv.cc:DECLARE_THREAD(srv_error_monitor_thread)(
storage/innobase/srv/srv0srv.cc:DECLARE_THREAD(srv_master_thread)(
storage/innobase/srv/srv0srv.cc:DECLARE_THREAD(srv_worker_thread)(
storage/innobase/srv/srv0srv.cc:DECLARE_THREAD(srv_purge_coordinator_thread)(
storage/innobase/srv/srv0start.cc:DECLARE_THREAD(io_handler_thread)(
storage/innobase/trx/trx0roll.cc:DECLARE_THREAD(trx_rollback_or_clean_all_recovered)(
```
