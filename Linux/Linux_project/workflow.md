# Day20 Workflow

## 1. 创建项目目录

进入 `Cpp_Engineering`：

```bash
cd ~/Cpp_Engineering
```

创建 Day20 项目：

```bash
mkdir -p day20_linux_project/src
cd day20_linux_project
```

## 2. 创建 C++ 多文件项目

创建：

```text
src/
├── calculator.h
├── calculator.cpp
└── main.cpp
```

其中：

- `calculator.h`：函数声明
- `calculator.cpp`：函数实现
- `main.cpp`：程序入口及功能调用

实现 `add()` 和 `subtract()` 两个函数。

## 3. 创建 CMake 配置

创建 `CMakeLists.txt`，配置：

- C++17
- `main.cpp`
- `calculator.cpp`
- `src` 头文件目录
- `linux_project` 可执行文件

## 4. 使用 CMake 构建

执行：

```bash
cmake -S . -B build
cmake --build build
```

生成：

```text
build/linux_project
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

## 5. 检查 Linux 可执行文件

执行：

```bash
file build/linux_project
```

确认生成的是 Linux ELF 可执行文件。

## 6. 加入进程运行测试

在 `main.cpp` 中加入：

```cpp
#include <unistd.h>
```

并使用：

```cpp
sleep(30);
```

让程序保持运行状态。

重新构建：

```bash
cmake --build build
```

后台运行：

```bash
./build/linux_project &
```

## 7. 查看运行中的进程

使用 Day18 学习的命令：

```bash
ps -p PID
pgrep linux_project
ps -o pid,stat,cmd
```

观察程序对应的 PID 和运行状态。

## 8. 结束进程

使用：

```bash
kill PID
```

结束测试进程，并使用：

```bash
pgrep linux_project
```

确认进程结束。

## 9. 创建 Debug 构建

使用 CMake 创建 Debug 构建目录：

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

## 10. 使用 GDB 调试

启动：

```bash
gdb ./build-debug/linux_project
```

在程序中设置断点后进行：

```text
run
print
next
continue
quit
```

观察变量并进行单步调试。

## 11. Day20 完整流程

```text
创建项目
  ↓
编写多文件 C++
  ↓
配置 CMake
  ↓
构建并运行
  ↓
file 检查 ELF
  ↓
后台运行程序
  ↓
ps / pgrep 查看进程
  ↓
kill 结束进程
  ↓
创建 Debug 构建
  ↓
GDB 断点调试
```