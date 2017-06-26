# SQL

## Parts of SQL Language
- Data-definition language
- Interactive data-manipulation language
- Integrity
- View definition
- Transaction control
- Embedded(嵌入) SQL and dynamic(动态) SQL
- Authorization

## Basic Schema Definition in SQL
``` sql
insert into account values ('A-9732', 'Perryridge', 1200);

delete from table_name;  /* delete tuples from a relation */
drop table table_name;  /* remove a relation from an SQL database */

create table customer (
  customer_name   char(20),
  customer_street char(30),
  customer_city   char(30),
  primary key (customer_name)
);

alter table table_name add attribute domain;
alter table table_name drop attribute;

select A1, A2,..., An from r1, r2,..., rm where p;

select distinct branch_name from loan;  /* elimination of duplicates(消除重复) */
select all branch_name from loan;  /* 不消除重复 */

select loan_number, branch_name, amount*100 from loan;

select loan_number from loan where branch_name = 'Perryridge' and amount > 1200;
select loan_number from loan where branch_name = 'Perryridge' or amount > 1200;
select loan_number from loan where branch_name = 'Perryridge' not amount > 1200;

select loan_number from loan where amount (not)between 90000 and 100000;
select loan_number from loan where amount <= 100000 and amount >= 90000;

select customer_name, borrower.loan_number as loan_id, amount
from borrower, loan
where borrower.loan_number = loan.loan_number;

select customer_name, T.loan_number, S.amount
from borrower as T, loan as S
where T.loan_number = S.loan_number;

select distinct customer_name
from borrower, loan
where borrower.loan_number = loan.loan_number and branch_name = 'Perryridge'
order by customer_name;  /* list in alphabetic order(字典顺序) */

select * from loan order by amount desc, loan_number asc; /* 先amount降序，相同时loan_number升序 */
```

## String Operation
- Percent(%): The % character matches any substring
- Underscore(_ ): The _ character matches any character
<br>
- `Perry%` matches any string begining with "Perry".<br>
- `%idge%` matches any string containing "idge".<br>
- `---` matches any string of exactly three character.<br>
- `---%` matches any string of at least three character.<br>

``` sql
select customer_name from customer where customer_street like '%Main%';
```

## Set Operation
``` sql
(select customer_name from depositor) union (select customer_name from borrower);
/* automatically eliminates duplicates(自动消除重复) */
(select customer_name from depositor) union all (select customer_name from borrower);
/* retain all duplicates(保持重复) */

/* intersect(交) */
(select customer_name from depositor) intersect (select customer_name from borrower);
(select customer_name from depositor) intersect all (select customer_name from borrower);

(select distinct customer_name from depositor) except (select customer_name from borrower);
(select customer_name from depositor) except all (select customer_name from borrower);

```

## Aggregate Functions
- Average: `avg`
- Minimum: `min`
- Maximum: `max`
- Total: `sum`
- Count: `count`
``` sql
select avg(balance) from account where branch_name = 'Perryridge';
select branch_name, avg(balance) from account group by branch_name;

select branch_name, count(distinct customer_name) from depositor, account
where depositor.account_number = account.account_number group by branch_name;

select branch_name, avg(balance) from account group by branch_name having avg(balance) > 1200;
/* those branches where the average account balance is more than 1200 */
/* apply having clause after groups have been formed */
```

## Null Values
``` sql
select loan_number from loan where amount is null;
```

## Nested Subqueries
``` sql
select distinct customer_name from borrower where customer_name in (select customer_name from depositor);
select distinct customer_name from depositor where customer_name not in ('Smith', 'Jones');

select branch_name from branch where assets > some (select assets from branch where branch_city = 'Brooklyn');
select branch_name from branch where assets > all (select assets from branch where branch_city = 'Brooklyn');

/* test for empty relations */
select customer_name from borrower
where (not) exists (select * from depositor where depositor.customer_name = borrower.customer_name);

/* test for the Absence of Duplicates Tuples */
select T.customer_name from depositor as T
where (not) unique (select R.customer_name from account, depositor as R
                    where T.customer_name = R.customer_name and R.account_number = account.account_number);
/* The unique construct returns the value true if the argument subquery contains no duplicate tuples */
```

## Complex Queries
``` sql
/* derived relations */
select branch_name, avg_balance
from (select branch_name, avg(balance)
      from account
      group by branch_name)
      as branch_avg(branch_name, avg_balance)
where avg_balance > 1200;

with max_balance (value) as select max(balance) from account;
select account_number from account, max_balance where account.balance = max_balance.value;
/* The with clause, introduced in SQL:1999, is currently supports only by some databases. */
/* nested subqueries would have made the query harder to read and understand. */
/* without with clause, queries would be more complicated and harder to understand. */
```

## Views
``` sql
create view all_customer as
  (select branch_name, customer_name
   from depositor, account
   where depositor.account_number = account.account_number)
  union
  (select branch_name, customer_name
   from borrower, loan
   where borrower.loan_number = loan.loan_number);

select customer_name from all_customer where branch_name = 'Perryridge';

create view perryridge_customer as
  select customer_name from all_customer where branch_name = 'Perryridge';
```

## Modification of the Database
``` sql
delete from r where P;  /* delete tuples from a relation */

insert into account values ('A-9732', 'Perryridge', 1200);
insert into account (account_number, branch_name, balance) values ('A-9732', 'Perryridge', 1200);

update account set balance = balance * 1.05 where balance >= 1000;
update account set balance = balance * 1.05 where balance > (select avg(balance) from account);
update account set balance = case
                                when balance <= 10000 then balance * 1.05
                                else balance * 1.06
                             end;
```

## Transaction
- `Commit work` commits the current transaction; that is, it makes the update performed.
- `Rollback word` causes the current transaction to be rolled back; that is, it undoes
all the updates performed.
