

/*
 * Date:2021-10-24 11:59
 * filename:16_5_static变量分析.c
 *
 */

#include <stdio.h>

void func(void) {
	static int i;
	++i;
	printf("i:%d\t",i);
}

int main() {
	for (int i = 0;i < 3;i++) {
		func();
	}
	return 0;
}
