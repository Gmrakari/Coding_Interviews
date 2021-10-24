

/*
 * Date:2021-10-24 11:00
 * filename:14_3_struct_成员变量和函数输出.c
 *
 */

#include <stdio.h>

int a;

void func(void) {
	printf("%d",a);
}
int main() {
	func();
}
