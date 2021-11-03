# `storage/innobase`

|L1|Description|Progress|
|:---|:---|:--|
|[include](include.md)    |include目录                         ||
|[ut](ut.md)              |工具类                              ||
|[os](os.md)              |操作系统相关操作的封装: <br/>event<br/>file<br/>process<br/> thread|<br/><br/>DONE<br/><br/>|
|[ha](ha.md)              |哈希算法实现                         ||
|[api](api.md)            |本地API实现                         ||
|[srv](srv.md)            |服务器主程序                     |DONE|
|[handler](handler.md)    |插件式存储引擎的实现                  ||
|[usr](usr.md)            |用户会话实现                         ||
||||
|[fil](fil.md)            |文件数据结构和文件操作             |DONE|
|[fut](fut.md)            |File-based Utilities: 文件工具   |DONE|
|[fsp](fsp.md)            |File Space物理文件管理: 区、页、段等|DONE|
|[page](page.md)          |页的实现                            ||
|[rem](rem.md)            |记录管理器实现                       ||
|[mach](mach.md)          |机器数据格式工具                  |DONE|
|[data](data.md)          |数据字段和元组                   |DONE|
|[row](row.md)            |行操作的实现                         ||
|[btr](btr.md)            |B+树的实现                          ||
|[dict](dict.md)          |数据字典的实现                       ||
|[fts](fts.md)            |Full Text实现                       ||
|[gis](gis.md)            |R树实现                             ||
||||
|[mem](mem.md)            |内存管理                        |DONE|
|[buf](buf.md)            |缓冲池的实现                         ||
|[ibuf](ibuf.md)          |插入缓冲的实现                       ||
|[log](log.md)            |日志缓冲和日志文件的实现               ||
||||
|[pars](pars.md)          |SQL解析器                           ||
|[que](que.md)            |查询图实现                           ||
|[eval](eval.md)          |SQL求值器                           ||
|[read](read.md)          |游标读实现                           ||
||||
|[sync](sync.md)          |基础同步原语Mutex的实现               ||
|[lock](lock.md)          |锁的实现                            ||
|[mtr](mtr.md)            |Mini事务实现                        ||
|[trx](trx.md)            |事务的实现                           ||
