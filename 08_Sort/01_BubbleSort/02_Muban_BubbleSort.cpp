#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iterator>


using namespace std;

/*
 * Date:2021-04-10 09:02
 * Author:Gmrakari
 * Filename:02_Muban_Bubble_sort.cpp
 *
 */

void printArray(vector<int> &arr)
{
	
}

void BubbleSort(vector<int> &arr)
{
	
}

int main(int argc,const char* argv[]){

	int array[] = { 8,3,6,11,1,22,60,2,50,5,0};
	int len = sizeof(array)/sizeof(array[0]);

	vector<int> vec(array,array+len);

	void BubbleSort(vector<int> &arr);

	void printArray(vector<int> &arr);

	cout << "Before BubbleSort :";
	printArray(vec);
	cout << endl;

	BubbleSort(vec);

	cout << "After BubbleSort :";
	printArray(vec);
	cout << endl;
}
