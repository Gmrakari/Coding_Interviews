#include <iostream>
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

	void InsertionSort(int array[],int len){
		int i = 0;
		int j = 0;
		int k = -1;

		int temp = -1;

		for(i = 1;i < len;i++){
			k = i;
			temp = array[k];

			for(j = i - 1; (j >= 0) && (array[j] > temp);j--){
				array[j + 1] = array[j];
				k = j;
			}
			array[k] = temp;
		}
	}
};

int main(int argc,char const *argv[]){
	Solution a;
	int array[] = {12,5,433,253,216,7};
	int len = sizeof(array)/sizeof(array[0]);

	a.printArray(array,len);
	a.InsertionSort(array,len);
	a.printArray(array,len);

	return 0;
}




