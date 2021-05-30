# MySQL .frm File Format

> v5.7

- References: https://dev.mysql.com/doc/internals/en/frm-file-format.html

## Structure

> uchar fileinfo[64],forminfo[288]

File Header:

|Offset|Size(byte)|Description|
|:---|:---|:---|
|0|1|Always 254|
|1|1|Always 1|
|2|1|FRM_VER+3+ MY_TEST(create_info->varchar)|
|3|1|legacy_db_type: DB_TYPE_INNODB etc|
|4|1|Always 1|
|5|1|00|
|6|2|IO_SIZE: 4096|
|8|2|Next block starts here|
|10|4|IO_SIZE+key_length+reclength+create_info->extra_size|
|14|2|tmp_key_length|
|16|2|reclength|
|18|4|create_info->max_rows|
|22|4|create_info->min_rows|
|26|1|is set in mysql_create_frm(): |
|27|1|Always 2: Use long pack-fields|
|28|2|is set to key_info_length in mysql_create_frm()|
|30|2|create_info->table_options|
|32|1|Always 0: No filename anymore|
|33|1|Always 5: Mark for 5.0 frm file|
|34|4|create_info->avg_row_length|
|38|1|csid: create_info->default_table_charset|
|39|1|Always 0|
|40|1|create_info->row_type|
|41|1|csid >> 8. Bytes 41-46 were for RAID support; now reused for other purposes|
|42|2|create_info->stats_sample_pages & 0xffff|
|44|1|create_info->stats_auto_recalc|
|45|1|Always 0|
|46|1|Always 0|
|47|4|key_length|
|51|4|MYSQL_VERSION_ID|
|55|4|create_info->extra_size|
|59|2|59-60 is reserved for extra_rec_buf_length|
|61|1|61 for default_part_db_type|
|62|2|create_info->key_block_size|
|64|||



## Example


``` sql
CREATE TABLE `t1` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'ID',
  `c1` varchar(45) COLLATE utf8mb4_bin NOT NULL COMMENT 'col 1',
  `c2` varchar(45) COLLATE utf8mb4_bin DEFAULT NULL COMMENT 'col 2',
  PRIMARY KEY (`id`),
  KEY `idx_c1` (`c1`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin COMMENT='table test';
```

```
# hexdump -C t1.frm
00000000  fe 01 0a 0c 03 00 00 10  01 00 00 30 00 00 c2 02  |...........0....|
00000010  6f 01 00 00 00 00 00 00  00 00 00 02 39 00 09 00  |o...........9...|
00000020  00 05 00 00 00 00 2e 00  00 00 00 00 00 00 00 c2  |................|
00000030  02 00 00 2c c6 00 00 20  00 00 00 00 00 00 00 00  |...,... ........|
00000040  2f 2f 00 00 20 00 00 00  00 00 00 00 00 00 00 00  |//.. ...........|
00000050  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00001000  02 02 00 00 11 00 00 00  04 00 01 00 00 00 01 80  |................| 4096
00001010  02 00 00 1b 00 04 00 01  00 b4 00 01 00 00 00 02  |................|
00001020  80 06 00 00 01 40 b4 00  ff 50 52 49 4d 41 52 59  |.....@...PRIMARY|
00001030  ff 69 64 78 5f 63 31 ff  00 00 00 00 00 00 00 00  |.idx_c1.........|
00001040  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
000012c0  00 00 ff 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
000012d0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00001430  00 00 00 06 00 49 6e 6e  6f 44 42 00 00 00 00 00  |.....InnoDB.....|
00001440  00 0c 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00001450  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00002000  ac 01 00 10 00 00 00 00  00 00 00 00 00 00 00 00  |................| 8192
00002010  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00002020  00 00 00 00 00 00 00 00  00 00 00 00 00 00 0a 74  |...............t|
00002030  61 62 6c 65 20 74 65 73  74 00 00 00 00 00 00 00  |able test.......|
00002040  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00002100  01 00 03 00 42 00 73 01  00 00 6f 01 0b 00 00 00  |....B.s...o.....|
00002110  00 00 00 00 00 00 50 00  16 00 01 00 0c 00 00 00  |......P.........|
00002120  42 00 04 03 02 14 29 20  20 20 20 20 20 20 20 20  |B.....)         | 00002120 +288
00002130  20 20 20 20 20 20 20 20  20 20 20 20 20 20 20 20  |                |
00002140  20 20 20 20 20 20 20 20  20 20 20 20 20 20 20 00  |               .|
00002150  04 00 03 69 64 00 05 00  03 63 31 00 06 00 03 63  |...id....c1....c|
00002160  32 00 04 03 0b 0b 00 02  00 00 1b 00 0f 00 00 03  |2...............| 00002162 +66
00002170  08 02 00 05 03 4c b4 00  06 00 00 01 40 00 00 00  |.....L......@...|
00002180  0f 2e 05 00 06 03 4c b4  00 bb 00 00 01 80 00 00  |......L.........|
00002190  00 0f 2e 05 00 ff 69 64  ff 63 31 ff 63 32 ff 00  |......id.c1.c2..| 00002195 +51(17*3)
000021a0  49 44 63 6f 6c 20 31 63  6f 6c 20 32              |IDcol 1col 2|
```


## Source Codes

- `sql/unireg.cc mysql_create_frm(...)`
- `sql/table.cc create_frm(...)`
