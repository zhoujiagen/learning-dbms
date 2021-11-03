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
...

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
...

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
           public Open_tables_state
{
...
};
```


### `NET`: network connection descriptor


``` c++
// include/mysql_com.h

typedef struct st_net {
  Vio *vio;
  unsigned char *buff,*buff_end,*write_pos,*read_pos;
  my_socket fd;					/* For Perl DBI/dbd */
  ...
} NET;

```

### `TABLE`: database table descriptor


``` c++
// sql/table.h

struct TABLE
{
  ...
};
```


### `Field`: field descriptor

``` c++
// sql/field.h
class Field: public Proto_field
{
  ...
};
```
