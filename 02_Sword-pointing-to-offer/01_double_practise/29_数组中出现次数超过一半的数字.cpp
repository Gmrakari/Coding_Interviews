

/*
 * Date:2021-07-23 11:55
 * filename:29_数组中出现次数超过一半的数字.cpp
 *
 */

/*
 * 
 题目
 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 例如输入一个长度为9的数组{1,2,3,2,2,2,2,5,4}。
 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

 示例1

 输入
 [1,2,3,2,2,2,5,4,2]

 返回值
 2

*/

#include <iostream>
#include <string>
#include <cstdio>
#include <exception>
#include <bits/stdc++.h>
#include <stdexcept>

/*
 * 解法一:
 * 基于Partition的函数的O(n)算法
 * 我们先在数组中随机选择一个数字，然后调整数组中数字的顺序，使得比选中的数字小数字都排在它的左边，
 * 比选中的数字大的数字都排在它的右边。
 * 如果这个选中的数字的下标刚好是n/2，那么这个数字就是数组的中位数
 * 如果它的下标大于n / 2，那么中位数应该位于它的左边，我们接着在它的左边部分的数组中查找
 * 如果它的下标小于n / 2，那么中位数应该位于它的右边，我们接着在它的右边部分的数组中查找
 *
 */
bool g_bInputInvalid = false;

int MoreThanHalfNum(int *numbers, int length) {
	int Partition(int data[], int length, int start, int end);
	bool CheckMoreThanHalf(int* numbers, int length, int number);
	bool CheckInvalidArray(int* numbers, int length);
	if (CheckInvalidArray(numbers, length)) return 0;

	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);
	while (index != middle) {
		if (index > middle) {
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else {
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}

	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, length, result)) return 0;

	return result;
}

bool CheckInvalidArray(int* numbers, int length)
{
	g_bInputInvalid = false;
	if(numbers == NULL && length <= 0)
		g_bInputInvalid = true;

	return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for(int i = 0; i < length; ++i)
	{
		if(numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	if(times * 2 <= length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

// Random Partition
int RandomInRange(int min, int max)
{
	int random = rand() % (max - min + 1) + min;
	return random;
}

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int Partition(int data[], int length, int start, int end)
{
	void Swap(int* num1, int* num2);
	int RandomInRange(int min, int max);
	if(data == NULL || length <= 0 || start < 0 || end >= length)
		//std::logic_error e("Invalid Parameters");
	//	throw std::exception(e);
		//throw new std::exception("Invalid Parameters");
		return 0;

	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);

	int small = start - 1;
	for(index = start; index < end; ++ index)
	{
		if(data[index] < data[end])
		{
			++ small;
			if(small != index)
				Swap(&data[index], &data[small]);
		}
	}

	++ small;
	Swap(&data[small], &data[end]);

	return small;
}

void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = MoreThanHalfNum(numbers, length);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag);
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

int main() {
	Test1();
}
