

/*
 * Date:2021-10-23 10:52
 * filename:05_函数中的指针参数.c
 *
 */

#include <stdio.h>

void test(char *p) {
	p = "abc";
}

char* test_2(char *p) {
	char *tmp = "abc";
	p = tmp;
	return p;
}

int main() {
	char *p = "test";
	//test(p);
	test_2(p);
	printf("%s\n",p);
}
