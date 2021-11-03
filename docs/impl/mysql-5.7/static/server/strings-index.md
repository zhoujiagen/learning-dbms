# `strings`

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [bchange.c](#bchangec)                  |    47 | short replacement routine written by Monty Widenius in 1987. ||
| [conf_to_src.c](#conf_to_srcc)          |   396 | reading a configuration file. ||
| [ctype-big5.c](#ctype-big5c)            |  6963 |-||
| [ctype-bin.c](#ctype-binc)              |   603 |-||
| [ctype-cp932.c](#ctype-cp932c)          | 34890 |-||
| [ctype-czech.c](#ctype-czechc)          |   624 |-||
| [ctype-euc_kr.c](#ctype-euc_krc)        | 10096 |-||
| [ctype-eucjpms.c](#ctype-eucjpmsc)      | 67630 |-||
| [ctype-extra.c](#ctype-extrac)          |  8785 |-||
| [ctype-gb18030.c](#ctype-gb18030c)      | 22584 |-||
| [ctype-gb2312.c](#ctype-gb2312c)        |  6498 |-||
| [ctype-gbk.c](#ctype-gbkc)              | 10896 |-||
| [ctype-latin1.c](#ctype-latin1c)        |   791 |-||
| [ctype-mb.c](#ctype-mbc)                |  1514 |-||
| [ctype-simple.c](#ctype-simplec)        |  1956 |-||
| [ctype-sjis.c](#ctype-sjisc)            | 34259 |-||
| [ctype-tis620.c](#ctype-tis620c)        |  1002 |-||
| [ctype-uca.c](#ctype-ucac)              | 26490 |-||
| [ctype-ucs2.c](#ctype-ucs2c)            |  3542 |-||
| [ctype-ujis.c](#ctype-ujisc)            | 67374 |-||
| [ctype-utf8.c](#ctype-utf8c)            |  8710 |-||
| [ctype-win1250ch.c](#ctype-win1250chc)  |   727 |-||
| [ctype.c](#ctypec)                      |  1116 | string handling programs for each char type MySQL handles. ||
| [decimal.c](#decimalc)                  |  2626 | for decimal and numeric conversions. ||
| [do_ctype.c](#do_ctypec)                |   168 | display case-conversion and sort-conversion tables. ||
| [dtoa.c](#dtoac)                        |  2785 |||
| [dump_map.c](#dump_mapc)                |    96 |-||
| [int2str.c](#int2strc)                  |   167 | integer-to-string. ||
| [is_prefix.c](#is_prefixc)              |    45 | checks whether string1 starts with string2. ||
| [latin2.def](#latin2def)                |   478 |||
| [llstr.c](#llstrc)                      |    53 | convert long long to temporary-buffer string, return pointer. ||
| [longlong2str.c](#longlong2strc)        |   156 | `llstr.c`, but to argument-buffer. ||
| [my_stpmov.c](#my_stpmovc)              |    42 |||
| [my_stpnmov.c](#my_stpnmovc)            |    45 |||
| [my_strchr.c](#my_strchrc)              |   123 |||
| [my_strtoll10.c](#my_strtoll10c)        |   248 | longlong2str for radix 10 ||
| [my_vsnprintf.c](#my_vsnprintfc)        |   695 | variant of printf. ||
| [str2int.c](#str2intc)                  |   192 | convert string to integer. ||
| [str_alloc.c](#str_allocc)              |    52 |||
| [strappend.c](#strappendc)              |    52 | fill up a string to n characters. ||
| [strcend.c](#strcendc)                  |    48 | point to where a character C occurs within str, or NULL. ||
| [strcont.c](#strcontc)                  |    57 | point to where any one of a set of characters appears. ||
| [strend.c](#strendc)                    |    37 | point to the `'\0'` byte which terminates str. ||
| [strfill.c](#strfillc)                  |    47 | fill a string with n copies of a byte. ||
| [strmake.c](#strmakec)                  |    67 | create new string from old string with fixed length, append end `\0` if needed. ||
| [strnlen.c](#strnlenc)                  |    42 | return min(length of string, n). ||
| [strxmov.c](#strxmovc)                  |    51 | move a series of concatenated source strings to dest. ||
| [strxnmov.c](#strxnmovc)                |    64 | like `strxmov.c` but with a maximum length n. ||
| [t_ctype.h](#t_ctypeh)                  |   245 |||
| [uca-dump.c](#uca-dumpc)                |   748 | shows unicode collation algorithm dump. ||
| [uctypedump.c](#uctypedumpc)            |   557 |||
| [utr11-dump.c](#utr11-dumpc)            |   135 | dump east Asian wide text file. ||
| [xml.c](#xmlc)                          |   586 | read and parse XML strings; used to read character definition information stored in `sql/share/charsets`. ||

## bchange.c
## conf_to_src.c
## ctype-big5.c
## ctype-bin.c
## ctype-cp932.c
## ctype-czech.c
## ctype-euc_kr.c
## ctype-eucjpms.c
## ctype-extra.c
## ctype-gb18030.c
## ctype-gb2312.c
## ctype-gbk.c
## ctype-latin1.c
## ctype-mb.c
## ctype-simple.c
## ctype-sjis.c
## ctype-tis620.c
## ctype-uca.c
## ctype-ucs2.c
## ctype-ujis.c
## ctype-utf8.c
## ctype-win1250ch.c
## ctype.c
## decimal.c
## do_ctype.c
## dtoa.c
## dump_map.c
## int2str.c
## is_prefix.c
## latin2.def
## llstr.c
## longlong2str.c
## my_stpmov.c
## my_stpnmov.c
## my_strchr.c
## my_strtoll10.c
## my_vsnprintf.c
## str2int.c
## str_alloc.c
## strappend.c
## strcend.c
## strcont.c
## strend.c
## strfill.c
## strmake.c
## strnlen.c
## strxmov.c
## strxnmov.c
## t_ctype.h
## uca-dump.c
## uctypedump.c
## utr11-dump.c
## xml.c
