# Day17 Workflow：Linux 权限与用户/组

## 1. 创建 Day17 权限实验环境

进入 Linux 环境后，创建 Day17 实验目录：

```bash
cd ~
mkdir day17_permission
cd day17_permission
```

---

## 2. 创建 Shell 测试文件

创建：

```bash
nano hello.sh
```

写入：

```bash
#!/bin/bash

echo "Hello Linux Permission"
```

使用：

```bash
ls -l hello.sh
```

查看文件当前权限。

---

## 3. 实际测试没有执行权限时的情况

直接执行：

```bash
./hello.sh
```

因为当时 `hello.sh` 没有执行权限，所以出现：

```text
Permission denied
```

由此实际遇到了 Linux 文件执行权限问题。

---

## 4. 添加执行权限并重新运行

执行：

```bash
chmod +x hello.sh
```

再次查看：

```bash
ls -l hello.sh
```

确认权限发生变化。

然后重新执行：

```bash
./hello.sh
```

得到：

```text
Hello Linux Permission
```

完成 Shell 文件执行权限实验。

---

## 5. 实际学习数字权限

继续使用 `chmod` 对权限进行修改测试：

```bash
chmod 755 hello.sh
```

并学习使用：

```bash
chmod 644 hello.sh
chmod 640 hello.sh
```

同时实际理解：

```text
4 = r
2 = w
1 = x
```

以及：

```text
755
644
640
```

分别对应的权限组合。

还学习了按照用户类别修改权限：

```bash
chmod u+x hello.sh
chmod g+x hello.sh
chmod o+x hello.sh
chmod a+x hello.sh
```

---

## 6. 查看当前 Linux 用户与组信息

实际使用：

```bash
whoami
```

查看当前使用的 Linux 用户。

使用：

```bash
id
```

查看当前用户的 UID、GID 和所属组。

同时结合之前的：

```bash
ls -l
```

理解文件显示的 owner 和 group。

---

## 7. 学习并实际理解 sudo

结合之前 Linux 环境安装软件时使用过的：

```bash
sudo apt update
sudo apt install build-essential cmake gdb
```

进一步理解 `sudo` 与文件权限的关系。

明确区分：

```text
chmod
→ 修改文件/目录权限

sudo
→ 以更高权限执行当前命令
```

---

## 8. 创建目录权限实验

创建目录和测试文件：

```bash
mkdir demo
touch demo/test.txt
```

查看目录：

```bash
ls -ld demo
```

修改目录权限：

```bash
chmod 700 demo
```

再次查看：

```bash
ls -ld demo
```

确认目录权限变为：

```text
rwx------
```

---

## 9. 实际测试目录权限

进入测试目录：

```bash
cd demo
```

测试创建文件：

```bash
touch new.txt
```

测试删除：

```bash
rm new.txt
```

通过实际操作理解目录权限对文件创建、删除和访问的影响。

---

## 10. Day17 实际完成内容

本次 Day17 实际完成：

```text
创建 Linux 权限实验目录
        ↓
创建 hello.sh
        ↓
查看文件权限
        ↓
直接执行，遇到 Permission denied
        ↓
chmod +x
        ↓
成功执行 hello.sh
        ↓
练习 755 / 644 / 640 等数字权限
        ↓
练习 u/g/o/a+x 权限修改
        ↓
使用 whoami / id 查看用户与组
        ↓
结合 sudo 理解权限提升
        ↓
创建 demo 目录和测试文件
        ↓
chmod 700
        ↓
实际测试目录访问、创建和删除文件
```

以上为 Day17 实际学习与操作过程。