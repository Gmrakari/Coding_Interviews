

/*
 * Date:2021-10-20 14:59
 * filename:002_01_打印字符串信息.cpp
 *
 */

#include <stdio.h>
#include <string.h> 
#include <iostream>
using namespace std;

void foo(char* s, int left, int right) {
	int i, j;
	char x, y;
	i = left;
	j = right;
	x = s[(left + right) / 2];
	do {
		while (s[i] > x && i < right) i++;
		while (s[j] < x && j > left) j--;

		if (i <= j) {
			y = s[i];
			s[i] = s[j];
			s[j] = y;
			i++;
			j--;
		}
	}while (i <= y);
}

int main() {
	char str[] = "abcdefghijklm";
	foo(str, 0, (int)strlen(str) - 1);
	cout << "s:";
	printf("%s", str);
	return 0;
}
