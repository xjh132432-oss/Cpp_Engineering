# Day 11：Git 分支与工程开发流程

## 一、今日目标

- 理解 Git 分支
- 掌握 feature 分支开发流程
- 掌握 switch
- 掌握 merge
- 理解 main 与 feature 分支的关系
- 将 Git 分支应用到 C++ 工程开发

## 二、核心知识

### 1. Git 分支

分支本质上是指向某个 commit 的引用。

### 2. feature 分支

用于独立开发一个新功能，不直接修改 main。

### 3. merge

将一个分支的开发成果合并到另一个分支。

## 三、今日项目结构

```text
day11/
├── main.cpp
├── calculator.cpp
├── calculator.h
└── README.md