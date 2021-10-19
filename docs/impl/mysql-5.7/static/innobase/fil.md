## fil: 文件数据结构和文件操作
<span id="fil 文件数据结构和文件操作" />

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [fil0fil.h](#fil0fil.h)                |  1658 | 低层文件系统 ||
| [fil0fil.cc](#fil0fil.cc)  |  7591 | 表空间内存缓存 ||

## fil0fil.h
<span id="fil0fil.h" />

### data structures

#### `enum fil_type_t` 文件类型

``` c++
enum fil_type_t {
	FIL_TYPE_TEMPORARY,    // 临时表空间
	FIL_TYPE_IMPORT,       // 导入的表空间
	FIL_TYPE_TABLESPACE,   // 持久化的表空间: 系统, undo日志或表
	FIL_TYPE_LOG           // redo日志: 涵盖了修改FIL_TYPE_TABLESPACE中文件
};
```

#### `struct fil_space_t` 表空间或日志数据空间

``` c++
struct fil_space_t {
	char*		name;
	ulint		id;
	lsn_t		max_lsn;
	bool		stop_ios;
	bool		stop_new_ops;
	bool		is_being_truncated;
	ulint		redo_skipped_count;               // UNIV_DEBUG
	fil_type_t	purpose;
	UT_LIST_BASE_NODE_T(fil_node_t) chain;
	ulint		size;
	ulint		size_in_header;
	ulint		free_len;
	ulint		free_limit;
	ulint		flags;
	ulint		n_reserved_extents;
	ulint		n_pending_flushes;
	ulint		n_pending_ops;
	hash_node_t	hash;
	hash_node_t	name_hash;
	rw_lock_t	latch;
	UT_LIST_NODE_T(fil_space_t) unflushed_spaces;
	UT_LIST_NODE_T(fil_space_t) named_spaces;
	bool		is_in_unflushed_spaces;
	UT_LIST_NODE_T(fil_space_t) space_list;

	Compression::Type	compression_type;
	Encryption::Type	encryption_type;
	byte			encryption_key[ENCRYPTION_KEY_LEN];
	ulint			encryption_klen;
	byte			encryption_iv[ENCRYPTION_KEY_LEN];

	void release_free_extents(ulint n_reserved);

	ulint		magic_n;
};
```

#### `struct fil_node_t`: 表空间或日志数据空间中文件节点.

``` c++
struct fil_node_t {
	fil_space_t*	space;
	char*		name;
	bool		is_open;
	pfs_os_file_t	handle;
	os_event_t	sync_event;
	bool		is_raw_disk;
	ulint		size;

	ulint		flush_size;

	ulint		init_size;
	ulint		max_size;
	ulint		n_pending;
	ulint		n_pending_flushes;
	bool		being_extended;
	int64_t		modification_counter;
	int64_t		flush_counter;
	UT_LIST_NODE_T(fil_node_t) chain;
	UT_LIST_NODE_T(fil_node_t) LRU;

	bool		punch_hole;

	ulint           block_size;

	bool		atomic_write;

	ulint		magic_n;                        // #define	FIL_NODE_MAGIC_N	89389
};
```

#### `enum ib_extention` 文件扩展名

``` c++
enum ib_extention {
	NO_EXT = 0,
	IBD = 1,           // ibd
	ISL = 2,           // isl
	CFG = 3,           // cfg
	CFP = 4            // cfp
};
```

#### `class Folder` 目录路径或后缀为.ibd的文件路径

``` c++
class Folder
{
public:
	Folder() : m_folder(NULL) {}
	Folder(const char* path, size_t len);
	class Folder& operator=(const char* path);

	~Folder() { ut_free(m_folder); }

	operator const char*() const {		return(m_folder);	}
	const char* operator()() const { return(m_folder); }
	size_t len() { return m_folder_len; }

	bool operator==(const Folder& other) const;
	bool operator>=(const Folder& other) const;
	bool operator>(const Folder& other) const;
	bool exists();

private:

	void	make_path(const char* path, size_t len);
	void	make_abs_path();
	char*	m_folder;
	size_t	m_folder_len;
	char	m_abs_path[FN_REFLEN + 2];
	size_t	m_abs_len;
};
```

#### `fil_faddr_t`

``` c++
typedef	byte	fil_faddr_t;
```

#### `struct fil_addr_t` 文件空间地址

``` c++
struct fil_addr_t {
	ulint	page;		/*!< page number within a space */
	ulint	boffset;	/*!< byte offset within the page */
};
```


`class FilSpace`: `fil_space_t`的引用计数封装.

`enum fil_load_status`: FIL_LOAD_OK, FIL_LOAD_ID_CHANGED, FIL_LOAD_NOT_FOUND, FIL_LOAD_INVALID.

`struct PageCallback`: 回调函子.

### values

``` c++
extern const char general_space_name[];
typedef std::list<char*, ut_allocator<char*> >	space_name_list_t;

#define	FIL_SPACE_MAGIC_N	89472
#define	FIL_NODE_MAGIC_N	89389

extern const char*	fil_path_to_mysql_datadir;
extern Folder   	folder_mysql_datadir;

#define FIL_IBD_FILE_INITIAL_SIZE	4
#define	FIL_NULL	ULINT32_UNDEFINED

#define FIL_ADDR_PAGE	0	/* first in address is the page offset */
#define	FIL_ADDR_BYTE	4	/* then comes 2-byte byte offset within page*/
#endif /* !UNIV_INNOCHECKSUM */
#define	FIL_ADDR_SIZE	6	/* address size is 6 bytes */

extern fil_addr_t	fil_addr_null;


// 文件页中偏移量
#define FIL_PAGE_SPACE_OR_CHKSUM 0
#define FIL_PAGE_OFFSET		4
#define FIL_PAGE_PREV		8
#define FIL_PAGE_NEXT		12
#define FIL_PAGE_LSN		16
#define	FIL_PAGE_TYPE		24
#define FIL_PAGE_FILE_FLUSH_LSN	26

static const ulint FIL_PAGE_VERSION = FIL_PAGE_FILE_FLUSH_LSN;
static const ulint FIL_PAGE_ALGORITHM_V1 = FIL_PAGE_VERSION + 1;
static const ulint FIL_PAGE_ORIGINAL_TYPE_V1 = FIL_PAGE_ALGORITHM_V1 + 1;
static const ulint FIL_PAGE_ORIGINAL_SIZE_V1 = FIL_PAGE_ORIGINAL_TYPE_V1 + 2;
static const ulint FIL_PAGE_COMPRESS_SIZE_V1 = FIL_PAGE_ORIGINAL_SIZE_V1 + 2;

#define	FIL_RTREE_SPLIT_SEQ_NUM	FIL_PAGE_FILE_FLUSH_LSN
#define FIL_PAGE_ARCH_LOG_NO_OR_SPACE_ID  34
#define FIL_PAGE_SPACE_ID  FIL_PAGE_ARCH_LOG_NO_OR_SPACE_ID
#define FIL_PAGE_DATA		38U

// 文件页尾部
#define FIL_PAGE_END_LSN_OLD_CHKSUM 8
#define FIL_PAGE_DATA_END	8


文件页类型:

#define FIL_PAGE_INDEX		17855
#define FIL_PAGE_RTREE		17854
#define FIL_PAGE_UNDO_LOG	2
#define FIL_PAGE_INODE		3
#define FIL_PAGE_IBUF_FREE_LIST	4

#define FIL_PAGE_TYPE_ALLOCATED	0
#define FIL_PAGE_IBUF_BITMAP	5
#define FIL_PAGE_TYPE_SYS	6
#define FIL_PAGE_TYPE_TRX_SYS	7
#define FIL_PAGE_TYPE_FSP_HDR	8
#define FIL_PAGE_TYPE_XDES	9
#define FIL_PAGE_TYPE_BLOB	10
#define FIL_PAGE_TYPE_ZBLOB	11
#define FIL_PAGE_TYPE_ZBLOB2	12
#define FIL_PAGE_TYPE_UNKNOWN	13
#define FIL_PAGE_COMPRESSED	14
#define FIL_PAGE_ENCRYPTED	15
#define FIL_PAGE_COMPRESSED_AND_ENCRYPTED 16

#define FIL_PAGE_ENCRYPTED_RTREE 17

#define FIL_PAGE_TYPE_LAST	FIL_PAGE_TYPE_UNKNOWN
```

### operations

``` c++
#define fil_page_type_is_index(page_type)                          \
        (page_type == FIL_PAGE_INDEX || page_type == FIL_PAGE_RTREE)

#define fil_page_index_page_check(page)                         \
        fil_page_type_is_index(fil_page_get_type(page))

```

## fil0fil.cc
<span id="fil0fil.cc" />

`struct fil_system_t`: 表空间内存缓存, 同时也存储日志数据空间中日志.

`enum fil_operation_t`: 表空间文件操作, 删除FIL_OPERATION_DELETE, 关闭FIL_OPERATION_CLOSE, 截断FIL_OPERATION_TRUNCATE.

`struct	Check`: 校验表空间中文件节点列表的函子.

`struct fil_iterator_t`: 表空间中页的迭代器.
