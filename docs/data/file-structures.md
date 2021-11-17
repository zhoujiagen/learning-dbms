# Notes of **File Structures: An Object-Oriented Approach with C++**


|时间|内容|
|:---|:---|
|20211110|kick off.|

## 术语

<!-- 记录阅读过程中出现的关键字及其简单的解释. -->

## 介绍

<!-- 描述书籍阐述观点的来源、拟解决的关键性问题和采用的方法论等. -->

## 动机

<!-- 描述阅读书籍的动机, 要达到什么目的等. -->

## 概念结构

<!-- 描述书籍的行文结构, 核心主题和子主题的内容结构和关系. -->


### 1. Introduction to Design and Specification of File Structures

A **file structure** is a combination of:

- representations for data in files,
- operations for accessing the data.

#### 1.1 The Heart of File Structure Design
#### 1.2 A Short History of File Structure Design
#### 1.3 A Conceptual Toolkit: File Structure Literacy
#### 1.4 An Object-Oriented Toolkit: Making File Structures Usable
#### 1.5 Using Objects in C++

### 2. Fundamental File Processing Operations

- c stream
- c++ stream class



#### 2.1 Physical Files and Logical Files
#### 2.2 Opening Files
#### 2.3 Closing Files
#### 2.4 Reading and Writing
#### 2.5 Seeking
#### 2.6 Special Characters in Files
#### 2.7 The Unix Directory Structure
#### 2.8 Physical Devices and Logical Files
#### 2.9 File-Related Header Files

- stdio.h
- iostream.h
- fstream.h
- fcntl.h
- file.h

#### 2.10 Unix File System Commands

### 3. Secondary Storage and System Software

#### 3.1 Disks
#### 3.2 Magnetic Tape
#### 3.3 Disk versus Tape
#### 3.4 Introduction to CD-ROM
#### 3.5 Physical Organization of CD-ROM
#### 3.6 CD-ROM Strengths and Weaknesses
#### 3.7 Storage as a Hierarchy
#### 3.8 A Journey of a Byte
#### 3.9 Buffer Management
#### 3.10 I/O in Unix

### 4. Fundamental File Structure Concepts

#### 4.1 Field and Record Organization

field structures:

- fix the length of fields
- begin each field with a length indicator
- separate the fields with delimiters
- use a "keyword=value" expression to identify fields

object: data residing in memory;<br/>
record: data residing in a file.

record structures:

- make records a predictable number of bytes: fixed-length record
- make records a predictable number of fields
- begin each record with a length indicator
- use an index to keep track of addresses
- place a delimiter at the end of each record

#### 4.2 Using Classes to Manipulate Buffers



#### 4.3 Using Inheritance for Record Buffer Classes

```
IOBuffer
- VariableLengthBuffer
-- DelimitedFieldBuffer
-- LengthFieldBuffer
- FixedLengthBuffer
-- FixedFieldBuffer
```

#### 4.4 Managing Fixed-Length, Fixed-Field Buffers
#### 4.5 An Object-Oriented Class for Record Files

BufferFile

### 5. Managing Files of Records

#### 5.1 Record Access

- sequential search
- direct access

RNN: relative record number

#### 5.2 More about Record Structures

Example: a file of sales transactions (30 bytes)

- a six-digit account number of the purchaser
- six digits for the data field
- a five-character stock number for the item purchased
- a three-digit field for quantity
- a ten-position field for total cost


#### 5.3 Encapsulating Record I/O Operations in a Single Class
#### 5.4 File Access and File Organization
#### 5.5 Beyond Record Structures
#### 5.6 Portability and Standardization

- IEEE Standard formats
- XDR: External Data Representation

### 6. Organizing Files for Performance

#### 6.1 Data Compression

**Data compression** involves encoding the information in a file in such a way that it takes up less space.

##### 6.1.1 Using a Difference Notation

- find a more compact notation
- redundancy reduction

##### 6.1.2 Suppressing Repeating Sequences

- run-length encoding

##### 6.1.3 Assigning Variable-Length Codes

- Morse code
- Huffman code

##### 6.1.4 Irreversible Compression Techniques

based on the assumption that some information can be sacrificed

##### 6.1.5 Compression in Unix

- System V: pack, unpack
- Berkeley Unix: compress, uncompress

#### 6.2 Reclaiming Space in Files

modification forms:

- record addition,
- record updating: can be treated as a record deletion followed by a record addition,
- record deletion.

##### 6.2.1 Record Deletion and Storage Compaction

record deletion strategy: place **a special mark** in each deleted record.

reclaim of space from deleted records: after deleted records have accumulated for some time, a special program is used to **reconstruct the file** with all the deleted records squeezed out.

##### 6.2.2 Deleting Fixed-Length Records for Reclaiming Space Dynamically

reclaim space dynamically: reuse the space from deleted records as soon as possible

- know immediately if there are empty slots in the file,
- jump directly to one of those slots if they exist.

data structures:

- avail list: a linked list that is made up of deleted records that have becomce avaiable space within the file
- stack

distinguish between physical and conceptual structures:

- deleted, avaiable recors are not moved anywhere when they are pushed onto the stack;
- the stacking and linking are done by arranging and rearranging the links used to make one avaiable record slot point to the next.

implementation:

- place the RRN of the first available record in the header record,
- place a `*` at the beginning of the record as a deletion mark,
- follow the deletion mark, place RRN of the next record on the avail list.

##### 6.2.3 Deleting Variable-Length Records

- place a byte count at the beginning of each record,
- place a single asterisk in the first field,
- follow the deletion mark, place a binary link field pointing to the next deleted record on the avail list.

reuse a record: the record must be the right size.

##### 6.2.4 Storage Fragmentation

- internal fragmentation: wasted space within a record, for example fixed-length records.

- external fragmentation: wasted space outsides records, for example variable-length records.

storage compacton:

- coalesce the holes in the storage space,
- adopt a placement strategy.

##### 6.2.5 Placement Strategies

- first fit
- best fit: order the avail list in ascending order by size
- worst fit: arrange the avail list in descending order by size

#### 6.3 Finding Things Quickly: An Introduction to Internal Sorting and Binary Searching

develop approaches that minimize the number of disk access in sorting and searching.

##### 6.3.1 Finding THings in Simple Field and Record Files

- What is the record stored in RRN 23?
- What is the record for Jane Kelly?

##### 6.3.2 Search By Guessing: Binary Search

- `class KeyType`
- `class RecType`

##### 6.3.3 Binary Search versus Sequential Search

In general, a binary search of a file with $n$ records tasks at most $\left \lfloor \texttt{log}_{2} n \right \rfloor + 1$ comparisons, and on average approximately $\left \lfloor \texttt{log}_{2} n \right \rfloor + 1/2$ comparisons.

##### 6.3.4 Sorting a Disk File in Memory

a general class of solutions to the problem of minimizing disk usage:

- force your disk access into a sequential mode,
- perform the more complex direct accesses in memory.

##### 6.3.5 The Limitation of Binary Searching and Internal Sorting

problems:

- binary searching requires more than one or two accesses
- keeping a file sorted is very expensive
- an internal sort works only on small files

#### 6.4 Keysorting

keysort: tag sort

- read the keys from the file into memory,
- sort the keys,
- rearrange the records in the file according to the new ordering of the keys.

##### 6.4.1 Description of the Method

- `class KeyRRN`: `KeyType KEY`, `int RRN`

##### 6.4.2 Limitation of the Keysort Method

work in sorted order, not sequentially.

##### 6.4.3 Another Solution: Why Bother to write the File Back?

- index file: write out the sorted `KeyRRN` array

##### 6.4.4 Pinned Records

a pinned record is one that cannot be moved: there are references to this record, such as index.

### 7. Indexing

#### 7.1 What is an Index?

simple indexes: simple array of structures that contain the key and reference field.

an index lets you impose order on a file without rearranging the file.

examples: book index, library card catalog.

record: an object in file; <br/>
recording: a data object.


#### 7.2 A Simple Index for Entry-Sequenced Files

entry-sequenced files: the records occur in the order they are entered into the file.

example: musical recording

|Record address|Label|ID number|Title|Composer(s)|Artist(s)|
|:---|:---|:---|:---|:---|:---|
|17|LON|2312|Romeo and Juliet|Prokofiev|Maazel|

- key: Label ID = Label + ID number

#### 7.3 Using Template Classes in C++ for Object I/O

``` c++
template <class RecType>
class RecordFile: public BufferFile {};
```

#### 7.4 Object-Oriented Support for Indexed, Entry-Sequenced Files of Data Objects

##### 7.4.1 Operations Required to Maintain an Indexed File

- create the original empty index and data files
- load the index file into memory before using it
- rewrite the index file from memory after using it
- add data records to the data file
- delete records from the data file
- update records in the data file
- update the index to reflect changes in the data file.

##### 7.4.2 Class TextIndexedFile

support files of data objects with primary keys that are strings.

##### 7.4.3 Enhancements to Class TextIndexedFile

- other types of keys
- data object class hierarchies
- multirecord index files
- optimization of operations

#### 7.5 Indexes That Are Too Large to Hold in Memory

- a hashed organization
- a tree-structured, or multilevel, index

#### 7.6 Indexing to Provide Access by Multiple Keys

secondary key -> primary key

#### 7.7 Retrieval Using Combinations of Secondary Keys

- intersections
- unions

#### 7.8 Improvding the Secondary Index Structure: Inverted Lists

##### 7.8.1 A First Attempt at a Solution

associate an array of references with each secondary key.

##### 7.8.2 A Better Solution: Linking the List of References

inverted lists: backward from a secondary key to the primary key to the record itself.

seconday index records:

- a secondary key field,
- a field containing the RRN of the first corresponding primary key reference in the inverted list.

the actual primary key reference associated with each secondary key would be stored in a seperate entry-sequenced file.

#### 7.9 Selective Indexes

selective index: containes only parts of the record collection, for example:

- the titles of classic recording,
- recording released prior to 1970.

#### 7.10 Binding

At what point is the the key bound to the physical address of its associated records?

- at the time the files are constructed,
- at the time that they are used.

### 8. Cosequential Processing and the Sorting of Large Files

#### 8.1 An Object-Oriented Model for Implementing Cosequential Processes

##### 8.1.1 Matching Names in Two Lists
##### 8.1.2 Merging Two Lists
##### 8.1.3 Summary of the Cosequential Processing Model

#### 8.2 Application of the Model to a General Ledger Program

##### 8.2.1 The Problem
##### 8.2.2 Application of the Model to the Ledger Program

#### 8.3 Extension of the Model to Include Multiway Merging

##### 8.3.1 A K-way Merge Algorithm
##### 8.3.2 A Selective Tree for Merging Large Numbers of Lists

#### 8.4 A Second Look at Sorting in Memory

##### 8.4.1 Overlapping Processing and I/O: Heapsort
##### 8.4.2 Building the Heap while Reading the File
##### 8.4.3 Sorting white Writing to the File

#### 8.5 Merging as a Way of Sorting Large Files on Disk

##### 8.5.1 How Much Time Does a Merge Sort Take?
##### 8.5.2 Sorting a File That Is Ten Times Larger
##### 8.5.3 The Cost of Increasing the File Size
##### 8.5.4 Hardware-Based Improvement
##### 8.5.5 Decreasing the Number of Seeks Using Multiple-Step Merges
##### 8.5.6 Increasing Run Lengths Using Replacement Selection
##### 8.5.7 Replacement Selection Plus Multistep Merging
##### 8.5.8 Using Two Disk Drives with Replacement Selection
##### 8.5.9 More Drives? More Processors?
##### 8.5.10 Effects of Multiprogramming
##### 8.5.11 A Conceptual Toolkit for External Sorting


#### 8.6 Sorting Files on Tape

##### 8.6.1 The Balanced Merge
##### 8.6.2 The K-way Balanced Merge
##### 8.6.3 Multiphase Merges
##### 8.6.4 Tapes versus Disks for External Sorting

#### 8.7 Sort-Merge Packages
#### 8.8 Sorting and Cosequential Processing in Unix

##### 8.8.1 Sorting and Merging in Unix
##### 8.8.2 Cosequential Processing Utilities in Unix

### 9. Multi-level Indexing and B-trees

#### 9.1 Introduction: The Invention of the B-Tree
#### 9.2 Statement of the Problem
#### 9.3 Indexing with Binary Search Trees

##### 9.3.1 AVL Trees
##### 9.3.2 Paged Binary Trees
##### 9.3.3 Problems with Paged Trees

#### 9.4 Multilevel Indexing, a Better Approach to Tree Indexes
#### 9.5 B-trees: Working up from the Bottom
#### 9.6 Example of Creating a B-Tree
#### 9.7 An Object-Oriented Representation of B-Trees

##### 9.7.1 Class BTreeNode: representing B-Tree Nodes in Memory
##### 9.7.2 Class BTree: Supporting Files of B-Tree Nodes

#### 9.8 B-Tree Methods Search, Insert, and Others

##### 9.8.1 Searching
##### 9.8.2 Insetiong
##### 9.8.3 Create, Open, and Close
##### 9.8.4 Testing the B-Tree

#### 9.9 B-Tree Nomenclature
#### 9.10 Formal Definition of B-Tree Properties
#### 9.11 Worst-Case Search Depth
#### 9.12 Deletion, Merging, and Redistribution

##### 9.12.1 Redistribution

#### 9.13 Redistribution During Insertion: A Way to Improve Storage Utilization
#### 9.14 B* Trees
#### 9.15 Buffering of Pages: Virtual B-Trees

##### 9.15.1 LRU Replacement
##### 9.15.2 Replacement Based on Page Height
##### 9.15.3 Importance of Virtual B-Trees

#### 9.16 Variable-Length Records and Keys

### 10. Indexed Sequential File Access and Prefix B+ trees

#### 10.1 Indexed Sequential Access
#### 10.2 Maintaining a Sequence Set

##### 10.2.1 The Use of Blocks
##### 10.2.2 Choice of Block Size

#### 10.3 Adding a Simple Index to the Sequence Set
#### 10.4 The Content of the Index: Separators Instead of Keys
#### 10.5 The Simple Prefix B+ Tree
#### 10.6 Simple Prefix B+ Tree Maintenance

##### 10.6.1 Changes Localized to Single Blocks in the Sequence Set
##### 10.6.2 Changes Involving Multiple Blocks in the Sequence Set

#### 10.7 Index Set Block Size
#### 10.8 Internal Structure of Index Set Blocks: A Variable-Order B-Tree
#### 10.9 Loading a Simple Prefix B+ Tree
#### 10.10 B+ Tree
#### 10.11 B-Trees, B+ Trees, and Simple Prefix B+ Trees in Perspective

### 11. Hashing

#### 11.1 Introduction

##### 11.1.1 What is Hashing?
##### 11.1.2 Collisions

#### 11.2 A Simple Hashing Algorithm
#### 11.3 Hashing Functions and Record Distributions

##### 11.3.1 Distributing Records among Addreses
##### 11.3.2 Some Other Hashing Methods
##### 11.3.3 Predicting the Distribution of Records
##### 11.3.4 Predicting Collisions for a Full File

#### 11.4 How Much Extra Memory Should Be Used?

##### 11.4.1 Packing Density
##### 11.4.2 Predicting Collisions for Different Packing Densities

#### 11.5 Collision Resolution by Progressive Overflow

##### 11.5.1 How Progressive Overflow Works
##### 11.5.2 Search Length

#### 11.6 Storing More Than One Record per Address: Buckets

##### 11.6.1 Effects of Buckets on Performance
##### 11.6.2 Implementation Issues

#### 11.7 Making Deletions

##### 11.7.1 Tombstones for Handling Deletions
##### 11.7.2 Implications of Tombstones for Insertion
##### 11.7.3 Effects of Deletions and Additions on Performance

#### 11.8 Other Collision Resolution Techniques

##### 11.8.1 Double Hasing
##### 11.8.2 Chained Progressive Overflow
##### 11.8.3 Chaining with a Separate Overflow Area
##### 11.8.4 Scatter Tables: Indexing Revisited

#### 11.9 Patterns of Record Access

### 12. Extendible Hashing

#### 12.1 Introduction
#### 12.2 How Extendible Hashing Works

##### 12.2.1 Tries
##### 12.2.2 Turning the Trie into a Directory
##### 12.2.3 Splitting to Handle Overflow

#### 12.3 Implementation

##### 12.3.1 Creating the Addresses
##### 12.3.2 Classes for Representing Bucket and Directory Objects
##### 12.3.3 Bucket and Directory Operations
##### 12.3.4 Implementation Summary

#### 12.4 Deletion

##### 12.4.1 Overview of the Deletion Process
##### 12.4.2 A Procedure for Finding Buddy Buckets
##### 12.4.3 Collapsing the Directory
##### 12.4.4 Implementing the Deletion Operations
##### 12.4.5 Summary of the Deletion Operation

#### 12.5 Extendible Hashing Performance

##### 12.5.1 Space Utilization for Buckets
##### 12.5.2 Space Utilization for the Directory

#### 12.6 Alternative Approaches

##### 12.6.1 Dynamic Hashing
##### 12.6.2 Linear Hashing
##### 12.6.3 Approaches to Controlling Splitting

### Appendix A. File Structures on CD-ROM

> skip

### Appendix B. ASCII Table

### Appendix C. Formatted Output with C++ Stream Classes

### Appendix D. Simple File Input/Output Examples

- Listc.cpp:    program to read and display the contents of a file using C streams
- Listcpp.cpp:  program to read and display the contents of a file using C++ stream classes
- Person.h:     definition for class Person, including code for constructor
- Writestr.cpp: write Person objects into a stream file
- Readdel.cpp:  read Person objects with fields delimited by '|'
- Readvar.cpp:  read variable length records and break up into Person objects
- Writeper.cpp: function to write a preson to a text file
- Readper.cpp:  function to prompt user and read fields of a Person

### Appendix E. Classes for Buffer Manipulation

- Person.h:     definition for class Person
- Person.cpp:   code for class Person
- Deltext.h:    definition for class DelimitedTextBuffer
- Deltext.cpp:  code for class DelimitedTextBuffer
- Lentext.h:    definition for class LengthTextBuffer
- Lentext.cpp:  code for class LengthTextBuffer
- Fixtext.h:    definition for class FixedTextBuffer
- Fixtext.cpp:  code for class FixedTextBuffer
- Test.cpp:     test program for all buffer classes

### Appendix F. A Class Hierarchy for Buffer Input/Output

- Person.h:     definition for class Person
- Person.cpp:   code for class Person
- Iobuffer.h:   definition for class IOBuffer
- Iobuffer.cpp: code for class IOBuffer
- Varlen.h:     definition for class VariableLengthBuffer
- Varlen.cpp:   code for class VariableLengthBuffer
- Delim.h:      definition for class DelimFieldBuffer
- Delim.cpp:    code for class DelimFieldBuffer
- Length.h:     definition for class LengthFieldBuffer
- Length.cpp:   code for class LengthFieldBuffer
- Fixlen.h:     definition for class FixedLengthBuffer
- Fixlen.cpp:   code for class FixedLengthBuffer
- Fixfld.h:     definition for class FixedFieldBuffer
- Fixfld.cpp:   code for class FixedFieldBuffer
- Buffile.h:    definition for class BufferFile
- Buffile.cpp:  code for class BufferFile
- Recfile.h:    template class RecordFile
- Test.cpp:     test program for Person and RecordFile including template function


### Appendix G. Single Level Indexing of Records by Key

- Recordng.h:   definition of class Recording with composite key
- Recordng.cpp: code for class Recording
- Makerec.cpp:  program to create a sample data file of recordings
- Textind.h:    definition of class TextIndex
- Textind.cpp:  code for class TextIndex
- RecFile.h:    template class RecordFile
- Makeind.cpp:  program to make an index file for a file of recordings
- Tindbuff.h:   definition of class TextIndexBuffer
- Tindbuff.cpp: code for class TextIndexBuffer
- Indfile.h:    template class TextIndexedFile
- Strclass.h:   Definition of class String
- Strclass.cpp: code for class String
- Simpind.h:    definition of template class SimpleIndex
- Simpind.tc:   code for template class SimpleIndex

### Appendix H. Cosequential Processing

- Coseq.h:      definition of class SosequentialProcess
- Strlist.h:    definition of class StringListProcess
- Strlist.cpp:  code for class StringListProcess
- Match.cpp:    main program for string matching and merging application
- Mastrans.h:   definition and code for template class MasterTransactionProcess
- Ledgpost.h:   definition of class LedgerProcess
- Ledgpost.cpp: code for class LedgerProcess
- Ledger.h:     definition of classes Ledger and Journal
- Ledger.cpp:   code for classes Ledger and Journal
- Heapsort.cpp: code for class Heap and Heapsort

### Appendix I. Multi-level Indexing with B-Trees

- Btnode.h:     definition of template class BTreeNode
- Btnode.tc:    method bodies for template class BTreeNode
- Btree.h:      definition of template class BTree
- Btree.tc:     method bodies for template class BTree
- Tstbtree.cpp: program to test B-tree insertion

### Appendix J. Extendible Hashing

- Hash.h:         functions Hash and MakeAddress
- Hash.cpp:       implementation of functions Hash and MakeAddress
- Bucket.h:       definition of class Bucket
- Bucket.cpp:     implementation of class Bucket
- Directory.h:    definition of class Directory
- Directory.cpp:  implementation of class Directory
- Tsthash.cpp:    program to test extendible hashing

## 总结

<!-- 概要记录书籍中如何解决关键性问题的. -->

## 应用

<!-- 记录如何使用书籍中方法论解决你自己的问题. -->

## 文献引用

<!-- 记录相关的和进一步阅读资料: 文献、网页链接等. -->

## 其他备注
