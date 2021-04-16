#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

/*
 * Date:2021-03-10 10:35
 * Author:Gmrakari
 * Filename:6.cpp
 *
 */

/*
 * 算法步骤
 * 比较相邻的元素。如果最后一个比最后第二个小，那么就交换他们两个
 * 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数
 * 针对所有的元素重复以上的步骤，除了最后一个
 * 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较
 *
 */

void printArray(int array[],int len)
{
	for(int i = 0; i < len;i++)
	{
		cout << array[i] << ' ';
	}
		printf("\n");
}

void BubbleSort(int array[],int len)
{
	int exchange = 1;
	for(int i = 0; (i < len && exchange);i++)
	{
		exchange = 0;
		for(int j = len - 1;j > 0;j--)
		{
			if(array[j] < array[j - 1])
			{
				swap(array[j],array[j - 1]);
				exchange = 1;
			}
		}
	}
}

int main(int argc,const char* argv[]){

	int array[] = { 8,3,6,11,1,22,60,2,50,5,0};
	int len = sizeof(array)/sizeof(array[0]);

	void BubbleSort(int array[],int len);

	void printArray(int array[],int len);

	cout << "Before BubbleSort :";
	printArray(array,len);
	cout << endl;

	BubbleSort(array,len);

	cout << "After BubbleSort :";
	printArray(array,len);
	cout << endl;
}
