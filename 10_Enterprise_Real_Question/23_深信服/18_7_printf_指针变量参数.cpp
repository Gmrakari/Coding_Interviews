

/*
 * Date:2021-10-24 12:17
 * filename:18_7_printf_指针变量参数.cpp
 *
 */

#include <stdio.h>

int fun(int *ptr, int val) {
	*ptr = 1;
	val = 1;
	return *ptr + val;
}

void caller(int val) {
	int ptr = 2;
	int ret;
	val = 3;
	ret = fun(&ptr, val);
	printf("ptr = %d,val = %d,ret = %d\n",ptr, val,ret);
}

int main() {
	caller(1);
}
