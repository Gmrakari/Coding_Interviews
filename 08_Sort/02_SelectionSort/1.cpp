#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-08 20:33
 * Author:Gmrakari
 * Filename:1.cpp
 */

/*
 * 算法步骤
 * 1、首先在未排序序列中找到最小(大)元素，存放到排序序列的起始位置
 * 2、再从剩余未排序元素中继续寻找最小(大)元素，然后放到已排序序列的末尾
 * 3、重复第二步，直到所有元素均排序完毕
 */

void printArray(int array[],int len){
	for(int i = 0; i < len;++i){
			cout << array[i] << ' ';
		}
		cout << endl;
	}

void SelectionSort(int array[],int len)
{
	int minIndex = -1;
	for(int i = 0;i < len;++i)
	{
		minIndex = i;
		for(int j = i + 1;j < len;++j)
		{
			if(array[minIndex] > array[j])
			{
				minIndex = j;
			}
		}
		swap(array[i],array[minIndex]);
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

