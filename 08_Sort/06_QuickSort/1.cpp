#include <iostream>
#include <algorithm>

using namespace std;


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
	while(low < high)
	{
		while( (low < high) && (array[high] >= pv) )
		{
			high--;
		}
		swap(array[low],array[high]);
		while( (low < high) && (array[low] <= pv) )
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
