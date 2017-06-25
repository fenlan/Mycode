# Relationnal Model

## Database Schema(模式)
> Account_schema = (account_number, branch_name, balance)<br>
> Branch_schema = (branch_name, branch, assets)<br>
> Customer_schema = (customer_name, customer_street, customer_city)<br>

## Keys
- `Candidate keys(候选码)`: Such minimal superkeys are called candidate keys.
- `Primary key`: identifying tuples within a relation.
- `Foreign key`: A relation schema may include among its attributes the primary
key of another relation schema. The attribute is called a `foreign key`.
- `Referencing relation(参照关系)`
- `Referenced relation(被参照关系)`
> 提示一下：foreign key 一定是被参照关系的主码<br>
> 提示一下：Order of tuples is irrelevant(不相干) (tuples may be stored in an arbitrary(随意) order)<br>

## Fundamental Relational-Algebra Operation(基本关系代数运算)
### The Select Operation
- The `select` operation selects tuples that satisfy a given predicate(谓词).
![Select Operation](images/select.png)<br>

### The Project(投影) Operation
- Suppose we want list all loan numbers and the amount of the loans, but do not
care about the branch name. The `project` operation allows us to produce this relation.
> 投影操作：取一个属性的所有值或者多个属性的所有值<br>

![Project Operation](images/project.png)<br>

### The Union(并) Operation
![Union Operation](images/union.png)<br>
- The relation `r` and `s` must be of the same arity(元). That is, they must have
the same number of attributes. (两个关系有相同元)
- The domains of the ith attribute of `r` and the ith attribut of `s` must be the
same, for all i. (两个关系的相同元的域相同，即是都是整型或者都是字符型)

### The Set-Difference Operation
- The set-difference operation, denoted by `-`, allow us to find tuples that are in
one relation but not in another.(同样需要满足并操作的条件)<br>
![Set-Difference Operation](images/set-difference.png)<br>

### The Cartesian-Product(笛卡尔乘积) Operation
- The `Cartesian-Product` operation, denoted by a cross(X), allows us to combine information
from any two relations.
![Cartesian-Product Operation](images/cartesian-product.png)<br>
> For those attributes that appear in only one of the two schemas, we shall usually
drop the relation-name prefix. (就是说只在一个模式里出现的属性可以去掉前缀)<br>

![Cartesian-Product Operation](images/cartesian-product1.png)<br>

### The Rename Operation
![Rename Operation](images/rename.png)<br>

### Formal Definition of the Relational Algebra
![Formal Definition](images/formal-definition.png)<br>

### The Set-Intersection(交) Operation
![Set-Intersection Operation](images/set-intersection.png)<br>

### The Natural-Join Operation
> 自己总结：笛卡尔乘积后不同关系中形同属性值相同的留下就是自然连接的结果<br>

![Natural-Join Operation](images/natural-join.png)<br>

### The Division Operation
> 笛卡尔乘积的相反方向<br>

![Division Operation](images/division.png)<br>

### The Assignment Operation
![Assignment Operation](images/assignment.png)<br>

### Aggregate Functions
![Aggregate Functions](images/aggregate.png)<br>
![Aggregate Functions](images/aggregate1.png)<br>

## Null Values
- 数学运算符对null操作的结果仍然为null
- 两个null值被认为是一样的<br>
![Null Values](images/null.png)<br>
![Null Values](images/null1.png)<br>
![Null Values](images/null2.png)<br>

## Modification of the Database
### Deletion
![Deletion](images/deletion.png)<br>
![Deletion](images/deletion1.png)<br>

### Insertion
![Insertion](images/insertion.png)<br>
![Insertion](images/insertion1.png)<br>

### Update
![Update](images/update.png)<br>
![Update](images/update1.png)<br>
