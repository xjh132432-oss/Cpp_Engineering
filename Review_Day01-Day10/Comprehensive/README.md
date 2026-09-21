# Cpp_Engineering Day01-Day10 总复习

## 一、C++ 多文件工程

1. `.h` 文件主要负责什么？
2. `.cpp` 文件主要负责什么？
3. 什么是声明？
4. 什么是定义？
5. 为什么 `.cpp` 通常要 include 自己的 `.h`？
6. `#pragma once` 解决什么问题？

## 二、编译与链接

7. `g++ -c main.cpp` 做什么？
8. `.o` 文件是什么？
9. `-o` 参数有什么作用？
10. 编译和链接有什么区别？
11. 如果函数已经声明，但是链接时报 undefined symbols，应该从哪里排查？

## 三、CMake

12. 为什么需要 CMake？
13. `CMakeLists.txt` 是什么？
14. `project()` 做什么？
15. `set(CMAKE_CXX_STANDARD 17)` 做什么？
16. `add_executable()` 做什么？
17. `cmake -S . -B build` 做什么？
18. `cmake --build build` 做什么？
19. 为什么推荐单独使用 build 目录？

## 四、Target

20. 什么是 target？
21. `target_include_directories()` 做什么？
22. `PRIVATE` 是什么意思？
23. `PUBLIC` 是什么意思？
24. 为什么 CMake 命令经常以 `target_` 开头？

## 五、静态库

25. `add_library(... STATIC ...)` 做什么？
26. 静态库最终是什么？
27. 为什么项目需要拆成 library？
28. `target_link_libraries()` 做什么？
29. `calculator_lib` 和 `day08_app` 分别是什么？
30. 两者之间是什么关系？

## 六、Debug / Release

31. 为什么需要 Debug？
32. 为什么需要 Release？
33. `CMAKE_BUILD_TYPE=Debug` 做什么？
34. `CMAKE_BUILD_TYPE=Release` 做什么？
35. 为什么推荐 `build-debug` 和 `build-release` 分开？

## 七、综合工程

36. 从 `.cpp` 到最终可执行文件经历了什么？
37. CMake 在这个过程中负责什么？
38. 如果头文件找不到，应该检查什么？
39. 如果链接失败，应该检查什么？
40. 如果 CMake 配置成功但编译失败，说明什么？