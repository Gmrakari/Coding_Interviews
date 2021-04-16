#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-10 09:05
 * Author:Gmrakari
 * Filename:00_Muban_SelectionSort.cpp
 */

void printArray(int array[],int len){
	for(int i = 0; i < len;++i){
			cout << array[i] << ' ';
		}
		cout << endl;
	}

void SelectionSort(int array[],int len)
{

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

