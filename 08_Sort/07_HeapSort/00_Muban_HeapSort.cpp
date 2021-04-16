#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-10 08:40
 * Author:Gmrakari
 * Filename:1.cpp
 *
 */

void max_heapify(int arr[],int start,int end)
{

}
void heap_sort(int arr[],int len)
{

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
