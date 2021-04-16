#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-10 09:15
 * Author:Gmrakari
 * Filename:14.cpp
 */

/*
 * 算法步骤
 * 1、申请内存空间，使其大小为两个已排序序列之和，该空间用来释放合并后的序列
 * 2、设定两个指针，最初位置分别为两个已经排序序列的起始位置
 * 3、比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
 * 4、重复步骤3直到某一指针到达序列尾
 * 5、将另一序列剩下的所有元素直接复制到合并列尾
 */

void printArray(int array[],int len){
	for(int i = 0; i < len;i++){
		cout << array[i] << ' ';
	}
		cout << endl;
}
void Merge(int src[],int des[],int low,int mid,int high)
{
	int i = low;
	int k = low;
	int j = mid + 1;

	while( i <= mid && j <= high )
	{
		if(src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while( i <= mid )
	{
		des[k++] = src[i++];
	}

	while( j <= high )
	{
		des[k++] = src[j++];
	}
}
void MSort(int src[],int des[],int low,int high,int max)
{
	void Merge(int src[],int des[],int low,int mid,int high);
	if( low == high )
	{
		des[low] = src[low];
	}
	else
	{
		int mid = (low + high) / 2;
		int* space = (int *)malloc(sizeof(int) * max);

		if(space != NULL)
		{
			MSort(src,space,low,mid,max);
			MSort(src,space,mid + 1,high,max);
			Merge(space,des,low,mid,high);
		}
		free(space);
	}
}
void MergeSort(int array[],int len)
{
	void MSort(int src[],int des[],int low,int high,int max);
	MSort(array,array,0,len - 1,len);
}

template<typename T>
void merge_sort(T arr[],int len)
{
	T *a = arr;
	T *b = new T[len];

	for(int seg = 1;seg < len;seg += seg)
	{
		for(int start = 0;start < len;start += seg + seg)
		{
			int low = start,mid = min(start + seg,len),high = min(start + seg + seg,len);
			int k = low;
			int start1 = low,end1 = mid;
			int start2 = mid,end2 = high;

			while( start1 < end1 && start2 < end2 )
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while( start1 < end1 )
				b[k++] = a[start1++];
			while( start2 < end2 )
			 	b[k++] = a[start2++];
		}

		T *temp = a;
		a = b;
		b = temp;
	}
	if(a != arr)
	{
		for(int i = 0;i < len;i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}

int main()
{
					
	void printArray(int array[],int len);
	
	void MergeSort(int array[],int len);

	int array[] = { 3,5,0,0,1,2,23,1,5,6,71,2,44,2,1,56,7,8,2 };
	int len =(int)sizeof(array) / sizeof(*array);

	printArray(array,len);
	cout << endl;

//	MergeSort(array,len);
	void merge_sort(int arr[],int len);
	
	

	::merge_sort<int>(array,len);

	printArray(array,len);
	cout << endl;

	return 0;
}

