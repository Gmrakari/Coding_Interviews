

/*
 * Date:2021-07-27 09:28
 * filename:41_和为S的两个数字.cpp
 *
 */

/*
 * #题意
题目描述

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

输入描述

5

100

输出描述

2 3 9 10 11 12 13 14 15 16 18 19 20 21 22

*/

#include <bits/stdc++.h>
using namespace std;

bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2) {
	bool found = false;
	if (length < 1 || num1 == NULL || num2 == NULL)
		return found;

	int ahead = length - 1;
	int behind = 0;

	while (ahead > behind) {
		long long curSum = data[ahead] + data[behind];
		if (curSum == sum) {
			*num1 = data[ahead];
			*num2 = data[behind];
			found = true;
			cout << *num2 << " + " << *num1 << " = " << sum << endl;
			break;
		}
		else if (curSum > sum) {
			ahead--;
		}
		else 
			behind++;
	}
	return found;
}

int main() {
	bool FindNumbersWithSum(int data[], int length, int sum, int *num1, int *num2);
	int data[] = {1, 2, 4, 7 ,11, 15}; 
	int length = sizeof(data) / sizeof(data[0]);
	int sum = 15;
	int num1;
	int num2;
	bool result = false;
	result = FindNumbersWithSum(data, length, sum, &num1, &num2);
	cout << result << endl;
}
