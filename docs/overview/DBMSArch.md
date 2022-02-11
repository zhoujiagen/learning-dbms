# Notes of **Architecture of a Database System**

|时间|内容|
|:---|:---|
|2022-02-10| kick off. |
|2022-02-11| reading section 1,2,3. |

<!--
Purugganan M, Hewitt J. How to read a scientific article[J]. Rice University, 2004.

IMRD structure: Introduction, Methods, Results, and Discussion.

Before and during your reading, ask yourself these questions:
• Who are these authors? What journal is this? Might I question the credibility of the work?
• Have I taken the time to understand all the terminology?
• Have I gone back to read an article or review that would help me understand this work better?
• Am I spending too much time reading the less important parts of this article?
• Is there someone I can talk to about confusing parts of this article?

After reading, ask yourself these questions:
• What specific problem does this research address? Why is it important?
• Is the method used a good one? The best one?
• What are the specific findings? Am I able to summarize them in one or two sentences?
• Are the findings supported by persuasive evidence?
• Is there an alternative interpretation of the data that the author did not address?
• How are the findings unique/new/unusual or supportive of other work in the field?
• How do these results relate to the work I’m interested in? To other work I’ve read about?
• What are some of the specific applications of the ideas presented here? What are some further experiments that would answer remaining questions?
 -->


## 引用

<!--
Author(s), Date of publication, Title (book or article), Journal,Volume #, Issue #, pages:
If web access: url; date accessed
-->

```
@Article{Hellerstein2007a,
  author    = {Joseph M. Hellerstein and Michael Stonebraker and James Hamilton},
  journal   = {Foundations and Trends{\textregistered} in Databases},
  title     = {Architecture of a Database System},
  year      = {2007},
  number    = {2},
  pages     = {141--259},
  volume    = {1},
  doi       = {10.1561/1900000002},
  priority  = {prio1},
  publisher = {Now Publishers},
}
```

## 关键字

## 主题

<!-- General subject, Specific subject -->

## 假设

assumption on readers:

- familiar with textbook database systems materials (`[72]`, `[83]`),
- familiar with the basic facilities of moder operating systems.


focus on relational database systems throughout this paper.

## 方法论

attempt to capture the main architectural aspects of modern database systems, with a discussion of advanced topics.

## 结果

## 关键点总结

<!--
Document level
• Title
• Abstract
• Keywords
• visuals (especially figure and table titles)
• first sentence or the last 1-2 sentences of the Introduction

Paragraph level: words or phrases to look for
• surprising
• unexpected
• in contrast with previous work
• has seldom been addressed
• we hypothesize that
• we propose
• we introduce
• we develop
• the data suggest
-->

### 文章结构

```
1 Introduction                                              1
1.1 Relational Systems: The Life of a Query                 2
1.2 Scope and Overview                                      7

2 Process Models                                            9
2.1 Uniprocessors and Lightweight Threads                   12
2.2 DBMS Threads                                            19
2.3 Standard Practice                                       20
2.4 Admission Control                                       22
2.5 Discussion and Additional Material                      24

3 Parallel Architecture: Processes and Memory Coordination  25
3.1 Shared Memory                                           25
3.2 Shared-Nothing                                          27
3.3 Shared-Disk                                             30
3.4 NUMA                                                    31
3.5 DBMS Threads and Multi-processors                       32
3.6 Standard Practice                                       33
3.7 Discussion and Additional Material                      34

4 Relational Query Processor                                37
4.1 Query Parsing and Authorization                         38
4.2 Query Rewrite                                           40
4.3 Query Optimizer                                         43
4.4 Query Executor                                          49
4.5 Access Methods                                          54
4.6 Data Warehouses                                         57
4.7 Database Extensibility                                  63
4.8 Standard Practice                                       68
4.9 Discussion and Additional Material                      69

5 Storage Management                                        71
5.1 Spatial Control                                         71
5.2 Temporal Control: Buffering                             73
5.3 Buffer Management                                       75
5.4 Standard Practice                                       77
5.5 Discussion and Additional Material                      77

6 Transactions: Concurrency Control and Recovery            79
6.1 A Note on ACID                                          80
6.2 A Brief Review of Serializability                       81
6.3 Locking and Latching                                    83
6.4 Log Manager                                             89
6.5 Locking and Logging in Indexes                          92
6.6 Interdependencies of Transactional Storage              96
6.7 Standard Practice                                       98
6.8 Discussion and Additional Material                      99

7 Shared Components                                         101
7.1 Catalog Manager                                         101
7.2 Memory Allocator                                        102
7.3 Disk Management Subsystems                              105
7.4 Replication Services                                    107
7.5 Administration, Monitoring, and Utilities               109

8 Conclusion                                                113

Acknowledgments                                             115

References                                                  117
```

### 术语

- DBMSs: Database Management Systems
- RDBMSs: Relational DBMSs

### 摘要

### 1 Introduction
#### 1.1 Relational Systems: The Life of a Query

see Fig. 1.1

#### 1.2 Scope and Overview

scope:

- focus on architectural fundamentals supporting core database functionality.
- not attemp to provide a comprehensive review of database algorithms.
- provide only minimal discussion of many extensions present in modern DBMSs

structure:

- overall process structure: uniprocessor machines, parallel architectures,
- a single query's view of the system,
- the storage architecture and transactional storage management design,
- shared components and utilities exists in most DBMS.

### 2 Process Models

definitions:

- **Operating System Process**: combines an operating system (OS) program execution unit (a thread of control) with an address space private to the process.
- **Operating System Thread**: an OS program execution unit without additnal private OS context and without a private address space.
- **Lightweight Thread(LWT) Package**: an application-level construct that supports multiple thread within a single OS process.
- **DBMS threads**: some DBMS implment their own LWT packages.
- **DBMS Client**: the software component that implements the API used by application program to communicate with a DBMS.
- **DBMS Worker**: the thread of execution in the DBMS that does work on behalf of a DBMS Client.

#### 2.1 Uniprocessors and Lightweight Threads

process model options:

- processor per DBMS Worker
- thread per DBMS Worker
- process pool

shared data and process boundaries:

- all SQL requests need to be moved into the server processes, and
- all results for return to the client need to be moved back out.

they use buffers:

- disk I/O buffers,
- client communication buffers.

#### 2.2 DBMS Threads

it was not until the 1990s that OS treads were widely implemented, and where they dis exist, the implementations varied greatly.

#### 2.3 Standard Practice

|process model option         | IBM DB2 | MySQL | Oracle | PostgreSQL | Microsoft SQL Server|
|:---                         |:---     |:---   |:---    |:---        |:---                 |
|Process per DBMS worker      |    Y    |       |   Y    |     Y      |                     |
|**Thread per DBMS worker**   |
|OS thread per DBMS worker    |    Y    |   Y   |        |            |                     |
|DBMS thread per DBMS worker  |         |       |        |            |         Y           |
|**Process/thread pool**      |
|process pool                 |    Y    |       |   Y    |            |                     |
|thread pool                  |    Y    |       |        |            |         Y           |

#### 2.4 Admission Control

any good multi-user system has an **admission control policy**, which does not accept new work unless sufficient DBMS resources are available.

with a good admission controller, a system will display graceful degradation under overload.

#### 2.5 Discussion and Additional Material

### 3 Parallel Architecture: Processes and Memory Coordination
#### 3.1 Shared Memory
#### 3.2 Shared-Nothing
#### 3.3 Shared-Disk
#### 3.4 NUMA

NUMA: Non-Uniform Memory Access

- each system in the cluster can access its own local memory quickly, whereas
- remote memory access across the high-speed cluster interconnect is somewhat delayed.

#### 3.5 DBMS Threads and Multi-processors
#### 3.6 Standard Practice

|parallel architecture  | IBM DB2 | MySQL | Oracle | PostgreSQL | Microsoft SQL Server|
|:---                   |:---     |:---   |:---    |:---        |:---                 |
|Shared-Memory          |    Y    |       |    Y   |            |          Y          |
|Shared-Nothing         |    Y    |       |        | Greenplum  |                     |
|Shared-Disk            | ZSeries |       |  RAC   |            |                     |

#### 3.7 Discussion and Additional Material

### 4 Relational Query Processor
#### 4.1 Query Parsing and Authorization
#### 4.2 Query Rewrite
#### 4.3 Query Optimizer
#### 4.4 Query Executor
#### 4.5 Access Methods
#### 4.6 Data Warehouses
#### 4.7 Database Extensibility
#### 4.8 Standard Practice
#### 4.9 Discussion and Additional Material

### 5 Storage Management
#### 5.1 Spatial Control
#### 5.2 Temporal Control: Buffering
#### 5.3 Buffer Management
#### 5.4 Standard Practice
#### 5.5 Discussion and Additional Material

### 6 Transactions: Concurrency Control and Recovery
#### 6.1 A Note on ACID
#### 6.2 A Brief Review of Serializability
#### 6.3 Locking and Latching
#### 6.4 Log Manager
#### 6.5 Locking and Logging in Indexes
#### 6.6 Interdependencies of Transactional Storage
#### 6.7 Standard Practice
#### 6.8 Discussion and Additional Material

### 7 Shared Components
#### 7.1 Catalog Manager
#### 7.2 Memory Allocator
#### 7.3 Disk Management Subsystems
#### 7.4 Replication Services
#### 7.5 Administration, Monitoring, and Utilities

### 8 Conclusion


## 上下文

<!-- how this article relates to other work in the field; how it ties in with key issues and findings by others, including yourself -->

## 意义

<!-- Significance to the field; in relation to your own work -->

while many of the algorithms and abstractions used by a DBMS are textbook material, there has been relatively sparse coverage in the literature of the systems desion issues that make a DBMS work.

this paper presents **an architecture discussion of DBMS design principles**, including:

- process models,
- parallel architecture,
- storage system design,
- transaction system implementation,
- query processor and optimizer architectures,
- typical shared components and utilities.

relation to my work: 帮助建立数据库管理系统的体系结构的基本概念.

## 重要的图表

<!-- brief description; page number -->

### Fig. 1.1 Main components of a DBMS

![Fig. 1.1 Main components of a DBMS](./images/DBMSArch-Fig. 1.1 Main components of a DBMS.png)

example: a gate agent clicks on a form to request the passenger list for a flight

1. Client Communications Manager
2. Process Manager
3. Relational Query Processor
4. Transactional Storage Manager
5. unwinding the stack

a number of shared components and utilities that are vital to the operation of a full-function DBMS


## 引用的重要文献

<!-- cite those obviously related to your topic AND any papers frequently cited by others because those works may well prove to be essential as you develop your own work -->

## 其他备注
