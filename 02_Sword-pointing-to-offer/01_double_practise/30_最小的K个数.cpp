

/*
 * Date:2021-07-23 13:40
 * filename:30_最小的K个数.cpp
 *
 */

/*
#题意
题目描述

输入n个整数，找出其中最小的K个数。

例如输入4,5,1,6,2,7,3,8这8个数字， 则最小的4个数字是1,2,3,4,。
*/

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int RandomInRange(int min, int max) {
	int random = rand() % (max - min + 1) + min;
	return random;
}

void Swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int Partition(int data[], int length, int start, int end) {
	if (data == NULL || length <= 0 || start < 0 || end >= length) {
		int ret = -1;
		return ret;
	}

	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);
	
	int small = start - 1;
	for (index = start; index < end; ++index) {
		if (data[index] < data[end]) {
			++small;
			if (small != index)
				Swap(&data[index], &data[small]);
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}
//解法一:只有当我们可以修改输入的数组时可用
void GetLeastNumbers(int* input, int n, int* output, int k) {
	if (input == NULL || output == NULL || k > n || n <= 0 || k <= 0) return ;

	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while (index != k - 1) {
		if (index > k - 1) {
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		else {
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}

	for (int i = 0; i < k; ++i) {
		output[i] = input[i];
	}
}

//解法二:适合处理海量数据
typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers_2(const vector<int>& data, intSet& leastNumbers, int k) {
	leastNumbers.clear();

	if (k < 1 || (int)data.size() < k) return ;
	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter) {
		if ((int)(leastNumbers.size()) < k)
			leastNumbers.insert(*iter);
		else {
			setIterator iterGreatest = leastNumbers.begin();

			if (*iter < *(leastNumbers.begin())) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}
