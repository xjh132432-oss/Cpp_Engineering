# Student Manager

一个用于巩固 C++ 工程化能力的综合实战项目。

## 功能

- 添加学生
- 查看所有学生
- 按姓名查询学生
- 统计平均分、最高分、最低分
- 退出程序

## 项目结构

```text
Engineering_Comprehensive_Project/
├── CMakeLists.txt
├── include/
│   └── student.h
├── src/
│   ├── main.cpp
│   └── student.cpp
├── build/
└── build-debug/
```

## 技术点

- C++17
- `std::vector`
- `const` 与引用
- `.h / .cpp` 分离
- CMake
- CMake Static Library
- Linux 开发环境
- GDB 调试

## 构建

```bash
cmake -S . -B build
cmake --build build
```

## 运行

```bash
./build/student_manager
```

## Debug 构建

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

使用 GDB：

```bash
gdb ./build-debug/student_manager
```