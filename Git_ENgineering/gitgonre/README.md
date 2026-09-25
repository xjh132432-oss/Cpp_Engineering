# Day 13：Git 与 C++ 工程结合

## 一、今日目标

- 理解 C++ 工程中哪些文件应该进入 Git
- 理解构建产物与源代码的区别
- 掌握 `.gitignore` 的基本使用
- 理解 `build/`、`.o`、`.a` 等文件为什么通常不提交
- 理解 tracked 与 untracked 的区别

## 二、核心知识

### 1. 源代码

例如：

```text
.cpp
.h
CMakeLists.txt
README.md