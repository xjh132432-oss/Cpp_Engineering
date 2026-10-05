# Workflow

## 1. 进入 Linux 环境

在 WSL Ubuntu 中进入项目：

```bash
cd ~/Cpp_Engineering
```

VS Code 使用 Remote - WSL 打开项目。

确认左下角：

```text
WSL: Ubuntu-24.04
```

---

## 2. 选择 CMake 项目

Cpp_Engineering 包含多个独立的 CMake 项目。

在 CMake Tools 中选择需要工作的：

```text
CMakeLists.txt
```

例如：

```text
Linux/TargetLink_OnLinux/CMakeLists.txt
```

---

## 3. 选择 Kit

选择：

```text
GCC 13.3.0 x86_64-linux-gnu
```

对应：

```text
/usr/bin/gcc
/usr/bin/g++
```

Linux 项目不使用 Windows MinGW 编译器。

---

## 4. Configure

执行 CMake Tools 的 Configure。

等价于：

```bash
cmake -S . -B build
```

成功后项目的 `build/` 中会生成 CMake 构建文件。

如果开启：

```text
CMAKE_EXPORT_COMPILE_COMMANDS
```

还会生成：

```text
build/compile_commands.json
```

---

## 5. Build

使用 CMake Tools Build。

等价于：

```bash
cmake --build build
```

构建成功后生成 Linux 可执行文件或库。

---

## 6. IntelliSense

CMake Tools 将当前 CMake 项目的编译信息提供给 C/C++ 扩展。

可以实现：

- 头文件跳转
- 类型跳转
- 成员补全
- Include 路径解析
- 编译错误检查

例如：

```cpp
Student student;

int main()
{
    student.
}
```

在函数体中输入 `student.` 可以获得 `Student` 的成员补全。

---

## 7. 配置问题排查

如果 Linux 项目出现 Windows 编译器配置：

```text
C:\mingw64\bin\g++.exe
```

应检查 VS Code 用户级 C/C++ 配置，避免使用：

```text
windows-gcc-x64
```

Linux 项目应使用：

```text
linux-gcc-x64
```

以及：

```text
/usr/bin/g++
```

优先让 CMake Tools 管理当前项目的编译配置。

---

## 8. 核心工作流

以后 Linux C++ 项目：

```text
进入 WSL
    ↓
VS Code Remote - WSL
    ↓
选择 CMakeLists.txt
    ↓
选择 Linux GCC Kit
    ↓
Configure
    ↓
Build
    ↓
IntelliSense / 跳转 / 补全
    ↓
运行 Linux 程序
```