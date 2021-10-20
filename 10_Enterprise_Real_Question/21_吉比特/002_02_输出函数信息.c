

/*
 * Date:2021-10-20 15:18
 * filename:002_02_输出函数信息.c
 *
 */

#include <cstdio>

int f(int x) {
	return x & (-x);
}

int main() {
	printf("%d,%d",f(127), f(128));
	return 0;
}
