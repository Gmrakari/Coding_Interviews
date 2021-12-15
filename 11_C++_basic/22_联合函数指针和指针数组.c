

/*
 * Date:2021-12-15 09:37
 * filename:pointer to function and pointer to array.c
 *
 */

#include <stdio.h>

static int num = 0;

int fun(int* num) {
	num++;
	printf("int* fun(int*):%d\n", *num);
	return 0;
}

int main() {
	int (*(*p)[10])(int*);
	int (*arr[10])(int*);
	p = &arr;
	for (int i = 0;i < 10;i++) {
		(*p)[i] = &fun;
		(*p)[i](&num);
	}
}
