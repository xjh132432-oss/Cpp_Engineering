# Day 10：CMake 完整工程与 Debug / Release

## 一、今日学习目标

- 理解 Debug 和 Release：
  Debug 主要用于开发和调试，Release 主要用于最终运行和发布。

- 掌握 `CMAKE_BUILD_TYPE`：
  指定当前构建使用的构建类型。

- 掌握 `cmake -S -B`：
  明确指定源码目录和构建目录。

- 理解构建目录：
  构建目录保存 CMake 生成的构建文件和编译产物，不属于源代码。

- 综合 Day 06～09：
  将 Target、源文件管理、静态库和 Target 依赖组合成完整 CMake 工程。

## 二、核心知识

### 1. Debug

Debug 主要用于开发和调试，通常保留更多调试信息。

### 2. Release

Release 主要用于最终运行和发布，通常会进行更多编译优化。

### 3. `CMAKE_BUILD_TYPE`

```cmake
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")