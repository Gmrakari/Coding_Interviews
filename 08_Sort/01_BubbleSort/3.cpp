#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

/*
 * Date:2021-03-05 10:30
 * Author:Gmrakari
 * Filename:3.cpp
 *
 */

void printArray(int array[],int len)
{
	for(int i = 0; i < len;i++)
	{
		cout << array[i] << ' ';
	}
		printf("\n");
}

/*

void BubbleSort(int array[],int len)
{
	int exchange = 1;
	for(int i = 0; (i < len && exchange);++i)
	{
		exchange = 0;
		for(int j = 0; j < len;++j)
		{
			if(array[j] > array[j + 1])
			{
				exchange = 1;
				swap(array[j],array[j + 1]);
			}
		}
	}
}

*/

void BubbleSort_1(int array[],int len)
{
	int exchange =  1;
	for(int i = 0; ( i < len && exchange );++i)
	{
		exchange = 0;
		for(int j = len - 1;j > 0;--j)
		{
			if(array[j] < array[j - 1])
			{
				swap(array[j],array[j - 1]);
				exchange = 1;
			}
		}
	}
}

int main(int argc,const char* argv[]){

	int array[] = { 8,3,6,11,1,22,60,2,50,5,0};
	int len = sizeof(array)/sizeof(array[0]);

	void BubbleSort(int array[],int len);

	void printArray(int array[],int len);

	cout << "Before BubbleSort :";
	printArray(array,len);
	cout << endl;

	BubbleSort_1(array,len);

	cout << "After BubbleSort :";
	printArray(array,len);
	cout << endl;
}
