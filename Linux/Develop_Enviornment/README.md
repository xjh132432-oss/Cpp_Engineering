
# Day16 — Linux Development Environment

## 1. Learning Goals

- 在 Ubuntu 24.04 中建立 C++ 开发环境
- 掌握 Linux 下 GCC / CMake / GDB 的基本使用
- 将已有 C++ 工程能力迁移到 Linux 环境
- 使用 Git 完成 Linux → GitHub 的工程协作流程

## 2. Development Environment

| Tool | Version |
|---|---|
| OS | Ubuntu 24.04 LTS |
| Compiler | GCC/G++ 13.3.0 |
| Build System | CMake 3.28.3 |
| Debugger | GDB 15.1 |
| Git | 2.43.0 |

工具路径：

```text
/usr/bin/g++
/usr/bin/cmake
/usr/bin/gdb
```

## 3. Core Understanding

Windows、macOS、Linux 可以分别拥有自己的 Git 工作区：

```text
Windows
   ↓ push
GitHub
   ↑ pull
Ubuntu / Linux
```

Git 仓库与操作系统无关。

Linux 工作区使用：

```text
~/Cpp_Engineering
```

作为本地工程目录，通过 GitHub 与其他设备同步。

## 4. Verification

验证 GCC：

```bash
g++ --version
which g++
```

验证 CMake：

```bash
cmake --version
which cmake
```

验证 GDB：

```bash
gdb --version
which gdb
```

当前环境验证通过。

## 5. Day16 Result

已经完成 Ubuntu Linux C++ 开发环境的建立与工具链验证。

下一步将在 Linux 环境中实际构建 `Cpp_Engineering`，验证 GCC + CMake 的完整工程流程。