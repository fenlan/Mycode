# Concurrency Control

## Locks
- `Shared(S)`. Data item can only be read. S-lock is requested using `lock-S` instruction. (只能读，不能写)
- `Exclusive(X)`. Data item can be both read as well as written. X-lock is requested using `lock-X` instruction.（读写均可）

## Lock-Based Protocols
- A `locking protocol` is a set of rules followed by all transactions while requesting
and releasing(释放) locks. Locking protocol restrict the set of possible schedules.

## The Two-Phase Locking Protocol(两阶段锁协议)
- `Growing Phase`: Transaction may obtain locks; transaction may not release locks.
- `Shrinking Phase`: Transaction may release locks; transaction may not obtain locks.
> 第一阶段是获得封锁，也称为扩展阶段。这在阶段，事务可以申请获得任何数据项上的任何类型的锁，但是不能释放任何锁。<br>
> 第二阶段是释放封锁，也称为收缩阶段。在这阶段，事务可以释放任何数据项上的任何类型的锁，但是不能再申请任何锁。<br>

> 注意：两段锁协议并不要求事务必须一次将所有要使用的数据全部加锁，因此遵守两段锁协议的事务`可能发生死锁`。<br>

- `Upgrade`: We denote conversion from shared to exclusive modes by `upgrade`.
- `Downgrade`: We denote conversion from exclusive to shared modes by `downgrade`.

## Graph-Based Protocols
![Graph-Based Protocols](images/graph-based.png)<br><br>
![Graph-Based Protocols](images/graph-based1.png)<br>

## Timestamp-Based Protocols(时间戳协议)
- If a transaction Ti has been assigned timestamp TS(Ti), and a new transaction Tj enters
the system, then TS(Ti) < TS(Tj).
- Two simple methods for implementing this scheme:
> 1. Use the value of the `system clock` as the timestamp.(系统时钟)<br>
> 2. Use a `logical counter` that is incremented after a new timestamp has been assigned.(逻辑计数器)<br>

- In order to assure such behavior, the protocol maintains for each data Q two timestamp values:
> 1. `W-timestamp(Q)` is the `largest time-stamp` of any transaction that executed `write(Q)` successfully.<br>
> 2. `R-timestamp(Q)` is the `largest time-stamp` of any transaction that executed `read(Q)` successfully.<br>

- Suppose a transaction Ti issues a `read(Q)`
> 1. If `TS(Ti) ≤ W-timestamp(Q)`, then Ti needs to read a value of Q that was already overwritten.
Hence, the `read` operation is rejected, and Ti is rolled back. <br>
> 2. If `TS(Ti) ≥ W-timestamp(Q)`, then the `read` operation is executed, and `R-timestamp(Q)`
is set to the `maximum of R-timestamp(Q)` and TS(Ti).<br>

- Suppose that transaction Ti issues `write(Q)`.
> 1. If `TS(Ti) < R-timestamp(Q)`, then the value of Q that Ti is producing was needed previously,
and the system assumed that that value would never be produced. Hence, the `write` operation
is rejected, and Ti is rolled back. <br>
> 2. If `TS(Ti) < W-timestamp(Q)`, then Ti is attempting to `write` an obsolete(过时) value of Q.
Hence, this `write` operation is rejected, and Ti is rolled back.<br>
> 3. Otherwise, the `write` operation is executed, and `W-timestamp(Q)` is set to TS(Ti).<br>

### Thomas' Write Rule
- 若`TS(Ti) < R-timestamp(Q)`，则Ti产生的Q值是先前所需要的值，且系统已经假定该值不会再产生，
因此，`write`操作被拒绝，Ti回滚。
- 若`TS(Ti) < W-timestamp(Q)`，则Ti试图写入的Q值已过时。因此这个`write`操作可以忽略。
- 其他情况，执行`write`操作，将`W-timestamp(Q)`设置为TS(Ti)。

## Validation-Based Protocols(基于有效性检查的协议)
- 适用于大部分事务都是只读事务的情况
- Execution of transaction Ti is done in three phases(阶段).
> 1. `Read and execution phase`: Transaction Ti writes only to temporary local variables(值是临时的)<br>
> 2. `Validation phase`: Transaction Ti performs a `validation test` to determine
if local variables can be written without violating serializability.<br>
> 3. `Write phase`: If Ti is validated, the updates are applied to the database;
otherwise, Ti is rolled back.<br>

> `提示`：事务内部这三个阶段必须依次进行，但事务之间可以交叉<br>

- Each transaction Ti has 3 timestamps
> `Start(Ti)`: the time when Ti started its execution <br>
> `Validation(Ti)`: the time when Ti entered its validation phase<br>
> `Finish(Ti)`: the time when Ti finished its write phase<br>

- If for all Ti with `TS (Ti) < TS (Tj)` either one of the following condition holds:
> `finish(Ti) < start(Tj)`<br>
> `start(Tj) < finish(Ti) < validation(Tj)` and the set of data items written by Ti
does `NOT intersect(不相交)` with the set of data items read by Tj. <br>

then validation succeeds and Tj can be committed. Otherwise, validation fails and Tj is aborted. <br>

## 多版本机制
> 不想写了，写吐了，看书吧，感觉就是之前的综合一下，但还是提醒一下，老师的ppt这部分内容不少哦<br>

## Deadlock Handling(死锁处理)
