# Day18 Workflow：Linux 进程与进程管理

## 1. 创建 Day18 实验环境

创建进程实验目录：

```bash
mkdir -p ~/day18_process
cd ~/day18_process
```

---

## 2. 编写持续运行的 C++ 程序

创建：

```bash
nano main.cpp
```

编写一个持续运行并每隔 2 秒输出一次信息的 C++ 程序。

程序使用：

```cpp
#include <unistd.h>
```

以及：

```cpp
sleep(2);
```

让程序持续运行并定期暂停。

---

## 3. 编译进程测试程序

执行：

```bash
g++ main.cpp -o process_demo
```

生成：

```text
process_demo
```

---

## 4. 前台运行程序

执行：

```bash
./process_demo
```

程序持续输出：

```text
Process is running...
Process is running...
...
```

程序运行期间终端被该程序占用。

使用：

```text
Ctrl + C
```

结束前台程序。

---

## 5. 查看 Linux 进程

学习并实际使用：

```bash
ps
```

查看当前终端相关的进程。

进一步使用：

```bash
ps aux
```

查看更完整的系统进程信息。

观察进程中的：

```text
USER
PID
%CPU
%MEM
STAT
COMMAND
```

等信息。

---

## 6. 使用 PID 定位测试程序

重新运行：

```bash
./process_demo
```

在另一个终端中使用：

```bash
ps aux | grep process_demo
```

通过搜索结果找到：

```text
process_demo
```

对应的 PID。

同时学习管道：

```text
ps aux
   ↓
|
   ↓
grep process_demo
```

即把前一个命令的输出交给后一个命令处理。

---

## 7. 使用 pgrep 查找进程

使用：

```bash
pgrep process_demo
```

直接获取 `process_demo` 对应的 PID。

---

## 8. 查看指定 PID

获得 PID 后，使用：

```bash
ps -p PID
```

查看指定进程。

同时使用：

```bash
ps -o pid,stat,cmd
```

观察进程状态。

结合程序中的：

```cpp
sleep(2);
```

理解进程处于等待状态时的表现。

---

## 9. 使用 kill 结束进程

使用：

```bash
kill PID
```

向指定进程发送终止信号。

随后使用：

```bash
pgrep process_demo
```

确认进程已经结束。

同时学习：

```bash
kill -9 PID
```

用于强制终止进程。

明确区分：

```text
kill PID
→ 请求进程正常结束

kill -9 PID
→ 强制终止进程
```

---

## 10. 测试后台运行

使用：

```bash
./process_demo &
```

让程序在后台运行。

终端显示类似：

```text
[1] 3456
```

其中：

```text
[1] → 当前 Shell 的 job 编号
3456 → 进程 PID
```

---

## 11. 查看后台任务

使用：

```bash
jobs
```

查看当前 Shell 管理的后台任务。

进一步使用：

```bash
ps
pgrep process_demo
```

确认后台程序仍然作为 Linux 进程运行。

---

## 12. 前后台切换

学习：

```bash
fg
```

将后台任务放回前台。

当存在多个 job 时：

```bash
fg %1
```

将指定 job 放回前台。

同时区分：

```text
PID
→ Linux 系统中的进程编号

job 编号
→ 当前 Shell 管理的任务编号
```

---

## 13. Day18 实际完成内容

```text
创建 day18_process
        ↓
编写持续运行的 C++ 程序
        ↓
g++ 编译 process_demo
        ↓
前台运行
        ↓
Ctrl + C 结束
        ↓
使用 ps 查看进程
        ↓
使用 ps aux 查看系统进程
        ↓
使用 ps aux | grep 查找目标进程
        ↓
使用 pgrep 获取 PID
        ↓
使用 ps -p 查看指定 PID
        ↓
观察进程状态
        ↓
使用 kill 结束进程
        ↓
学习 kill -9 强制结束
        ↓
使用 & 后台运行
        ↓
使用 jobs 查看后台任务
        ↓
使用 fg 切回前台
```

以上为 Day18 实际完成的学习与实验过程。