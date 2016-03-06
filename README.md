# Understanding Unix/Linux Progamming

#Index
 1. [intentio](#intention)
 2. [Start](#chapters)

# <span id="intention">What is my intention</span>
 为了更加深入的学习Linux，还有参考了 `Understanding Unix/linux Programming` 的内容来完成我在里面的学习过程和代码的训练

# <span id="chapters">Start to Learn</span>

## chapter One - Unix 系统编程概述
 - 介绍
   
 >  涉及什么是系统编程，Unix系统编程。从分析系统入手，解释如何写系统相关的程序，然后分析Unix的命令，最后就是来动手实现

 - 系统编程

   + 什么是系统编程
     
     简单的程序模型：程序对输入数据的处理然后输出。

     系统模型：在一个多用户的系统中，简单模型已经不再适用，多个用同时运行多个程序，也有可能访问多个设备

     虽然模型复杂了，但是程序而言使用的还是简单模型。

     **考虑**：更为复杂的情况，有许多键盘和显示器随意链接到不同的程序，随意操作它们。但是在计算机内部，这种随意却是不允许的，必须采用一种`机制`进行管理。

     操作系统管理所有资源，是的混乱状态得到改变，为程序提供服务。这就是操作系统的职责。程序对于设备的访问都必须经过内核(操作系统)的才能操作。

     在进行系统编程时，必须对系统的结构和工作方式有深刻的了解，也要知道内核提供哪些服务？如何使用它们。

   + 理解系统编程
    
     内核提供服务，使得程序可以访问系统资源。

     通过三个方面来理解
     
     1. 分析程序
     2. 学习系统调用
     3. 程序实现

 - 理解Unix

   + 从用户的角度来理解Unix
     
     Unix可以为我们提供的服务，它能为我们做什么？

     Unix下的很多软件就是为我们的需求提供服务的方式。例如：`date`, `fortune`, `ls`, `cd`, ...

   + 从系统的角度来看Unix
     
     Unix 提供通信，协作，网络访问等功能。也就是对资源的调度和协调，程序之间可以相互协作之类的。

 - 动手实践

   便携关于 `more` 的功能程序

 - 工作步骤和概要图
   
   empty...

## Chapter 2 - Unix/Linux 的文件读写和缓存

### <span id="function">有关的函数以及头文件包含</span>

 - open    /* #include <fcntl.h> */

 - creat   /* #include <fcntl.h> */

 - read    /* #include <unistd.h> */

 - write   /* #include <unistd.h> */

 - lseek   /* #include <sys/types.h> 
              #include <unistd.h> */

 - close   /* #include <unistd.h> */

### 大概的流程

   从 `who`, `cp` 功能去使用这些[读写函数](#function)完成,接着对缓冲区的了解和使用,最后是对系统调用错误的处理。

### who
   
   > 使用 open, read, close 函数实现 who 


### cp
   
   > 使用 open, create, read, write, close 函数实现 cp  

### 缓冲区

   > 对于缓冲的使用，会节省很多次系统调用所消耗的时间。

  缓存区的大小对性能的影响，就像一个小勺子和一个大勺子去打汤一样，同样的时间勺子打到的汤是不一样的。

  一个文件大小 `2500` bytes, 第一个缓存区有 `100` bytes,那么 `cp` 就需要 `25` 次 read  和 `25` 次 write ,总共系统调用 `50` 次，那么缓冲区增加到 `1000` bytes，系统调用就会减少到 `6` 次这样。确实是可观的。

  系统调用需要时间，频繁的系统调用会降低程序的运行效率。

  缓存技术会加快程序的运行效率。

### 系统调用错误

   内核通过 `errno` 这个全局变量来指明错误的类型。

   提供了 `perror()` 来实现错误信息的显示。
 
### 总结
   系统调用的文件读写操作
   对于缓冲区重要性的了解
   对于系统调用错误信息的使用
   
## Chapter 3 - 目录的操作

### 有关函数与头文件包含和结构体

 /* include <sys/types.h> */
 /* include <dirent.h> */
 - opendir 打开目录
 - readdir 读取目录
 - closedir 关闭目录
 
 /* include <sys/stat.h> */ 
 - stat 获取文件的信息

 /* include <pwd.h> */
 /* include <grp.h> */
 - getpwuid 获取用户名的ID
 - getgrgid 获取组名的ID

 - struct `dirent` 目录结构 /* include <dirent> */

 /* include <stdio.h> */
 - rename 更改名字

 /* include <sys/types.h> */
 /* include <sys/stat.h> */
 - chmod 更改文件的掩码 

 /* include <unistd.h> */
 - chown 更改文件所有者

### 编写 ls 命令 

### 关于目录

## Chapter 4 - 文件与目录如何在磁盘中组织的

### 问题

  目录是一个树状的结构，在磁盘中存储。那么磁盘是如何显示为一个包含文件，属性和目录的树状结构呢？我们需要编写一个 pwd 的命令来分析它

  上一章，了解有关于文件属性，目录内容，用户和组的结构。这一章就需要来分析一下磁盘与文件树的映射表现。

### 需要了解文件系统的内部结构

   文件系统大概的构成 |`super block`|`i-node table`| `data area`|
  
   每个文件都是一个`i-node`，也包括目录。

   目录就是一个 `文件名` & `i-node` 的列表。

   super block 记录了文件系统的一个总结信息。包括了很多总结的信息。

   `i-node` 记录了文件的属性，也有关于文件内容相应的 `data` 块。

   **一切都是文件**

   目录也属于文件，不过内容就是 `文件 `和 `i-node` 的列表集。

   文件之间的链接就是之间的包含，例如子目录包含父目录的指针   
###  
# <span id="log">Question</span>
2016-3-2 by wuyingqiang

  - 再次理解 `fgets`, `fputs`, `fgetc`, `fputc` 的函数功能. 
  - 了解 `errno`,`perror()`
