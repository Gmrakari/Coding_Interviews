#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-08 19:47
 * Author:Gmrakari
 * Filename:4.cpp
 *
 */

/*
 * 算法步骤
 * 1、创建一个堆Heap[0···n - 1]
 * 2、把堆首(最大值)和堆尾交换
 * 3、把堆的尺寸缩小1，并调用shift_down(0)，目的是把新的数组顶端数据调整到相应位置
 * 4、重复步骤2，直到堆的尺寸为1
 */

void max_heapify(int arr[],int start,int end)
{
	//建立父子结点指标
	int dad = start;
	int son = dad * 2 + 1;

	//若子结点在指标范围内才能做比较
	while( son <= end )
	{
		//选择较大的子结点
		if(son + 1 <= end && arr[son] < arr[ son + 1 ])
			son++;
		if(arr[dad] > arr[son])
			return ;
		else
		{
			//否则交换子结点的内容，再继续子结点和孙子结点的比较
			swap(arr[dad],arr[son]);
			dad = son;
			son = dad * 2 + 1;

		}
	}
}
void heap_sort(int arr[],int len)
{
	void max_heapify(int arr[],int start,int end);

	//初始化，i从最后一个父节点开始调整
	for(int i = len / 2 - 1;i >= 0;i--)
			max_heapify(arr,i,len - 1);

	//先将的元素和已经排好的前一位交换再重新调整（刚调整的元素之前的元素），直到排序完成
	for(int i = len -1;i > 0;i--)
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
