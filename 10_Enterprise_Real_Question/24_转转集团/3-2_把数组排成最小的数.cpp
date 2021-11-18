

/*
 * Date:2021-11-17 20:49
 * filename:3-2_把数组排成最小的数.cpp
 *
 */

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

void PrintMinNumber1(int* numbers, int length) {
	if (numbers == NULL || length <= 0)
		return ;

	char** strNumbers = (char**)(new int[length]);
	for (int i = 0;i < length; ++i) {
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0;i < length; ++i) 
		printf("%s", strNumbers[i]);
	printf("\n");

	for (int i = 0;i < length; ++i)  
		delete[] strNumbers[i];
	delete[] strNumbers;

}


class Solution {
public:
	string PrintMinNumber(vector<int> number) {
		string str;
		for (int i = 0;i < (int)number.size(); ++i) {
			str += number[i];
		}
		return str;
	}
};

void test() {
	int number[] = {3, 32, 321};
	int length = sizeof(number) / sizeof(number[0]);

	PrintMinNumber1(number, length);

}

int main() {
	test();

}
