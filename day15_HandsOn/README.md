# Day15 - Git 工程化完整工作流

## 一、学习目标

综合 Day11-Day14：

- Feature Branch
- Commit
- Merge
- Build / Test
- Tag
- 完整开发流程

## 二、项目结构

```text
day15/
├── CMakeLists.txt
├── include/
│   └── calculator.h
├── src/
│   ├── calculator.cpp
│   └── main.cpp
├── build/
└── README.md
```

## 三、功能

- `add()`：加法
- `multiply()`：乘法
- `subtract()`：减法
- `square()`：平方

## 四、构建与运行

```bash
cmake -S . -B build
cmake --build build
./build/calculator
```

运行结果：

```text
add: 30
multiply: 200
subtract: 10
square: 25
```

## 五、Git 工作流

```text
main
 ↓
feature/day15-subtract
 ↓
开发 → Build/Test → Commit
 ↓
Merge
 ↓
feature/day15-square
 ↓
开发 → Build/Test → Commit
 ↓
Merge
 ↓
Build/Test
 ↓
v0.3.0
```

## 六、关键命令

```bash
git switch -c feature/xxx
git add .
git commit -m "feat: ..."
git switch main
git merge feature/xxx
git tag v0.3.0
```

## 七、复习要点

1. Branch 用于隔离功能开发。
2. Commit 用于记录明确的开发节点。
3. Merge 将功能交付到 `main`。
4. Merge 后重新 Build/Test。
5. 稳定代码使用 Tag 标记版本。
