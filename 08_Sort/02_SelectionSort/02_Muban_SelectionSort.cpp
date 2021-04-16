#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Date:2021-03-10 09:05
 * Author:Gmrakari
 * Filename:00_Muban_SelectionSort.cpp
 */

void printArray(vector<int> &vec)
{
	for(int i = 0; i < vec.size();i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void SelectionSort(vector<int> &vec)
{
	
}

int main(int argc,const char* argv[]){
	int array[] = { 8,3,6,11,0,21,51,1,12,36,60,1,2};
	int len = sizeof(array)/sizeof(array[0]);

	vector<int> vec(array,array + len);

	cout << "Before SelectionSort :";
	printArray(vec);
	cout << endl;

	SelectionSort(vec);

	cout << "After SelectionSort :";
	printArray(vec);
	
	cout << endl;
}

