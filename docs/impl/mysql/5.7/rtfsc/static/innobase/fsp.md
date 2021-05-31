# fsp: File Space物理文件管理, 区、页、段等

> MySQL 5.7 Reference Manual <br/>
> 14.12.2 File Space Management<br/>
> MySQL Glossary - segment

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [fsp0file.h](#fsp0file.h)              |   576 | 表空间中数据文件控制信息 ||
| [fsp0fsp.h](#fsp0fsp.h)                |   742 | 文件空间管理 ||
| [fsp0fsp.ic](#fsp0fsp.ic)              |   306 | 处理UNIV_INNOCHECKSUM ||
| [fsp0space.h](#fsp0space.h)            |   220 | 通用共享表空间 ||
| [fsp0sysspace.h](#fsp0sysspace.h)      |   302 | 多文件的共享的系统表空间 ||
| [fsp0types.h](#fsp0types.h)            |   349 | 文件空间管理中类型 ||
| [fsp0file.cc](#fsp0file.cc)          |  1196 | 表空间数据文件实现 ||
| [fsp0fsp.cc](#fsp0fsp.cc)            |  4233 | 文件空间管理 ||
| [fsp0space.cc](#fsp0space.cc)        |   245 | 通用共享表空间实现 ||
| [fsp0sysspace.cc](#fsp0sysspace.cc)  |  1022 | 多文件的共享的系统表空间实现 ||

## fsp0file.h
<span id="fsp0file.h" />

`DataFile`: 数据文件控制信息.

`RemoteDataFile`: 链接数据文件控制信息.

## fsp0fsp.h
<span id="fsp0fsp.h" />

空间头 SPACE HEADER:

``` c++
/*			SPACE HEADER
			============

File space header data structure: this data structure is contained in the
first page of a space. The space for this header is reserved in every extent
descriptor page, but used only in the first. */

/*-------------------------------------*/
#define FSP_SPACE_ID		0	/* space id */
#define FSP_NOT_USED		4	/* this field contained a value up to
					which we know that the modifications
					in the database have been flushed to
					the file space; not used now */
#define	FSP_SIZE		8	/* Current size of the space in
					pages */
#define	FSP_FREE_LIMIT		12	/* Minimum page number for which the
					free list has not been initialized:
					the pages >= this limit are, by
					definition, free; note that in a
					single-table tablespace where size
					< 64 pages, this number is 64, i.e.,
					we have initialized the space
					about the first extent, but have not
					physically allocated those pages to the
					file */
#define	FSP_SPACE_FLAGS		16	/* fsp_space_t.flags, similar to
					dict_table_t::flags */
#define	FSP_FRAG_N_USED		20	/* number of used pages in the
					FSP_FREE_FRAG list */
#define	FSP_FREE		24	/* list of free extents */
#define	FSP_FREE_FRAG		(24 + FLST_BASE_NODE_SIZE)
					/* list of partially free extents not
					belonging to any segment */
#define	FSP_FULL_FRAG		(24 + 2 * FLST_BASE_NODE_SIZE)
					/* list of full extents not belonging
					to any segment */
#define FSP_SEG_ID		(24 + 3 * FLST_BASE_NODE_SIZE)
					/* 8 bytes which give the first unused
					segment id */
#define FSP_SEG_INODES_FULL	(32 + 3 * FLST_BASE_NODE_SIZE)
					/* list of pages containing segment
					headers, where all the segment inode
					slots are reserved */
#define FSP_SEG_INODES_FREE	(32 + 4 * FLST_BASE_NODE_SIZE)
					/* list of pages containing segment
					headers, where not all the segment
					header slots are reserved */
/*-------------------------------------*/
/* File space header size */
#define	FSP_HEADER_SIZE		(32 + 5 * FLST_BASE_NODE_SIZE)
```

文件段inode FILE SEGMENT INODE:

``` c++
/*			FILE SEGMENT INODE
			==================

Segment inode which is created for each segment in a tablespace. NOTE: in
purge we assume that a segment having only one currently used page can be
freed in a few steps, so that the freeing cannot fill the file buffer with
bufferfixed file pages. */

typedef	byte	fseg_inode_t;

#define FSEG_INODE_PAGE_NODE	FSEG_PAGE_DATA
					/* the list node for linking
					segment inode pages */

#define FSEG_ARR_OFFSET		(FSEG_PAGE_DATA + FLST_NODE_SIZE)
/*-------------------------------------*/
#define	FSEG_ID			0	/* 8 bytes of segment id: if this is 0,
					it means that the header is unused */
#define FSEG_NOT_FULL_N_USED	8
					/* number of used segment pages in
					the FSEG_NOT_FULL list */
#define	FSEG_FREE		12
					/* list of free extents of this
					segment */
#define	FSEG_NOT_FULL		(12 + FLST_BASE_NODE_SIZE)
					/* list of partially free extents */
#define	FSEG_FULL		(12 + 2 * FLST_BASE_NODE_SIZE)
					/* list of full extents */
#define	FSEG_MAGIC_N		(12 + 3 * FLST_BASE_NODE_SIZE)
					/* magic number used in debugging */
#define	FSEG_FRAG_ARR		(16 + 3 * FLST_BASE_NODE_SIZE)
					/* array of individual pages
					belonging to this segment in fsp
					fragment extent lists */
#define FSEG_FRAG_ARR_N_SLOTS	(FSP_EXTENT_SIZE / 2)
					/* number of slots in the array for
					the fragment pages */
#define	FSEG_FRAG_SLOT_SIZE	4	/* a fragment page slot contains its
					page number within space, FIL_NULL
					means that the slot is not in use */
/*-------------------------------------*/
#define FSEG_INODE_SIZE					\
	(16 + 3 * FLST_BASE_NODE_SIZE			\
	 + FSEG_FRAG_ARR_N_SLOTS * FSEG_FRAG_SLOT_SIZE)

#define FSP_SEG_INODES_PER_PAGE(page_size)		\
	((page_size.physical() - FSEG_ARR_OFFSET - 10) / FSEG_INODE_SIZE)
				/* Number of segment inodes which fit on a
				single page */

#define FSEG_MAGIC_N_VALUE	97937874

#define	FSEG_FILLFACTOR		8	/* If this value is x, then if
					the number of unused but reserved
					pages in a segment is less than
					reserved pages * 1/x, and there are
					at least FSEG_FRAG_LIMIT used pages,
					then we allow a new empty extent to
					be added to the segment in
					fseg_alloc_free_page. Otherwise, we
					use unused pages of the segment. */

#define FSEG_FRAG_LIMIT		FSEG_FRAG_ARR_N_SLOTS
					/* If the segment has >= this many
					used pages, it may be expanded by
					allocating extents to the segment;
					until that only individual fragment
					pages are allocated from the space */

#define	FSEG_FREE_LIST_LIMIT	40	/* If the reserved size of a segment
					is at least this many extents, we
					allow extents to be put to the free
					list of the extent: at most
					FSEG_FREE_LIST_MAX_LEN many */
#define	FSEG_FREE_LIST_MAX_LEN	4
/* @} */
```

区描述符 EXTENT DESCRIPTOR:

``` c++
/*			EXTENT DESCRIPTOR
			=================

File extent descriptor data structure: contains bits to tell which pages in
the extent are free and which contain old tuple version to clean. */

/*-------------------------------------*/
#define	XDES_ID			0	/* The identifier of the segment
					to which this extent belongs */
#define XDES_FLST_NODE		8	/* The list node data structure
					for the descriptors */
#define	XDES_STATE		(FLST_NODE_SIZE + 8)
					/* contains state information
					of the extent */
#define	XDES_BITMAP		(FLST_NODE_SIZE + 12)
					/* Descriptor bitmap of the pages
					in the extent */
/*-------------------------------------*/

#define	XDES_BITS_PER_PAGE	2	/* How many bits are there per page */
#define	XDES_FREE_BIT		0	/* Index of the bit which tells if
					the page is free */
#define	XDES_CLEAN_BIT		1	/* NOTE: currently not used!
					Index of the bit which tells if
					there are old versions of tuples
					on the page */
/* States of a descriptor */
#define	XDES_FREE		1	/* extent is in free list of space */
#define	XDES_FREE_FRAG		2	/* extent is in free fragment list of
					space */
#define	XDES_FULL_FRAG		3	/* extent is in full fragment list of
					space */
#define	XDES_FSEG		4	/* extent belongs to a segment */

/** File extent data structure size in bytes. */
#define	XDES_SIZE							\
	(XDES_BITMAP							\
	+ UT_BITS_IN_BYTES(FSP_EXTENT_SIZE * XDES_BITS_PER_PAGE))

/** File extent data structure size in bytes for MAX page size. */
#define	XDES_SIZE_MAX							\
	(XDES_BITMAP							\
	+ UT_BITS_IN_BYTES(FSP_EXTENT_SIZE_MAX * XDES_BITS_PER_PAGE))

/** File extent data structure size in bytes for MIN page size. */
#define	XDES_SIZE_MIN							\
	(XDES_BITMAP							\
	+ UT_BITS_IN_BYTES(FSP_EXTENT_SIZE_MIN * XDES_BITS_PER_PAGE))

/** Offset of the descriptor array on a descriptor page */
#define	XDES_ARR_OFFSET		(FSP_HEADER_OFFSET + FSP_HEADER_SIZE)
```

## fsp0fsp.ic
<span id="fsp0fsp.ic" />

处理UNIV_INNOCHECKSUM

## fsp0space.h
<span id="fsp0space.h" />

`class Tablespace` 系统表空间或临时表空间.


## fsp0sysspace.h
<span id="fsp0sysspace.h" />

`class SysTablespace`: 共享表空间, 当前可以是系统表空间或临时表空间.

## fsp0types.h
<span id="fsp0types.h" />

### data structures

#### `fseg_header_t` 文件段头

``` c++
typedef	byte	fseg_header_t;
```

#### `class fseg_header` 打印文件段头信息的封装类

``` c++
class fseg_header
{
public:
	fseg_header(
		const fseg_header_t*	header,
		mtr_t*			mtr)
		:
		m_header(header),
		m_mtr(mtr)
	{}

	std::ostream&
	to_stream(std::ostream&	out) const;
private:
	const fseg_header_t*	m_header;

	mtr_t*			m_mtr;
}
```

#### `enum fsp_reserve_t` 预留的空闲区标记

``` c++
enum fsp_reserve_t {
	FSP_NORMAL,
	FSP_UNDO,
	FSP_CLEANING,
	FSP_BLOB
};
```

### values

按序插入记录的标记:

``` c++
#define	FSP_UP		((byte)111)			// 字母升序
#define	FSP_DOWN	((byte)112)			// 字母降序
#define	FSP_NO_DIR	((byte)113)		// 无序
```

文件空间中区的大小:

``` c++
/** File space extent size in pages
page size | file space extent size
----------+-----------------------
   4 KiB  | 256 pages = 1 MiB
   8 KiB  | 128 pages = 1 MiB
  16 KiB  |  64 pages = 1 MiB
  32 KiB  |  64 pages = 2 MiB
  64 KiB  |  64 pages = 4 MiB
*/
#define FSP_EXTENT_SIZE         ((UNIV_PAGE_SIZE <= (16384) ?	\
				(1048576 / UNIV_PAGE_SIZE) :	\
				((UNIV_PAGE_SIZE <= (32768)) ?	\
				(2097152 / UNIV_PAGE_SIZE) :	\
				(4194304 / UNIV_PAGE_SIZE))))

#define	FSP_EXTENT_SIZE_MAX	(4194304 / UNIV_PAGE_SIZE_MAX)	// 4MB
#define	FSP_EXTENT_SIZE_MIN	(1048576 / UNIV_PAGE_SIZE_MIN)	// 1MB
#define FSEG_PAGE_DATA		FIL_PAGE_DATA	// 在文件段中页中放置数据的起始偏移量
// #define FIL_PAGE_DATA		38U	 				// fil0fil.h
```

文件段头:

``` c++
#define FSEG_HDR_SPACE		0		// inode的space id
#define FSEG_HDR_PAGE_NO	4		// inode的页号
#define FSEG_HDR_OFFSET		8		// inode的偏移量

#define FSEG_HEADER_SIZE	10	// 文件段头的字节长度
```

空间中位于低地址的页:

``` c++
// 单个描述符页描述的页数量
/* #define XDES_DESCRIBED_PER_PAGE		UNIV_PAGE_SIZE */

// FSP_XDES_OFFSET, FSP_IBUF_BITMAP_OFFSET在每个表空间中每XDES_DESCRIBED_PER_PAGE页重复
#define FSP_XDES_OFFSET			0							// 区描述符页偏移量
#define FSP_IBUF_BITMAP_OFFSET		1				// 插入缓冲位图页偏移量
#define FSP_FIRST_INODE_PAGE_NO		2				// 第一个inode页号(tablespace 0)
#define FSP_IBUF_HEADER_PAGE_NO		3				// 插入缓冲头页号(tablespace 0)
#define FSP_IBUF_TREE_ROOT_PAGE_NO	4			// 插入缓冲B树根页号(tablespace 0)
#define FSP_TRX_SYS_PAGE_NO		5						// 事务系统头页号(tablespace 0)
#define	FSP_FIRST_RSEG_PAGE_NO		6				// 第一个回滚段页号(tablespace 0)
#define FSP_DICT_HDR_PAGE_NO		7					// 数据字典头页号(tablespace 0)
```

表空间标记:

``` c++
#define FSP_FLAGS_WIDTH_POST_ANTELOPE	1		// POST_ANTELOPE标记的位数
#define FSP_FLAGS_WIDTH_ZIP_SSIZE	4				// 表空间压缩也大小的标记位数
#define FSP_FLAGS_WIDTH_ATOMIC_BLOBS	1		// ATOMIC_BLOBS的位数
#define FSP_FLAGS_WIDTH_PAGE_SSIZE	4			// 表空间页到校的标记位数
#define FSP_FLAGS_WIDTH_DATA_DIR	1				// DATA_DIR标记的位数: 表空间是否在默认数据目录中
#define FSP_FLAGS_WIDTH_SHARED		1				// SHARED标记的位数: 表空间是否用CREATE TABLESPACE创建从而被多个表共享
#define FSP_FLAGS_WIDTH_TEMPORARY	1				// TEMPORARY标记的位数: 表空间是否是临时表空间
#define FSP_FLAGS_WIDTH_ENCRYPTION	1			// 加密标记的位数
#define FSP_FLAGS_WIDTH		(FSP_FLAGS_WIDTH_POST_ANTELOPE	\
				+ FSP_FLAGS_WIDTH_ZIP_SSIZE	\
				+ FSP_FLAGS_WIDTH_ATOMIC_BLOBS	\
				+ FSP_FLAGS_WIDTH_PAGE_SSIZE	\
				+ FSP_FLAGS_WIDTH_DATA_DIR	\
				+ FSP_FLAGS_WIDTH_SHARED	\
				+ FSP_FLAGS_WIDTH_TEMPORARY	\
				+ FSP_FLAGS_WIDTH_ENCRYPTION)			// 已知标记的总位数

#define FSP_FLAGS_MASK		(~(~0 << FSP_FLAGS_WIDTH))	// 标记掩码
```


### operations

``` c++
// 校验表空间标记.
// 在表空间头页中偏移量FSP_SPACE_FLAGS处存储这些标记.
bool
fsp_flags_is_valid(
	ulint	flags)
	MY_ATTRIBUTE((warn_unused_result, const));

// 检查表空间是否是系统临时表空间.
bool
fsp_is_system_temporary(
	ulint	space_id);

// 检查表空间中是否关闭了校验和.
bool
fsp_is_checksum_disabled(
	ulint	space_id);

// 检查表空间是否是file-per-table表空间.
bool
fsp_is_file_per_table(
	ulint	space_id,
	ulint	fsp_flags);

// 在调试模式汇总跳过一些耗时的检查.
bool
fsp_skip_sanity_check(
	ulint	space_id);
```

## fsp0file.cc
<span id="fsp0file.cc" />

## fsp0fsp.cc
<span id="fsp0fsp.cc" />

操作的实现:

- `fsp_xxx`: 文件空间相关操作
- `fsp_header_xxx`: 文件空间头部相关操作
- `fseg_xxx`: 文件段相关操作
- `xdes_xxx`: 区描述符相关操作.

## fsp0space.cc
<span id="fsp0space.cc" />

`class Tablespace`的实现.

## fsp0sysspace.cc
<span id="fsp0sysspace.cc" />

`class SysTablespace`的实现.
