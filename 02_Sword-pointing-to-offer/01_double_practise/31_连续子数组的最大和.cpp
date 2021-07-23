

/*
 * Date:2021-07-23 14:05
 * filename:31_连续子数组的最大和.cpp
 *
 */

// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。
// 求所有子数组的和的最大值。要求时间复杂度为O(n)。


#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// 解法一: 举例分析数组的规律
bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength) {
	if ((pData == NULL) || (nLength <= 0)) {
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;
	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for (int i = 0;i < nLength;++i) {
		if (nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}
	return nGreatestSum;
}

// 动态规划
int FindGreatestSumOfSubArray_DP(int *pData, int nLength) {
	if ((pData == NULL) || (nLength <= 0)) {
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;

	int N = 800000;
	int nGreatestSum[N];
	int maxNum;
	maxNum = nGreatestSum[0] = pData[0];
	for (int i = 1; i < nLength - 1;i++) {
		nGreatestSum[i] = max(pData[i], nGreatestSum[i - 1] + pData[i]);
		if (nGreatestSum[i] > maxNum) {
			maxNum = nGreatestSum[i];
		}

	}
	return maxNum;
}

void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if(testName != NULL)
		printf("%s begins: \n", testName);

	cout << "array:";
	int result = FindGreatestSumOfSubArray(pData, nLength);
	cout << result << endl;

	cout << "DP: ";	
	result = FindGreatestSumOfSubArray_DP(pData, nLength);
	cout << result << endl;

	if(result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
	int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

int main() {
	Test1();
}
