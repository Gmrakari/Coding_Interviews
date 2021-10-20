

/*
 * Date:2021-10-20 16:14
 * filename:002_04_计算变量的值.cpp
 *
 */

#include <iostream>
void fun(int x, int *y, int &z) {
	x = *y = z;
	*y = x + z;
	z = x + *y;
}

int main() {
	int a = 1;
	int b = 2;
	int c = 3;
	fun(a, &b, c);
	printf("%d,%d,%d",a, b, c);
	return 0;
}
