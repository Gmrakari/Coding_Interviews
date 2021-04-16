#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-09 09:35
 * Author:Gmrakari
 * Filename:5.cpp
 *
 */

/*
 * 算法步骤
 * 1、创建一个堆Heap[0···n - 1]
 * 2、把堆首(最大值)和堆尾交换
 * 3、把堆的尺寸缩小1，兵调用shift_down(0)，目的是把新的数组顶端数据调整到相应位置
 * 4、重复步骤2，直到堆的尺寸为1
 */


void max_heapify(int arr[],int start,int end)
{
	int dad = start;
	int son = dad * 2 + 1;

	while( son <= end )
	{
		if( son + 1 <= end && arr[son] < arr[son + 1] )
			son++;
		if( arr[dad] > arr[son] )
			return ;
		else
		{
			swap(arr[dad],arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void heap_sort(int arr[],int len)
{
	void max_heapify(int arr[],int start,int end);

	 //初始化
	 for(int i = len / 2 - 1;i >= 0;i--)
	 {
		max_heapify(arr,i,len - 1);
	 }

	 //最后一个元素和堆顶交换
	 for(int i = len - 1;i > 0;i--)
	 {
		swap(arr[0],arr[i]);
		max_heapify(arr,0,i - 1);
	 }
}

void print(int arr[],int len)
{
	for(int i = 0;i < len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 3,5,0,0,1,2,23,1,5,6,71,2,44,2,1,56,7,8,2 };
	int len =(int)sizeof(arr) / sizeof(*arr);
	void print(int arr[],int len);
	
	print(arr,len);
	heap_sort(arr,len);
	print(arr,len);

	return 0;
}
