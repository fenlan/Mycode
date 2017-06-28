# Nosql

## What's Meaning?
- `Nosql`: not only sql

## ACID Rules
- `Atomic`
- `Consistent`
- `Isolated`
- `Durable`

## What is Nosql
- `No-relational` database management systems
- `Different` from traditional RDBMS in some significant ways.
- `Core(核心)` of Nosql
> 1. `Hash function` mathematical algorithm – take variable length of Input and
produce a consistent, fixedlength Output. <br>
> 2. `Key/Value` pair is stored for later retrieval of record(不知道如何翻译).<br>

- `Designed for`
> 1. Distributed data(分散的数据)<br>
> 2. very large scale(规模) of data storing needs <br>

- These type of data storing may not require fixed schema, avoid join operations
and typically scale horizontally.<br>
> 这些类型的数据存储可能不需要固定模式，避免连接操作，并且通常水平地缩放.<br>

## Why Nosql
- 数据量大
- 数据类型复杂
- 很难确定数据的关系
> 插个题外话，或许这就是为什么python那么适合于大数据，python 的list和dictionary就是这样的特性<br>

## CAP Theorem
- `Consistency`
- `Availablity`
- `Partition Tolerance`(分区容忍)

## Advantages
- `High Scalability`(高扩展)
- `Distributed Computing`(分散计算)
> 没有关系数据库那样复杂的约束，Nosql避免连接，没有太多相互约束，因此扩展性很好，可分散计算<br>

- `Lower Cost`
- `Schema Flexibility`(模式灵活)
- `Semi-Structured Data`(半结构化数据)
- `No Complicated Relationship`(没有复杂关系)

## Disadvantages
- `No Standardization`
- `Limited Query Capabilities`
- `Eventual Consistent is not intuitive to program`(最终一致性不直观)

## Categories of NoSQL database
- `Document Oriented`
- `XML database`
- `Graph databases`
- `Key-value store`
