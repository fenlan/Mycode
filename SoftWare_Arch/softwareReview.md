## 体系结构
组件 + 连接件 + 约束

## 体系风格分类
- independent components
	- communicating processes
	- event systems
		- implicit invocation (隐式调用)
		- explicit invocation (显式调用)

- data flow
	- batch sequential
	- pipes & filters

- data-centered
	- repository
	- blackboard

- virtual machine
	- interpreter
	- rule-based system

- call/return
	- main pgm & subroutine
	- object oriented
	- layered

## date flow
`Batch sequential`
- 每个处理步骤是一个独立的程序
- 每一步必须在前一步结束后才能开始(有次序)
- 数据必须是完整的,以整体的方式传递

> Examples : 编译器、Computer Aided Software Engineering(VS IDE)

`pipes & filters` : 每个组件都有一组输入和输出,组件读取输入的数据流,经过内部处理,产生输出数据流。这个过程通常通过对输入流的变换及增量计算来完成。

- Advantages
	- 使得软件具有良好的隐蔽性和高内聚、低耦合的特点
	- 可将整个系统的 I/O 出特性理解为各个过滤器功能的简单合成
	- 支持功能模块的重用
	- 系统易于维护和扩展
	- 支持某些特定属性的分析
	- 支持多个过滤器的并发执行

- Disadvantages
	- 通常导致进程成为批处理的结构
	- 不适合于交互性很强的应用
	- 在数据传输上没有通用的标准,每个过滤器都增加了解析数据的工作
	- 处理两个独立但相关的数据流可能会遇到困难
	- 某些 flter 可能需要大尺寸 cache (如排序组件)

> Examples : 媒体播放器

`Batch Sequential vs Pipe & Filter`
- `total` VS `incremental`
- `High latency (real-time is hard)` VS `Results start immediately`
- `Random access to input` VS `Processing localized in input`
- `No concurrency` VS `Feedback loops possible`
- `Non-interactive` VS `Often interactive, awkwardly`

`何时选择data flow风格`
- 任务由数据主导
- 事先知道数据的确切流向
- 可能带来性能损耗

## Controller
`开环控制` : 系统无反馈,由人进行反馈。
`闭环控制` : 系统有反馈,不需要人进行反馈。
`何时选择控制风格`
- 任务包含连续的动作、行为、状态的改变
- 不适合人参与的情况
- 一般是软硬件结合的系统

## Call/Return
`Main Program and Subroutine`
关键字 : Model

`Object-Oriented`
- Elements of Object Architectures
	- 封装:限制对某些信息的访问
	- 交互:通过过程调用或类似的协议
	- 多态:在运行时选择具体的操作
	- 继承:对共享的功能保持唯一的接口
	- 复用和维护:利用封装和聚合提高生产力

- Problems with Object Approaches
	- Managing many objects
	- Managing many interactions
	- Distributed responsibility for behavior
	- Capturing families of related designs

`layered`
- 层次风格特点
	- 每层为上一层提供服务,使用下一层的服务,只能见到与自己邻接的层
	- 大的问题分解为若干个渐进的小问题,逐步解决,隐藏了很多复杂度
	- 修改一层,最多影响两层,通常只会影响上层。若层之间接口稳固,则不会造成其他影响
	- 上层必须知道下层的身份,不能调整层次之间的顺序
	- 层层相调,影响性能

## Data Centered / Shared Data
`Shared Information Systems`
- Advantages : 很容易增加数据的生产者和消费者
- Issues : synchronization (同步) // confguration and schema management (配置和管理) // atomicity (原子性) // consistency(一致性) // persistence (持久性) // performance (性能)

`Repository`
- porblem : 主要任务是操纵数据、数据需要长期保存
- context : 通常需要数据库等特定软件的支持

> 数据库是典型的仓库

`Blackboard`
- 黑板的作用相当于共享内存
- 解决无确定性求解 策略问题(边走边看,摸着石头过河
- 设计公共数据结构
- 设计多个专用组件,每个组件解决任务的一个特定部分
- 每个组件可对公共数据结构进行添加、修改、删除
- 仲裁者组件对每个组件的工作结果进行评估,协调各组件的工作


- Blackboard 的组成
	- 知识源(专家)
	- 黑板数据结构
	- 控制(仲裁者)

- 黑板的特点
	- 没有直接的算法可解
	- 不确定
	- Best-efort or approximation is good enough

`仓库和黑板的区别`
- 黑板:黑板的状态触发进一步的操作
- 仓库:操作的执行次序是预先确定的

## Virtual Machine
`interpreter`
- 解释器是用来“执行其他程序的程序”,很多脚本语supported by the execution environment.言都采用解释的方式运行,即程序源代码直接被解释执行(不需编译)。浏览器也是典型的解释器


- 组件:一个状态机(解释引擎)、三个存储区
- 连接件:过程调用 / 对存储区的数据访问

- Advantages
	- Functionality : 可以模拟非本机功能
	- Testing : 可以模拟“灾难”模式
	- Flexibility : 非常通用的工具

- Disadvantages
	- Efciency : Much, much slower than hardware AND Much slower than compiled system
	- Testing : Additional layer of software to be verifed(要验证的附加软件层)
	- 解释器和编译器的区别
		- 解释器的执行速度慢于编译器产生的目标代码的执行速度,但低于 “ 编译 + 链接 + 执行 ” 的总时间
		- 每次解释执行时,都需要分析程序结构,而编译器只需一次性编译代码

`Rule-based system`
- 当业务规则很复杂时,不宜用 if-else 结构表示
- 按照 OCP (开放 / 封闭原则),应把可变部分与不变部分进行分离,在前者发生变化时就不会影响后者
- 给予规则的系统的特点
	- Interpretation engine (rule interpreter)
	- Code to be executed (knowledge base)
	- Control state of interpreter (rule/data selection)
	- Current state of the code (working memory)

- 优点
	- 降低修改业务逻辑的成本与风险
	- 缩短开发时间
	- 规则可在多个应用中共享

- 与解释器风格的不同
	- 解释器:在高级程序语言与 OS/ 硬件平台间建立虚拟机
	- 基于规则的系统:在自然语言 /XML 规则和高级程序语言间建立虚拟机

## Independent Component
`Communicating Processes`
- 完成任务需要多个 proc 协同, prco 间的协同通过 msg完成, msg 是“显性”的,即需要指明“源”和“目的地”
- 组件间相对独立,依靠“发消息”通信

`Event Systems`
- 组件对事件进行订阅(登记),并在事件被触发时得到通知。而事件并不知道(或不关心)都有谁订阅了自己

- The implicit invocation
	- 基于事件的隐式调用风格的思想
		- 构件不直接调用一个过程,而是触发一个或多个事件
		- 其它构件中的过程注册一个或多个事件,当一个事件被触发,系统自动调用在这个事件中注册的所有过程
	- 构件是一些模块(过程,或事件的集合)
	- 主要特点是事件的触发者并不知道哪些构件会被这些事件影响
	- Advantages
		- 为软件重用提供了强大的支持。当需要将一个构件加入现存系统中时,只需将它注册到系统的事件中。新的关注者不对现有的关注者构成任何影响
		- 为改进系统带来了方便。当用一个构件代替另一个构件时,不会影响到其它构件的接口。
	- Disadvantages
		- 构件放弃了对系统计算的控制
		- 因为语义依赖于被触发事件的上下文约束
		- 系统依靠一个共享的“电话簿”(记录了每个事件的关注者),可能存在全局性能和资源管理的问题

## Quality Attribute Scenarios(方案)
- `source(刺激源)` – an entity that generates a stimulus
- `stimulus(刺激)` – a condition that afects the system
- `artifact(被刺激体)` - the part of that was stimulated by the stimulus
- `environment` - the condition under which the stimulus occurred
- `response` - the activity that results because of the stimulus
- `response measure` - the measure by which the system’s response will be evaluated

## System Quality Attributes (U-STAMP)
`Availability` : The availability of a system is the probability that it will be operational when it is needed
`Modifability` : Modifability is about the cost of change
`Performance` : Performance is about timing. Performance is concerned with how long it takes the system to respond when an event occurs.
`Security` : 合法用户可用,非法用户不可用
`Testability` : Software testability refers to the ease with which software can be made to demonstrate its faults through (typically execution-based) testing. (让软件的 bug 容易被测试出来)
`Usability` : Usability is concerned with how easy it is for the user to accomplish a desired task and the kind of user support the system provides

## Tactics
An architectural tactic is a fine-grained design approach used to achieve a quality attribute response.(满足特定质量属性的具体设计手段)
`Availability Tactics`
- Fault Detection : Ping/echo, Heartbeat, Exceptions
- Fault Recovery :
	- Fault recovery consists of preparing for recovery and making the system repair.
	- Voting, Active redundancy, Passive redundancy, Spare, Shadow operation, State resynchronization, Checkpoint/rollback
- Fault Prevention : Removal from service, Transactions, Process monitor

`Modifiability Tactics`
- Localize Modifications(本地化修改)
	- 保持语义一致性
	- 预计预期的变化
	- 概括成模块
	- 限制可能的选择

- Prevent Ripple Effects(阻止扩散效应)
	- Hide information
	- Maintain existing interfaces
	- Restrict communication paths (尽量让模块间的数据联系简单化,减少 “ 多对多 ” 的关系)
	- Use an intermediary.（使用中介）

- 推迟约束时间
	- Runtime registration
	- Publish/subscribe registration
	- 配置文件可以避免把数据写入代码
	- 多态
	- 组件代替

`Performance Tactics`
performance tactics is to generate a response to an event arriving at the system within some time constraint.
- Two basic contributors
	- Resource consumption : Resources include CPU, data stores, network communication bandwidth, and memory, but it can also include entities defined by the particular system under design.
	- Blocked time : A computation can be blocked from using a resource

- Resource demand
	- Increase computational efficiency. (随着排序数据量的增大,用快速排序代替冒泡排序)
	- Reduce computational overhead.
	- Manage event rate. (舰载雷达每分钟转一圈比每秒转一圈所需处理的数据量要少得多)
	- Control frequency of sampling (控制采样频率)
	- Bound execution times.
	- Bound queue sizes.
- Resource management
	- Introduce concurrency.(利用多机、多核、多进程、多线程等)
	- Maintain multiple copies of either data or computations.
	- Increase available resources.
- Resource arbitration (仲裁)
	- First-in/First-out.
	- Fixed-priority scheduling.
	- Dynamic priority scheduling
	- Static scheduling

`Security Tactics`
- Resisting attacks
	- Authenticate users
	- Authorize users
	- Maintain data confidentiality(网银常用 https 来提高保密性)
	- Maintain integrity(保持诚信)
	- Limit exposure(限制暴露,如端口)
	- Limit access
- Detecting attacks
	- 入侵侦测系统
- Recovering from attacks
	- Restoring state
	- Attacker identification(攻击者识别)

`Testability Tactics`
The goal of tactics for testability is to allow for easier testing when an increment of software development is completed.
- INPUT/OUTPUT
	- Record/playback (半自动化 / 自动化测试)
	- Separate interface from implementation(基于统一的接口实现不同的排序算法,则测试程序基于接口编写即可测试各类排序算法)
	- Specialize access routes/interfaces(专门访问路由/接口) : 提供特殊的界面、方法专门用于测试
- Internal Monitoring
	- Built-in monitors. (IDE 中设置断点)

`Usability Tactics`
Usability is concerned with how easy it is for the user to accomplish a desired task and the kind of support the system provides to the user.
- Runtime Tactics
	- Maintain a model of the task(系统猜测用户要完成的任务)
	- Maintain a model of the user(网站调整用户的鼠标滚轮速度,以防用户翻页过快漏过内容)
	- Maintain a model of the system(浏览器打开页面时显示进度)
- Design-time Tactics
	- Separate the user interface from the rest of the application.(MVC用户界面和业务逻辑可由不同人员开发,且可独立发生变化)


## Architecture Evaluation
`Architecture Trade-off Analysis Method (ATAM)架构权衡分析法`
- 分析了多个质量属性间的关联。属性间可能存在冲突,需要权衡取舍
- 按照质量需求,评价体系结构设计

`Purpose of ATAM`
- 让我们能尽早提出正确问题,来发现
	- 风险( risks ):可能在将来损害某些质量属性的方案
	- 非风险( non-risks ):可以提高质量、帮助实现目标的决策
	- 关键点 / 敏感点( sensitivity points ):方案中一个小小的变化,就可能对某些质量属性有很大影响
	- 权衡点( tradeoffs ):影响一个以上质量的决策


- ATAM 的主要目标是发现体系结构可能带来的风险
- 发现体系结构方案和系统的特性之间的关联
- 发现风险后,可以做进一步的分析、设计
- 明显的权衡可以被明确指出并写入文档


- ATAM 的益处:
	- 明确质量需求
	- 提高体系结构文档质量
	- 体系结构方案文档的基础
	- 及早发现风险