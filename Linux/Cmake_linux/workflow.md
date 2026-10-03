# Day22 Workflow

## 1. CMake + Linux 构建

使用 CMake 配置并构建项目：

```bash
cmake -S . -B build
cmake --build build
```

使用 verbose 查看实际编译过程：

```bash
cmake --build build --verbose
```

确认：

- `main.cpp` 和 `student.cpp` 分别编译为 `.o`
- 最后链接生成 `student`
- `target_include_directories` 正确产生 `-I .../include`

## 2. 检查 Linux 可执行文件

执行：

```bash
file build/student
ldd build/student
ls -lh build/student
./build/student
```

实际观察：

- `student` 是 ELF 64-bit x86-64 可执行文件
- 程序采用动态链接
- 存在多个 `.so` 动态库依赖
- 文件具有执行权限
- 程序正常运行

## 3. Debug 构建

执行：

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

使用：

```bash
file build-debug/student
```

确认程序包含：

```text
debug_info
```

## 4. CMake + GDB

启动：

```bash
gdb ./build-debug/student
```

执行：

```gdb
break getMax
run
list
print student.size()
continue
```

在 `getMax()` 中成功断点，并观察到空 vector：

```text
student.size() = 0
```

确认 GDB 可以定位源码文件、行号和函数参数。

## 5. Release 构建

执行：

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

比较 Debug 和 Release：

```bash
ls -lh build-debug/student build-release/student
```

实际结果：

```text
Debug：   140K
Release：  22K
```

## 6. 今日完成

- CMake Linux 构建
- verbose 查看编译/链接过程
- ELF 可执行文件检查
- 动态库依赖检查
- Linux 文件执行权限
- Debug 构建
- Release 构建
- CMake + GDB 综合调试