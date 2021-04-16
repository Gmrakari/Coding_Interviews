#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void printArray(int array[],int len){
	for(int i = 0; i < len;i++){
		cout << array[i] << ' ';
	}
		cout << endl;
}
void Merge(int src[],int des[],int low,int mid,int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;
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
	if(low == high)
	{
		des[low] = src[low];
	}
	else
	{
		int mid = (low + high) / 2;
		int* space = (int *)malloc(sizeof(int) * max);
		if( space != NULL )
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
int main()
{
					
	void printArray(int array[],int len);
	
	void MergeSort(int array[],int len);

	int array[] = { 3,5,0,0,1,2,23,1,5,6,71,2,44,2,1,56,7,8,2 };
	int len =(int)sizeof(array) / sizeof(*array);

	printArray(array,len);
	cout << endl;

	MergeSort(array,len);
	
	printArray(array,len);
	cout << endl;

	return 0;
}

