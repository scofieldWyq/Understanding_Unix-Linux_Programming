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


### 系统调用错误

### 总结
# <span id="log">Question</span>
2016-3-2 by wuyingqiang

  - 再次理解 fgets, fputs, fgetc, fputc 的函数功能. 
