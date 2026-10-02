# Day21 Workflow

## 1. 创建项目

建立 `day21_handsOn`，使用：

```text
main.cpp
student.h
student.cpp
```

实现学生成绩管理程序。

---

## 2. 实现基础功能

定义 `Student`：

```cpp
int age;
std::string name;
double score;
```

实现：

- `printstudent()`
- `printAll()`
- `getAverage()`
- `getMax()`
- `getMin()`

使用：

```cpp
std::vector<Student>
```

保存多个学生。

---

## 3. 第一次 Debug：vector 越界

故意将 `getMax()` 中的访问改为：

```cpp
student[5]
```

使用：

```bash
g++ -g main.cpp student.cpp -o student
gdb ./student
```

通过：

```gdb
break getMax
run
list
print student.size()
print student[0].score
print student[5].score
```

观察越界访问结果。

确认：

```text
size = 5
合法下标 = 0 ~ 4
```

理解越界访问属于未定义行为。

---

## 4. 第二次 Debug：除零

故意将：

```cpp
return sum / student.size();
```

改为：

```cpp
return sum / 0;
```

重新编译，观察编译器警告。

运行得到：

```text
Average:inf
```

使用 GDB 进入 `getAverage()`，逐步观察：

```text
sum
student.size()
```

追踪学生成绩累加过程：

```text
0
→ 85.5
→ 177.5
→ 256
→ 344
→ 439.5
```

确认前面的数据处理正确，错误发生在最终除法。

---

## 5. 第三次 Debug：空 vector

恢复：

```cpp
return sum / student.size();
```

创建：

```cpp
std::vector<Student> empty;
```

调用：

```cpp
getAverage(empty);
```

通过 GDB 确认：

```text
sum = 0
student.size() = 0
```

运行结果：

```text
-nan
```

定位到空容器导致的：

```text
0.0 / 0
```

---

## 6. 修复 getAverage()

增加空容器判断：

```cpp
if (student.empty())
{
    return 0.0;
}
```

正常数据继续计算：

```cpp
return sum / student.size();
```

重新编译并测试。

---

## 7. 修改 getMax() 接口

发现：

```cpp
const Student&
```

无法表达“没有 Student”。

将返回类型修改为：

```cpp
const Student*
```

空 vector：

```cpp
return nullptr;
```

正常 vector：

```cpp
return maxpeople;
```

`main.cpp` 使用：

```cpp
if (max == nullptr)
```

判断结果。

非空时使用：

```cpp
max->name
max->age
max->score
```

---

## 8. 最终测试

正常数据测试：

```text
Max → Eve → 95.5
Min → Charlie → 78.5
Average → 87.9
```

空 vector 测试：

```text
getMax(empty) → nullptr
getAverage(empty) → 0
```

确认程序可以正常运行。

---

## 9. 本日实际掌握

- 使用 `g++ -g` 编译 Debug 版本
- 使用 GDB 设置断点
- 使用 `list` 查看代码
- 使用 `next` 单步执行
- 使用 `print` 查看变量
- 使用 `continue` 继续运行
- 定位 `vector` 越界
- 定位除零问题
- 处理空 `vector`
- 理解引用无法表示空对象
- 使用指针和 `nullptr` 表达可选对象
- 使用 `->` 访问指针指向对象的成员

## 10. Git

完成代码、README 和 workflow 后：

```bash
git status
git diff
git add .
git diff --cached
git commit -m "feat(day21): practice gdb debugging"
git status
```