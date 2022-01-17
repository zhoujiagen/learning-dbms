# Database Internals - Part II. Distributed Systems

## 8. Introduction and Overview
### Concurrent Execution

concurrent operations overlap in time, while parallel operations are executed by multiple processors: `[WEIKUM01]`

#### Shared State in a Distributed System
### Fallacies of Distributed Computing
#### Processing
#### Clocks and Time

some failure-detection algorithms rely on a shared notion of time and a guarantee that the clock drift is always within allowed bounds for correctness: `[GUPTA01]`

#### State Consistency
#### Local and Remote Execution

local and remote execution are not the same: `[WALDO96]`

interleaving local and blocking remote calls may lead to performance degradation and unintended side effects: `[VINOSKI08]`

#### Need to Handle Failures

out-of-memory killer: `[KERRISK10]`

#### Network Partitions and Partial Failures

perspectives on the CAP Theorem: `[GILBERT12]`

partial failures: `[TANENBAUM06]`

bit rot: `[GRAY05]`

#### Cascading Failures
### Distributed Systems Abstractions
#### Links

prefect link: `[CACHIN11]`

for the exactly-once guarantee to hold, nodes should have a common knowledge `[HALPERN90]` :

- everyone knows about some fact,
- everyone knows that everyone else also knows about that fact.

### Two Generals’ Problem
### FLP Impossibility

FLP Impossibility Problem: `[FISCHER85]`

For a consensus protocol to be correct, it has to preserve 3 properties:

- agreement: the decision the protocol arrives at has to be unanimous;
- validity: the agreed value has to be proposed by one of the participants;
- termination: an agreement is final only if there are no processes that did not reach the decision state.

assumptions:

- processing is entirely asynchronous;
- there's no shared notion of time between the processes;
- algorithms in such systems cannot be based on timeouts;
- there's no way for a process to find out whether the other process has crashed or is simply runnning too slow.

Given these assumptions, there exists no protocol that can guarantee consensus in a bounded time. No completely asynchronous consensus algorithm can tolerate the unannounced crash of even a single remote process.

### System Synchrony

time dependent solutions to solve a consensus problem: `[ARJOMANDI83]`

partially synchronous: `[DWORK88]`

### Failure Models
#### Crash Faults

the possibility of recovery requires introducing a durable state and recovery protocol into the system: `[SKEEN83]`

#### Omission Faults
#### Arbitrary Faults

Byzantine fault tolerance in cryptocurrencies: `[GILAD17]`

#### Handling Failures

mask failure by forming process groups and introducing redundancy into the algorithm: `[CHRISTIAN91]`

### Summary

## 9. Failure Detection

failure detectors are allowed to produce false-positives: `[CHANDRA96]`

### Heartbeats and Pings
#### Timeout-Free Failure Detector

timeout-free failure detector: `[AGUILERA97]`

#### Outsourced Heartbeats

SWIM: Scalable Weakly Consistent Infection-style Process Group Membership Protocol, `[Das2002]`

### Phi-Accural Failure Detector

phi-accrual($\varphi$-accrual) failure dector: `[HAYASHIBARA04]`

### Gossip and Failure Detection

gossip-style failure detection service: `[VANRENESSE98]`

### Reversing Failure Detection Problem Statement

FUSE: failure notification service, `[DUNAGAN04]`

### Summary

prove the usefulness of failure detectors: `[CHANDRA96]`

## 10. Leader Election

### Bully Algorithm

bully algorithm use process ranks to identify the new leader: `[MOLINA82]`

### Next-In-Line Failover

use multiple next-in-line alternative processes as a failover to shorten reelection: `[GHOLIPOUR09]`

### Candidate/Ordinary Optimization

to lower requirements on the number of messages by splitting the nodes into two subsets: candidate and ordinary; `[MURSHED12]`

### Invitation Algorithm

### Ring Algorithm

ring algorithm: `[CHANG79]`

### Summary

If wen can reach consensus about the leader identity, we can use the same means to reach consensus on anything else. `[ABRAHAM13]`

stable leader election algorithm: `[AGUILERA01]`

## 11. Replication and Consistency

update multiple copies of data atomically is a problem equivalent to consensus: `[MILOSEVIC11]`

### Achieving Availability

### Infamous CAP

CAP conjecture: tradeoffs between Consistenty, Availability and Partition tolerance `[BREWER00]`

we cannot implement a system that simultaneously guarantees both availability and consistency in the presence of network partitions: `[GILBERT02]`

we can build systems that guarantee strong consistency while providing best effort availability, or guarantee availability while providing best effort consistency: `[GILBERT12]`

PACELEC conjecture: `[ABADI12]`

#### Use CAP Carefully

while we can trun a knob and trade consitency for availability, partition tolerance is a property we cannot realistically tune or trade fro anything: `[HALE10]`

availability in CAP is different from the aforementioned high availability: `[KLEPPMANN15]`

#### Harvest and Yield

define two tunable metrics: harvest and yield, choosing between which still consitutes correct behavior: `[FOX99]`

### Shared Memory

tree types of registers:

- safe
- regular
- atomic

### Ordering

### Consistency Models

two perspective of consistency: state, operation (`[TANENBAUM06]`, `[AGUILERA16]`)

consistency has synchronization costs: `[ATTIYA94]`

#### Strict Consistency

strict consistency model is impossible to implement, as the laws of physics and the way distributed systems work set limits on how fast things may change: `[SINHA97]`

#### Linearizability

linearizability: `[LEE15]`

there may exist more than one way in which the events can be ordered: `[HERLIHY90]`

as soon as a single read operation returns a particular value, all read that come after it return the value at least as recent as the one it returns: `[BAILIS14a]`

atomic write operation do not consider current register value, unlike CAS(compare-and-swap), that move from one value to the next only when the previous value is unchanges: `[HERLIHY94]`

ABA problem: `[DECHEV10]`

it is possible to implement linearizability using low level primitives: `[MCKENNEY05a]`, `[MCKENNEY05b]`

we can implement a concurrent queue by creating a linked list node and then aomically appending it to the tail of the list: `[KHANCHANDANI18]`

in distributed systems, linearizability can be implemented using consensue: `[HOWARD14]`

combile linearizable histories producres a history that is also linearizable: `[HERLIHY90]`

RIFL: Reusable Infrastructure for Linearizability, `[LEE15]`

#### Sequential Consistency

sequential consistency: `KINGSBURY18a`

sequential consistency was initially introduced in the context of concurrency, describing it as a way to execute multiprocessor programs correctly: `[LAMPORT79]`

distinguish between sequential consistency and linearizability:

- both require operations to be globally ordered,
- linearizability requires the local order of each process and global order to be consistent, i.e. respects a real-time operation order,
- under sequential consistency, ordering holds only for the same-origin writes: `[VIOTTI16]`
- linearizability histories is composable, while sequential consistent schedules are not composable: `[ATTIYA94]`

modern CPU memory model: `[DREPPER07]`, `[GEORGOPOULOS16]`

#### Causal Consistency

in a causally consistent system, we get session guarantees for the application: `[TERRY94]`

causal consistency can be implemented using logical clocks: `[LAMPORT78]`

the two prominent and frequently cited projects implementing causal consistency:

- COPS: Clusters of Order-Preserving Servers, `[LLOYD11]`
- Eiger: `[LLOYD13]`


vector clocks:

messages each specifying their dependencies are causally releated and were progaated out of order, the process buffers them until it can collect all operation dependencies and restore their causal order: `[KINGSBURY18b]`

Dynamo `[DECANDIA07]` and Riak `[SHEEHY10a]`, use vector clocks `[LAMPORT78]` `[MATTERN88]` for establishing causal order.

we cannot end up in a situation where we have a write conflict if values are independent: `[LAMPORT79]`

Riak allows users to see and resolve divergent histories: `[DAILY13]`

### Session Models

session model `[VIOTTI16]`, 在`[TANENBAUM06]`中称为以客户端为中心的一致性模型

session models make no assumptions about operations made by different process (clients) or from the different logical session: `[TANENBAUM14]`

read-own-writes, monotonic reads model, monotonic writes model, writes-follow-reads

Pipelined RAM(PRAM) consistency: `[LIPTON88]`, `[BRZEZINSKI03]`

- combine monotonic reads, monotonic writes and read-own-writes
- also known as FIFO consistency

### Eventual Consistency

eventual consistency: `[VOGELS09]`

### Tunable Consistency

- Replication Factor $N$: number of nodes that wil store a copy of data,
- Write Consistency $W$: number of nodes that have to acknowledge a write for it to success,
- Read Consistency $R$: number of nodes that have to respond to a read operation for it to succeed.

### Witness Replicas

using witness replicas helps to reduce storage costs while preserving consistency invariants. implementations: Spanner `[CORBETT12]`, Apache Cassandra.

### Strong Eventual Consistency and CRDTs

strong eventual consistency: `[GOMES17]`

CRDT: Conflict-Free Replicated Data Types, `[SHAPIRO11a]`; Redis中实现 `[BIYIKOGLU13]`

super-peers, G-Set: `[SHAPIRO11b]`

a conflict-free replicated JSON data type: `[KLEPPMANN14]`

### Summary

## 12. Anti-Entropy and Dissemination

反熵与传播

propagate updates to all nodes in the cluster using approaches: `[DEMERS87]`

- broadcast: notification broadcast from one process to all others,
- anti-entropy: periodic peer-to-peer information exchange,
- gossip: cooperative broadcase, where message recipients become broadcasters and help to spread the information quicker and more reliably.

### Read Repair

in case some of the replicas have missed the recent updates and their responses differ, the coordinator detects inconsistencies and send updates back to the replicas: `[DECANDIA07]`

### Digest Reads

### Hinted Handoff

hinted handoff: a write-side repair mechanism `[DECANDIA07]` `[ELLIS11]`

sloppy quorums imporve availability at the cose of consistency: `[DOWNEY12]`

### Merkle Trees

Merkle trees: `[MERKLE87]`

### Bitmap Version Vectors

bitmap version vectors: `[GONÇALVES15]`

### Gossip Dissemination

gossip protocols: `[DEMERS87]`

#### Gossip Mechanics

gossip protocols offer convergent consistency: `[BIRMAN07]`

#### Overlay Networks

gossip algorithms can distributed a message withing $\texttt{log}N$ message rounds: `[KREMARREC07]`

#### Hybrid Gossip

Plumtrees: Push/lazy-push multicast trees: `[LEITAO07]`; used in Riak core

#### Partial Views

HyParView (Hybrid Partial View) protocol: `[LEITAO07]`, used in Partisan

performance and quality measure: how quickly a peer sampling service vonverges to a stable overlay in cases of topology reorganization `[JELASITY04]`

### Summary

many modern systems use gossip for failure derection and membership information: `[DECANDIA07]`

## 13. Distributed Transactions

atomicity requirements holds not only for the local operations, but also for operations executed on other nodes: `[LAMPSON79]`

### Making Operations Appear Atomic

atomic commitment algorithms do not work int he presense of Byzantine failures: `[HADZILACOS05]`

the problem that atomic commiment is trying to solve is reaching an agreement on whether or not to execute the proposed transaction: `[ROBINSON08]`

Apache Kafka use atomic commitment algorithms: `[MEHTA17]`

### Two-Phase Commit

2PC: two-phase commit


in the context of database systems, each 2PC round is usually responsible for a single transaction. `[BERNSTEIN09]`

#### Cohort Failures in 2PC
#### Coordinator Failures in 2PC

`[BERNSTEIN87]`

### Three-Phase Commit

three-phase commit: `[SKEEN83]`, solve a nonblocking atomic commitment problen `[BABAOGLU93]`


#### Coordinator Failures in 3PC

### Distributed Transactions with Calvin

Calvin: a fast distributed transaction protocol, `[THOMSON12]`

implementation: FaunaDB

### Distributed Transactions with Spanner

Spanner: `[CORBETT12]`

implementation/derivatives: CockroachDB, YugaByte DB

comparasion between Spanner and Calvin: `[ABADI17]`

### Database Partitioning
#### Consistent Hashing

consisten hashing: `[KARGER97]`

### Distributed Transactions with Percolator

SI: snapshot isolation; prevents read skew, an anomaly permitted under the read-committed isolation level `[BERENSON95]`

Percolator: a library that implements a transactional API on top of the distributed database Bigtable;

database based on the Percolator model: TiDB

### Coordination Avoidance

coordination avoidance: attempt to reduce the amount of coordination while still providing strong consistency guarantees, `[BAILIS14b]`

implementation: RAMP(Read-Atomic Multi Partition) transactions `[BAILIS14c]`

### Summary

consensus algorithms on transaction commit: `[GRAY04]`

## 14. Consensus

FLP impossibility

consensus algorithms assume an asynchronous model and guarantee safety, while an external failure detector can provide information about other processes, guaranteeing liveness `[CHANDRA96]`

### Broadcast

best effort broadcast: `[CACHIN11]`

### Atomic Broadcast

atomic broadcast/total order multicast: guarantees both reliable delivery and total order.

#### Virtual Synchrony

an atomic broadcast helps to deliver totally ordered messages to a static group of processes, and virtual synchrony delivers totally ordered messages to a **dynamic** group of peers. `[BIRMAN10]`

not received braod adoption: `[BIRMAN06]`

#### Zookeeper Atomic Broadcast (ZAB)

implementation of atomic broadcast: ZAB used by Apache ZooKeeper `[HUNT10]` `[JUNQUEIRA11]`

### Paxos

an atomic broadcase is a problem equivalent to consensus in an asynchronous system with crash failures, since participants have to agree on the message order and must be able to learn about it. `[CHANDRA96]`

"The Part-Time Parliament" paper: `[LAMPORT98]`

"Paxos Make Simple": `[LAMPORT01]`

#### Paxos Algorithm
#### Quorums in Paxos
#### Failure Scenarios
#### Multi-Paxos

`[CHANDRA07]`

we can think of single-decree Paxos as a write-once register: `[RYSTSOV16]`

Active Disk Paxos: `[CHOCKLER15]`

CASPaxos: `[RYSTSOV18]`

#### Fast Paxos

`[LAMPORT06]`

classis paxos v.s. fast paxos: `[JUNQUEIRA07]`

`[ZHAO15]`

#### Egalitarian Paxos

EPaxos: Egalitarian Paxos, `[MORARU11]`

Generalized Paxos: `[LAMPORT05]`

`[MORARU13]`

#### Flexible Paxos

Flexible Paxos: `[HOWARD16]`

Vertical Paxos: `[LAMPORT09]`

#### Generalized Solution to Consensus

`[HOWARD19]`

### Raft

"In Search of an Understandable Consensus Algorithm" `[ONGARO14]`

terms/epoch: `[HOWARD14]`

#### Leader Role in Raft
#### Failure Scenarios

used in: CockroachDB, Etcd, Consul

### Byzantine Consensus

#### PBFT Algorithm

PBFT: Practical Byzantine Fault Tolerance, `[CASTRO99]`

#### Recovery and Checkpointing

optimize PBFT: `[BAUDET19]`, `[BUCHMAN18]`

### Summary

## Part II Conclusion
