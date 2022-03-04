# Learning DBMS

|时间|内容|
|:---|:---|
|2022-02-09| Add Readings and Implementations seperation for docs. |

## Readings

### Perspectives on the Storage Engines

Topics:

- DBMS overview
- B-Tree and variants
- File format
- Transaction: processing and recovery
- Log-Structured Storage

#### Overview

|Progress|Title|Notes|
|:---|:---|:---|
|100|[Architecture of a Database System](./overview/DBMSArch.md)||
||[Database Systems: The Complete Book](./overview/DBMSCBook.md)||
||[How to Build a Non-Volatile Memory Database Management System](./overview/NVMDBMS.md)||
||[Main Memory Database Systems: An Overview](./overview/MemDBMS.md)||
||[The working set model for program behavior](./overview/ProgramWorkSetModel.md)||
||[The Design and Implementation of Modern Column-Oriented Database Systems](./overview/ColumnDBMS.md)||
||[Column-oriented Database Systems: A Comparison Study](./overview/ColumnDBMSCmp.md)||
||[What Every Programmer Should Know About Memory](./overview/ProgrammerMemory.md)||
||[Bigtable: A Distributed Storage System for Structured Data](./overview/Bigtable.md)||
||[Understanding InnoDB clustered indexes](./overview/InnodbIndex.md)||

#### B-Tree and variants

> TBD

#### File format

> TBD

#### Transaction

|Progress|Title|Notes|
|:---|:---|:---|
|100|[ARIES: a transaction recovery method supporting fine-granularity locking and partial rollbacks using write-ahead logging](./transaction/aries.md)||
|100|[Transaction Processing: Concepts and Techniques](./transaction/TPCT.md)||
||[Transactional Information Systems: Theory, Algorithms, and the Practice of Concurrency Control and Recovery](./transaction/TIS.md)||

#### Log-Structured Storage

|Progress|Title|Notes|
|:---|:---|:---|
||[The log-structured merge-tree (LSM-tree)](log-structured-storage/LSMTree.md)||
||[LSM-based Storage Techniques: A Survey](log-structured-storage/LSMSurvey.md)||

### Perspectives on the Distributed Systems

Topics:

- Distributed systems overview
- Failure detection
- Leader election
- Replication and Consistency
- Anti-Entropy [^anti-entropy] and Dissemination [^dissemination]
- Distributed Transactions
- Consensus

[^anti-entropy]: in a distributed system, **entropy** represents a degree of state divergence between nodes.<br/>
      **anti-entropy** is usually used to bring the nodes back up-to-date in case of the primary deliver mechanism has failed, i.e. **anti-entropy** is used to lower the convergence time bounds in eventually consistent systems.

[^dissemination]: **dissemination**: propagation, *the action or fact of spreading something, especially information, widely.*

> TBD

### Perspectives on the Query Processing

Topics:

- Query parsing
- Query optimization

|Progress|Title|Notes|
|:---|:---|:---|
|100|[Query Optimization](./query/optimization/query-optimization.md)||

## Implementations

- [Dgraph](./implementation/graph/dgraph.md)
- [JanusGraph](./implementation/graph/janusgraph.md)
- [Apache Jena](./implementation/graph/jena.md)
- [SPARQL](./implementation/graph/sparql.md)
- [AllegroGraph](./implementation/graph/allegrograph.md)
- [Apache Solr](./implementation/graph/solr.md)
- [Apache TinkerPop](./implementation/graph/tinkerpop.md)
- [ElasticSearch](./implementation/graph/elasticsearch.md)
- [ClickHouse](./implementation/clickhouse.md)
- [Presto](./implementation/presto.md)
- [MySQL](implementation/mysql/mysql-5.7/mysql-index.md)
