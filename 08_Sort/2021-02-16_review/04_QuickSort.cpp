#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution{
	public:
		int partition(int array[],int low,int high)
		{
			int pv = array[low];
			while( low < high )
			{
				while( low < high && array[high] >= pv )
				{
					high--;
				}
				swap(array[low],array[high]);
			
				while( low < high && array[low] <= pv )
				{
					low++;
				}
				swap(array[low],array[high]);
			}
			return low;
		}

		void QSort(int array[],int low,int high)
		{
			if( low < high )
			{
				int pv = partition(array,low,high);
				QSort(array,low,pv);
				QSort(array,pv + 1,high);
			}
		}

		void QuickSort(int array[],int len)
		{
			QSort(array,0,len - 1);
		}

		void printArray(int array[],int len)
		{
			int i = 0;
			for(i = 0; i < len;++i)
			{
				cout << array[i] << " ";
			}
			cout << endl;
		}
};
int main(int argc,char const *argv[]){
	int array[] = {1,3,5,7,9,2,4,6,8,0,0};
	int len = sizeof(array)/sizeof(*array);

	Solution A;
	std::cout << "Before Sort :";
	A.printArray(array,len);
	cout << endl;
	
	std::cout << "After Sort:";
	A.QuickSort(array,len);
	A.printArray(array,len);
	cout << endl;	


}

