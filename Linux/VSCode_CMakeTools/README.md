# VS Code + Linux + CMake Tools

## 1. 目标

将 Linux C++ 开发环境接入 VS Code，实现：

- VS Code Remote - WSL
- Linux GCC / G++
- CMake Tools
- C/C++ IntelliSense
- CMake Configure / Build
- Linux 项目代码补全与跳转

---

## 2. 开发环境

- Windows 11
- WSL2
- Ubuntu 24.04
- GCC / G++ 13.3.0
- CMake 3.28.3
- VS Code
- CMake Tools
- C/C++ Extension

VS Code 左下角通过：

```text
WSL: Ubuntu-24.04
```

确认当前处于 Linux 环境。

---

## 3. CMake Tools 基本流程

进入包含 `CMakeLists.txt` 的 Linux 项目后：

```text
选择 CMake Project
        ↓
选择 Linux GCC Kit
        ↓
Configure
        ↓
Build
        ↓
运行生成的程序
```

Linux Kit：

```text
GCC 13.3.0 x86_64-linux-gnu
C=/usr/bin/gcc
CXX=/usr/bin/g++
```

---

## 4. IntelliSense

CMake Tools 可以向 C/C++ 扩展提供当前 CMake 项目的编译信息。

项目配置后可以生成：

```text
build/compile_commands.json
```

其中记录源文件实际使用的：

- 编译器
- Include 路径
- C++ 标准
- 编译参数

C/C++ 扩展根据这些信息进行代码补全、跳转和错误检查。

---

## 5. 多 CMake 项目

`Cpp_Engineering` 中存在多个独立 CMake 项目。

因此每个项目保持自己的：

```text
CMakeLists.txt
build/
└── compile_commands.json
```

不要把整个仓库强制当成一个 CMake 项目。

VS Code 可以打开整个 `Cpp_Engineering`，再通过 CMake Tools 选择当前需要配置的 `CMakeLists.txt`。

---

## 6. 最终形成的开发方式

以后 Linux C++ 项目主要使用：

```text
VS Code
  ↓
Remote - WSL
  ↓
CMake Tools
  ↓
CMake
  ↓
GCC / G++
  ↓
Linux executable
```

VS Code 负责编辑、补全、跳转和调试，CMake Tools 负责项目配置与构建，实际编译环境仍然是 Linux。