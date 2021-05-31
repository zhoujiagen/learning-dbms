# rem: 记录管理器实现

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [rem0cmp.h](#rem0cmp.h)                |   243 |||
| [rem0cmp.ic](#rem0cmp.ic)              |   124 |||
| [rem0rec.h](#rem0rec.h)                |  1080 |||
| [rem0rec.ic](#rem0rec.ic)              |  1747 |||
| [rem0types.h](#rem0types.h)            |    56 | 记录管理器的全局类型 ||
| [rem0cmp.cc](#rem0cmp.cc)  |  1259 |||
| [rem0rec.cc](#rem0rec.cc)  |  2309 |||

## rem0cmp.h
<span id="rem0cmp.h" />

## rem0cmp.ic
<span id="rem0cmp.ic" />

## rem0rec.h
<span id="rem0rec.h" />

## rem0rec.ic
<span id="rem0rec.ic" />

## rem0types.h
<span id="rem0types.h" />

物理记录为字节数组:

``` c++
/* We define the physical record simply as an array of bytes */
typedef byte	rec_t;
```

记录格式:

``` c++
/** Innodb row types are a subset of the MySQL global enum row_type.
They are made into their own enum so that switch statements can account
for each of them. */
enum rec_format_enum {
	REC_FORMAT_REDUNDANT	= 0,	/*!< REDUNDANT row format */
	REC_FORMAT_COMPACT	= 1,	/*!< COMPACT row format */
	REC_FORMAT_COMPRESSED	= 2,	/*!< COMPRESSED row format */
	REC_FORMAT_DYNAMIC	= 3	/*!< DYNAMIC row format */
};
typedef enum rec_format_enum rec_format_t;
```


## rem0cmp.cc
<span id="rem0cmp.cc" />

## rem0rec.cc
<span id="rem0rec.cc" />
