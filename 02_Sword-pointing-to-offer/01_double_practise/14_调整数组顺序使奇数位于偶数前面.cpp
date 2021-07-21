

/*
 * Date:2021-07-21 10:36
 * filename:14_调整数组顺序使奇数位于偶数前面.cpp
 *
 */

/*

#题意
题目描述

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

样例输入

5 1 2 3 4 5

样例输出

1 3 5 2 4

*/


/*
 *
 思路:
 下面我们考虑算法复杂度的同时还会考虑其稳定性，（排序的稳定型则是指相同元素在数组中的相对位置是否发生变化），
 这里的稳定性我们理解为，顺序交换后，各个奇数（或者偶数）在数组中的相对位置是否发生变化

#暴力方法

扫描数组，开辟俩个数组，一个存放奇数，另外一个存放偶数。然后再连接数组

#最简单的思路

从头扫描这个数组，每碰到一个偶数时，拿出这个数字，并把位于这个数字后面的所有数字往前挪动一位。
挪完之后在数组的末尾有一个空位，这时把该偶数放入这个空位。由于每碰到一个偶数就需要移动O(n)个数字，因此总的时间复杂度是O(n^2)。

*/

#include <iostream>
using namespace std;

void ReorderOddEven(int *pData, unsigned int length) {
	if (pData == NULL || length == 0) 
		return ;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		//向后移动pBegin,直到它指向偶数
		while (pBegin < pEnd && (*pBegin & 0x1) != 0) {
			pBegin ++;
		}
		while (pBegin < pEnd && (*pEnd & 0x1) == 0) {
			pEnd --;
		}

		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

//变成一个模式
void Reorder(int *pData, unsigned int length, bool (*func)(int)) {
	if (pData == NULL || length == 0)
		return ;

	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd) {
		while (pBegin < pEnd && !func(*pBegin)) {
			pBegin ++;
		}
		while (pBegin < pEnd && func(*pEnd)) {
			pEnd --;
		}

		if (pBegin < pEnd) {
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n) {
	return (n & 1) == 0;
}

void print(int *pData, int length) {
	for (int i = 0; i < length;i++) {
		cout << pData[i] << " ";
	}
	cout << endl;
}

int main() {
	int array[] = {1, 2, 3, 4, 5};
	int *pData = array;

	int length = sizeof(array) / sizeof(array[0]);

	void ReorderOddEven(int *pData, unsigned int length);
	void Reorder(int *pData, unsigned int length, bool (*func)(int));
	bool isEven(int n);
	void print(int *pData, int length);

	for (int i = 0; i < length;i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	//1 方法一
	//ReorderOddEven(pData, length);

	// 模式 通用 
	Reorder(pData, length,isEven);
	print(pData, length);
}
