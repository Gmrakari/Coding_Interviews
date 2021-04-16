#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-09 10:12
 * Author:Gmrakari
 * Filename:2.cpp
 */

void printArray(int array[],int len){
	for(int i = 0; i < len;++i){
			cout << array[i] << ' ';
		}
		cout << endl;
	}

void SelectionSort(int arr[],int len)
{
	int minIndex = -1;

	for(int i = 0;i < len;++i)
	{
		minIndex = i;
		for(int j = i + 1;j < len;j++)
		{
			if(arr[minIndex] > arr[j])
				minIndex = j;
		}
		swap(arr[minIndex],arr[i]);
	}
}

int main(int argc,const char* argv[]){
	int array[] = { 8,3,6,11,0,21,51,1,12,36,60,1,2};
	int len = sizeof(array)/sizeof(array[0]);

	cout << "Before SelectionSort :";
	printArray(array,len);
	cout << endl;

	SelectionSort(array,len);

	cout << "After SelectionSort :";
	printArray(array,len);
	
	cout << endl;
}

