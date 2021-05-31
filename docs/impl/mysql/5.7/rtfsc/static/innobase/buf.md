# buf: 缓冲池的实现

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [buf0block_hint.h](#buf0block_hint.h)  |    56 |||
| [buf0buddy.h](#buf0buddy.h)            |    76 |||
| [buf0buddy.ic](#buf0buddy.ic)          |   120 |||
| [buf0buf.h](#buf0buf.h)                |  2441 |||
| [buf0buf.ic](#buf0buf.ic)              |  1361 |||
| [buf0checksum.h](#buf0checksum.h)      |    67 | 缓冲池校验和函数 ||
| [buf0dblwr.h](#buf0dblwr.h)            |   144 | 双写缓冲模块 ||
| [buf0dump.h](#buf0dump.h)              |    51 | 缓冲池dump/load ||
| [buf0flu.h](#buf0flu.h)                |   419 |||
| [buf0flu.ic](#buf0flu.ic)              |   133 | 数据库缓冲池刷出算法 ||
| [buf0lru.h](#buf0lru.h)                |   279 | 数据库缓冲池LRU替换算法 ||
| [buf0lru.ic](#buf0lru.ic)              |     7 |||
| [buf0rea.h](#buf0rea.h)                |   141 | 数据库缓冲的读 ||
| [buf0types.h](#buf0types.h)            |   133 | 数据库缓冲池的全局类型 ||
| [buf0block_hint.cc](#buf0block_hint.cc)  |    64 |||
| [buf0buddy.cc](#buf0buddy.cc)            |   862 |||
| [buf0buf.cc](#buf0buf.cc)                |  6968 |||
| [buf0checksum.cc](#buf0checksum.cc)      |   141 |||
| [buf0dblwr.cc](#buf0dblwr.cc)            |  1271 |||
| [buf0dump.cc](#buf0dump.cc)              |   794 |||
| [buf0flu.cc](#buf0flu.cc)                |  3823 |||
| [buf0lru.cc](#buf0lru.cc)                |  2768 |||
| [buf0rea.cc](#buf0rea.cc)                |   907 |||


## buf0block_hint.h
<span id="buf0block_hint.h" />

``` c++
namespace buf {
class Block_hint {
  // ...
private:
 /** The block pointer stored by store(). */
 buf_block_t *m_block;
 /** If m_block is non-null, the m_block->page.id at time it was stored. */
 page_id_t m_page_id;
 // ...
};
}  // namespace buf
```

## buf0buddy.h
<span id="buf0buddy.h" />

## buf0buddy.ic
<span id="buf0buddy.ic" />

## buf0buf.h
<span id="buf0buf.h" />

访问数据库页的函数:

``` c++
/** This is the general function used to get access to a database page.
@param[in]	page_id		page id
@param[in]	rw_latch	RW_S_LATCH, RW_X_LATCH, RW_NO_LATCH
@param[in]	guess		guessed block or NULL
@param[in]	mode		BUF_GET, BUF_GET_IF_IN_POOL,
BUF_PEEK_IF_IN_POOL, BUF_GET_NO_LATCH, or BUF_GET_IF_IN_POOL_OR_WATCH
@param[in]	file		file name
@param[in]	line		line where called
@param[in]	mtr		mini-transaction
@param[in]	dirty_with_no_latch
				mark page as dirty even if page
				is being pinned without any latch
@return pointer to the block or NULL */
buf_block_t*
buf_page_get_gen(
	const page_id_t&	page_id,
	const page_size_t&	page_size,
	ulint			rw_latch,
	buf_block_t*		guess,
	ulint			mode,
	const char*		file,
	ulint			line,
	mtr_t*			mtr,
	bool			dirty_with_no_latch = false);

/** @name Modes for buf_page_get_gen */
/* @{ */
#define BUF_GET			10	/*!< get always */
#define	BUF_GET_IF_IN_POOL	11	/*!< get if in pool */
#define BUF_PEEK_IF_IN_POOL	12	/*!< get if in pool, do not make
					the block young in the LRU list */
#define BUF_GET_NO_LATCH	14	/*!< get and bufferfix, but
					set no latch; we have
					separated this case, because
					it is error-prone programming
					not to set a latch, and it
					should be used with care */
#define BUF_GET_IF_IN_POOL_OR_WATCH	15
					/*!< Get the page only if it's in the
					buffer pool, if not then set a watch
					on the page. */
#define BUF_GET_POSSIBLY_FREED		16
					/*!< Like BUF_GET, but do not mind
					if the file page has been freed. */
/* @} */
/** @name Modes for buf_page_get_known_nowait */
/* @{ */
#define BUF_MAKE_YOUNG	51		/*!< Move the block to the
					start of the LRU list if there
					is a danger that the block
					would drift out of the buffer
					pool*/
#define BUF_KEEP_OLD	52		/*!< Preserve the current LRU
					position of the block. */
/* @} */
```

TODO buf0buf.h

## buf0buf.ic
<span id="buf0buf.ic" />

## buf0checksum.h
<span id="buf0checksum.h" />

## buf0dblwr.h
<span id="buf0dblwr.h" />

## buf0dump.h
<span id="buf0dump.h" />

## buf0flu.h
<span id="buf0flu.h" />

## buf0flu.ic
<span id="buf0flu.ic" />

## buf0lru.h
<span id="buf0lru.h" />

## buf0lru.ic
<span id="buf0lru.ic" />

## buf0rea.h
<span id="buf0rea.h" />

## buf0types.h
<span id="buf0types.h" />

缓冲页, 缓冲块, 缓冲帧:

``` c++
/** Buffer page (uncompressed or compressed) */
class buf_page_t;
/** Buffer block for which an uncompressed page exists */
struct buf_block_t;
/** Buffer pool chunk comprising buf_block_t */
struct buf_chunk_t;
/** Buffer pool comprising buf_chunk_t */
struct buf_pool_t;

/** Buffer pool statistics struct */
struct buf_pool_stat_t;
/** Buffer pool buddy statistics struct */
struct buf_buddy_stat_t;

/** Doublewrite memory struct */
struct buf_dblwr_t;

/** Flush observer for bulk create index */
class FlushObserver;

/** A buffer frame. @see page_t */
typedef	byte	buf_frame_t;
```

`enum buf_flush_t`: 刷出类型标记.

`enum buf_remove_t`: 从缓冲池中移除表空间中页的算法.

`buf_io_fix`: io_fix类型标记.

`enum srv_checksum_algorithm_t`: 校验和算法类型.

互斥量和锁:

``` c++
#include "ut0mutex.h"
#include "sync0rw.h"

typedef ib_bpmutex_t BPageMutex;
typedef ib_mutex_t BufPoolMutex;
typedef ib_mutex_t FlushListMutex;
typedef BPageMutex BufPoolZipMutex;
typedef rw_lock_t BPageLock;
```

## buf0block_hint.cc
<span id="buf0block_hint.cc" />

`class Block_hint`的部分方法实现.

## buf0buddy.cc
<span id="buf0buddy.cc" />

## buf0buf.cc
<span id="buf0buf.cc" />

## buf0checksum.cc
<span id="buf0checksum.cc" />

## buf0dblwr.cc
<span id="buf0dblwr.cc" />

## buf0dump.cc
<span id="buf0dump.cc" />

## buf0flu.cc
<span id="buf0flu.cc" />

## buf0lru.cc
<span id="buf0lru.cc" />

## buf0rea.cc
<span id="buf0rea.cc" />
