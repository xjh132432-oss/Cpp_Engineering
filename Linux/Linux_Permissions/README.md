# Day17：Linux 权限与用户/组

## 一、学习目标

理解 Linux 权限系统，以及它在实际 Linux 开发环境中的作用：

- 文件权限
- 用户与组
- `owner / group / other`
- `r / w / x`
- `chmod`
- 数字权限
- `root / sudo`
- 文件权限与目录权限的区别

---

## 二、文件权限

使用：

```bash
ls -l
```

可以看到类似：

```text
-rw-r--r-- 1 qwer qwer ... main.cpp
```

权限部分：

```text
rw- r-- r--
│   │   │
│   │   └── other
│   └────── group
└────────── owner
```

### 普通文件

```text
r → 读取文件内容
w → 修改文件内容
x → 执行文件
```

### 目录

```text
r → 查看目录内容
w → 创建/删除目录中的文件
x → 进入/访问目录
```

---

## 三、Linux 可执行权限

Linux 中文件能否直接执行与执行权限有关。

例如：

```bash
./hello.sh
```

如果没有 `x` 权限，会出现：

```text
Permission denied
```

添加：

```bash
chmod +x hello.sh
```

之后即可执行。

```text
./hello.sh
```

其中：

```text
. → 当前目录
```

Linux 不要求可执行文件必须具有 `.exe` 后缀；Linux 常见可执行程序格式为 ELF。

---

## 四、数字权限

权限对应：

```text
r = 4
w = 2
x = 1
```

组合：

```text
rwx = 7
rw- = 6
r-x = 5
r-- = 4
```

例如：

```text
755 = rwx r-x r-x
644 = rw- r-- r--
640 = rw- r-- ---
700 = rwx --- ---
```

修改权限：

```bash
chmod 755 hello.sh
chmod 644 file
chmod 640 file
chmod 700 demo
```

也可以：

```bash
chmod u+x hello.sh
chmod g+x hello.sh
chmod o+x hello.sh
chmod a+x hello.sh
```

---

## 五、用户与组

Linux 是多用户系统。

查看当前用户：

```bash
whoami
```

查看用户和组信息：

```bash
id
```

文件通常包含：

```text
owner
group
```

再结合：

```text
owner / group / other
```

决定不同用户能够进行什么操作。

组可以把多个用户组织起来，从而统一管理项目文件的访问权限。

---

## 六、root 与 sudo

`root` 是 Linux 中拥有很高系统权限的用户。

普通用户不能随意修改系统文件。

`sudo`：

```bash
sudo command
```

表示以更高权限执行当前命令。

需要区分：

```text
chmod
→ 修改文件/目录本身的权限

sudo
→ 以更高权限执行当前命令
```

---

## 七、目录权限

目录权限与普通文件不同：

```text
r → 查看目录内容
w → 创建/删除目录中的文件
x → 进入/访问目录
```

例如：

```bash
chmod 700 demo
```

表示：

```text
rwx --- ---
```

只有 owner 拥有完整权限。

特别需要注意：

> 删除文件时，主要受到父目录写权限的控制，而不是简单看文件自身是否有 `w` 权限。

---

## 八、常用命令

```bash
ls -l
ls -ld demo

whoami
id

chmod +x hello.sh
chmod 755 hello.sh
chmod 644 file
chmod 640 file
chmod 700 demo

sudo command
```

---

## 九、核心理解

Day17 最终形成：

```text
用户
 ↓
owner / group / other
 ↓
r / w / x
 ↓
4 / 2 / 1
 ↓
755 / 644 / 700
 ↓
chmod
```

同时：

```text
whoami → 当前用户
id     → 用户与组信息
ls -l  → 文件权限、owner、group
chmod  → 修改权限
sudo   → 更高权限执行命令
```

目录则需要单独理解：

```text
目录 r → 查看
目录 w → 创建/删除
目录 x → 进入/访问
```