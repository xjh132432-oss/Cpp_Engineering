# Day16 Workflow — Linux Development Environment

## 1. Enter Ubuntu

在 Windows PowerShell 中进入 WSL2：

```bash
wsl -d Ubuntu-24.04
```

进入 Ubuntu 后验证系统：

```bash
uname -a
cat /etc/os-release
```

确认当前环境为 Ubuntu 24.04 LTS。

---

## 2. Check Linux Toolchain

首先检查 Git：

```bash
which git
```

然后检查 C++ 编译器：

```bash
which g++
```

发现 Ubuntu 原本没有 `g++`。

这里确认了 Windows 与 Linux 的工具链是相互独立的：

```text
Windows
C:\mingw64\bin\g++.exe
        ↓
MinGW GCC

Ubuntu
/usr/bin/g++
        ↓
Linux GCC
```

Windows 中已经安装的 MinGW GCC 不会自动成为 Ubuntu 的 GCC。

---

## 3. Install Linux Development Tools

更新 Ubuntu 软件包：

```bash
sudo apt update
```

安装基础 C/C++ 开发工具：

```bash
sudo apt install build-essential cmake gdb
```

其中：

- `build-essential`：Ubuntu 常用 C/C++ 开发工具集合，包含 GCC、G++、Make 等
- `cmake`：C++ 项目构建系统
- `gdb`：GNU Debugger，Linux 下的调试工具

---

## 4. Verify Toolchain

安装完成后检查：

```bash
gcc --version
g++ --version
cmake --version
gdb --version
git --version
```

实际环境：

```text
GCC/G++  13.3.0
CMake    3.28.3
GDB      15.1
Git      2.43.0
```

检查工具路径：

```bash
which gcc
which g++
which cmake
which gdb
which git
```

实际路径：

```text
/usr/bin/gcc
/usr/bin/g++
/usr/bin/cmake
/usr/bin/gdb
/usr/bin/git
```

确认使用的是 Ubuntu Linux 原生工具链。

---

## 5. Linux C++ Test

建立最小 Linux C++ 测试程序。

创建：

```text
main.cpp
```

内容：

```cpp
#include <iostream>

int main() {
    std::cout << "Hello Linux C++" << std::endl;
    return 0;
}
```

使用 Linux GCC 编译：

```bash
g++ main.cpp -o main
```

运行：

```bash
./main
```

得到：

```text
Hello Linux C++
```

这一过程验证：

```text
main.cpp
   ↓
Linux GCC
   ↓
编译
   ↓
Linux 可执行文件
   ↓
./main
```

---

## 6. Verify Linux Executable Format

使用：

```bash
file main
```

检查生成文件。

确认生成的是 Linux ELF 可执行文件。

Linux 常见可执行文件格式为：

```text
ELF
```

Windows 常见可执行文件格式为：

```text
PE / .exe
```

因此这一步不仅验证程序能够运行，也验证了程序确实是由 Linux 工具链生成的原生 Linux 可执行文件。

---

## 7. Write CMakeLists.txt

为了验证 Linux 下的 CMake，创建：

```text
CMakeLists.txt
```

基本结构：

```cmake
cmake_minimum_required(VERSION 3.20)

project(LinuxDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(linux_demo main.cpp)
```

这里对应之前已经学习过的 CMake 工程结构：

```text
CMakeLists.txt
       ↓
project()
       ↓
设置 C++ 标准
       ↓
add_executable()
       ↓
生成可执行程序
```

---

## 8. CMake Configure

使用：

```bash
cmake -S . -B build
```

这里：

- `-S .`：指定当前目录为源码目录
- `-B build`：指定 `build` 为构建目录

CMake 根据 `CMakeLists.txt` 生成构建系统。

---

## 9. CMake Build

执行：

```bash
cmake --build build
```

CMake 调用 Linux GCC 完成实际编译。

完整流程：

```text
CMakeLists.txt
      ↓
cmake -S . -B build
      ↓
生成 Build System
      ↓
cmake --build build
      ↓
Linux GCC
      ↓
linux_demo
```

---

## 10. Run CMake Program

运行生成的程序：

```bash
./build/linux_demo
```

输出：

```text
Hello Linux C++
```

说明 Linux 下：

```text
CMake
  ↓
GCC
  ↓
C++
  ↓
可执行文件
  ↓
运行
```

整个构建流程正常。

---

## 11. Test File Practice

在 Linux 环境中使用独立的 `test` 文件进行测试记录。

测试的目的不是重新学习 C++ 语法，而是验证：

```text
源代码
 ↓
GCC
 ↓
CMake
 ↓
可执行文件
 ↓
测试运行
```

测试结果确认：

```text
Hello Linux C++
```

说明 Linux C++ 编译环境与 CMake 构建环境均可以正常工作。

---

## 12. Compare Development Environments

目前已经接触三个 C++ 开发环境：

| Environment | Compiler |
|---|---|
| macOS | AppleClang |
| Windows | MinGW GCC |
| Ubuntu / WSL2 | Linux GCC |

同一套 C++ 源代码可以通过不同平台的工具链进行构建：

```text
             C++ Source
                 │
       ┌─────────┼─────────┐
       ↓         ↓         ↓
    macOS     Windows    Linux
   Clang      MinGW GCC   GCC
```

Day16 的重点是把之前已经具备的 C++ 工程能力扩展到 Linux 环境。

---

## 13. Git Repository Verification

进入 Cpp_Engineering：

```bash
cd ~/Cpp_Engineering
```

检查：

```bash
git status
```

实际状态：

```text
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

查看历史：

```bash
git log --oneline --decorate -10
```

确认 Ubuntu 中已经存在之前项目的 Git 历史。

说明：

```text
Windows / macOS
       ↓
    GitHub
       ↓
Ubuntu
```

Linux 下使用的是同一个 Git 仓库历史，而不是重新建立一个“Linux 仓库”。

---

## 14. Git Commit Workflow

完成 Day16 文件整理后，按照固定流程提交。

### ① 检查状态

```bash
git status
```

### ② 查看修改

```bash
git diff
```

### ③ 加入暂存区

```bash
git add day16/
```

### ④ 检查暂存内容

```bash
git diff --cached
```

确认只有 Day16 相关文件。

### ⑤ Commit

```bash
git commit -m "feat(day16): add Linux development environment"
```

### ⑥ Push

```bash
git push
```

### ⑦ 最终检查

```bash
git status
```

目标：

```text
nothing to commit, working tree clean
```

---

## 15. Day16 Final Result

Day16 完成的核心内容：

- WSL2 Ubuntu 24.04
- Linux GCC/G++
- CMake
- GDB
- Git
- Linux 原生 C++ 编译
- Linux ELF 可执行文件验证
- CMakeLists.txt 编写
- CMake Configure
- CMake Build
- test 文件测试
- macOS / Windows / Linux 工具链对比
- Linux 下 Git 仓库验证
- Day16 Git 提交流程

最终形成：

```text
Windows
   ↓
WSL2
   ↓
Ubuntu 24.04
   ↓
GCC / CMake / GDB
   ↓
C++ Source
   ↓
CMake Build
   ↓
Linux ELF
   ↓
Test
   ↓
Git
   ↓
GitHub
```

**Day16 的核心不是学习 Linux 基础命令，而是把已有 C++ 工程能力真正放到 Linux 工具链中运行。**