

/*
 * Date:2021-12-28 09:53
 * filename:strlen.cpp
 *
 */
#include <stdio.h>
#include <string.h>

size_t m_strlen(const char *str) {
	const char *end = str;
	for (; *end != '\0'; end++)
		;

	return end - str;
}

int main() {
	char str[] = "abc";

	printf("%d\n",(int)m_strlen(str));
	printf("%d\n",(int)strlen(str));
}
