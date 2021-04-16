#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-05 18:45
 * Author:Gmrakari
 * Filename:2.cpp
 *
 */

void max_heapify(int arr[],int start,int end)
{
		//建立父子节点指标
	int dad = start;
	int son = dad * 2 + 1;

	while(son <= end)	//若子结点在指标范围内才能做比较
	{
		if(son + 1 <= end && arr[son] < arr[son + 1])	//选择较大的子结点
			son++;
		if(arr[dad] > arr[son])
			return ;
		else
		{
			swap(arr[dad],arr[son]);	//否则交换子结点内容，再继续子结点和孙子结点的比较
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void heap_sort(int arr[],int len)
{
	//初始化,i从最后一个父节点开始调整
	for(int i = len / 2 - 1;i >= 0;i--)
		max_heapify(arr,i,len - 1);

	//先将第一个元素和已经排好的前一位交换再重新调整(刚调整的元素之前的元素),直到排序完成
	for(int i = len - 1; i > 0;i--)
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
