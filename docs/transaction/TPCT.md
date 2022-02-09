# Notes of **Transaction Processing: Concepts and Techniques**


|时间|内容|
|:---|:---|
|2019-03-17|在阅读Linux系统编程和架构的基础上重新阅读.|
|2019-04-14|re-read 文件组织: 文件和缓冲区管理, 面向元组的文件系统, 访问路径|
|2019-04-15|add ProtocolBuf message of file, page, etc in project rdfstrore-protocol.|
|2019-04-16|lesson learned: should distinguish disk and memory data structure|

## 术语

<!-- 记录阅读过程中出现的关键字及其简单的解释. -->

## 介绍

<!-- 描述书籍阐述观点的来源、拟解决的关键性问题和采用的方法论等. -->

## 动机

<!-- 描述阅读书籍的动机, 要达到什么目的等. -->

## 概念结构

<!-- 描述书籍的行文结构, 核心主题和子主题的内容结构和关系. -->

### 第一部分 事务处理基础
#### 1 概述
#### 2 计算机系统基本术语
### 第二部分 容错基础知识
#### 3 容错 (fault tolerance)

IFIP, IEEE: 容错计算

容错的硬件错误: n工


三种软件容错风格:

-  checkpoint-restart
- process pairs
- persistent processes


故障模型和软件故障屏蔽

三个实体: 进程, 消息和存储

- 高可用的存储
故障屏蔽程序: 失败表决双工(failvote)
- 高可用的进程
备用进程接管主进程: 检查点重启, 检查点消息, 持久进程
- 基于会话和进程对的可靠消息
会话, 设定超时, 消息序列号 将消息错误 => 丢失的消息 - failfast ack, send timeout, resend => 高可用性




### 第三部分 面向事务的计算
#### 4 事务模型 (transaction models)

#### 5 事务处理监控器：概述 (transaction processing monitors - an overview)

transactional RPC
transaction manager
resource manager
lock manager

事务处理系统进程结构概念: 图5-6.

事务处理监控器的信息流: 图5-8.

简单事务执行控制流例: 图5-9.

事务处理组件: 图5-10.


#### 6 事务处理监控器 (transaction processing monitors)

事务处理系统层次: 图6-1.

资源管理器接口概览: 图6-2.

C/S交互中实现状态关联的方式: 图6-5.

基于TRPC的TOPS核心数据结构: 图6-7, 6-8.

持久性队列的状态转换: 图6-14.


### 第四部分 并发控制
#### 7 隔离性的概念 (isolation concepts)

三种不正确的依赖:

(1) 丢失更新: T1 READ - T1 WRITE - T2 WRITE / T1 WRITE - T2 WRITE - T1 WRITE <br/>
(2) 脏读: T2 WRITE - T1 READ - T2 future WRITE <br/>
(3) 不可重复读: T1 READ - T2 WRITE - T2 READ

隔离性定理

隔离性级别

幻想和谓词锁

粒度锁: 意向锁, 更新型锁, 码区间锁, DAG封锁协议

封锁的启发式算法

嵌套事务封锁

调度与死锁


#### 8 锁的实现 (lock implementation)

原子机器指令

信号量: `get()`, `give()`, 只支持两种锁类型: 共享锁, 排它锁

锁管理程序(Lock Manager)

死锁检测

并行事务和并行嵌套事务封锁

```
typedef long PID;						// 进程ID
typedef struct Process {
	PID pid;
	PCB * sem_wait;
} PCB;								// 进程控制块

PID MyPID(void);
PCB * MyPCBP(void);
void wait(void);
void wakeup(PCB * him);

Boolean CS(int * cell, int * old, int * new) 		// compare-and-swap (4 bytes)
Boolean CSD(long * cell, long * old, long * new) 	// compare-and-swap (8 bytes)
```

信号量:

信号量等待链表

```
typedef PCB * xsemaphore
void Xsem_init(xsemaphore * sem)
void Xsem_get(xsemaphore * sem)
void Xsem_give(xsemaphore * sem)
```


### 第五部分 恢复
#### 9 日志管理程序 (log manager)

- 支持快速写的算法
- 谨慎写(careful write)
- 串行写
- 乒乓写(Ping-Pong)
- 成组提交
- 提前写数据集(WADS)
- 交错分配

LogM与其他RM的交互: 图9-1.

日志相关的低水位线: 图9-7

- 重启低水位 = min( 事务低水位, RM低水位)
- 归档恢复低水位 = argmin(对象恢复低水位)


#### 10 事务管理器概念 (transaction manager concepts)

应用程序与RM的交互: 图10-4, 10-6.

RM与TM的交互: 图10-5.

系统重启中数据流: 图10-7.


#### 11 事务管理器结构 (transaction manager structure)

#### 12 高级事务管理器主题 (advanced transaction manager topics)

### 第六部分 事务型文件系统：一个资源管理器实例
#### 13 文件和缓冲区管理 (file and buffer management)

主存中访问外存中文件的方式: <br/>
(1) 读/写映射技术: 文件中对象的次序与被复制到主存中的位置不必相关 - used in book <br/>
(2) 内存映射文件技术: 将文件作为一个整体复制到一块连续的主存区域<br/>
(3) 扩展虚拟存储器.

介质和文件管理

基本文件系统的对象:<br/>
块Block: 通过IO接口进行的操作涉及多个块<br/>
页面Page: 缓冲管理器维护的虚拟地址空间以页面为单位进行组织 - 大小与块相同<br/>
槽Slot: 磁道上能够存储一个块的物理位置 - 假设Slot足够大可以容纳一个Block<br/>

基本文件系统的操作

磁盘空间管理

磁盘 -> 柱面 -> 磁道 -> 槽: <disk-id, cyl-no, track-no, slot-no>

映射: f: Block -> Slot, 涉及: 初始分配, 增量扩展, 碎片整理<br/>
(1) 静态连续分配: 文件第一个槽的地址和总块数<br/>
(2) 基于区段的分配(extend-based): 进行多次连续分配<br/>
(3) 单槽分配<br/>
(4) 伙伴系统

文件系统的目录(Catalog)管理: 地址空间的映射, 空闲空间的管理
地址空间的映射 和 空闲区信息 的管理需要辅助数据结构, 必须存储在永久存储器中.

物理存储器的层次结构: 图13-5.

需解决问题:<br/>
(1) how can simple files that appear as arrays of blocks be mapped onto magnetic disks with their specific geometric properties?<br/>
(2) how can objects on external storage be accessed in main memory without requiring the use of the basic file system for each component?<br/>
(3) how is durability managed without going across the very slow external storage interface to often?<br/>
(4) how can files be shared among concurrent activities?<br/>
(5) how can external file handling be optimized by exploiting locality?

block: 块, 基本文件系统对象<br/>
page: 页, 虚拟地址空间单元<br/>
slot: 块的物理位置<br/>
假设: block/page/slot同大小

磁盘槽分配问题:<br/>
(1) 初始分配<br/>
when a file is created, how many contiguous slots shoule be allocated to it?<br/>
(2) 增量扩展<br/>
if an existing file grows beyond the number of slots currently allocated, how many additional contiguous blocks should be assigned to that file?<br/>
(3) 重组<br/>
when and how should the free space on the disk be reorganized?

static and contiguous allocation<br/>
extent-based allocation<br/>
single-slot allocation<br/>
buddy system

不同地址空间的映射: 空闲空间管理、地址翻译使用的数据结构等

底层文件系统的目录管理: 文件描述符、槽位图、区段表

**缓冲区管理**

目标: 使页面在主存中可寻址, 同日志管理器和恢复管理器协调一致的向磁盘写页面.

缓冲区管理器管理虚存中个一个段, 段被分为大小相等的框架(frame), 每个框架容纳一个页面

操作: 存取页面P中偏移量O地址上的数据<br/>
  在缓冲区中搜索: 是否命中<br/>
  寻找空闲框架: 未命中时<br/>
  决定被替换的页面: 替换策略<br/>
  确定框架的地址: 占用框架F<br/>
  确定块的地址: PAGEID P => FILEID, blockno - 使用文件目录信息<br/>
  返回F

```
#define EIGHTK 8192
#define buffersize MANY
#define hashsize PRIME
#define delta SMALL
#define MAXLSN VERY_LARGE_VALUE

typedef unsigned int FILENO; 					// 文件存在期间, 唯一的确定文件
typedef unsigned int BLOCKID;

typedef struct {
	int 		flip;
	FILENO 	fileno;
	BLOCKID 	blockno;
} BLOCKHEAD;						// 块头

typedef struct {
	BLOCKHEAD 	header;
	char 		contents[EIGHTK-sizeof(header)-2];
	int 		flop;
} BLOCK, *BLOCKP;						// 块

typedef struct {} FILE; 				// 文件句柄
typedef FILE * FILEID; 				// 指向文件句柄的指针(文件打开时有效)

typedef struct {
PAGEID	pageid;	     		// 页ID
PAGEPTR	pageaddr;      			// 页指针(OUT参数)
	int		index;      	    		// 页内记录号(调用者使用)
	semaphore *	pagesem;       			// 页保护信号量指针
  Boolean	modified;        			// 调用者修改页标志
  Boolean	invalid;	     			// 调用者撤销页标志
} BUFFER_ACC_CB, * BUFFER_ACC_CBP; 		// 访问控制块

struct {
	PAGE_HEADER 	page_header;		// 页头
	char 			page_body[];		// 页的有效负荷
} bufferpool[buffersize];					// 缓冲区(假设大小固定)
struct {
	Uint 			free_index;		// 空闲框架索引
} free_frames[buffersize];					// 空闲框架索引表
Ulong 		no_free_frames;				// 当前空闲框架数量
semaphore 	free_frame_sem;				// 保护free_frames的信号量

typedef struct {
	PAGEID 		pageid;
	FILEID * 		in_file;
	Uint 			frame_index;
	semaphore 		pagesem;		// 页保护信号量
	Boolean 		modified;
	int 			fixcount;
	LSN 			forminlsn;
	BUFFER_CBP 	prev_in_LSN;
	BUFFER_CBP 	next_in_LSN;
	BUFFER_CBP 	next_in_hclass;
} BUFFER_CB, * BUFFER_CBP;				// 控制块

struct {
	semaphore 		class_sem;
	BUFFER_CBP 	first_bcb;		// 第一个控制块的指针
} buffer_hash[hashsize];					// 控制块哈希链表

BUFFER_CBP 		mru_page;				// 指向最近被使用的页的CB指针
BUFFER_CBP 		lru_page;				// 指向最近最久未使用的页的CB的指针
semaphore 		LRU_sem;				// 保护LRU链的信号量

BUFFER_CBP 		free_cb_list;				// 指向空闲BCB链表的第一个元素的指针
Uint 			no_free_cbs;				// 当前空闲BCB数量
semaphore 		free_cb_sem;				// 保护free_cb_list的信号量

BUFFER_ACC_CBP	free_acc_cb_list;			// 指向空闲BACB链表的第一个元素的指针
Uint			no_free_acc_cbs;
semaphore		free_acb_sem;
```

函数:

```
Boolean bufferfix(PAGEID pageid, LOCK_MODE mode, BUFFER_ACC_CBP * address)
Boolean bufferunfix(BUFFER_ACC_CBP)
Boolean emptyfix(PAGEID pageid, LOCK_MODE mode, BUFFER_ACC_CBP address)
Boolean flush(BUFFER_ACC_CBP)
```

空闲控制块链表的处理:

```
BUFFER_CBP get_bcb()
void give_bcb(BUFFER_CBP)
BUFFER_ACC_CBP get_acb()
void give_acb(BUFFER_ACC_CBP)
Uint hashpage(PAGEID)
FILEID find_filecb(PAGEID)
LSN log_max_lsn()
```

TODO BM视角的日志和恢复
TODO BM的性能优化方法: checkpoint, pre-fetching and pre-flusing, 与事务调度协作, 减少管理消耗

TODO implement this


#### 14 面向元组的文件系统 (the tuple-oriented file system)

面向元组的文件系统需要提供的6个基础服务:

- (1) 存储分配: 将元组存储在底层面向块的文件系统中的块中
- (2) 元组寻址: 每个元组赋予一个稳定的标识符, 通过该标识符高效访问元组
- (3) 枚举: 快速访问: 从一个元组访问下一个元组/访问所有元组
- (4) 内容寻址: 使用元组属性访问元组
- (5) 维护: 删除元组, 元组之间的关联
- (6) 保护: 基本的安全保护: 加密/内容敏感的访问控制

将元组映射到页

```
typedef struct {
	FILENO 	fileno;				// 页面所属文件
	unsigned int 	pageno;			// 文件中页号
} PAGEID, *PAGEIDP;						// 页标识符

enum PAGE_TYPE {
DATA,			// 仅包含一个文件(关系)的元组
INDEX, 		// 包含一个索引文件的节点
FREESPACE, 		// 包含空闲区管理表
DIRECTORY, 		// 包含关于本文件或其他文件的元数据
CLUSTER, 		// 包含多个关系的元组
TABLE			// 包含一些管理性(如寻址)的表
}
enum PAGE_STATE { VALID, INVALID, INDOUBT, SHADOW }
typedef struct {
	PAGEID 	thatsme; 			// 页标识符
	PAGE_TYPE 	page_type; 			// 页类型
	OBJID 		object_id;			// 关系、索引等的内部ID
	LSN 		safe_up_to;			// 用于WAL协议的页面LSN
	PAGEID 	previous;			// 通常页面在双链表中
	PAGEID 	next;
	PAGE_STATE status;
	int 		no_entries;			// 页目录中项数量
	int 		unused;			// 未使用的非连续空闲区字节数
	int 		freespace;			// 用于有效负荷的连续空闲字节数
	char 		stuff[];				// 会不断增长
} PAGE_HEADER, * PAGE_PTR;				// 页头

struct {
	char not_needed[PAGESIZE];		//
	Uint offset_in_page[];				// 元组在页中的偏移量
} PAGE_DIR, * PPAGE_DIR;					// 页目录
```

影响页中空闲空间的操作:

- 插入元组
- 删除元组
- 更新元组
- 重组织: 压缩空洞

文件中空闲空间管理<br/>
(1) 表<br/>
区分: 表页, 数据页<br/>
表页存储在文件中, 一个表页后有多个数据页<br/>
(2) 游标<br/>
文件目录(File Catalog): 空页锚点, 当前可插入页<br/>
空页锚点指向空闲页链表<br/>

TODO 文件目录如何组织的???

元组标识<NODEID, FILEID, TUPLENAME>, 实现方法:

- 相对字节地址(Relative Byte Address, RBA): PAGEID + offset
- 元组ID(TID): <页号, 页目录索引>, 前向地址指针
- 数据库键: 文件或关系中唯一的序列号, 使用数据库键翻译表
- 主键: 使用场景: 关系, 索引, 顺序文件, 哈希文件, 相对文件


物理元组管理:

- 属性值的物理表示<br/>
定长字段定长元组<br/>
变长字段和长度字段<br/>
自描述属性序列<br/>
前缀字段指针<br/>
- 短元组的物理表示<br/>
关系标识 | 元组标识 | 定长字段数量 | 变长字段数量| 变长字段值... | 变长字段偏移量指针数组 | 变长字段值...
- 长元组的物理表示

- 复杂元组和超长属性的物理表示


文件组织:

- 扫描
- 项序列文件
- 系统序列文件
- 相对文件
- 键序列文件
- 哈希文件


#### 15 存取路径 (access paths)

哈希文件


B树

叶子节点中数据的含义:<br/>
(1) 指向元组的指针 - 访问路径<br/>
(2) 元组本身 - 文件组织<br/>

基本操作:<br/>
    查找<br/>
    插入<br/>
    增长: 页节点分裂, 索引节点分裂, 根节点分裂 - 上溢<br/>
    删除: 页节点合并, 索引节点合并 - 下溢

B树上的同步: - Isolation

(1) 页视角<br/>
检索: 共享信号量, 蟹行技术<br/>
插入: 乐观方式, 路径回溯<br/>
Bayer and Schkolnick提出的算法<br/>
删除<br/>
(2) 元组视角<br/>
Mohan提出的码区间封锁协议<br/>
    避免幻象: 封锁索引入口项, 而不是对元组本身加锁<br/>
码区间锁的锁名: <表名, 索引名, 码值><br/>
封锁码值V, 隐含着封锁半开区间[V, X), X为该索引节点中下一个较大的码值: <属性值, 元组标识><br/>
支持的操作:<br/>
    精确匹配查询: key-value = c, 前缀式封锁[<c, >)<br/>
    范围查找: c1 <= key-value <= c2, [c1, W),[W, X), [Z, c2), [c2, c3)<br/>
    插入元组: 插入索引入口项<c, Kn>, c1 <= c < c2, [<c, kmin>, <c2, kmin>), 两个码区间锁: c1 IX锁, c X锁<br/>
    删除元组: 删除<c,kd>, 下一个较小的索引入口项<c1, ke>; c1 = c c上加IX锁; c1 < c c1,c上加X锁

B树上的恢复: - Recovery

例子: T1引起叶子节点(Pa, 指向Pa的指针Pi)分裂(Pa, Pa'), T2在分裂产生的新节点(Pa')中插入元组后提交, T2回滚.

日志记录:<br/>
    T1: Pi中插入新入口项, 从Pa中删除部分入口项, 分配新节点Pa'<br/>
    T2: 在Pa’中插入新入口项

回滚事务: 在节点页上不是执行物理撤销, 而是执行逆操作;<br/>
重做事务: 重做日志中修改页的操作.


### 第七部分 系统概览
#### 16 TP系统概览 (survey of tp systems)

### 第八部分 附录
#### 附录A 参考文献
#### 附录B 数据结构和接口
#### 附录C 词汇表

## 总结

<!-- 概要记录书籍中如何解决关键性问题的. -->

## 应用

<!-- 记录如何使用书籍中方法论解决你自己的问题. -->

### 事务处理标准

X/Open DTP(distributed transaction processing) http://pubs.opengroup.org/onlinepubs/009680699/toc.pdf

- [1] ISO/IEC 10026-1:1992, Information technology—Open Systems Interconnection—Distributed Transaction Processing: Part 1 OSI TP Model.
- [2] ISO/IEC 10026-2:1992, Information technology—Open Systems Interconnection—Distributed Transaction Processing: Part 2 OSI TP Service Definition.
- [3] ISO/IEC 10026-3:1992, Information technology—Open Systems Interconnection—Distributed Transaction Processing: Part 3 OSI TP Protocol Specification.

ISO/IEC 9804:1994 (ITU-T X.851) Service definition for the commitment, concurrency and recovery service element

ISO/IEC 9805:1994 Protocol for the commitment, concurrency and recovery service element<br/>
part 1: Protocol specification (ITU-T X.852)<br/>
part 2: Protocol Implementation Conformance Statement (PICS) proforma (ITU-T X.853)<br/>

- [7] X/Open Guide G307: Distributed Transaction Processing Reference Model (V2), X/Open Company Ltd., November 1993.
- [8] X/Open Preliminary Specification P209: Distributed Transaction Processing—The TX (Transaction Demarcation) Specification, X/Open Company Ltd., October 1992; ISBN: 1-872630-65-0.
- [9] X/Open CAE Specification C193: Distributed Transaction Processing—The XA Specification, X/Open Company Ltd., December 1991; ISBN: 1 872630 24 3.
- [10] X/Open Snapshot S214: Distributed Transaction Processing—The Peer-to-Peer Specification, X/Open Company Ltd., December 1992; ISBN: 1-872630-79-0.
- [11] X/Open Snapshot S216: Distributed Transaction Processing—The XATMI Specification, X/Open Company Ltd., December 1992; ISBN: 1-872630-80-4.
- [12] X/Open Snapshot S218: Distributed Transaction Processing—The TxRPC Specification, X/Open Company Ltd., December 1992; ISBN: 1-872630-81-2.
- [13] X/Open Snapshot S201: Distributed Transaction Processing—The XA+ Specification, X/Open Company Ltd., March 1993; ISBN: 1-872630-93-6.

wikipedia: https://en.wikipedia.org/wiki/X/Open_XA

Miscrosoft
https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ms686548(v=vs.85)

IBM DB2
https://www.ibm.com/support/knowledgecenter/en/SSEPGG_9.5.0/com.ibm.db2.luw.admin.2pc.doc/doc/c0004558.html




### TPC

SUMMARY: http://www.tpc.org/tpc_documents_current_versions/current_specifications.asp

Category:
  OLTP: [A], [B], C, E
  Decision Support: [D], DS
  Data Integration: DI, H, [R]
  Data Virtualization: VMS, HCI, V
  Big Data: BB, HS,
  IoT: IoT
  ECommerce: [W]


* TPC-A [Obsolete]
http://www.tpc.org/tpca/default.asp

TPC-A measures performance in **update-intensive** database environments typical
in **on-line transaction processing** applications. (Obsolete as of 6/6/95)


*  TPC-B [Obsolete]
http://www.tpc.org/tpcb/default.asp

TPC-B measures throughput in terms of how many transactions per second
a system can perform. (Obsolete as of 6/6/95)

* TPC-C
http://www.tpc.org/tpcc/default.asp

Approved in July of 1992, TPC Benchmark C is an on-line transaction processing (OLTP) benchmark.

* TPC-D [Obsolete]
http://www.tpc.org/tpcd/default.asp

TPC-D represents a broad range of **decision support (DS)** applications that
require complex, long running queries against large complex data structures. (Obsolete as of 4/6/99)

* TPC-DI
http://www.tpc.org/tpcdi/default.asp

TPC-DI is a benchmark for **Data Integration**
The TPC-DI benchmark combines and transforms data extracted from
an On-Line Transaction Processing (OTLP) system along with other sources of data,
and loads it into a data warehouse.

* TPC-DS
http://www.tpc.org/tpcds/default.asp

TPC-DS is a **Decision Support** Benchmark
The TPC Benchmark DS (TPC-DS) is a decision support benchmark that
models several generally applicable aspects of a decision support system,
including queries and data maintenance.

TPC-DS Version 2 enables emerging technologies, such as Big Data systems, to execute the benchmark.

* TPC-E
http://www.tpc.org/tpce/default.asp

Approved in February of 2007, TPC Benchmark E is an **on-line transaction processing (OLTP)** benchmark.

* TPC-H
http://www.tpc.org/tpch/default.asp

TPC-H is a **Decision Support** Benchmark

* TPC-R [Obsolete]
http://www.tpc.org/tpcr/default.asp

TPC-R is a business reporting, **decision support** benchmark. (Obsolete as of 1/1/2005)

* TPC-VMS
http://www.tpc.org/tpcvms/default.asp

TPC-VMS is a **Data Virtualization** Benchmark
Introduced in 2012, the TPC Virtual Measurement Single System Specification (TPC-VMS)
leverages the TPC-C, TPC-E, TPC-H and TPC-DS Benchmarks
by adding the methodology and requirements
for running and reporting performance metrics for virtualized databases.

* TPC-W [Obsolete]
http://www.tpc.org/tpcw/default.asp

TPC-W is a transactional web **e-Commerce** benchmark. (Obsolete as of 4/28/05)



* TPCx-BB
http://www.tpc.org/tpcx-bb/default.asp

TPCx-BB is a Big Data Benchmark
TPCx-BB Express Benchmark BB (TPCx-BB) measures the performance of Hadoop-based Big Data systems systems.

* TPCx-HCI
http://www.tpc.org/tpcx-hci/default.asp

TPCx-HCI is a Benchmark for Hyper-Converged Infrastructure
The TPC Express Benchmark HCI (TPCx-HCI) benchmark measures
the performance of Hyper-Converged Infrastructure clusters under a demanding database workload.
It stresses the virtualized hardware and software of converged storage, networking,
and compute resources of the HCI platform.

* TPCx-HS
v1: http://www.tpc.org/tpcx-hs/default.asp?version=1
v2: http://www.tpc.org/tpcx-hs/default.asp

Introduced in 2016 TPCx-HS V2 is based on TPCx-HS V1 with support for Apache Spark -
a popular platform for in-memory data processing that enables real-time analytics on Apache Hadoop.

* TPCx-IoT
http://www.tpc.org/tpcx-iot/default.asp

TPCx-IoT, the industry’s first benchmark which enables direct comparison of
different software and hardware solutions for IoT gateways.

* TPCx-V
http://www.tpc.org/tpcx-v/default.asp

TPCx-V is a Virtualization Benchmark for Database Workloads
The TPC Express Benchmark V (TPCx-V) benchmark measures the performance of
a virtualized server platform under a demanding database workload.


### TATP

Telecom Application Transaction Processing Benchmark
http://tatpbenchmark.sourceforge.net/

### Five-minute rule

https://en.wikipedia.org/wiki/Five-minute_rule

In computer science, the five-minute rule is a rule of thumb for deciding whether a data item should be kept in memory, or stored on disk and read back into memory when required.

It was first formulated by Jim Gray and G. F. Putzolu in 1985, and then subsequently revised in 1997 and 2007 to reflect changes in the relative cost and performance of memory and persistent storage.

The rule is as follows:
The 5-minute random rule: cache randomly accessed disk pages that are re-used every 5 minutes or less.

Gray also issued a counterpart one-minute rule for sequential access:
The 1-minute rule: cache sequentially accessed disk pages that are re-used every 1 minute or less.


### Oracle Database Storage Structures

Oracle Database Concepts 12.2:

- Part I    Oracle Relational Data Structures
- Part II   Oracle Data Access
- Part III  Oracle Transaction Management
- Part IV  Oracle Database Storage Structures
- Part V   Oracle Instance Architecture
- Part VI  Multitenant Architecture
- Part VII Oracle Database Administration and Application Development

Figure 1-1 Oracle Instatnce and Database:

- SGA: system global area
- PGA: program global area

- PMON: Process Monitor Process
- PMAN: Process Manager
- SMON: System Monitor Process
- RECO: Recoverer Process
- MMON:  manageability monitor process
- MMNL: manageability monitor lite process
- LREG: Listener Registration Process

- DBWn: Database Writer Process
- CKPT: Checkpoint Process
- LGWR: Log Writer Process
- ARCn: Archiver Processes
- FBDA: flashback data archive process
- CJQ0: job coordinator process
- Jnnn: job queue slave processes
- SMCO: Space Management Coordinator Process
- Wnnn: slave processes of SMCO
- Innn: I/O slave processes

物理存储结构

An Oracle database is a set of files that store Oracle data in persistent disk storage.

- (1) Data files and temp files
A data file is a physical file on disk that was created by Oracle Database and contains data structures such as tables and indexes. A temp file is a data file that belongs to a temporary tablespace. The database writes data to these files in an Oracle proprietary format that cannot be read by other programs.

- (2) Control files
A control file is a root file that tracks the physical components of the database.

- (3) Online redo log files
The online redo log is a set of files containing records of changes made to data.

A database instance is a set of memory structures that manage database files.

逻辑存储结构: Figure 12-1, 12-2.

- (1) A data block is the smallest logical unit of data storage in Oracle Database. - 数据块
One logical data block corresponds to a specific number of bytes of physical disk space, for example, 2 KB. Data blocks are the smallest units of storage that Oracle Database can use or allocate.

- (2) An extent is a set of logically contiguous data blocks allocated for storing a specific type of information - 区段
In the preceding graphic, the 24 KB extent has 12 data blocks, while the 72 KB extent has 36 data blocks.

- (3) A segment is a set of extents allocated for a specific database object, such as a table. - 片段
For example, the data for the employees table is stored in its own data segment, whereas each index for employees is stored in its own index segment. Every database object that consumes storage consists of a single segment.

- (4) A tablespace is a database storage unit that contains one or more segments. - 表空间
Each segment belongs to one and only one tablespace. Thus, all extents for a segment are stored in the same tablespace. Within a tablespace, a segment can include extents from multiple data files, as shown in the preceding graphic. For example, one extent for a segment may be stored in users01.dbf, while another is
stored in users02.dbf. A single extent can never span data files.

types of tablespace:

- (1) locally managed tablespace(default)
maintains a bitmap in the data file header to track free and used space in the data file body.<br/>
ASSM: automatic segment space management<br/>
MSSM: manual segment space management
- (2) dictionary-managed tablespace
uses the data dictionary to manage its extents.<br/>
data dictionary(数据字典): A read-only collection of database tables and views containing reference information about the database, its structures, and its users.


Figure 12-4: Bitmap-Managed Storage

#### data block

Figure 12-6, 12-7

block overhead: Block header, Table directory, Row directory

A row is stored in a variable-length record. This record is divided into one or more row pieces. Each row piece has a row header and column data.

Figure 12-8: The format of a Row Piece

In row chaining, Oracle Database stores the data for the row in a chain of one or more data blocks reserved for the segment.

Figure 12-13: Row Chaining

An index contains a root block, branch blocks, and leaf blocks.


#### extent

Figure 12-17

#### segment

A segment is a set of extents that contains all the data for a logical storage structure within a tablespace.

- data segment for a table
- index segment for an index on a table

user segment, temporaty segment, undo segment


Figure 12-19: Creation of a User Segment

allocates temporary segments

- for queries as needed during a user session and drops them when the query completes
- for temporary tables and their indexes: Temporary tables hold data that exists only for the duration of a transaction or session

When a transaction starts, the database binds (assigns) the transaction to an undo segment, and therefore to a transaction table, in the current undo tablespace.

The high water mark (HWM) is the point in a segment beyond which data blocks are unformatted and have never been used.

Figure 12-27: Advancing HWM and Low HWM

#### tablespace

A tablespace is a logical storage container for segments.

Figure 12-28: Tablespaces


- SYSTEM tablespace
- SYSAUX tablespace
- undo tablespace


### MySQL文件组织

- 文件格式: https://dev.mysql.com/doc/internals/en/frm-file-format.html
- InnoDB页格式: https://dev.mysql.com/doc/internals/en/innodb-page-structure.html
- InnoDB记录格式: https://dev.mysql.com/doc/internals/en/innodb-record-structure.html
- Binary Log: https://dev.mysql.com/doc/internals/en/binary-log-overview.html
- Important Algorithms and Structures: https://dev.mysql.com/doc/internals/en/algorithms.html

### ZFS

- Add Disk Storage to Oracle Virtual Box: https://www.vitalsofttech.com/add-disk-storage-to-oracle-virtualbox-with-linux/
- 如何在 Ubuntu 上使用 ZFS 文件系统: https://linux.cn/article-9346-1.html
- How to format external drive into ZFS?: https://apple.stackovernet.com/cn/q/31547
- libzfs4j - libzfs binding for Java: https://github.com/kohsuke/libzfs4j

## 文献引用

<!-- 记录相关的和进一步阅读资料: 文献、网页链接等. -->

## 其他备注
