

/*
 * Date:2021-10-24 09:11
 * filename:07_字符串的正确处理.c
 *
 */

#include <stdio.h>
#include <string.h>

void fun_a() {
	char buf[4] = {0};
	memcpy(buf, "hello", strlen("hel"));
	printf("%s\n",buf);
}

void fun_b() {
	char buf[] = "hell";
	printf("%s\n",buf);
}

void fun_c() {
	char buf[4];
	strcpy(buf, "hell"); //‘void* __builtin_memcpy(void*, const void*, long unsigned int)’ 
											//writing 5 bytes into a region of size 4 overflows the destination
	printf("%s\n",buf);
}

void fun_d() {
	char buf[4] = "hell"; //initializer-string for char array is too long 初始化超过定义的长度
	printf("%s\n",buf);
}

int main() {
	//fun_a();
	//fun_b();
	//fun_c();
	fun_d();
}
