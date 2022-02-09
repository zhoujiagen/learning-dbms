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
