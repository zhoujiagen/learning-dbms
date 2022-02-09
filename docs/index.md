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

### Perspectives on the Query Processing

Topics:

- Query parsing
- Query optimization

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
