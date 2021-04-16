#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * 拿出来
 * 满足条件的元素往后移动
 */

void printArray(vector<int> &vec)
{
	for(int i = 0; i < vec.size();i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void InsertionSort(vector<int> &vec)
{
	int k = -1;
	int temp = -1;

	for(int i = 1; i < vec.size();i++)
	{
		k = i;
		temp = vec[k];

		for(int j = i - 1;(j >= 0) && (vec[j] > temp);j--)
		{
			vec[j + 1] = vec[j];
			k = j;
		}
		vec[k] = temp;
	}
}

int main(int argc,const char* argv[])
{

	int array[] = { 8,3,6,11,0,21,51,1,12,36,60,1,2};
	int len = sizeof(array)/sizeof(array[0]);

	vector<int> vec(array,array + len);

	cout << "Before InsertionSort :";
	printArray(vec);
	cout << endl;

	InsertionSort(vec);

	cout << "After InsertionSort :";
	printArray(vec);
	
	cout << endl;
}
