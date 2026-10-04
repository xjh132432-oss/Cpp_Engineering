# Day23 Workflow

## 1. 创建 CMake 多 Target

将项目拆分为：

```text
student_lib
student_manager
```

使用静态库：

```cmake
add_library(student_lib STATIC src/student.cpp)
```

创建可执行文件：

```cmake
add_executable(student_manager
    src/main.cpp
)
```

使用：

```cmake
target_link_libraries(student_manager PRIVATE student_lib)
```

完成静态库与可执行文件的链接。

## 2. 构建并检查

执行：

```bash
rm -rf build
cmake -S . -B build
cmake --build build --verbose
```

确认生成：

```text
build/libstudent_lib.a
build/student_manager
```

使用：

```bash
file build/libstudent_lib.a build/student_manager
```

确认静态库和 ELF 可执行文件类型。

程序运行正常：

```bash
./build/student_manager
```

## 3. 排查 CMake include 路径错误

故意将：

```text
include
```

修改为：

```text
includ
```

重新构建：

```bash
cmake --build build
```

出现：

```text
fatal error: student.h: No such file or directory
```

判断为编译阶段错误。

恢复正确路径：

```text
${CMAKE_CURRENT_SOURCE_DIR}/include
```

重新构建并运行，验证修复成功。

## 4. 排查链接错误

故意将 `student.cpp` 中：

```text
getMax()
```

修改为：

```text
getMaxxxx()
```

保持 `student.h` 和 `main.cpp` 中的 `getMax()` 不变。

重新构建：

```bash
rm -rf build
cmake -S . -B build
cmake --build build
```

观察到：

```text
student_lib 编译成功
main.cpp 编译成功
最终链接失败
```

错误：

```text
undefined reference to `getMax(...)'
```

判断为链接阶段错误。

## 5. 恢复代码

将：

```text
getMaxxxx()
```

恢复为：

```text
getMax()
```

重新构建并运行，确认程序恢复正常。

## 6. 今日完成

- CMake 多 Target
- 静态库 `add_library`
- 可执行文件 `add_executable`
- `target_link_libraries`
- Linux 静态库与 ELF 文件检查
- CMake include 路径错误排查
- 编译错误定位
- 链接错误定位
- CMake + Linux 工程排错流程