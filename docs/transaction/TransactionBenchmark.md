# Benchmarks on Database Transactions

## TPC

> The TPC is a non-profit corporation focused on developing data-centric benchmark standards and disseminating objective, verifyable data to the industry.

SUMMARY: http://www.tpc.org/tpc_documents_current_versions/current_specifications.asp

Category:
  OLTP: [A], [B], C, E
  Decision Support: [D], DS
  Data Integration: DI, H, [R]
  Data Virtualization: VMS, HCI, V
  Big Data: BB, HS,
  IoT: IoT
  ECommerce: [W]


### TPC-A [Obsolete]

https://www.tpc.org/tpca/default5.asp

https://www.tpc.org/tpc_documents_current_versions/pdf/tpca_v2.0.0.pdf

TPC-A measures performance in **update-intensive** database environments typical
in **on-line transaction processing** applications. (Obsolete as of 6/6/95)

```
Branch: Branch_ID, Branch_Balance

Teller: Teller_ID, Branch_ID, Teller_Balance

Account: Account_ID, Branch_ID, Account_Balance

History: Account_ID, Teller_ID, Branch_ID, Amount, Time_Stamp
```


###  TPC-B [Obsolete]
http://www.tpc.org/tpcb/default.asp

TPC-B measures throughput in terms of how many transactions per second
a system can perform. (Obsolete as of 6/6/95)

### TPC-C
http://www.tpc.org/tpcc/default.asp

Approved in July of 1992, TPC Benchmark C is an on-line transaction processing (OLTP) benchmark.

### TPC-D [Obsolete]
http://www.tpc.org/tpcd/default.asp

TPC-D represents a broad range of **decision support (DS)** applications that
require complex, long running queries against large complex data structures. (Obsolete as of 4/6/99)

### TPC-DI
http://www.tpc.org/tpcdi/default.asp

TPC-DI is a benchmark for **Data Integration**
The TPC-DI benchmark combines and transforms data extracted from
an On-Line Transaction Processing (OTLP) system along with other sources of data,
and loads it into a data warehouse.

### TPC-DS
http://www.tpc.org/tpcds/default.asp

TPC-DS is a **Decision Support** Benchmark
The TPC Benchmark DS (TPC-DS) is a decision support benchmark that
models several generally applicable aspects of a decision support system,
including queries and data maintenance.

TPC-DS Version 2 enables emerging technologies, such as Big Data systems, to execute the benchmark.

### TPC-E
http://www.tpc.org/tpce/default.asp

Approved in February of 2007, TPC Benchmark E is an **on-line transaction processing (OLTP)** benchmark.

### TPC-H
http://www.tpc.org/tpch/default.asp

TPC-H is a **Decision Support** Benchmark

### TPC-R [Obsolete]
http://www.tpc.org/tpcr/default.asp

TPC-R is a business reporting, **decision support** benchmark. (Obsolete as of 1/1/2005)

### TPC-VMS
http://www.tpc.org/tpcvms/default.asp

TPC-VMS is a **Data Virtualization** Benchmark
Introduced in 2012, the TPC Virtual Measurement Single System Specification (TPC-VMS)
leverages the TPC-C, TPC-E, TPC-H and TPC-DS Benchmarks
by adding the methodology and requirements
for running and reporting performance metrics for virtualized databases.

### TPC-W [Obsolete]
http://www.tpc.org/tpcw/default.asp

TPC-W is a transactional web **e-Commerce** benchmark. (Obsolete as of 4/28/05)



### TPCx-BB
http://www.tpc.org/tpcx-bb/default.asp

TPCx-BB is a Big Data Benchmark
TPCx-BB Express Benchmark BB (TPCx-BB) measures the performance of Hadoop-based Big Data systems systems.

### TPCx-HCI
http://www.tpc.org/tpcx-hci/default.asp

TPCx-HCI is a Benchmark for Hyper-Converged Infrastructure
The TPC Express Benchmark HCI (TPCx-HCI) benchmark measures
the performance of Hyper-Converged Infrastructure clusters under a demanding database workload.
It stresses the virtualized hardware and software of converged storage, networking,
and compute resources of the HCI platform.

### TPCx-HS
v1: http://www.tpc.org/tpcx-hs/default.asp?version=1
v2: http://www.tpc.org/tpcx-hs/default.asp

Introduced in 2016 TPCx-HS V2 is based on TPCx-HS V1 with support for Apache Spark -
a popular platform for in-memory data processing that enables real-time analytics on Apache Hadoop.

### TPCx-IoT
http://www.tpc.org/tpcx-iot/default.asp

TPCx-IoT, the industry’s first benchmark which enables direct comparison of
different software and hardware solutions for IoT gateways.

### TPCx-V
http://www.tpc.org/tpcx-v/default.asp

TPCx-V is a Virtualization Benchmark for Database Workloads
The TPC Express Benchmark V (TPCx-V) benchmark measures the performance of
a virtualized server platform under a demanding database workload.


## TATP

Telecom Application Transaction Processing Benchmark
http://tatpbenchmark.sourceforge.net/
