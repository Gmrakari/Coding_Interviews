

/*
 * Date:2021-07-21 09:36
 * filename:12_打印1到最大的n位数.cpp
 *
 */

/*
#题意
题目描述

给定一个数字N，打印从1到最大的N位数。

输入

每个输入文件仅包含一组测试样例。

对于每个测试案例，输入一个数字N(1<=N<=5)。 输出 对应每个测试案例，依次打印从1到最大的N位数。

样例输入

1

样例输出

1 2 3 4 5 6 7 8 9

*/

/*
	 char-'0’对应与char型对应的int型。
	 int-char出来的结果是char型。
	 实际上就是ascii
	 举个例子看：'0'-'0'= 0， '0'+1='1'
	 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void Print1ToMaxOfNDigits_1(int n) {
	int number = 1;
	int i = 0;
	while(i++ < n) {
		number *= 10;
	}
	for (i = 1;i < number;i++) {
		cout << i << " ";
	}
}

void Print1ToMaxOfNDigits(int n) {
	bool Increment(char* number);
	void PrintNumber(char* number);
	if (n <= 0)
		return ;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while(!Increment(number)) {
		PrintNumber(number);
	}
	delete []number;
}

//用O(1)时间判断是不是已经到了最大的n位数
bool Increment(char* number) {
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--) {
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;

		if (nSum >= 10) {
			if (i == 0)
				isOverflow = true;
			else {
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else {
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}


//打印用字符串表示的数字
void PrintNumber(char* number) {
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength;++i) {
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0) {
			printf("%c", number[i]);
		}
	}
	printf("\t");
}

/*
 * 如果我们在数字前面补0的话，就会发现n位所有十进制数其实就是n个从0到9的全排列。
 * 也就是说，我们把数字的每一位都从0到9排列一遍，就得到了所有的十进制数。
 * 只是我们在打印的时候，数字排在前面的0我们不打印出来
 *
 */

void Print1ToMaxOfNDigits_2(int n) {
	void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index);
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0;i < 10;++i) {
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}
void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index) {
	void PrintNumber(char* number);
	if (index == length - 1) {
		PrintNumber(number);
		return ;
	}

	for (int i = 0; i < 10;++i) {
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

int main() {
	/*
		 int n;
		 cin >> n;
		 char *number = new char[n + 1];
		 memset(number, '0', n);
		 for (int i = 0; i < (int)strlen(number); i++) {
		 printf("%c", number[i]);
		 }
		 */
	void Print1ToMaxOfNDigits(int n);
	bool Increment(char* number);
	void PrintNumber(char* number);

	int n;
	cin >> n;
	Print1ToMaxOfNDigits(n);
}
