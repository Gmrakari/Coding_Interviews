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

	void ShellSort(int array[],int len)
	{
		int i = 0;
		int j = 0;
		int k = -1;
		int temp = -1;
		int gap = len;

		do{
			gap = gap / 3 + 1;

			for( i = gap; i < len; i += gap )
			{
				k = i;
				temp = array[k];

				for(j = i - gap; ( j >= 0  && (array[j] > temp));j-= gap)
				{
					array[j + gap] = array[j];
					k = j;
				}
				array[k] = temp;
			}
		}while( gap > 1 );
	}
		
};

int main(int argc,const char* argv[]){
	int array[] = { 8,3,6,11,0,2,60,3};
	int len = sizeof(array)/sizeof(array[0]);

	Solution a;
	std::cout << "Before ShellSort :";
	a.printArray(array,len);
	cout << endl;

	a.ShellSort(array,len);	

	std::cout << "After ShellSort :";
	a.printArray(array,len);
	cout << endl;
}
