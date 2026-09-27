# 学习感悟与实践

## g++ main.cpp -o process_demo 时出现<unisted.h>编译错误 再次进入nano发现是拼写错误

## ./process_demo & 以为同样是在另一个linux窗口下运行询问ai后解决
## ./process_demo & 以为是像手机电脑一样的后台运行 运行命令后仍然有输出以为没奏效 实际运行后就可以输入命令

## kill 进程多次失败 随后使用kill -9 成功



# Day18：Linux 进程与进程管理

## 一、学习目标

理解：

- 程序与进程的区别
- PID
- Linux 进程查看
- 进程状态
- 进程结束
- 前台与后台运行
- Shell job 与 PID 的区别

---

## 二、程序与进程

### 程序

磁盘上的可执行文件：

```text
process_demo
```

### 进程

执行程序后，Linux 将程序加载并运行形成进程。

```text
可执行文件
    ↓
执行
    ↓
进程
```

同一个程序可以同时产生多个不同的进程，每个进程拥有不同的 PID。

---

## 三、PID

PID：

```text
Process ID
```

即进程 ID。

每个运行中的进程都有自己的 PID。

例如：

```text
PID = 3456
```

之后可以通过 PID 对这个进程进行查看和发送信号等操作。

---

## 四、查看进程

### `ps`

```bash
ps
```

查看当前终端相关进程。

### `ps aux`

```bash
ps aux
```

查看更完整的系统进程信息。

常见字段：

```text
USER       用户
PID        进程 ID
%CPU       CPU 使用情况
%MEM       内存使用情况
STAT       进程状态
COMMAND    执行的命令
```

---

## 五、查找指定进程

使用：

```bash
ps aux | grep process_demo
```

通过管道将：

```text
ps aux
```

的输出交给：

```text
grep process_demo
```

进行筛选。

也可以直接：

```bash
pgrep process_demo
```

获取匹配进程的 PID。

---

## 六、查看指定进程

```bash
ps -p PID
```

查看指定 PID 的进程。

也可以：

```bash
ps -o pid,stat,cmd
```

查看 PID、状态和命令。

程序中的：

```cpp
sleep(2);
```

会使进程暂时进入等待状态，因此可以观察到进程状态的变化。

---

## 七、结束进程

### 正常请求结束

```bash
kill PID
```

`kill` 的本质是：

> 向指定进程发送信号。

默认情况下：

```text
kill PID
↓
SIGTERM
```

请求进程正常结束。

### 强制结束

```bash
kill -9 PID
```

其中：

```text
-9
↓
SIGKILL
```

用于强制终止进程。

通常应优先尝试：

```bash
kill PID
```

而不是直接使用：

```bash
kill -9 PID
```

---

## 八、前台与后台

前台运行：

```bash
./process_demo
```

程序会占用当前终端。

后台运行：

```bash
./process_demo &
```

最后的：

```text
&
```

表示让程序在后台运行。

---

## 九、Job 与 PID

后台运行后可能出现：

```text
[1] 3456
```

其中：

```text
[1]
↓
Shell job 编号

3456
↓
进程 PID
```

两者不是同一个概念。

查看当前 Shell 的后台任务：

```bash
jobs
```

将后台任务放回前台：

```bash
fg
```

指定 job：

```bash
fg %1
```

---

## 十、完整进程管理流程

```text
启动程序
   ↓
产生进程
   ↓
获得 PID
   ↓
ps / pgrep
   ↓
查看进程
   ↓
kill PID
   ↓
进程结束
```

后台运行时：

```text
./program &
      ↓
   后台进程
      ↓
     jobs
      ↓
      fg
      ↓
   回到前台
```

---

## 十一、Day18 核心命令

```bash
ps
ps aux

ps aux | grep process_demo
pgrep process_demo
ps -p PID
ps -o pid,stat,cmd

kill PID
kill -9 PID

jobs
fg
fg %1

./process_demo &
```

---

## 十二、复习重点

1. **程序是磁盘上的可执行文件，进程是程序运行后的实例。**
2. 每个进程都有自己的 **PID**。
3. `ps` 用于查看进程。
4. `ps aux` 可以查看更完整的进程信息。
5. `pgrep` 可以根据名称查找进程 PID。
6. `|` 是管道，可以把一个命令的输出交给另一个命令。
7. `kill PID` 本质上是向进程发送信号。
8. `kill -9 PID` 用于强制终止进程。
9. `&` 可以让程序后台运行。
10. `jobs` 管理当前 Shell 的后台任务。
11. **PID 和 job 编号不是一回事。**
12. `fg` 可以将后台任务切回前台。