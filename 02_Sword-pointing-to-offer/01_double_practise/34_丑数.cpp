

/*
 * Date:2021-07-24 10:40
 * filename:34_丑数.cpp
 *
 */

/*
#题意
题目描述

把只包含因子2、3和5的数称作丑数（Ugly Number）。

例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//方法一:逐个判断每个整数是不是丑数的解法 直观但是不够高效

bool IsUgly(int number) {
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0) 
		number /= 3;
	while (number % 5 == 0) 
		number /= 5;

	return (number == 1) ? true : false;
}

int GetUglyNumber(int index) {
	if (index <= 0)
		return 0;
	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index) {
		++number;
		if (IsUgly(number)) {
			++uglyFound;
		}
	}
	return number;
}

int GetUglyNumber_DP(int index) {
	vector<int> dp(index + 1);
	dp[1] = 1;
	int p2 = 1;
	int p3 = 1;
	int p5 = 1;
	for (int i = 2; i < index + 1;i++) {
		int t2 = dp[p2] * 2;
		int t3 = dp[p3] * 3;
		int t5 = dp[p5] * 5;
		dp[i] = min(t2,min(t3, t5));
		if (t2 == dp[i])
			p2++;
		if (t3 == dp[i])
			p3++;
		if (t5 == dp[i])
			p5++;
	}
	return dp[index];
}

//创建数组保存已经找到的丑数,用空间换时间的解法
int GetUglyNumber_2(int index) {
	int Min(int number1, int number2, int number3);
	if (index <= 0) 
		return 0;

	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while (nextUglyIndex < index) {
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
			++pMultiply5;

		++nextUglyIndex;
	}

	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

int Min(int number1, int number2, int number3) {
	int min = (number1 < number2) ? number1 : number2;
	min = min < number3 ? min : number3;
	return min;
}

int main() {
	cout << "逐个判断:";
	cout << GetUglyNumber(8) << endl;
	cout << "dp:";
	cout << GetUglyNumber_DP(8) << endl;
	cout << "用空间换时间:";
	cout << GetUglyNumber_2(8) << endl;
}
