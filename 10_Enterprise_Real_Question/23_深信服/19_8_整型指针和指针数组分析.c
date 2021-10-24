

/*
 * Date:2021-10-24 12:25
 * filename:19_8_整型指针和指针数组分析.c
 *
 */

#include <stdio.h>

void foo(void) {
	int a[5][2] = {
		0,1,2,3,4,5,6,7
	};

	int *p1 = a[1];
	int (*p2)[2] = &a[1];
	printf("*p1++:%d\n",*p1++);
	printf("*++p1:%d\n",*++p1);
	printf("**p2:%d\n",**p2);
	printf("p2[2][2]:%d\n",p2[2][2]);
}

int main() {
	foo();
}
