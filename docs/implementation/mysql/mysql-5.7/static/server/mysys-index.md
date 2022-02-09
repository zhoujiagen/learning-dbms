# `mysys`

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [array.c](#arrayc)                          |   293 | Dynamic array handling. ||
| [base64.c](#base64c)                        |   476 | base64 encoding. ||
| [charset-def.c](#charset-defc)              |   421 | Include character sets in the client. ||
| [charset.c](#charsetc)                      |   980 | Using dynamic character sets, set default character set, ... ||
| [checksum.c](#checksumc)                    |    47 | Calculate checksum for a memory block, used for pack_isam. ||
| [errors.c](#errorsc)                        |   104 | English text of global errors. ||
| [hash.c](#hashc)                            |   824 | Hash search/compare/free functions "for saving keys". ||
| [kqueue_timers.c](#kqueue_timersc)          |   257 |  ||
| [lf_alloc-pin.c](#lf_alloc-pinc)            |   482 | wait-free concurrent allocator based on pinning addresses. ||
| [lf_dynarray.c](#lf_dynarrayc)              |   220 | wait-free dynamic array. ||
| [lf_hash.c](#lf_hashc)                      |   736 | extensible hash. ||
| [list.c](#listc)                            |   126 | Double-linked lists. ||
| [mf_arr_appstr.c](#mf_arr_appstrc)          |    74 | Append str to array, or move to the end if it already exists. ||
| [mf_cache.c](#mf_cachec)                    |   117 | Open a temporary file and cache it with io_cache. ||
| [mf_dirname.c](#mf_dirnamec)                |   167 | Parse/convert directory names. ||
| [mf_fn_ext.c](#mf_fn_extc)                  |    66 | Get filename extension. ||
| [mf_format.c](#mf_formatc)                  |   159 | Format a filename. ||
| [mf_getdate.c](#mf_getdatec)                |   100 | Get date, return in yyyy-mm-dd hh:mm:ss format. ||
| [mf_iocache.c](#mf_iocachec)                |  1745 | Cached read/write of files in fixed-size units. ||
| [mf_iocache2.c](#mf_iocache2c)              |   528 | Continuation of mf_iocache.c. ||
| [mf_keycache.c](#mf_keycachec)              |  4063 | Key block caching for certain file types. ||
| [mf_keycaches.c](#mf_keycachesc)            |   375 | Handling of multiple key caches. ||
| [mf_loadpath.c](#mf_loadpathc)              |    84 | Return full path name (no ..\ stuff). ||
| [mf_pack.c](#mf_packc)                      |   421 | Packing/unpacking directory names for create purposes. ||
| [mf_path.c](#mf_pathc)                      |   133 | Determine where a program can find its files. ||
| [mf_qsort.c](#mf_qsortc)                    |   217 | Quicksort. ||
| [mf_qsort2.c](#mf_qsort2c)                  |    32 | Quicksort, part 2 (allows the passing of an extra argument to the sort-compare routine). ||
| [mf_radix.c](#mf_radixc)                    |    71 | Radix sort. ||
| [mf_same.c](#mf_samec)                      |    53 | Determine whether filenames are the same. ||
| [mf_soundex.c](#mf_soundexc)                |   117 | Soundex algorithm derived from EDN Nov. 14, 1985 (pg. 36). ||
| [mf_tempfile.c](#mf_tempfilec)              |   152 | Create a temporary file. ||
| [mf_unixpath.c](#mf_unixpathc)              |    48 | Convert filename to UNIX-style filename. ||
| [mf_wcomp.c](#mf_wcompc)                    |   101 | Comparisons with wildcards. ||
| [mulalloc.c](#mulallocc)                    |    76 | Malloc many pointers at the same time. ||
| [my_access.c](#my_accessc)                  |   280 | Check if file or path is accessible. ||
| [my_alloc.c](#my_allocc)                    |   569 | malloc of results which will be freed simultaneously. ||
| [my_bit.c](#my_bitc)                        |    76 | smallest X where 2^X ≥ value, maybe useful for divisions. ||
| [my_bitmap.c](#my_bitmapc)                  |   684 | Handle uchar arrays as large bitmaps. ||
| [my_chmod.c](#my_chmodc)                    |   114 | Change permission on a file. ||
| [my_chsize.c](#my_chsizec)                  |   118 | Truncate file if shorter, else fill with a filler character. ||
| [my_compare.c](#my_comparec)                |   486 | Compare two keys, ... ||
| [my_compress.c](#my_compressc)              |   279 | Compress packet (see also description of `zlib` directory). ||
| [my_conio.c](#my_conioc)                    |   309 | - ||
| [my_copy.c](#my_copyc)                      |   165 | Copy files. ||
| [my_crc32.c](#my_crc32c)                    |    30 | Include `zlib\crc32.c`. ||
| [my_create.c](#my_createc)                  |    86 | Create file. ||
| [my_delete.c](#my_deletec)                  |   145 | Delete file. ||
| [my_div.c](#my_divc)                        |    50 | Get file's name. ||
| [my_error.c](#my_errorc)                    |   489 | Return formatted error to user. ||
| [my_file.c](#my_filec)                      |   156 | See how many open files we want. ||
| [my_fopen.c](#my_fopenc)                    |   391 | File open. ||
| [my_fstream.c](#my_fstreamc)                |   198 | Streaming file read/write. ||
| [my_gethwaddr.c](#my_gethwaddrc)            |   271 | Get hardware address for an interface. ||
| [my_getsystime.c](#my_getsystimec)          |   168 | Time-of-day functions, portably. ||
| [my_getwd.c](#my_getwdc)                    |   174 | Get working directory. ||
| [my_handler_errors.h](#my_handler_errorsh)  |   101 | - ||
| [my_init.c](#my_initc)                      |   579 | Initialize variables and functions in the mysys library. ||
| [my_largepage.c](#my_largepagec)            |   170 | Gets the size of large pages from the OS. ||
| [my_lib.c](#my_libc)                        |   390 | Compare/convert directory names and file names. ||
| [my_lock.c](#my_lockc)                      |   233 | Lock part of a file. ||
| [my_malloc.c](#my_mallocc)                  |   337 | Malloc (memory allocate) and dup functions. ||
| [my_memmem.c](#my_memmemc)                  |    96 | - ||
| [my_mess.c](#my_messc)                      |    77 | Print an error message . ||
| [my_mkdir.c](#my_mkdirc)                    |    60 | Make directory. ||
| [my_mmap.c](#my_mmapc)                      |   101 | Memory mapping. ||
| [my_once.c](#my_oncec)                      |   132 | Allocation / duplication for "things we don't need to free". ||
| [my_open.c](#my_openc)                      |   206 | Open a file. ||
| [my_pread.c](#my_preadc)                    |   219 | Read a specified number of bytes from a file. ||
| [my_rdtsc.c](#my_rdtscc)                    |   914 | determine elapsed times. ||
| [my_read.c](#my_readc)                      |   119 | Read a specified number of bytes from a file, possibly retry. ||
| [my_redel.c](#my_redelc)                    |   144 | Rename and delete file. ||
| [my_rename.c](#my_renamec)                  |    71 | Rename without delete. ||
| [my_seek.c](#my_seekc)                      |   123 | Seek, that is, point to a spot within a file. ||
| [my_static.c](#my_staticc)                  |   155 | Static variables used by the mysys library. ||
| [my_static.h](#my_statich)                  |    27 | - ||
| [my_symlink.c](#my_symlinkc)                |   220 | Read a symbolic link. ||
| [my_symlink2.c](#my_symlink2c)              |   207 | Part 2 of `my_symlink.c`. ||
| [my_sync.c](#my_syncc)                      |   207 | Sync data in file to disk. ||
| [my_syslog.c](#my_syslogc)                  |   299 | Send message to system logger. ||
| [my_thr_init.c](#my_thr_initc)              |   471 | initialize/allocate "all mysys & debug thread variables". ||
| [my_thread.c](#my_threadc)                  |   197 | Thread utility. ||
| [my_windac.c](#my_windacc)                  |   248 | - ||
| [my_winerr.c](#my_winerrc)                  |   137 | - ||
| [my_winfile.c](#my_winfilec)                |   690 | - ||
| [my_write.c](#my_writec)                    |   141 | Write a specified number of bytes to a file. ||
| [mysys_priv.h](#mysys_privh)                |   116 | - ||
| [posix_timers.c](#posix_timersc)            |   407 | POSIX timer. ||
| [psi_noop.c](#psi_noopc)                    |  1068 | noop performance interface. ||
| [ptr_cmp.c](#ptr_cmpc)                      |    67 | Point to an optimal byte-comparison function. ||
| [queues.c](#queuesc)                        |   710 | Handle priority queues as in Robert Sedgewick's book. ||
| [sql_chars.c](#sql_charsc)                  |   132 | Char classes for lexical scanners. ||
| [stacktrace.c](#stacktracec)                |   814 | Stack trace. ||
| [string.c](#stringc)                        |   199 | Initialize/append/free dynamically-sized strings; see also `sql/sql_string.cc`. ||
| [test_charset.c](#test_charsetc)            |    88 | Standalone program: display character set information. ||
| [test_dir.c](#test_dirc)                    |    56 | Standalone program: placeholder for "test all functions" idea. ||
| [test_xml.c](#test_xmlc)                    |   112 | Standalone program: test XML routines. ||
| [testhash.c](#testhashc)                    |   297 | Standalone program: test the hash library routines. ||
| [thr_cond.c](#thr_condc)                    |   125 | Thread conditial variables. ||
| [thr_lock.c](#thr_lockc)                    |  1534 | Read and write locks for Posix threads. ||
| [thr_mutex.c](#thr_mutexc)                  |   207 | A wrapper for mutex functions. ||
| [thr_rwlock.c](#thr_rwlockc)                |   151 | Synchronizes the readers' thread locks with the writer's lock. ||
| [tree.c](#treec)                            |   772 | Initialize/search/free binary trees. ||
| [typelib.c](#typelibc)                      |   400 | Find a string in a set of strings; returns the offset to the string found. ||
| [win_timers.c](#win_timersc)                |   371 | - ||

## array.c
## base64.c
## charset-def.c
## charset.c
## checksum.c
## errors.c
## hash.c
## kqueue_timers.c
## lf_alloc-pin.c
## lf_dynarray.c
## lf_hash.c
## list.c
## mf_arr_appstr.c
## mf_cache.c
## mf_dirname.c
## mf_fn_ext.c
## mf_format.c
## mf_getdate.c
## mf_iocache.c
## mf_iocache2.c
## mf_keycache.c
## mf_keycaches.c
## mf_loadpath.c
## mf_pack.c
## mf_path.c
## mf_qsort.c
## mf_qsort2.c
## mf_radix.c
## mf_same.c
## mf_soundex.c
## mf_tempfile.c
## mf_unixpath.c
## mf_wcomp.c
## mulalloc.c
## my_access.c
## my_alloc.c
## my_bit.c
## my_bitmap.c
## my_chmod.c
## my_chsize.c
## my_compare.c
## my_compress.c
## my_conio.c
## my_copy.c
## my_crc32.c
## my_create.c
## my_delete.c
## my_div.c
## my_error.c
## my_file.c
## my_fopen.c
## my_fstream.c
## my_gethwaddr.c
## my_getsystime.c
## my_getwd.c
## my_handler_errors.h
## my_init.c
## my_largepage.c
## my_lib.c
## my_lock.c
## my_malloc.c
## my_memmem.c
## my_mess.c
## my_mkdir.c
## my_mmap.c
## my_once.c
## my_open.c
## my_pread.c
## my_rdtsc.c
## my_read.c
## my_redel.c
## my_rename.c
## my_seek.c
## my_static.c
## my_static.h
## my_symlink.c
## my_symlink2.c
## my_sync.c
## my_syslog.c
## my_thr_init.c
## my_thread.c
## my_windac.c
## my_winerr.c
## my_winfile.c
## my_write.c
## mysys_priv.h
## posix_timers.c
## psi_noop.c
## ptr_cmp.c
## queues.c
## sql_chars.c
## stacktrace.c
## string.c
## test_charset.c
## test_dir.c
## test_xml.c
## testhash.c
## thr_cond.c
## thr_lock.c
## thr_mutex.c
## thr_rwlock.c
## tree.c
## typelib.c
## win_timers.c
