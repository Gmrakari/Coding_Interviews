#预处理：处理#include、#define、#ifdef 等宏命令
#编译：把预处理完的文件编译为汇编程序.s
#汇编：把汇编程序.s编译为.o二进制文件
#链接：把多个二进制文件.o集合（链接）成一个可执行文件

# $^： 规则中所有的依赖
# $< : 规则中的第一个依赖
# $@：规则中的目标

# 模式自动匹配 %

#目标文件名字
target = test

#编译器，默认是gcc
CC = g++

#编译参数
CFLAG = -Wall

#编译包含的头文件所在目录
include = -I.include/

#所有用到的源文件
src = $(wildcard ./*cpp) 

#把源文件SRCS字符串的后最.cpp改为.o
obj = $(patsubst ./%.cpp, ./%.o, $(src))

$(target) : $(obj)
	$(CC) $^ -o $@

#重定义隐藏规则，匹配上述目标linklist.o & test-main.cpp
%.o : %.cpp
	$(CC) -c $(include) $(CFLAG) $< -o $@

#清空除源文件外的所有生成文件 
.PHONY:clean
clean:
	rm $(obj) $(target) -f

