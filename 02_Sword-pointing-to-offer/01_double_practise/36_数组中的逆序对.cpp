

/*
 * Date:2021-07-24 11:43
 * filename:36_数组中的逆序对.cpp
 *
 */

/*
 *
#题意
题目描述

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。 输入一个数组，求出这个数组中的逆序对的总数

样例输入

7 5 6 4

样例输出
5

分别是(7, 6), (7, 5), (7 ,4), (6, 4), (5, 4)

*/

#include <iostream>
using namespace std;

/*
 * 先把数组分隔成子数组，先统计出子数组内部的逆序对的数目，然后再统计出两个想另子数组之间的逆序对的数目
 * 在统计逆序对的过程中，还需要对数组进行排序。
 * 实质上是一个归并排序
 */
int InversePairs(int *data, int length) {
	int InversePairsCore(int *data, int *copy, int start, int end);
	if (data == NULL || length < 0) 
		return 0;

	int *copy = new int [length];
	for (int i = 0; i < length; ++i) 
		copy[i] = data[i];

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}

int InversePairsCore(int *data, int *copy, int start, int end) {
	if (start == end) {
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;

	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length - 1, end);

	//i初始化为前半段最后一个数字的下标
	int i = start + length;

	//j初始化为后半段最后一个数字的下标
	int j = end;
	int indexCopy = end;
	int count = 0;
	//归并 相当于 两个有序数组合成一个有序表
	//若前面的数大于后面的数 就构成逆序对
	while (i >= start && j >= start + length + 1) {
		if (data[i] > data[j]) {
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else {
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; --i)
		copy[indexCopy--] = data[i];

	for (; j >= start + length + 1; --j)
		copy[indexCopy--] = data[j];

	return left + right + count;
}
