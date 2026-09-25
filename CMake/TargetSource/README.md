# Day 08：CMake 源文件管理与变量

## 一、今日学习目标

- 掌握 CMake 变量 `set()`：
  使用变量保存和管理项目中的源文件列表。

- 掌握 `target_sources()`：
  为指定 Target 添加源文件。

- 理解源文件管理：
  CMake 只有将 `.cpp` 加入 Target，文件才会参与项目构建。

- 综合使用变量和 Target：
  使用 `set()` + `target_sources()` 管理多文件 C++ 工程。

## 二、核心知识

### 1. CMake 变量

```cmake
set(SOURCES
    src/main.cpp
    src/student.cpp
    src/printer.cpp
)