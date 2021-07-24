

/*
 * Date:2021-07-24 14:58
 * filename:38_数字在排序数组中出现的次数.cpp
 *
 */

// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

#include <bits/stdc++.h>
using namespace std;

int GetFirstK(int *data, int length, int k, int start, int end) {
	if (start > end) 
		return -1;

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if (middleData == k) {
		if ((middleIndex > 0 && data[middleIndex - 1] != k)
				|| middleIndex == 0) 
			return middleIndex;
		else 
			end = middleIndex - 1;
	}
	else if (middleData > k )
		end = middleIndex - 1;
	else 
		start = middleIndex + 1;

	return GetFirstK(data, length, k, start, end);
}

int GetLastK(int *data, int length, int k, int start, int end) {
	if (start > end) 
		return -1;

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if (middleData == k) {
		if ((middleIndex < length - 1 && data[middleIndex + 1] != k)
				|| middleIndex == length - 1)
			return middleIndex;
		else
			start = middleIndex + 1;
	}
	else if (middleData < k) 
		start = middleIndex + 1;
	else
		end = middleIndex - 1;
	return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int *data, int length, int k) {
	int number = 0;
	if (data != NULL && length > 0) {
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetFirstK(data, length, k, 0, length - 1);

		if (first > -1 && last > -1) 
			number = last - first + 1;
	}
	return number;
}

int main() {

	int array[] = {1, 2, 3, 3, 3, 3, 4, 5};
	int k = 1; 
	int length = sizeof(array) / sizeof(array[0]);
	int ret = GetNumberOfK(array, length, k);
	cout << ret << endl;

}

/*
#include <cstdio>

int GetFirstK(const int* data, int length, int k, int start, int end);
int GetLastK(const int* data, int length, int k, int start, int end);

int GetNumberOfK(const int* data, int length, int k)
{
	int number = 0;

	if(data != nullptr && length > 0)
	{
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		if(first > -1 && last > -1)
			number = last - first + 1;
	}

	return number;
}

// 找到数组中第一个k的下标。如果数组中不存在k，返回-1
int GetFirstK(const int* data, int length, int k, int start, int end)
{
	if(start > end)
		return -1;

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if(middleData == k)
	{
		if((middleIndex > 0 && data[middleIndex - 1] != k)
				|| middleIndex == 0)
			return middleIndex;
		else
			end  = middleIndex - 1;
	}
	else if(middleData > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;

	return GetFirstK(data, length, k, start, end);
}

// 找到数组中最后一个k的下标。如果数组中不存在k，返回-1
int GetLastK(const int* data, int length, int k, int start, int end)
{
	if(start > end)
		return -1;

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if(middleData == k)
	{
		if((middleIndex < length - 1 && data[middleIndex + 1] != k)
				|| middleIndex == length - 1)
			return middleIndex;
		else
			start  = middleIndex + 1;
	}
	else if(middleData < k)
		start = middleIndex + 1;
	else
		end = middleIndex - 1;

	return GetLastK(data, length, k, start, end);
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int k, int expected)
{
	if(testName != nullptr)
		printf("%s begins: ", testName);

	int result = GetNumberOfK(data, length, k);
	if(result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
	int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
	Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

int main(int argc, char* argv[])
{
	Test1();
}

*/

//下面的pass 上面的failure
