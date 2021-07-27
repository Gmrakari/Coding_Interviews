

/*
 * Date:2021-07-27 10:20
 * filename:43_n个骰子的点数.cpp
 *
 */

/*
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 解法一：基于递归求骰子点数，时间效率不够高

 考虑如何统计每一个点数出现的次数

 要想求出n个骰子的点数和，可以先把n个骰子分为两堆：第一堆只有一个，另一个有n - 1个。单独的那一个有可能出现从1到6的点数。
 我们需要从1到6的每一种点数和剩下的n - 1个骰子来计算点数和。
 接下来把剩下的n - 1个骰子还是分成两堆，第一堆只有一个，第二堆有 n - 2个。
 我们把上一轮那个单独骰子的点数和这一轮单独骰子的点数相加，再和剩下的n - 2个骰子来计算点数和。
 递归结束的条件就是最后只剩下一个骰子

 定义一个长度为6n - n + 1的数组，和为s的点数出现的次数保存到数组第s - n个元素里
 */

#include <bits/stdc++.h>
using namespace std;
int g_maxValue = 6;

void PrintProbability(int number) {
	void Probability(int number, int* pProbabilities);
	if (number < 1) 
		return ;

	int maxSum = number * g_maxValue;
	int* pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; ++i) 
		pProbabilities[i - number] = 0;
	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum;++i) {
		double ratio = (double)pProbabilities[i - number] / total;
		printf("%d: %e\n", i, ratio);
	}
	delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities) {
	void Probability(int original, int current, int sum, int* pProbabilities);
	for (int i = 1; i <= g_maxValue; ++i) 
		Probability(number, number, i, pProbabilities);
}

void Probability(int original, int current, int sum, int* pProbabilities) {
	if (current == 1) 
		pProbabilities[sum - original]++;
	else {
		for (int i = 1; i <= g_maxValue; ++i) {
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

//解法二，基于循环求骰子点数，时间性能好
void PrintProbability_2(int number) {
	if (number < 1) 
		return ;

	int* pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];

	for (int i = 0; i < g_maxValue * number + 1; ++i) {
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i <= g_maxValue; ++i) 
		pProbabilities[flag][i] = 1;

	for (int k = 2; k <= number; ++k) {
		for (int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;

		for (int i = k; i <= g_maxValue * k; ++i) {
			pProbabilities[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= g_maxValue; ++j) 
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
		}
		flag = 1 - flag;
	}

	double total = pow((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; ++i) {
		double ratio = (double)pProbabilities[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

int main(int argc,const char* argv[])
{

	void PrintProbability(int Number);
	PrintProbability(1);
	void PrintProbability_2(int number);
	cout << endl;
	PrintProbability_2(1);
}
