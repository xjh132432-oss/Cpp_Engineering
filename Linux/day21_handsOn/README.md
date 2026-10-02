# Day21 Hands-on：C++ + GDB Debugging

## 1. 项目简介

通过一个简单的学生成绩管理程序，进行 Linux 下 C++ 实际开发与 GDB 调试练习。

重点不是继续学习 C++ 语法，而是训练：

- 多文件 C++ 程序调试
- GDB 断点、单步执行、变量查看
- `vector` 边界问题定位
- 除零问题定位
- 空容器边界条件处理
- 指针与引用在函数接口设计中的区别

---

## 2. 项目结构

```text
day21_handsOn/
└── src/
    ├── main.cpp
    ├── student.h
    └── student.cpp
```

### 核心数据结构

```cpp
struct Student {
    int age;
    std::string name;
    double score;
};
```

实现功能：

- 输出单个学生信息
- 输出全部学生
- 计算平均分
- 查找最高分学生
- 查找最低分学生

---

## 3. 本日核心内容

### GDB 基础调试

实际使用：

```bash
g++ -g main.cpp student.cpp -o student
gdb ./student
```

主要练习：

```gdb
break
run
list
next
print
continue
```

通过逐步执行观察变量状态，而不是只看最终输出。

---

## 4. 实际 Debug 案例

### 4.1 `vector` 越界

故意访问：

```cpp
student[5]
```

实际数据只有 5 个元素：

```text
合法下标：0 ~ 4
```

通过 GDB 观察到越界访问可能不会立即崩溃，但得到的数据并不可靠。

结论：

> 程序没有崩溃不代表程序正确，越界访问属于未定义行为。

---

### 4.2 除零

故意修改为：

```cpp
return sum / 0;
```

运行得到：

```text
Average:inf
```

随后测试空 `vector`：

```cpp
std::vector<Student> empty;
```

此时：

```text
sum = 0
student.size() = 0
```

执行：

```cpp
0.0 / 0
```

得到：

```text
-nan
```

通过 GDB 定位到真正的问题：

```cpp
return sum / student.size();
```

---

### 4.3 空 `vector` 边界处理

使用：

```cpp
if (student.empty())
{
    return 0.0;
}
```

避免空容器进行除零操作。

---

### 4.4 引用与指针接口设计

原来的 `getMax()`：

```cpp
const Student& getMax(const std::vector<Student>& student);
```

发现空 `vector` 时不存在可以返回的 `Student` 对象。

因此修改为：

```cpp
const Student* getMax(const std::vector<Student>& student);
```

空容器：

```cpp
return nullptr;
```

调用方：

```cpp
if (max == nullptr)
{
    std::cout << "empty vector!" << std::endl;
}
else
{
    std::cout << max->name << std::endl;
}
```

由此练习：

```text
引用 → 必须引用有效对象
指针 → 可以表示“没有对象”（nullptr）
```

---

## 5. 最终测试

正常数据：

```text
Alice 20 85.5
Bob 21 92
Charlie 19 78.5
David 20 88
Eve 21 95.5
```

结果：

```text
Min:
Name:Charlie
Age:19
Score:78.5

Max:
Name:Eve
Age:21
Score:95.5
```

空 `vector`：

```text
empty vector!
0
```

说明最高分和平均分的空容器边界情况均已处理。

---

## 6. 本日重点

```text
编译
  ↓
运行
  ↓
发现异常
  ↓
GDB 设置断点
  ↓
单步执行
  ↓
print 查看变量
  ↓
定位错误
  ↓
修改代码
  ↓
重新编译
  ↓
重新测试
```

核心目标：

> 从“看到错误”进一步做到“通过调试工具定位错误发生的位置和原因”。