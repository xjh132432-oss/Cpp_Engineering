# Day19 Workflow

## 1. 创建实验目录

```bash
mkdir -p ~/day19_gdb
cd ~/day19_gdb
```

## 2. 创建 C++ 调试程序

创建 `main.cpp`，编写 `add()` 函数和 `main()`，用于后续 GDB 调试。

主要代码结构：

```cpp
int add(int a, int b)
{
    int result = a + b;
    return result;
}

int main()
{
    int x = 10;
    int y = 20;

    int sum = add(x, y);

    std::cout << sum << std::endl;

    return 0;
}
```

## 3. 使用调试信息编译

```bash
g++ -g main.cpp -o demo
```

使用 `-g` 生成 GDB 所需的调试信息。

## 4. 启动 GDB

```bash
gdb demo
```

进入：

```text
(gdb)
```

## 5. 设置断点

使用：

```gdb
break 14
```

查看断点：

```gdb
info breakpoints
```

## 6. 运行并暂停程序

```gdb
run
```

程序运行到断点后暂停。

## 7. 查看变量

使用：

```gdb
print x
print y
```

查看当前变量值。

## 8. 单步执行

使用：

```gdb
next
```

执行当前代码行。

使用：

```gdb
step
```

进入函数内部执行。

## 9. 查看当前代码

```gdb
list
```

查看当前调试位置附近的源代码。

## 10. 继续运行

```gdb
continue
```

让程序继续运行到下一个断点或程序结束。

## 11. 退出 GDB

```gdb
quit
```

## Day19 实际操作流程

```text
创建 day19_gdb
    ↓
编写 main.cpp
    ↓
g++ -g 编译
    ↓
gdb demo
    ↓
设置断点
    ↓
run
    ↓
print 查看变量
    ↓
next / step 单步执行
    ↓
list 查看代码
    ↓
continue
    ↓
quit
```SW