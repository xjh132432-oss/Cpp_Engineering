# Day 07：CMake Target 与编译配置

## 一、今日学习目标

- 理解 CMake 中的 Target：
  Target 是 CMake 管理的构建目标，例如可执行文件或库。

- 掌握 `target_include_directories()`：
  为指定 Target 设置头文件搜索路径。

- 掌握 `target_compile_features()`：
  为指定 Target 指定所需要的 C++ 标准。

- 理解 `PRIVATE`：
  配置只作用于当前 Target。

- 理解 `PUBLIC` 和 `PRIVATE`：
  `PRIVATE` 只作用于当前 Target，`PUBLIC` 可以继续影响依赖当前 Target 的其他 Target。

- 使用 Target-based CMake：
  将编译配置与具体 Target 绑定。

## 二、核心知识

### 1. Target

Target 是 CMake 管理的一个构建目标。

```cmake
add_executable(student_manager
    src/main.cpp
    src/student.cpp
    src/printer.cpp
)