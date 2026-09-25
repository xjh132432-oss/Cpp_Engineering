# Day 09：CMake 静态库与 Target 依赖

## 一、今日学习目标

- 理解 Library：
  将一组具有独立功能的代码组织成一个独立的库。

- 掌握 `add_library()`：
  使用 CMake 创建静态库 Target。

- 理解静态库：
  静态库在链接阶段被加入最终的可执行程序。

- 掌握 `target_link_libraries()`：
  建立可执行程序与库之间的 Target 依赖关系。

- 理解 Target 依赖：
  可执行程序可以依赖其他 Target，而不需要直接管理所有实现文件。

- 理解 `PUBLIC` 和 `PRIVATE` 在库中的作用：
  `PUBLIC` 可以向依赖当前 Target 的其他 Target 传播配置，`PRIVATE` 只作用于当前 Target。

## 二、核心知识

### 1. Library

Library 用于将一组具有独立功能的代码组织起来。

例如：

```text
student.h
student.cpp
