

/*
 * Date:2021-10-26 10:11
 * filename:09_enum_数据内容.c
 *
 */

#include <stdio.h>

enum etest {
	eparam1,
	eparam2,
	eparam3 = 10,
	eparam4,
	eparam5 = 'a',
	eparam6
}epr;

int main() {
	printf("%d,%d\n",eparam4, eparam6);
	return 0;
}
