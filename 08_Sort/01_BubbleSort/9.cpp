#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iterator>


using namespace std;

/*
 * Date:2021-04-10 09:02
 * Author:Gmrakari
 * Filename:9.cpp
 *
 */

void printArray(vector<int> &arr)
{
/*
	for(int i = 0; i < arr.size();i++)
	{
		cout << arr[i] << ' ';
	}
		printf("\n");
*/
	for(vector<int>::iterator it = arr.begin(); it != arr.end();it++)
	{
		cout << *it << " ";
	}
		printf("\n");
}

void BubbleSort(vector<int> &arr)
{
	int exchange = 1;
	for(int i = 0;(i < arr.size() && exchange);++i)
	{
		exchange = 0;
		for(int j = 0;j < arr.size();++j)
		{
			if(arr[i] < arr[j])
			{
				swap(arr[i],arr[j]);
				exchange = 1;
			}
		}
	}
}

int main(int argc,const char* argv[]){

	int array[] = { 8,3,6,11,1,22,60,2,50,5,0};
	int len = sizeof(array)/sizeof(array[0]);

	vector<int> vec(array,array+len);

	//void BubbleSort(int array[],int len);

	//void printArray(int array[],int len);

	cout << "Before BubbleSort :";
	printArray(vec);
	cout << endl;

	BubbleSort(vec);

	cout << "After BubbleSort :";
	printArray(vec);
	cout << endl;
}
