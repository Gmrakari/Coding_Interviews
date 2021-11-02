

/*
 * Date:2021-11-02 20:14
 * filename:11_&_操作符号.c
 *
 */

#include <stdio.h>

void testB() {
	int i = 5, j = 7;
	printf("%d\n", i & j);
}

void testA() {
	int i = 900, j = 817;
	printf("%d\n", i & j);
}

int main() {
	testB();
}
