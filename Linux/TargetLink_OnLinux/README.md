# Day23：CMake 多 Target + 静态库 + Linux 工程排错

## 一、今日目标

在 Linux 环境下复习并实践：

- CMake 多 Target
- 静态库
- `target_link_libraries`
- CMake 编译过程
- 编译错误与链接错误的区别
- 使用实际构建输出定位问题

## 二、项目结构

```text
day23/
├── CMakeLists.txt
├── include/
│   └── student.h
├── src/
│   ├── student.cpp
│   └── main.cpp
├── build/
├── README.md
└── workflow.md
```

## 三、CMake 多 Target

项目包含两个 Target：

```text
student.cpp
    ↓
student_lib
    ↓
libstudent_lib.a

main.cpp
    ↓
student_manager
```

通过：

```cmake
add_library(student_lib STATIC src/student.cpp)

add_executable(student_manager
    src/main.cpp
)

target_link_libraries(student_manager
    PRIVATE
    student_lib
)
```

建立静态库与可执行文件之间的链接关系。

最终：

```text
main.cpp.o + libstudent_lib.a
            ↓
     student_manager
```

## 四、Linux 构建结果

使用：

```bash
cmake -S . -B build
cmake --build build --verbose
```

观察到：

```text
student.cpp
    ↓
student.cpp.o
    ↓
libstudent_lib.a

main.cpp
    ↓
main.cpp.o
    ↓
main.cpp.o + libstudent_lib.a
    ↓
student_manager
```

检查文件：

```bash
file build/libstudent_lib.a build/student_manager
```

结果：

```text
libstudent_lib.a → current ar archive
student_manager  → ELF 64-bit LSB pie executable
```

## 五、编译错误排查

故意将：

```cmake
${CMAKE_CURRENT_SOURCE_DIR}/include
```

改成错误路径：

```cmake
${CMAKE_CURRENT_SOURCE_DIR}/includ
```

构建时出现：

```text
fatal error: student.h: No such file or directory
```

错误发生在：

```text
student.cpp
    ↓
编译
    ↓
student.cpp.o
```

原因是 CMake 传递给编译器的头文件搜索路径错误。

修复后，通过 verbose 输出确认：

```text
-I/home/qwer/day23/include
```

程序重新构建并正常运行。

## 六、链接错误排查

故意将 `student.cpp` 中的：

```cpp
getMax()
```

改为：

```cpp
getMaxxxx()
```

但 `student.h` 和 `main.cpp` 仍然使用：

```cpp
getMax()
```

构建结果：

```text
student_lib
    ↓
编译成功
    ↓
libstudent_lib.a

main.cpp
    ↓
编译成功
    ↓
main.cpp.o

最终链接
    ↓
undefined reference to `getMax(...)`
```

说明：

- `student.cpp` 可以正常编译
- `main.cpp` 可以正常编译
- 最终链接阶段找不到 `getMax()` 的实现

## 七、今日核心认知

### 编译错误

典型错误：

```text
fatal error: student.h: No such file or directory
```

发生在：

```text
.cpp → .o
```

常见原因：

- 头文件不存在
- include 路径错误
- 头文件无法找到

### 链接错误

典型错误：

```text
undefined reference to `getMax(...)'
```

发生在：

```text
.o / .a → 可执行文件
```

常见原因：

- 函数只有声明没有正确实现
- 实现与声明不一致
- 库没有正确链接

### 工程排错思路

```text
出现错误
   ↓
判断失败阶段
   ↓
编译？链接？运行？
   ↓
检查对应阶段负责的内容
   ↓
定位问题
   ↓
修复
   ↓
重新构建验证
```