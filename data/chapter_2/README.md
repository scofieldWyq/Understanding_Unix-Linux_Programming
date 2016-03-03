# chapter 2 - 文件读写与缓冲区

## <span id="function">有关的函数以及头文件包含</span>

 - open    /* #include <fcntl.h> */

 - creat   /* #include <fcntl.h> */

 - read    /* #include <unistd.h> */

 - write   /* #include <unistd.h> */

 - lseek   /* #include <sys/types.h> 
              #include <unistd.h> */

 - close   /* #include <unistd.h> */

## 大概的流程

   从 `who`, `cp` 功能去使用这些[读写函数](#function)完成,接着对缓冲区的了解和使用,最后是对系统调用错误的处理。

## who
   
   > 使用 open, read, close 函数实现 who
    
   这里对文件 `utmp` 的读取和格式化输出，就可以做到 `who` 的功能

## cp
   
   > 使用 open, create, read, write, close 函数实现 cp 
  

## 缓冲区


## 系统调用错误

## 总结

