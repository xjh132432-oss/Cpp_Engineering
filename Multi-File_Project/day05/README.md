# Day 05：多文件工程实战

## 一、今日目标

- 使用多个模块完成一个实际程序
- 理解模块职责分离
- 理解 `main.cpp`、功能模块、输出模块之间的关系
- 独立完成多文件工程编译
- 在已有工程基础上增加新功能

## 二、工程结构

```text
day05/
├── include/
│   ├── student.h
│   └── printer.h
├── src/
│   ├── student.cpp
│   ├── printer.cpp
│   └── main.cpp
├── README.md
└── .gitignore