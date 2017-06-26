# Advanced SQL

## SQL Data Types and Schemas
``` sql
date '2001-04-25';
time '09:30:00';
timestamp '2001-04-25 10:29:01.45';

create type Dollars as numeric(12,2) final;
create type Pounds as numeric(12,2) final;
create table account (
  account_number char(10),
  branch_name char(15),
  balance Dollars
)
```

## Integrity Constraints
- `not null`
``` sql
account_number char(10) not null;
balance numeric(12,2) not null;
```
- `unique`: The unique specification says that attributes A1, A2,..., Am form a candidate key;
``` sql
unique (A1, A2,..., Am)
/* no two tuples in the relation can be equal on all the primary-key attributes */
```
- `check`
``` sql
create table student (
  name          char(15) not null,
  student_id    char(10),
  degree_level  char(15),
  primary key (student_id),
  check (degree_level in ('Bachelors', 'Masters', 'Doctorate'))
)

create table account (
  account_number      char(10),
  branch_name         char(15),
  balance             numeric(16,2),
  primary key (branch_name),
  foreign key (branch_name) references branch,
  check (balance >= 0)
)
```
- `primary key`
- `foreign key`

## Authorization
- Authorization to read data
- Authorization to insert new data
- Authorization to update data
- Authorization to delete data
``` sql  
grant <privilege list> on <relation name or view name> to <user/role list>;
grant select on account to John, Mary;
grant select on database to 'fenlan'@'localhost' identified by 'password';

revoke <privilege list> on <relation name or view name> from <user/role list>;
/* 撤销权限 */
```

## Embedded SQL
> 看书吧，我觉得不太重要<br>

## Dynamic SQL
> 大概意思就是其他语言调用数据库连接，比如用java, c, php, python等操作数据库<br>
<br>
> 还有一些扩展内容，我感觉不考，所以没写<br>
