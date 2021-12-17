

/*
 * Date:2021-12-17 15:47
 * filename:01_char_strlen_and_sizeof.c
 *
 */

#include <stdio.h>
#include <string.h>

void fun(char m_str[100]) {
	printf("sizeof(m_str):%ld\n",sizeof(m_str));
}

int main() {
	char str[] = "Hello";

	printf("char str[]:%s\n",str);
	printf("sizeof(str) in main:%ld\n", sizeof(str));
	printf("strlen(str):%d\n", (int)strlen(str));

	char* p = str;

	printf("sizeof(p):%ld\n", sizeof(p));

	fun(str);
	return 0;
}
