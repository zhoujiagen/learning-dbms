# Notes of **Database Systems: The Complete Book**


|时间|内容|
|:---|:---|
|2022-02-09| kick off. |

## 术语

<!-- 记录阅读过程中出现的关键字及其简单的解释. -->

## 介绍

<!-- 描述书籍阐述观点的来源、拟解决的关键性问题和采用的方法论等. -->

## 动机

<!-- 描述阅读书籍的动机, 要达到什么目的等. -->

## 概念结构

<!-- 描述书籍的行文结构, 核心主题和子主题的内容结构和关系. -->

#### 1 The Worlds of Database Systems
##### 1.1 The Evolution of Database Systems
##### 1.2 Overview of a Database Management System
##### 1.3 Outline of Database-System Studies
##### 1.4 References for Chapter 1

### PART I: Relational Database Modeling

#### 2 The Relational Model of Data
##### 2.1 An Overview of Data Models
##### 2.2 Basics of the Relational Model
##### 2.3 Defining a Relation Schema in SQL
##### 2.4 An Algebraic Query Language
##### 2.5 Constraints on Relations
##### 2.6 Summary of Chapter 2
##### 2.7 References for Chapter 2

#### 3 Design Theory for Relational Databases
##### 3.1 Functional Dependencies
##### 3.2 Rules About Functional Dependencies
##### 3.3 Design of Relational Database Schemas
##### 3.4 Decomposition: The Good, Bad, and Ugly
##### 3.5 Third Normal Form
##### 3.6 Multivalued Dependencies
##### 3.7 An Algorithm for Discovering MVD's
##### 3.8 Summary of Chapter 3
##### 3.9 References for Chapter 3

#### 4 High-Level Database Models
##### 4.1 The Entity/Relationship Model
##### 4.2 Design Principles
##### 4.3 Constraints in the E/R Model
##### 4.4 Weak Entity Sets
##### 4.5 From E/R Diagrams to Relational Designs
##### 4.6 Converting Subclass Structures to Relations
##### 4.7 Unified Modeling Language
##### 4.8 From UML Diagrams to Relations
##### 4.9 Object Definition Language
##### 4.10 From ODL Designs to Relational Designs
##### 4.11 Summary of Chapter 4
##### 4.12 References for Chapter 4

### PART II: Relational Database Programming

#### 5 Algebraic and Logical Query Languages
##### 5.1 Relational Operations on Bags
##### 5.2 Extended Operators of Relational Algebra
##### 5.3 A Logic for Relations
##### 5.4 Relational Algebra and Datalog
##### 5.5 Summary of Chapter 5
##### 5.6 References for Chapter 5

#### 6 The Database Language SQL
##### 6.1 Simple Queries in SQL
##### 6.2 Queries Involving More Than One Relation
##### 6.3 Subqueries
##### 6.4 Full-Relation Operations
##### 6.5 Database Modifications
##### 6.6 Transactions in SQL
##### 6.7 Summary of Chapter 6
##### 6.8 References for Chapter 6

#### 7 Constraints and Triggers
##### 7.1 Keys and Foreign Keys
##### 7.2 Constraints on Attributes and Tuples
##### 7.3 Modification of Constraints
##### 7.4 Assertions
##### 7.5 Triggers
##### 7.6 Summary of Chapter 7
##### 7.7 References for Chapter 7

#### 8 Views and Indexes
##### 8.1 Virtual Views
##### 8.2 Modifying Views
##### 8.3 Indexes in SQL
##### 8.4 Selection of Indexes
##### 8.5 Materialized Views
##### 8.6 Summary of Chapter 8
##### 8.7 References for Chapter 8

#### 9 SQL in a Server Environment
##### 9.1 The Three-Tier Architecture
##### 9.2 The SQL Environment
##### 9.3 The SQL/Host-Language Interface
##### 9.4 Stored Procedures
##### 9.5 Using a Call-Level Interface
##### 9.6 JDBC
##### 9.7 PHP
##### 9.8 Summary of Chapter 9
##### 9.9 References for Chapter 9

#### 10 Advanced Topics in Relational Databases
##### 10.1 Security and User Authorization in SQL
##### 10.2 Recursion in SQL
##### 10.3 The Object-Relational Model
##### 10.4 User-Defined Types in SQL
##### 10.5 Operations on Object-Relational Data
##### 10.6 On-Line Analytic Processing
##### 10.7 Data Cubes
##### 10.8 Summary of Chapter 10
##### 10.9 References for Chapter 10

### PART III: Modeling and Programming for Semistructured Data

#### 11 The Semistructured-Data Model
##### 11.1 Semistructured Data
##### 11.2 XML
##### 11.3 Document Type Definitions
##### 11.4 XML Schema
##### 11.5 Summary of Chapter 11
##### 11.6 References for Chapter 11

#### 12 Programming Languages for XML
##### 12.1 XPath
##### 12.2 XQuery
##### 12.3 Extensible Stylesheet Language
##### 12.4 Summary of Chapter 12
##### 12.5 References for Chapter 12

### PART IV: Database System Implementation

#### 13 Secondary Storage Management
##### 13.1 The Memory Hierarchy
##### 13.2 Disks
##### 13.3 Accelerating Access to Secondary Storage
##### 13.4 Disk Failures
##### 13.5 Arranging Data on Disk
##### 13.6 Representing Block and Record Addresses
##### 13.7 Variable-Length Data and Records
##### 13.8 Record Modifications
##### 13.9 Summary of Chapter 13
##### 13.10 References for Chapter 13

#### 14 Index Structures
##### 14.1 Index-Structure Basics
##### 14.2 B-Trees
##### 14.3 Hash Tables
##### 14.4 Multidimensional Indexes
##### 14.5 Hash Structures for Multidimensional Data
##### 14.6 Tree Structures for Multidimensional Data
##### 14.7 Bitmap Indexes
##### 14.8 Summary of Chapter 14
##### 14.9 References for Chapter 14

#### 15 Query Execution
##### 15.1 Introduction to Physical-Query-Plan Operators
##### 15.2 One-Pass Algorithms
##### 15.3 Nested-Loop Joins
##### 15.4 Two-Pass Algorithms Based on Sorting
##### 15.5 Two-Pass Algorithms Based on Hashing
##### 15.6 Index-Based Algorithms
##### 15.7 Buffer Management
##### 15.8 Algorithms Using More Than Two Passes
##### 15.9 Summary of Chapter 15
##### 15.10 References for Chapter 15

#### 16 The Query Compiler
##### 16.1 Parsing and Preprocessing
##### 16.2 Algebraic Laws for Improving Query Plans
##### 16.3 From Parse Trees to Logical Query Plans
##### 16.4 Estimating the Cost of Operations
##### 16.5 Introduction to Cost-Based Plan Selection
##### 16.6 Choosing an Order for Joins
##### 16.7 Completing the Physical-Query-Plan
##### 16.8 Summary of Chapter 16
##### 16.9 References for Chapter 16

#### 17 Coping With System Failures
##### 17.1 Issues and Models for Resilient Operation
##### 17.2 Undo Logging
##### 17.3 Redo Logging
##### 17.4 Undo/Redo Logging
##### 17.5 Protecting Against Media Failures
##### 17.6 Summary of Chapter 17
##### 17.7 References for Chapter 17

#### 18 Concurrency Control
##### 18.1 Serial and Serializable Schedules
##### 18.2 Conflict-Serializability
##### 18.3 Enforcing Serializability by Locks
##### 18.4 Locking Systems With Several Lock Modes
##### 18.5 An Architecture for a Locking Scheduler
##### 18.6 Hierarchies of Database Elements
##### 18.7 The Tree Protocol
##### 18.8 Concurrency Control by Timestamps
##### 18.9 Concurrency Control by Validation
##### 18.10 Summary of Chapter 18
##### 18.11 References for Chapter 18

#### 19 More About Transaction Management
##### 19.1 Serializability and Recoverability
##### 19.2 Deadlocks
##### 19.3 Long-Duration Transactions
##### 19.4 Summary of Chapter 19
##### 19.5 References for Chapter 19

#### 20 Parallel and Distributed Databases
##### 20.1 Parallel Algorithms on Relations
##### 20.2 The Map-Reduce Parallelism Framework
##### 20.3 Distributed Databases
##### 20.4 Distributed Query Processing
##### 20.5 Distributed Commit
##### 20.6 Distributed Locking
##### 20.7 Peer-to-Peer Distributed Search
##### 20.8 Summary of Chapter 20
##### 20.9 References for Chapter 20

### PART V: Other Issues in Management of Massive Data

#### 21 Information Integration
##### 21.1 Introduction to Information Integration
##### 21.2 Modes of Information Integration
##### 21.3 Wrappers in Mediator-Based Systems
##### 21.4 Capability-Based Optimization
##### 21.5 Optimizing Mediator Queries
##### 21.6 Local-as-View Mediators
##### 21.7 Entity Resolution
##### 21.8 Summary of Chapter 21
##### 21.9 References for Chapter 21

#### 22 Data Mining
##### 22.1 Frequent-Itemset Mining
##### 22.2 Algorithms for Finding Frequent Itemsets
##### 22.3 Finding Similar Items
##### 22.4 Locality-Sensitive Hashing
##### 22.5 Clustering of Large-Scale Data
##### 22.6 Summary of Chapter 22
##### 22.7 References for Chapter 22

#### 23 Database Systems and the Internet
##### 23.1 The Architecture of a Search Engine
##### 23.2 PageRank for Identifying Important Pages
##### 23.3 Topic-Specific PageRank
##### 23.4 Data Streams
##### 23.5 Data Mining of Streams
##### 23.6 Summary of Chapter 23
##### 23.7 References for Chapter 23

## 总结

<!-- 概要记录书籍中如何解决关键性问题的. -->

## 应用

<!-- 记录如何使用书籍中方法论解决你自己的问题. -->

## 文献引用

<!-- 记录相关的和进一步阅读资料: 文献、网页链接等. -->

## 其他备注
