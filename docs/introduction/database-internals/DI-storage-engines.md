# Database Internals - Part I. Storage Engines

## 1. Introduction and Overview
### DBMS Architecture

describe DBMS architectures: `[HELLERSTEIN07]`, `[WEIKUM01]`, `[ELMASRI11]`, `[MOLINA08]`

### Memory- Versus Disk-Based DBMS

NVM(Non-Volatile Memory): `[ARULRAJ17]`

#### Durability in Memory-Based Stores

memory-based database implementation: `[MOLINA92]`

### Column- Versus Row-Oriented DBMS

pioneer open source column-oriented store: MonetDB, C-Store.

#### Row-Oriented Data Layout

row-oriented store storing entire rows together improves spatial locality(program behaviour): `[DENNING68]`

#### Column-Oriented Data Layout

each value have to hold a key, some column stores use implicit identifiers(virtual ID) instead, and use the offset of the value to map it back to the related values: `[ABADI13]`

column-oriented file format: Apache Parquet, Apace ORC, RCFile,

column-oriented stores: Apache Kudu, ClockHouse, `[ROY12]`

#### Distinctions and Optimizations

modern CPU vectorized instructions: `[DREPPER07]`

#### Wide Column Stores

BigTable: `[CHANG06]`

HBase

### Data Files and Index Files
#### Data Files
#### Index Files

while primary indx files hold a unique entry per search key, secondary indexed may hold several entries per serach key: `[MOLINA08]`

#### Primary Index as an Indirection

To reduce the costs of pointer updates, instead of pyaload offsets, some implementation use primary keys for indirection, for example MySQL InnoDB uses a primary index and performs two lookupes: `[TARIQ11]`

### Buffering, Immutability, and Ordering

Storage structures have 3 common variables:

- buffering: whether or not choose to collect a certain amount of data in memory before putting in on disk. example: Lazy B-Trees, Two-component LSM Tree.

- immutable: whether or not read parts of the file, update them, and write the updated results at the same location in the file. example: Copy-on-Write, Bw-Trees.

- ordering: whether or not the data records are stored in the key order in the pages on disk. example: Bitcask, WiscKey.


### Summary

## 2. B-Tree Basics
### Binary Search Trees
#### Tree Balancing
#### Trees for Disk-Based Storage
### Disk-Based Structures
#### Hard Disk Drives
#### Solid State Drives
#### On-Disk Structures
### Ubiquitous B-Trees
#### B-Tree Hierarchy
#### Separator Keys
#### B-Tree Lookup Complexity
#### B-Tree Lookup Algorithm
#### Counting Keys
#### B-Tree Node Splits
#### B-Tree Node Merges
### Summary

## 3. File Formats
### Motivation
### Binary Encoding
#### Primitive Types
#### Strings and Variable-Size Data
#### Bit-Packed Data: Booleans, Enums, and Flags
### General Principles
### Page Structure
### Slotted Pages
### Cell Layout
### Combining Cells into Slotted Pages
### Managing Variable-Size Data
### Versioning
### Checksumming
### Summary

## 4. Implementing B-Trees
### Page Header
#### Magic Numbers
#### Sibling Links
#### Rightmost Pointers
#### Node High Keys
#### Overflow Pages
### Binary Search
#### Binary Search with Indirection Pointers
### Propagating Splits and Merges
#### Breadcrumbs
### Rebalancing
### Right-Only Appends
#### Bulk Loading
### Compression
### Vacuum and Maintenance
#### Fragmentation Caused by Updates and Deletes
#### Page Defragmentation
### Summary

## 5. Transaction Processing and Recovery

ACID: `[HAERDER83]`

### Buffer Management

virtual disk: `[BAYER72]`

#### Caching Semantics
#### Cache Eviction
#### Locking Pages in Cache

pinning page: `[GRAEFE11]`

#### Page Replacement

Bélády’s anomaly: `[BEDALY69]`


LRU(least recently used): `[TANENBAUM14]`

2Q(two queue LRU): `[JONSON94]`

LRU-K: `[ONEIL93]`

CLOCK algorithm: `[SOUNDARARARJAN06]`

LFU(least frequently used)

TinyLFU: `[EINZIGER17]`, `[CORMODE11]`

### Recovery

ARIES(Algorithm for Recovery and Isolation Exploiting Semantics): `[MOHAN92]`

`fsync`: `[CORBET18]`

#### Log Semantics

fuzzy checkpoint: `[MOHAN92]`

#### Operation Versus Data Log

System R: `[CHAMBERLIN81]`

use logical logging to perform an undo for concurrency and performance, use physical logging to perform a redo to imporve recovery time: `[MOHAN92]`

#### Steal and Force Policies

no-steal policy: `[WEIKUM01]`

#### ARIES

`[MOHAN92]`

### Concurrency Control
#### Serializability

schedule: `[MOLINA08]`

correct schedule: `[WEIKUM01]`

#### Transaction Isolation
#### Read and Write Anomalies

the SQL standard: `[MELTON06]`

write skew: `[FEKETE04]`

#### Isolation Levels

serializability: `[BAILIS14a]`, `[BAILIS14b]`

write skew under snapshot isolation: `[FEKETE04]`

#### Optimistic Concurrency Control

transaction execution phases: read phase, validation phase, write phase. `[WEIKUM01]`

#### Multiversion Concurrency Control

Depending on the isolation level implemented by the database system, read operations may or may not be allowed to access uncommitted values. `[WEIKUM01]`

implement snapshot isolation: `[HELLERSTEIN07]`

#### Pessimistic Concurrency Control

Thomas Write Rule: `[THOMAS79]`

aborted transactions restart with a new timestamp: `[RAMAKRISHNAN03]`

#### Lock-Based Concurrency Control

downside of using locks: `[REN16]`

deadlock detection can be done periodically or continuously: `[WEIKUM01]`

restrictions to avoid deadlock: wait-die, wound-die `[RAMAKRISHNAN03]`

busy wait and queue techniques: `[MELLORCRUMMEY91]`

latch crabbing/latch coupling: `[RAMAKRISHNAN03]`

root-to-leaf traversal: `[GRAEFE10]`

Blink-Trees: `[LEHMAN81]`

### Summary

## 6. B-Tree Variants
### Copy-on-Write

`[Driscoll1986]`

LMDB(Lightning Memory-Mapped Database Manager): http://www.lmdb.tech/doc/


#### Implementing Copy-on-Write: LMDB
### Abstracting Node Updates
### Lazy B-Trees

buffering B-Tree updates in intermediate structures instead of applying them to the tree directly.

#### WiredTiger

WiredTiger: https://docs.mongodb.com/manual/core/wiredtiger/

Update buffers are implemented using **skiplists**, which have a complexity similar to search trees `[PAPADAKIS93]` but have a better concurrency profile `[PUGH90a]`.

#### Lazy-Adaptive Tree

LA-Tree(Lazy-Adaptive Tree): `[AGRAWAL09]`

### FD-Trees

FD-Tree(Flash Disk Tree): `[LI10]`

#### Fractional Cascading

fractional cascading: `[CHAZELLE86]`

#### Logarithmic Runs
### Bw-Trees

Bw-Tree(Buzzword-Tree): `[LEVANDOSKI14]`

#### Update Chains
#### Taming Concurrency with Compare-and-Swap
#### Structural Modification Operations

SMO(Structural Modification Operations): `[WANG18]`

#### Consolidation and Garbage Collection

### Cache-Oblivious B-Trees

cache-oblivious structures: `[DEMAINE02]`

two-level memory hierarchy: page cache, disk; `[AGGARWAL88]`

#### van Emde Boas Layout

cache-oblivious B-trees: `[BENDER05]`

### Summary

## 7. Log-Structured Storage

immutability: `[HELLAND15]`

in-place update storage structures are optimized for read performance: ` [GRAEFE04]`

### LSM Trees

LSM Trees: `[ONEIL96]`

log-structured filesystem: `[ROSENBLUM92]`

ISAM(Indexed Sequential Access Method): `[RAMAKRISHNAN03]`, `[LARSON81]`

#### LSM Tree Structure

ordered LSM Trees: `[ONEIL96]`



#### Updates and Deletes
#### LSM Tree Lookups
#### Merge-Iteration

a sorted collection of iterator heads is mantained with $O(\texttt{log}N)$ (average case): `[KNUTH98]`

#### Reconciliation
#### Maintenance in LSM Trees

### Read, Write, and Space Amplification
#### RUM Conjecture

RUM Conjecture [ATHANASSOULIS16]

### Implementation Details
#### Sorted String Tables
#### Bloom Filters

probabilistic data structures:

- Bloom filter: for set membership, `[BLOOM70]`
- HyperLogLog: for cardinality estimation, `[FLAJOLET12]`
- Count-Min Sketch: for frequency estimation, `[CORMODE12]`

#### Skiplist

skiplist: `[PUGH90b]`

concurrent skiplist: `[HERLIHY10]`

concurrent skiplist with hazard pointers: `[RUSSEL12]`

#### Disk Access
#### Compression
### Unordered LSM Storage
#### Bitcask

Bitcask: one of the storage engine used in Riak, `[SHEEHY10b]`

#### WiscKey

WiscKey: `[LU16]`

- decouple sorting from garbage collection,
- keep the keys sorted in LSM trees,
- keep data records in unordered append-only files called vLogs(value logs).

### Concurrency in LSM Trees
### Log Stacking

LSS: Log-structured storage

stack multiple log-structure systems on top each other: `[YANG14]`

#### Flash Translation Layer

FTL: flash translation layer

#### Filesystem Logging

keep partitions aligned to the underlying hardware: `[INTEL14]`

keep writes aligned to page size: `[KIM12]`

### LLAMA and Mindful Stacking

LLAMA: latch-free, log-structured, access-method aware

#### Open-Channel SSDs

LOCS: LSM Tree-based KV Store on Open-Channel SSD, `[WANG13]`

LightNVM: use Open-Channel SSDs, in the Linux kernel, `[BJØRLING17]`

SDF: Software Defined Flash, ``

### Summary

## Part I Conclusion

probabilistic data structures: `[FLAJOLET12]`, `[CORMODE04]`

bringing ideas from matchine learning: `[KRASKA18]`

non-volatie and byte-addressable storage: `[VENKATARAMAN11]`
