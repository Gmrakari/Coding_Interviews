#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-09 10:31
 * Author:Gmrakari
 * Filename:10.cpp
 */

/*
 * 算法步骤
 * 1、从数列中挑出一个元素，称为基准pv = array[low]
 * 2、重新排序数列，所有元素比基准小的放在基准前面，所有元素比基准大的放在基准后面
 * (相同的元素可以移到任一边)。在这个分区退出之后，该基准就处于数列的中国位置
 * 3、递归把小于基准元素的子序列和大于基准值元素的子序列排序
 *
 */

void printArray(int array[],int len)
{
	for(int i = 0; i < len;i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int partition(int array[],int low,int high)
{
	int pv = array[low];

	while( low < high )
	{
		while(low < high && array[high] >= pv)
		{
			high--;
		}
		swap(array[low],array[high]);
		
		while( low < high && array[low] <= pv )
		{
			low++;
		}
		swap(array[low],array[high]);
	}
	return low;
}

void QSort(int array[],int low,int high)
{
	int partition(int array[],int low,int high);
	if(low < high)
	{
		int pivot = partition(array,low,high);
		QSort(array,low,pivot - 1);
		QSort(array,pivot + 1,high);
	}
}

void QuickSort(int array[],int len)
{
	void QSort(int array[],int low,int high);
	QSort(array,0,len - 1);
}

int main(int argc,const char* argv[])
{

	void printArray(int array[],int len);
	void QuickSort(int array[],int len);

	int array[] = {1,3,5,7,9,2,4,6,8,0,0};
	int len = sizeof(array)/sizeof(*array);

	printArray(array,len);

	QuickSort(array,len);

	printArray(array,len);

}
