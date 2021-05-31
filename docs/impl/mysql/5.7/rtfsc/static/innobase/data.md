# data: 数据字段和元组

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [data0data.h](#data0data.h)            |   678 |||
| [data0data.ic](#data0data.ic)          |   805 |||
| [data0type.h](#data0type.h)            |   569 |||
| [data0type.ic](#data0type.ic)          |   666 |||
| [data0types.h](#data0types.h)          |    18 |||
| [data0data.cc](#data0data.cc)  |   833 |||
| [data0type.cc](#data0type.cc)  |   285 |||


## data0data.h
<span id="data0data.h" />

SQL数据字段结构定义:

``` c++
/** Structure for an SQL data field */
struct dfield_t{
	void*		data;	/*!< pointer to data */
	unsigned	ext:1;	/*!< TRUE=externally stored, FALSE=local */
	unsigned	spatial_status:2;
				/*!< spatial status of externally stored field
				in undo log for purge */
	unsigned	len;	/*!< data length; UNIV_SQL_NULL if SQL null */
	dtype_t		type;	/*!< type of data */

	/** Create a deep copy of this object
	@param[in]	heap	the memory heap in which the clone will be
				created.
	@return	the cloned object. */
	dfield_t* clone(mem_heap_t* heap);
};
```

SQL数据元组结构定义:

``` c++
/** Structure for an SQL data tuple of fields (logical record) */
struct dtuple_t {
	ulint		info_bits;	/*!< info bits of an index record:
					the default is 0; this field is used
					if an index record is built from
					a data tuple */
	ulint		n_fields;	/*!< number of fields in dtuple */
	ulint		n_fields_cmp;	/*!< number of fields which should
					be used in comparison services
					of rem0cmp.*; the index search
					is performed by comparing only these
					fields, others are ignored; the
					default value in dtuple creation is
					the same value as n_fields */
	dfield_t*	fields;		/*!< fields */
	ulint		n_v_fields;	/*!< number of virtual fields */
	dfield_t*	v_fields;	/*!< fields on virtual column */
	UT_LIST_NODE_T(dtuple_t) tuple_list;
					/*!< data tuples can be linked into a
					list using this field */
#ifdef UNIV_DEBUG
	mem_heap_t	*m_heap;	/*!< memory heap where this tuple is
					allocated. */
	ulint		magic_n;	/*!< magic number, used in
					debug assertions */
/** Value of dtuple_t::magic_n */
# define		DATA_TUPLE_MAGIC_N	65478679
#endif /* UNIV_DEBUG */


	/** Get number of externally stored fields.
	@retval number of externally stored fields. */
	inline ulint get_n_ext() const
	{
		ulint n_ext = 0;
		for (ulint i = 0; i < n_fields; ++i) {
			if (dfield_is_ext(&fields[i])) {
				n_ext++;
			}
		}
		return (n_ext);
	}
};
```

大记录向量中字段槽:

``` c++
/** A slot for a field in a big rec vector */
struct big_rec_field_t {

	/** Constructor.
	@param[in]	field_no_	the field number
	@param[in]	len_		the data length
	@param[in]	data_		the data */
	big_rec_field_t(ulint field_no_, ulint len_, const void* data_)
		: field_no(field_no_),
		  len(len_),
		  data(data_)
	{}

	ulint		field_no;	/*!< field number in record */
	ulint		len;		/*!< stored data length, in bytes */
	const void*	data;		/*!< stored data */
};
```

大记录中溢出数据的存储格式:

``` c++
/** Storage format for overflow data in a big record, that is, a
clustered index record which needs external storage of data fields */
struct big_rec_t {
	mem_heap_t*	heap;		/*!< memory heap from which
					allocated */
	const ulint	capacity;	/*!< fields array size */
	ulint		n_fields;	/*!< number of stored fields */
	big_rec_field_t*fields;		/*!< stored fields */

	/** Constructor.
	@param[in]	max	the capacity of the array of fields. */
	explicit big_rec_t(const ulint max)
		: heap(0),
		  capacity(max),
		  n_fields(0),
		  fields(0)
	{}

	/** Append one big_rec_field_t object to the end of array of fields */
	void append(const big_rec_field_t& field)
	{
		ut_ad(n_fields < capacity);
		fields[n_fields] = field;
		n_fields++;
	}

	/** Allocate a big_rec_t object in the given memory heap, and for
	storing n_fld number of fields.
	@param[in]	heap	memory heap in which this object is allocated
	@param[in]	n_fld	maximum number of fields that can be stored in
			this object
	@return the allocated object */
	static big_rec_t* alloc(
		mem_heap_t*	heap,
		ulint		n_fld);
};
```

`dfield_xxx`: `struct dfield_t`的操作函数声明.

`dtuple_xxx`: `struct dtuple_t`的操作函数声明.

## data0data.ic
<span id="data0data.ic" />

部分`dfield_xxx`的实现.
部分`dtuple_xxx`的实现.

## data0type.h
<span id="data0type.h" />

SQL数据类型的结构:

``` c++
/* Structure for an SQL data type.
If you add fields to this structure, be sure to initialize them everywhere.
This structure is initialized in the following functions:
dtype_set()
dtype_read_for_order_and_null_size()
dtype_new_read_for_order_and_null_size()
sym_tab_add_null_lit() */

struct dtype_t{
	unsigned	prtype:32;	/*!< precise type; MySQL data
					type, charset code, flags to
					indicate nullability,
					signedness, whether this is a
					binary string, whether this is
					a true VARCHAR where MySQL
					uses 2 bytes to store the length */
	unsigned	mtype:8;	/*!< main data type */

	/* the remaining fields do not affect alphabetical ordering: */

	unsigned	len:16;		/*!< length; for MySQL data this
					is field->pack_length(),
					except that for a >= 5.0.3
					type true VARCHAR this is the
					maximum byte length of the
					string data (in addition to
					the string, MySQL uses 1 or 2
					bytes to store the string length) */
#ifndef UNIV_HOTBACKUP
	unsigned	mbminmaxlen:5;	/*!< minimum and maximum length of a
					character, in bytes;
					DATA_MBMINMAXLEN(mbminlen,mbmaxlen);
					mbminlen=DATA_MBMINLEN(mbminmaxlen);
					mbmaxlen=DATA_MBMINLEN(mbminmaxlen) */
#endif /* !UNIV_HOTBACKUP */
};
```

SQL `LIKE`操作符比较类型:

``` c++
/** SQL Like operator comparison types */
enum ib_like_t {
	IB_LIKE_EXACT,	/**< e.g.  STRING */
	IB_LIKE_PREFIX	/**< e.g., STRING% */
};
```

列的MAIN TYPE:

``` c++
/* The 'MAIN TYPE' of a column */
#define DATA_MISSING	0	/* missing column */
#define	DATA_VARCHAR	1	/* character varying of the
				latin1_swedish_ci charset-collation; note
				that the MySQL format for this, DATA_BINARY,
				DATA_VARMYSQL, is also affected by whether the
				'precise type' contains
				DATA_MYSQL_TRUE_VARCHAR */
#define DATA_CHAR	2	/* fixed length character of the
				latin1_swedish_ci charset-collation */
#define DATA_FIXBINARY	3	/* binary string of fixed length */
#define DATA_BINARY	4	/* binary string */
#define DATA_BLOB	5	/* binary large object, or a TEXT type;
				if prtype & DATA_BINARY_TYPE == 0, then this is
				actually a TEXT column (or a BLOB created
				with < 4.0.14; since column prefix indexes
				came only in 4.0.14, the missing flag in BLOBs
				created before that does not cause any harm) */
#define	DATA_INT	6	/* integer: can be any size 1 - 8 bytes */
#define	DATA_SYS_CHILD	7	/* address of the child page in node pointer */
#define	DATA_SYS	8	/* system column */

/* Data types >= DATA_FLOAT must be compared using the whole field, not as
binary strings */

#define DATA_FLOAT	9
#define DATA_DOUBLE	10
#define DATA_DECIMAL	11	/* decimal number stored as an ASCII string */
#define	DATA_VARMYSQL	12	/* any charset varying length char */
#define	DATA_MYSQL	13	/* any charset fixed length char */
				/* NOTE that 4.1.1 used DATA_MYSQL and
				DATA_VARMYSQL for all character sets, and the
				charset-collation for tables created with it
				can also be latin1_swedish_ci */

/* DATA_POINT&DATA_VAR_POINT are for standard geometry datatype 'point' and
DATA_GEOMETRY include all other standard geometry datatypes as described in
OGC standard(line_string, polygon, multi_point, multi_polygon,
multi_line_string, geometry_collection, geometry).
Currently, geometry data is stored in the standard Well-Known Binary(WKB)
format (http://www.opengeospatial.org/standards/sfa).
We use BLOB as underlying datatype for DATA_GEOMETRY and DATA_VAR_POINT
while CHAR for DATA_POINT */
#define DATA_GEOMETRY	14	/* geometry datatype of variable length */
/* The following two are disabled temporarily, we won't create them in
get_innobase_type_from_mysql_type().
TODO: We will enable DATA_POINT/them when we come to the fixed-length POINT
again. */
#define DATA_POINT	15	/* geometry datatype of fixed length POINT */
#define DATA_VAR_POINT	16	/* geometry datatype of variable length
				POINT, used when we want to store POINT
				as BLOB internally */
#define DATA_MTYPE_MAX	63	/* dtype_store_for_order_and_null_size()
				requires the values are <= 63 */

#define DATA_MTYPE_CURRENT_MIN	DATA_VARCHAR	/* minimum value of mtype */
#define DATA_MTYPE_CURRENT_MAX	DATA_VAR_POINT	/* maximum value of mtype */
```

列的PRECISE TYPE:

``` c++
#define DATA_ENGLISH	4	/* English language character string: this
				is a relic from pre-MySQL time and only used
				for InnoDB's own system tables */
#define DATA_ERROR	111	/* another relic from pre-MySQL time */

#define DATA_MYSQL_TYPE_MASK 255 /* AND with this mask to extract the MySQL
				 type from the precise type */
#define DATA_MYSQL_TRUE_VARCHAR 15 /* MySQL type code for the >= 5.0.3
				   format true VARCHAR */

/* Precise data types for system columns and the length of those columns;
NOTE: the values must run from 0 up in the order given! All codes must
be less than 256 */
#define	DATA_ROW_ID	0	/* row id: a 48-bit integer */
#define DATA_ROW_ID_LEN	6	/* stored length for row id */

#define DATA_TRX_ID	1	/* transaction id: 6 bytes */
#define DATA_TRX_ID_LEN	6

#define	DATA_ROLL_PTR	2	/* rollback data pointer: 7 bytes */
#define DATA_ROLL_PTR_LEN 7

#define	DATA_N_SYS_COLS 3	/* number of system columns defined above */

#define	DATA_ITT_N_SYS_COLS	2
				/* number of system columns for intrinsic
				temporary table */

#define DATA_FTS_DOC_ID	3	/* Used as FTS DOC ID column */

#define DATA_SYS_PRTYPE_MASK 0xF /* mask to extract the above from prtype */

/* Flags ORed to the precise data type */
#define DATA_NOT_NULL	256	/* this is ORed to the precise type when
				the column is declared as NOT NULL */
#define DATA_UNSIGNED	512	/* this id ORed to the precise type when
				we have an unsigned integer type */
#define	DATA_BINARY_TYPE 1024	/* if the data type is a binary character
				string, this is ORed to the precise type:
				this only holds for tables created with
				>= MySQL-4.0.14 */
/* #define	DATA_NONLATIN1	2048 This is a relic from < 4.1.2 and < 5.0.1.
				In earlier versions this was set for some
				BLOB columns.
*/
#define DATA_GIS_MBR	2048	/* Used as GIS MBR column */
#define DATA_MBR_LEN	SPDIMS * 2 * sizeof(double) /* GIS MBR length*/

#define	DATA_LONG_TRUE_VARCHAR 4096	/* this is ORed to the precise data
				type when the column is true VARCHAR where
				MySQL uses 2 bytes to store the data len;
				for shorter VARCHARs MySQL uses only 1 byte */
#define	DATA_VIRTUAL	8192	/* Virtual column */
```

`dtype_xxx`: `struct dtype_t`的操作函数.

## data0type.ic
<span id="data0type.ic" />

部分`dtype_xxx`的实现.

## data0types.h
<span id="data0types.h" />

SQL数据字段结构声明: `struct dfield_t`.

SQL数据元组结构声明: `struct dtuple_t`.

## data0data.cc
<span id="data0data.cc" />

部分`dfield_xxx`的实现.
部分`dtuple_xxx`的实现.

## data0type.cc
<span id="data0type.cc" />

部分`dtype_xxx`的实现.
