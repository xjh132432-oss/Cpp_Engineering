# Day19 - GDB 调试

## 一、学习目标

- 了解为什么需要调试器
- 掌握 GDB 基本使用流程
- 理解断点、变量查看、单步执行
- 区分 `next` 和 `step`
- 建立 Linux 下基本 C++ 调试能力

---

## 二、GDB

GDB（GNU Debugger）用于调试程序。

可以在程序运行过程中：

```text
暂停程序
↓
查看变量
↓
单步执行
↓
观察程序状态
↓
定位问题
```

---

## 三、编译调试程序

普通编译：

```bash
g++ main.cpp -o demo
```

带调试信息：

```bash
g++ -g main.cpp -o demo
```

`-g`：

> 在可执行文件中加入调试信息，使 GDB 能够对应源码、行号和变量。

---

## 四、启动 GDB

```bash
gdb demo
```

进入：

```text
(gdb)
```

---

## 五、断点

设置断点：

```gdb
break 14
```

简写：

```gdb
b 14
```

查看断点：

```gdb
info breakpoints
```

断点的作用：

> 让程序运行到指定位置后暂停。

---

## 六、运行程序

```gdb
run
```

简写：

```gdb
r
```

程序会运行到：

```text
断点
```

然后暂停。

---

## 七、查看变量

```gdb
print x
```

简写：

```gdb
p x
```

例如：

```gdb
p x
p y
p sum
```

用于观察当前变量值。

---

## 八、单步执行

### `next`

```gdb
next
```

简写：

```gdb
n
```

执行当前代码行。

如果当前行调用函数：

```cpp
sum = add(x, y);
```

`next` 会执行函数，但不会进入函数内部。

### `step`

```gdb
step
```

简写：

```gdb
s
```

遇到函数调用时可以进入函数内部。

因此：

```text
next → 不进入函数

step → 进入函数
```

---

## 九、查看源码

```gdb
list
```

简写：

```gdb
l
```

查看当前调试位置附近的源代码。

---

## 十、继续运行

```gdb
continue
```

简写：

```gdb
c
```

让程序继续执行，直到：

- 下一个断点
- 程序结束
- 程序发生异常

---

## 十一、退出 GDB

```gdb
quit
```

简写：

```gdb
q
```

---

## 十二、完整调试流程

```bash
g++ -g main.cpp -o demo
gdb demo
```

进入 GDB 后：

```gdb
break 14
run
print x
print y
next
print sum
step
list
continue
quit
```

---

## 十三、核心命令

| 命令 | 简写 | 作用 |
|---|---|---|
| `run` | `r` | 运行程序 |
| `break` | `b` | 设置断点 |
| `info breakpoints` | — | 查看断点 |
| `print` | `p` | 查看变量 |
| `next` | `n` | 单步执行，不进入函数 |
| `step` | `s` | 单步执行并进入函数 |
| `list` | `l` | 查看源码 |
| `continue` | `c` | 继续运行 |
| `quit` | `q` | 退出 GDB |

---

## 十四、核心理解

Day19 建立的调试思维：

```text
程序运行
   ↓
设置断点
   ↓
程序暂停
   ↓
查看变量
   ↓
单步执行
   ↓
观察状态变化
   ↓
定位问题
```

GDB 的核心不是记命令，而是学会：

> **让程序停下来，然后观察程序到底发生了什么。**