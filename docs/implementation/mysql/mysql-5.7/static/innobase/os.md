# os: 操作系统相关操作的封装, event, file, process, thread

> PFS: Performance Schema
> PSI: Performance schema instrumentation

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [os0atomic.h](#os0atomic.h)            |   352 | 原子性操作的宏 ||
| [os0atomic.ic](#os0atomic.ic)          |   206 | 操作系统同步原语接口 ||
| [os0event.h](#os0event.h)              |   125 | 操作系统条件变量的接口 ||
| [os0file.h](#os0file.h)                |  2153 | 操作系统文件IO的接口 ||
| [os0file.ic](#os0file.ic)              |   591 |||
| [os0once.h](#os0once.h)                |   105 | 在多线程环境中精确执行给定函数一次的类 ||
| [os0proc.h](#os0proc.h)                |    56 | 操作系统进程控制原语的接口 ||
| [os0proc.ic](#os0proc.ic)              |     9 |||
| [os0thread.h](#os0thread.h)            |   180 | 操作系统进程和线程控制原语的接口 ||
| [os0thread.ic](#os0thread.ic)          |     7 |||
| [os0event.cc](#os0event.cc)    |   645 |||
| [os0file.cc](#os0file.cc)      |  9388 |||
| [os0proc.cc](#os0proc.cc)      |   190 |||
| [os0thread.cc](#os0thread.cc)  |   318 |||


## os0atomic.h
<span id="os0atomic.h" />

原子性操作的字:

``` c++
typedef ulint	lock_word_t;
```

原子性操作:

``` c++
#define os_atomic_inc_ulint(m,v,d)	os_atomic_increment_ulint(v, d)
#define os_atomic_dec_ulint(m,v,d)	os_atomic_decrement_ulint(v, d)
#define TAS(l, n)			os_atomic_test_and_set((l), (n))
#define CAS(l, o, n)		os_atomic_val_compare_and_swap((l), (o), (n))
```

Memory Barrier:

``` c++
#elif defined HAVE_IB_GCC_ATOMIC_THREAD_FENCE
# define HAVE_MEMORY_BARRIER
# define os_rmb	__atomic_thread_fence(__ATOMIC_ACQUIRE)
# define os_wmb	__atomic_thread_fence(__ATOMIC_RELEASE)
# define IB_MEMORY_BARRIER_STARTUP_MSG \
	"GCC builtin __atomic_thread_fence() is used for memory barrier"

#elif defined(HAVE_IB_GCC_SYNC_SYNCHRONISE)
# define HAVE_MEMORY_BARRIER
# define os_rmb	__sync_synchronize()
# define os_wmb	__sync_synchronize()
# define IB_MEMORY_BARRIER_STARTUP_MSG \
	"GCC builtin __sync_synchronize() is used for memory barrier"
```

## os0atomic.ic
<span id="os0atomic.ic" />

``` c++
/** Do an atomic test and set.
@param[in,out]	ptr	Memory location to set
@param[in]	new_val	new value
@return	old value of memory location. */
lock_word_t
os_atomic_test_and_set(
	volatile lock_word_t*	ptr,
	lock_word_t		new_val)

/** Do an atomic compare and set
@param[in,out]	ptr	Memory location to set
@param[in]	old_val	old value to compare
@param[in]	new_val	new value to set
@return the value of ptr before the operation. */
UNIV_INLINE
lock_word_t
os_atomic_val_compare_and_swap(
	volatile lock_word_t*	ptr,
	lock_word_t		old_val,
	lock_word_t		new_val)
```

## os0event.h
<span id="os0event.h" />

## os0file.h
<span id="os0file.h" />

文件句柄和目录:

``` c++
// DIR: dirent.h
typedef DIR*	os_file_dir_t;	/*!< directory stream */

/** File handle */
typedef int	os_file_t;
```

文件中字节偏移量:

``` c++
typedef unsigned long long uint64_t;
typedef uint64_t ib_uint64_t; // univ.i

/** File offset in bytes */
typedef ib_uint64_t os_offset_t;
```


压缩算法:

``` c++
/** Compression algorithm. */
struct Compression {

	/** Algorithm types supported */
	enum Type {
		/* Note: During recovery we don't have the compression type
		because the .frm file has not been read yet. Therefore
		we write the recovered pages out without compression. */

		/** No compression */
		NONE = 0,

		/** Use ZLib */
		ZLIB = 1,

		/** Use LZ4 faster variant, usually lower compression. */
		LZ4 = 2
	};

	/** Compressed page meta-data */
	struct meta_t {

		/** Version number */
		uint8_t		m_version;

		/** Algorithm type */
		Type		m_algorithm;

		/** Original page type */
		uint16_t	m_original_type;

		/** Original page size, before compression */
		uint16_t	m_original_size;

		/** Size after compression */
		uint16_t	m_compressed_size;
	};

	/** Version of compressed page */
	static const uint8_t FIL_PAGE_VERSION_1 = 1;
	static const uint8_t FIL_PAGE_VERSION_2 = 2;

	...

	/** Compression type */
	Type		m_type;
};
```

加密算法:

``` c++
/** Encryption algorithm. */
struct Encryption {

	/** Algorithm types supported */
	enum Type {

		/** No encryption */
		NONE = 0,

		/** Use AES */
		AES = 1,
	};

	/** Encryption information format version */
	enum Version {

		/** Version in 5.7.11 */
		ENCRYPTION_VERSION_1 = 0,

		/** Version in > 5.7.11 */
		ENCRYPTION_VERSION_2 = 1,
	};

  ...

	/** Encrypt type */
	Type			m_type;

	/** Encrypt key */
	byte*			m_key;

	/** Encrypt key length*/
	ulint			m_klen;

	/** Encrypt initial vector */
	byte*			m_iv;

	/** Current master key id */
	static ulint		master_key_id;

	/** Current uuid of server instance */
	static char		uuid[ENCRYPTION_SERVER_UUID_LEN + 1];
};
```

AIO操作请求:

``` c++
/** No transformations during read/write, write as is. */
#define IORequestRead		IORequest(IORequest::READ)
#define IORequestWrite		IORequest(IORequest::WRITE)
#define IORequestLogRead	IORequest(IORequest::LOG | IORequest::READ)
#define IORequestLogWrite	IORequest(IORequest::LOG | IORequest::WRITE)

/**
The IO Context that is passed down to the low level IO code */
class IORequest {
public:
	/** Flags passed in the request, they can be ORred together. */
	enum {
		READ = 1,
		WRITE = 2,

		/** Double write buffer recovery. */
		DBLWR_RECOVER = 4,

		/** Enumarations below can be ORed to READ/WRITE above*/

		/** Data file */
		DATA_FILE = 8,

		/** Log file request*/
		LOG = 16,

		/** Disable partial read warnings */
		DISABLE_PARTIAL_IO_WARNINGS = 32,

		/** Do not to wake i/o-handler threads, but the caller will do
		the waking explicitly later, in this way the caller can post
		several requests in a batch; NOTE that the batch must not be
		so big that it exhausts the slots in AIO arrays! NOTE that
		a simulated batch may introduce hidden chances of deadlocks,
		because I/Os are not actually handled until all
		have been posted: use with great caution! */
		DO_NOT_WAKE = 64,

		/** Ignore failed reads of non-existent pages */
		IGNORE_MISSING = 128,

		/** Use punch hole if available, only makes sense if
		compression algorithm != NONE. Ignored if not set */
		PUNCH_HOLE = 256,

		/** Force raw read, do not try to compress/decompress.
		This can be used to force a read and write without any
		compression e.g., for redo log, merge sort temporary files
		and the truncate redo log. */
		NO_COMPRESSION = 512
	};

	...

private:
	/* File system best block size */
	uint32_t		m_block_size;

	/** Request type bit flags */
	uint16_t		m_type;

	/** Compression algorithm */
	Compression		m_compression;

	/** Encryption algorithm */
	Encryption		m_encryption;
};
```

文件操作函数声明:

``` c++
os_file_xxx
os_aio_xxx
pfs_os_file_xxx
pfs_os_aio_func
```

## os0file.ic
<span id="os0file.ic" />

`pfs_os_file_xxx`, `pfs_os_aio_func`函数实现.

## os0once.h
<span id="os0once.h" />

## os0proc.h
<span id="os0proc.h" />

## os0proc.ic
<span id="os0proc.ic" />

## os0thread.h
<span id="os0thread.h" />

## os0thread.ic
<span id="os0thread.ic" />

## os0event.cc
<span id="os0event.cc" />

## os0file.cc
<span id="os0file.cc" />

I/O操作的块:

``` c++
/** Blocks for doing IO, used in the transparent compression
and encryption code. */
struct Block {
	/** Default constructor */
	Block() : m_ptr(), m_in_use() { }

	byte*		m_ptr;

	byte		pad[CACHE_LINE_SIZE - sizeof(ulint)];
	lock_word_t	m_in_use;
};
```

AIO上下文:

``` c++
/** The asynchronous I/O context */
struct Slot {
	Slot() { memset(this, 0, sizeof(*this)); }

	/** index of the slot in the aio array */
	uint16_t		pos;

	/** true if this slot is reserved */
	bool			is_reserved;

	/** time when reserved */
	ib_time_monotonic_t	reservation_time;

	/** buffer used in i/o */
	byte*			buf;

	/** Buffer pointer used for actual IO. We advance this
	when partial IO is required and not buf */
	byte*			ptr;

	/** OS_FILE_READ or OS_FILE_WRITE */
	IORequest		type;

	/** file offset in bytes */
	os_offset_t		offset;

	/** file where to read or write */
	pfs_os_file_t		file;

	/** file name or path */
	const char*		name;

	/** used only in simulated aio: true if the physical i/o
	already made and only the slot message needs to be passed
	to the caller of os_aio_simulated_handle */
	bool			io_already_done;

	/** The file node for which the IO is requested. */
	fil_node_t*		m1;

	/** the requester of an aio operation and which can be used
	to identify which pending aio operation was completed */
	void*			m2;

	/** AIO completion status */
	dberr_t			err;

#ifdef WIN_ASYNC_IO
	// ...
#elif defined(LINUX_NATIVE_AIO)
	/** Linux control block for aio */
	struct iocb		control;

	/** AIO return code */
	int			ret;

	/** bytes written/read. */
	ssize_t			n_bytes;

	/** length of the block to read or write */
	ulint			len;
#else
	// ...
#endif /* WIN_ASYNC_IO */

	/** Length of the block before it was compressed */
	uint32			original_len;

	/** Buffer block for compressed pages or encrypted pages */
	Block*			buf_block;

	/** true, if we shouldn't punch a hole after writing the page */
	bool			skip_punch_hole;
};
```

AIO:

``` c++
/** The asynchronous i/o array structure */
class AIO {
  ...

private:
	typedef std::vector<Slot> Slots;

	/** the mutex protecting the aio array */
	mutable SysMutex	m_mutex;

	/** Pointer to the slots in the array.
	Number of elements must be divisible by n_threads. */
	Slots			m_slots;

	/** Number of segments in the aio array of pending aio requests.
	A thread can wait separately for any one of the segments. */
	ulint			m_n_segments;

	/** The event which is set to the signaled state when
	there is space in the aio outside the ibuf segment */
	os_event_t		m_not_full;

	/** The event which is set to the signaled state when
	there are no pending i/os in this array */
	os_event_t		m_is_empty;

	/** Number of reserved slots in the AIO array outside
	the ibuf segment */
	ulint			m_n_reserved;

#if defined(LINUX_NATIVE_AIO)
	typedef std::vector<io_event> IOEvents;

	/** completion queue for IO. There is one such queue per
	segment. Each thread will work on one ctx exclusively. */
	io_context_t*		m_aio_ctx;

	/** The array to collect completed IOs. There is one such
	event for each possible pending IO. The size of the array
	is equal to m_slots.size(). */
	IOEvents		m_events;
#endif /* LINUX_NATIV_AIO */

	/** The aio arrays for non-ibuf i/o and ibuf i/o, as well as
	sync AIO. These are NULL when the module has not yet been
	initialized. */

	/** Insert buffer */
	static AIO*		s_ibuf;

	/** Redo log */
	static AIO*		s_log;

	/** Reads */
	static AIO*		s_reads;

	/** Writes */
	static AIO*		s_writes;

	/** Synchronous I/O */
	static AIO*		s_sync;
}


/** Generic AIO Handler methods. Currently handles IO post processing. */
class AIOHandler { /* ... */ }


#if defined(LINUX_NATIVE_AIO)
/** Linux native AIO handler */
class LinuxAIOHandler { /* ... */ }
#endif /* LINUX_NATIVE_AIO */


/** Simulated AIO handler for reaping IO requests */
class SimulatedAIOHandler { /* ... */ }
```

同步文件的I/O:

``` c++
/** Helper class for doing synchronous file IO. Currently, the objective
is to hide the OS specific code, so that the higher level functions aren't
peppered with #ifdef. Makes the code flow difficult to follow.  */
class SyncFileIO { /* ... */ }
```

`os_file_xxx`, `os_aio_xxx`函数实现.

## os0proc.cc
<span id="os0proc.cc" />

## os0thread.cc
<span id="os0thread.cc" />
