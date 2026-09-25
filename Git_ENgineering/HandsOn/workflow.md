# Day15 Git Workflow

## 完整流程

```text
main
 ↓
创建 feature 分支
 ↓
开发功能
 ↓
Build / Test
 ↓
Commit
 ↓
切回 main
 ↓
Merge
 ↓
再次 Build / Test
 ↓
Tag 稳定版本
```

## 常用命令

```bash
# 创建功能分支
git switch -c feature/xxx

# 构建
cmake -S . -B build
cmake --build build

# 查看状态
git status

# 提交
git add .
git commit -m "feat: ..."

# 合并
git switch main
git merge feature/xxx

# 创建版本
git tag v0.3.0

# 查看历史
git log --oneline --decorate --graph --all
```

## 核心原则

- `feature/*`：独立开发功能
- `commit`：记录一个明确的开发节点
- `merge`：将功能合并到 `main`
- Merge 后必须重新 Build / Test
- 确认稳定后再创建 Tag
- `main` 保持可构建、可运行