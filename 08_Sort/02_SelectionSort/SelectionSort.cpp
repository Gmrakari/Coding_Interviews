
#include <iostream>
#include <algorithm>

using namespace std;
class Solution{
public:
	void printArray(int array[],int len){
		int i = 0;
		for(i = 0; i < len;i++){
			std::cout << array[i] << " ";
		}
		std::cout << endl;
	}
	void SelectionSort(int array[],int len)
	{
		int i = 0;
		int j = 0;
		int k = -1;
	
		for(i = 0;i < len;i++)
		{
			k = i;
			for(j = i + 1; j < len;j++)
			{
				if(array[k] > array[j])
				{	
					k = j;
				}	
			}
			swap(array[i],array[k]);
		}
	}

};

int main(int argc,const char* argv[]){
	int array[] = { 8,3,6,11,0};
	int len = sizeof(array)/sizeof(array[0]);

	Solution a;
	std::cout << "Before SelectionSort :";
	a.printArray(array,len);
	cout << endl;

	a.SelectionSort(array,len);

	std::cout << "After SelectionSort :";
	a.printArray(array,len);
	cout << endl;
}

