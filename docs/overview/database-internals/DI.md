# Notes of **Database Internals**


|时间|内容|
|:---|:---|
|20211228|kick off.|

## 术语

<!-- 记录阅读过程中出现的关键字及其简单的解释. -->


### tags

- ==Database architecture==
- ==Column-oriented DBMS==
- ==In-memory DBMS==
- ==Binary search trees==
- ==Algorithm for splits and merges in B-Trees==
- ==File organization techniques==
- ==Disk-based B-Trees==
- ==Transaction processing and Recovery, generally==
- ==Concurrency control in B-Trees==
- ==Parallel and concurrent data structures==
- ==Chronological developments in the field of transaction processing==
- ==Copy-on-Write B-Trees==
- ==Lazy-Adaptive Trees==
- ==FD-Trees==
- ==Bw-Trees==
- ==Cache-Oblivious B-Trees==
- ==LSM Trees==
- ==Bitcask==
- ==WiscKey==
- ==LOCS(LSM Tree-based KV Store on Open-Channel SSD)==
- ==LLAMA==


- ==Distributed system abstraction, failure models, and timming assumption==
- ==Failure detection and algorithms==
- ==Leader election algorithms==
- ==Consistency models==
- ==Gossip protocols==
- ==Atomic commitment integration with local transaction processing and recovery subsystems==
- ==Recent progress in the area of distributed transactions==

- ==Atomic broadcast==
- ==Classic Paxos==
- ==Fast Paxos==
- ==Multi-Paxos==
- ==EPaxos==
- ==Raft==
- ==Recent developments of consensus==


- ==Database systems==
- ==Distributed systems==
- ==Operating databases==



## 介绍

<!-- 描述书籍阐述观点的来源、拟解决的关键性问题和采用的方法论等. -->

综合性的描述数据库内部的存储引擎和分布式系统中概念、原理和方法.

## 动机

<!-- 描述阅读书籍的动机, 要达到什么目的等. -->

1. 对数据库内部机制有个基本的了解和理解;
2. 收集常见的数据库领域的参考文献.

## 概念结构

<!-- 描述书籍的行文结构, 核心主题和子主题的内容结构和关系. -->

#### Preface

### Part I. Storage Engines

见 [Database Internals - Storage Engines](./DI-storage-engines.md)

### Part II. Distributed Systems

见 [Database Internals - Distributed Systems](./DI-distributed-systems.md)

## 总结

<!-- 概要记录书籍中如何解决关键性问题的. -->

## 应用

<!-- 记录如何使用书籍中方法论解决你自己的问题. -->

## 文献引用

<!-- 记录相关的和进一步阅读资料: 文献、网页链接等. -->

```
@Book{Petrov2019,
  author    = {Alex Petrov},
  publisher = {O'Reilly Media, Inc.},
  title     = {Database Internals},
  year      = {2019},
  isbn      = {9781492040347},
}
```

参考文献: [References of **Database Internals**](./DI-references.md)

## 其他备注
