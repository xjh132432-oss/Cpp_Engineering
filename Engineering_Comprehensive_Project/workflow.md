# Workflow

## 2026-10-06

### 1. 完成 Student Manager

完成学生数据结构及基本功能：

- 添加学生
- 查看所有学生
- 查询学生
- 统计平均分、最高分、最低分
- 菜单与退出

完成 `.h / .cpp` 分离。

### 2. C++ 代码检查与修正

修正并巩固：

- `\n` 换行
- `max / min` 初始化
- `const auto&` 只读遍历
- `vector.empty()`
- 菜单退出与非法输入处理

### 3. CMake

完成：

- `add_executable`
- `add_library`
- Static Library
- `target_include_directories`
- `target_link_libraries`

期间修复：

- `add_library` 参数错误
- `student_lib` 拼写错误

### 4. Linux 构建

完成：

```bash
cmake -S . -B build
cmake --build build
```

成功生成：

```text
student_manager
libstudent_lib.a
```

### 5. Debug 与 GDB

完成 Debug 构建：

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

使用 GDB 对 `ShowStatistics()` 进行调试，完成断点、运行、变量观察和单步调试。

## Result

完成一次从：

```text
C++ 多文件
→ CMake
→ 静态库
→ 编译
→ 链接
→ Linux 运行
→ Debug
→ GDB
```

的完整工程实践。