# srv: 服务器主程序

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [srv0conc.h](#srv0conc.h)              |    76 | 并发管理头文件 ||
| [srv0mon.h](#srv0mon.h)                |   853 | 服务器监控计数器 ||
| [srv0mon.ic](#srv0mon.ic)              |    95 |||
| [srv0srv.h](#srv0srv.h)                |   960 | 服务器主程序 ||
| [srv0srv.ic](#srv0srv.ic)              |     6 |||
| [srv0start.h](#srv0start.h)            |   163 | 启动Innobase数据库服务器 ||
| [srv0conc.cc](#srv0conc.cc)    |   316 |||
| [srv0mon.cc](#srv0mon.cc)      |  2013 |||
| [srv0srv.cc](#srv0srv.cc)      |  2995 |||
| [srv0start.cc](#srv0start.cc)  |  2956 |||


## srv0conc.h
<span id="srv0conc.h" />

最大线程数:

``` c++
/** We are prepared for a situation that we have this many threads waiting for
a semaphore inside InnoDB. innobase_start_or_create_for_mysql() sets the
value. */

extern	ulint	srv_max_n_threads;
```

线程并发度:

``` c++
/** The following controls how many threads we let inside InnoDB concurrently:
threads waiting for locks are not counted into the number because otherwise
we could get a deadlock. Value of 0 will disable the concurrency check. */

extern ulong	srv_thread_concurrency;
```

`struct row_prebuilt_t`声明: 用于MySQL内部的表句柄中预建结构.

`srv_conc_xxx`声明.

## srv0mon.h
<span id="srv0mon.h" />

## srv0mon.ic
<span id="srv0mon.ic" />

## srv0srv.h
<span id="srv0srv.h" />

`struct srv_stats_t`: InnoDB中全局计数器:

`extern xxx`: 参数定义等.

文件刷出选项:

``` c++
/** Alternatives for the file flush option in Unix; see the InnoDB manual
about what these mean */
enum srv_unix_flush_t {
	SRV_UNIX_FSYNC = 1,	/*!< fsync, the default */
	SRV_UNIX_O_DSYNC,	/*!< open log files in O_SYNC mode */
	SRV_UNIX_LITTLESYNC,	/*!< do not call os_file_flush()
				when writing data files, but do flush
				after writing to log files */
	SRV_UNIX_NOSYNC,	/*!< do not flush after writing */
	SRV_UNIX_O_DIRECT,	/*!< invoke os_file_set_nocache() on
				data files. This implies using
				non-buffered IO but still using fsync,
				the reason for which is that some FS
				do not flush meta-data when
				unbuffered IO happens */
	SRV_UNIX_O_DIRECT_NO_FSYNC
				/*!< do not use fsync() when using
				direct IO i.e.: it can be set to avoid
				the fsync() call that we make when
				using SRV_UNIX_O_DIRECT. However, in
				this case user/DBA should be sure about
				the integrity of the meta-data */
};
```

恢复选项:

``` c++
/** Alternatives for srv_force_recovery. Non-zero values are intended
to help the user get a damaged database up so that he can dump intact
tables and rows with SELECT INTO OUTFILE. The database must not otherwise
be used with these options! A bigger number below means that all precautions
of lower numbers are included. */
enum {
	SRV_FORCE_IGNORE_CORRUPT = 1,	/*!< let the server run even if it
					detects a corrupt page */
	SRV_FORCE_NO_BACKGROUND	= 2,	/*!< prevent the main thread from
					running: if a crash would occur
					in purge, this prevents it */
	SRV_FORCE_NO_TRX_UNDO = 3,	/*!< do not run trx rollback after
					recovery */
	SRV_FORCE_NO_IBUF_MERGE = 4,	/*!< prevent also ibuf operations:
					if they would cause a crash, better
					not do them */
	SRV_FORCE_NO_UNDO_LOG_SCAN = 5,	/*!< do not look at undo logs when
					starting the database: InnoDB will
					treat even incomplete transactions
					as committed */
	SRV_FORCE_NO_LOG_REDO = 6	/*!< do not do the log roll-forward
					in connection with recovery */
};
```

收集统计量时处理NULL值的方法:

``` c++
/* Alternatives for srv_innodb_stats_method, which could be changed by
setting innodb_stats_method */
enum srv_stats_method_name_enum {
	SRV_STATS_NULLS_EQUAL,		/* All NULL values are treated as
					equal. This is the default setting
					for innodb_stats_method */
	SRV_STATS_NULLS_UNEQUAL,	/* All NULL values are treated as
					NOT equal. */
	SRV_STATS_NULLS_IGNORED		/* NULL values are ignored */
};
```

系统中线程类型:

``` c++
/** Types of threads existing in the system. */
enum srv_thread_type {
	SRV_NONE,			/*!< None */
	SRV_WORKER,			/*!< threads serving parallelized
					queries and queries released from
					lock wait */
	SRV_PURGE,			/*!< Purge coordinator thread */
	SRV_MASTER			/*!< the master thread, (whose type
					number must be biggest) */
};
```

`srv_xxx`: 服务器操作函数声明.

线程声明:

``` c++
/* A thread which prints the info output by various InnoDB monitors.
@return a dummy parameter */
os_thread_ret_t
DECLARE_THREAD(srv_monitor_thread)

/* The master thread controlling the server.
@return a dummy parameter */
os_thread_ret_t
DECLARE_THREAD(srv_master_thread)

/* A thread which prints warnings about semaphore waits which have lasted
too long. These can be used to track bugs which cause hangs.
@return a dummy parameter */
os_thread_ret_t
DECLARE_THREAD(srv_error_monitor_thread)

/* Purge coordinator thread that schedules the purge tasks.
@return a dummy parameter */
os_thread_ret_t
DECLARE_THREAD(srv_purge_coordinator_thread)

/* Worker thread that reads tasks from the work queue and executes them.
@return a dummy parameter */
os_thread_ret_t
DECLARE_THREAD(srv_worker_thread)
```

`struct export_var_t`: 传递给MySQL的状态变量.

线程表中的线程槽:

``` c++
/** Thread slot in the thread table.  */
struct srv_slot_t{
	srv_thread_type type;			/*!< thread type: user,
						utility etc. */
	ibool		in_use;			/*!< TRUE if this slot
						is in use */
	ibool		suspended;		/*!< TRUE if the thread is
						waiting for the event of this
						slot */
	ib_time_monotonic_t	suspend_time;	/*!< time when the thread was
						suspended. Initialized by
						lock_wait_table_reserve_slot()
						for lock wait */
	ulong		wait_timeout;		/*!< wait time that if exceeded
						the thread will be timed out.
						Initialized by
						lock_wait_table_reserve_slot()
						for lock wait */
	os_event_t	event;			/*!< event used in suspending
						the thread when it has nothing
						to do */
	que_thr_t*	thr;			/*!< suspended query thread
						(only used for user threads) */
};
```

## srv0srv.ic
<span id="srv0srv.ic" />

## srv0start.h
<span id="srv0start.h" />

`srv_ccc`参数声明.

`srv_xxx`函数声明.

关闭状态:

``` c++
/** Shutdown state */
enum srv_shutdown_t {
	SRV_SHUTDOWN_NONE = 0,	/*!< Database running normally */
	SRV_SHUTDOWN_CLEANUP,	/*!< Cleaning up in
				logs_empty_and_mark_files_at_shutdown() */
	SRV_SHUTDOWN_FLUSH_PHASE,/*!< At this phase the master and the
				purge threads must have completed their
				work. Once we enter this phase the
				page_cleaner can clean up the buffer
				pool and exit */
	SRV_SHUTDOWN_LAST_PHASE,/*!< Last phase after ensuring that
				the buffer pool can be freed: flush
				all file spaces and close all files */
	SRV_SHUTDOWN_EXIT_THREADS/*!< Exit all threads */
};
```

启停Innobase的函数声明:

``` c++
/* Starts Innobase and creates a new database if database files
are not found and the user wants.
@return DB_SUCCESS or error code */
dberr_t
innobase_start_or_create_for_mysql(void);

/* Shuts down the Innobase database.
@return DB_SUCCESS or error code */
dberr_t
innobase_shutdown_for_mysql(void);
```

## srv0conc.cc
<span id="srv0conc.cc" />

跟踪活跃和等待线程的结构:

``` c++
/** Variables tracking the active and waiting threads. */
struct srv_conc_t {
	char		pad[64  - (sizeof(ulint) + sizeof(lint))];

	/** Number of transactions that have declared_to_be_inside_innodb set.
	It used to be a non-error for this value to drop below zero temporarily.
	This is no longer true. We'll, however, keep the lint datatype to add
	assertions to catch any corner cases that we may have missed. */

	volatile lint	n_active;

	/** Number of OS threads waiting in the FIFO for permission to
	enter InnoDB */
	volatile lint	n_waiting;
};

/* Control variables for tracking concurrency. */
static srv_conc_t	srv_conc;
```

`srv_conc_xxx`的实现.

## srv0mon.cc
<span id="srv0mon.cc" />

## srv0srv.cc
<span id="srv0srv.cc" />

`srv_ccc`: 参数定义等.

`srv_xxx`服务器操作函数实现.

线程函数实现: `srv_monitor_thread`, `srv_master_thread`, `srv_error_monitor_thread`, `srv_purge_coordinator_thread`, `srv_worker_thread`.

服务器系统的结构定义:

``` c++
/** The server system struct */
struct srv_sys_t{
	ib_mutex_t	tasks_mutex;		/*!< variable protecting the
						tasks queue */
	UT_LIST_BASE_NODE_T(que_thr_t)
			tasks;			/*!< task queue */

	ib_mutex_t	mutex;			/*!< variable protecting the
						fields below. */
	ulint		n_sys_threads;		/*!< size of the sys_threads
						array */

	srv_slot_t*	sys_threads;		/*!< server thread table */

	ulint		n_threads_active[SRV_MASTER + 1];
						/*!< number of threads active
						in a thread class */

	srv_stats_t::ulint_ctr_1_t
			activity_count;		/*!< For tracking server
						activity */
};
```

## srv0start.cc
<span id="srv0start.cc" />

头文件中声明的函数实现.

跟踪背景线程创建的标记:

``` c++
/** Bit flags for tracking background thread creation. They are used to
determine which threads need to be stopped if we need to abort during
the initialisation step. */
enum srv_start_state_t {
	SRV_START_STATE_NONE = 0,		/*!< No thread started */
	SRV_START_STATE_LOCK_SYS = 1,		/*!< Started lock-timeout
						thread. */
	SRV_START_STATE_IO = 2,			/*!< Started IO threads */
	SRV_START_STATE_MONITOR = 4,		/*!< Started montior thread */
	SRV_START_STATE_MASTER = 8,		/*!< Started master threadd. */
	SRV_START_STATE_PURGE = 16,		/*!< Started purge thread(s) */
	SRV_START_STATE_STAT = 32		/*!< Started bufdump + dict stat
						and FTS optimize thread. */
};
```

被handler调用:

```
ha_innodb.cc/innobase_init
innobase_start_or_create_for_mysql

ha_innodb.cc/innobase_end
innobase_shutdown_for_mysql
```
