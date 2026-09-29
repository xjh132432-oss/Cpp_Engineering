# Day20 - Linux C++ 工程综合实践

## 一、学习目标

将前面学习的：

- C++
- CMake
- Linux
- 进程
- GDB

连接成一个完整的 Linux C++ 开发流程。

---

## 二、项目结构

```text
day20_linux_project/
├── CMakeLists.txt
├── README.md
├── workflow.md
└── src/
    ├── calculator.h
    ├── calculator.cpp
    └── main.cpp
```

---

## 三、多文件 C++ 工程

```text
calculator.h
    ↓
函数声明

calculator.cpp
    ↓
函数实现

main.cpp
    ↓
程序入口 / 调用函数
```

本次项目实现：

```cpp
int add(int a, int b);
int subtract(int a, int b);
```

---

## 四、CMake 构建

配置：

```bash
cmake -S . -B build
```

构建：

```bash
cmake --build build
```

运行：

```bash
./build/linux_project
```

程序输出：

```text
sum = 25
difference = 15
```

核心流程：

```text
CMakeLists.txt
      ↓
CMake
      ↓
编译
      ↓
链接
      ↓
linux_project
```

---

## 五、Linux ELF

检查：

```bash
file build/linux_project
```

Linux 下生成的 C++ 可执行文件通常是 ELF 格式。

因此：

```text
.cpp
 ↓
g++
 ↓
ELF executable
 ↓
Linux process
```

---

## 六、进程管理

为了观察程序运行状态，使用：

```cpp
sleep(30);
```

让程序保持运行。

后台运行：

```bash
./build/linux_project &
```

查看进程：

```bash
ps -p PID
pgrep linux_project
ps -o pid,stat,cmd
```

结束进程：

```bash
kill PID
```

这一部分连接 Day18：

```text
程序
 ↓
运行
 ↓
进程
 ↓
PID
 ↓
ps / pgrep
 ↓
kill
```

---

## 七、Debug 构建

创建 Debug 构建：

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
```

编译：

```bash
cmake --build build-debug
```

运行：

```bash
./build-debug/linux_project
```

Debug 构建主要用于开发和调试。

---

## 八、GDB 调试

启动：

```bash
gdb ./build-debug/linux_project
```

核心操作：

```gdb
break 断点
run
print
next
step
continue
quit
```

调试流程：

```text
设置断点
 ↓
run
 ↓
程序暂停
 ↓
print 查看变量
 ↓
next / step 单步执行
 ↓
continue
 ↓
quit
```

---

## 九、Debug / Release

Debug：

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

Release：

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

两者属于同一个项目的不同构建配置。

---

## 十、Day20 核心工程链

```text
C++源码
   ↓
CMake
   ↓
Build
   ↓
Linux ELF
   ↓
运行
   ↓
Process / PID
   ↓
GDB Debug
   ↓
Git
```

Day20 的重点不是增加新的 Linux 命令，而是把前面 Day16～19 的知识连接起来，形成完整的 Linux C++ 开发流程。

---

## 十一、核心复习

需要能够独立解释：

1. 为什么 Linux C++ 项目需要 CMake？
2. `cmake -S . -B build` 做了什么？
3. `cmake --build build` 做了什么？
4. ELF 是什么？
5. 程序和进程有什么区别？
6. PID 是什么？
7. `ps`、`pgrep`、`kill` 分别解决什么问题？
8. Debug 构建和 Release 构建有什么区别？
9. 为什么 GDB 调试需要调试信息？
10. `next` 和 `step` 有什么区别？

---

## 十二、阶段总结

Day16～20：

```text
Day16  Linux开发环境
Day17  权限 / 用户 / sudo
Day18  进程 / PID / 前后台
Day19  GDB
Day20  Linux C++工程综合实践
```

完成后形成：

```text
C++ + CMake + Git + Linux + GDB
```

这一套基础工程能力。