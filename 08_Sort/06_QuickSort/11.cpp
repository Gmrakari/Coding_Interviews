#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-10 09:48
 * Author:Gmrakari
 * Filename:11.cpp
 */

/*
 * 1、从数列中挑出一个元素，称为基准(pv)
 * 2、重新排序序列，所有元素比基准小的放在基准前面，所有元素比基准大的放在基准后面(相同的数可以放在任一边)。
 * 在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区(partition)操作
 * 3、递归地(recursive)把小于基准值元素的子序列和大于基准值元素的子序列排序
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
		while( low < high && array[high] >= pv )
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
