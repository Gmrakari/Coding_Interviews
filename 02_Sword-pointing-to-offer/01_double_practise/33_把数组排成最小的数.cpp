

/*
 * Date:2021-07-23 16:39
 * filename:33_把数组排成最小的数.cpp
 *
 */
/*
#题意
题目描述

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。 

例如输入数组{3，32，321}

输出则打印出这三个数字能排成的最小数字为321323


*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

int compare(const void* strNumber1, const void* strNumber2) {
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	strcat(g_StrCombine1, *(const char**)strNumber2);

	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcpy(g_StrCombine2, *(const char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}


void PrintMinNumber(int* numbers, int length) {
	if (numbers == NULL || length <= 0) return ;

	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; ++i) {
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for(int i = 0; i < length; ++i) 
		printf("%s", strNumbers[i]);
	printf("\n");

	for (int i = 0; i < length; ++i) 
		delete[] strNumbers[i];
	delete[] strNumbers;
}

int main() {
	int number[] = {3, 32, 321};
	int length = sizeof(number) / sizeof(number[0]);

	PrintMinNumber(number, length);
}
