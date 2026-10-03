# Day22：CMake + Linux + GDB 综合实践

## 一、今日目标

将前面学习的 CMake、Linux、GDB 串联起来，完成：

- Linux 下使用 CMake 构建 C++ 项目
- 理解编译、链接和可执行文件
- 使用 `file`、`ldd` 检查 Linux 程序
- 区分 Debug / Release 构建
- 使用 CMake 生成 Debug 程序并进行 GDB 调试

## 二、项目结构

```text
day22_cmake_linux/
├── CMakeLists.txt
├── README.md
├── workflow.md
├── include/
│   └── student.h
├── src/
│   ├── main.cpp
│   └── student.cpp
├── build/
├── build-debug/
└── build-release/
```

## 三、CMake 构建

使用：

```bash
cmake -S . -B build
cmake --build build
```

使用 `--verbose` 查看实际编译过程：

```bash
cmake --build build --verbose
```

观察到：

```text
main.cpp → main.cpp.o
student.cpp → student.cpp.o
        ↓
      链接
        ↓
   build/student
```

同时验证了：

```cmake
${CMAKE_CURRENT_SOURCE_DIR}/include
```

会转换为编译器的：

```text
-I/home/qwer/day22_cmake_linux/include
```

## 四、Linux 可执行文件

检查：

```bash
file build/student
```

结果表明程序是：

```text
ELF 64-bit
x86-64
PIE executable
dynamically linked
```

Linux 下可执行文件不需要 `.exe` 后缀。

查看动态库：

```bash
ldd build/student
```

可以看到程序依赖：

- `libstdc++.so.6`
- `libgcc_s.so.1`
- `libc.so.6`
- `libm.so.6`
- `ld-linux-x86-64.so.2`

查看文件权限：

```bash
ls -lh build/student
```

程序具有执行权限，可以直接：

```bash
./build/student
```

## 五、Debug 构建

生成 Debug 构建：

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

检查：

```bash
file build-debug/student
```

结果包含：

```text
with debug_info
```

说明程序包含调试信息，可以被 GDB 进行源码级调试。

## 六、GDB 调试

启动：

```bash
gdb ./build-debug/student
```

设置断点：

```gdb
break getMax
run
```

查看源码：

```gdb
list
```

查看 vector 大小：

```gdb
print student.size()
```

在空 vector 的调用处观察到：

```text
student.size() = 0
```

GDB 能够定位到：

```text
src/student.cpp:32
```

说明 CMake 的 Debug 构建与 GDB 已经连接起来。

## 七、Debug / Release 对比

Release：

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

实际结果：

```text
Debug：   140K
Release：  22K
```

Debug 程序包含 `debug_info`，Release 程序主要面向最终运行。

## 八、今日核心认知

```text
CMakeLists.txt
      ↓
CMake 配置
      ↓
编译
      ↓
.o
      ↓
链接
      ↓
ELF 可执行文件
      ↓
动态库
      ↓
Linux 运行
```

Debug 模式进一步形成：

```text
CMake
 ↓
Debug 构建
 ↓
debug_info
 ↓
GDB
 ↓
源码级调试
```

今日完成 CMake、Linux、ELF、动态库、Debug/Release 和 GDB 的综合实践。