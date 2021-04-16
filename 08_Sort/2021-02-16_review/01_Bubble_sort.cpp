#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
	public:
			void Bubble_Sort(int array[],int len)
			{
				int exchange = 1;
				int i = 0, j = 0;
				for(i = 0; i < len && exchange == 1; i++){
					exchange = 0;
					for(j = len - 1; j > 0;j--){
						if(array[j] < array[j - 1])	
						swap(array[j],array[j - 1]);
						exchange = 1;
					}
				}
			}
			/*
			 *void Bubble_Sort(int &array[],int len){
			 *	int exchange = 1;
			 *	int i = 0, j = 0;
			 *	for(i = 0;(i < len) && exchange;i++){
			 *		exchange = 0;
			 *		for( j = len - 1; j > 0;j-- ){
			 *			if(array[j] < array[j - 1])
			 *				swap(array[j],array[j - 1]);
			 *				exchange = 1;
			 *		}
			 *	}
			 *}
			 */
			void print(int array[],int len)
			{
				for(int i = 0; i < len ;i++){
					cout << array[i] << " " ;
				}
				cout << endl;
			}
};

int main(){
	 Solution A;
	 int array[] = { 1,8,9,3,22,4,10,2,6,33,4,50,10,2};
	 int len = sizeof(array) / sizeof(array[0]);
	 cout << "before sort:";
	 A.print(array,len);
	 cout << "after sort:";
	 A.Bubble_Sort(array,len);
	 A.print(array,len);

}


