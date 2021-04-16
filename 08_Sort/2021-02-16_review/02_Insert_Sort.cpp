#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
	public:
			void print(int array[],int len)
			{
				for(int i = 0; i < len ;i++){
					cout << array[i] << " " ;
				}
				cout << endl;
			}
			/*
			 * error write
			void Insert_sort(int array[],int len){
				int temp = 0;
				int i = 0, j = 0;
				for( i = 0;i < len;i++){
					temp = array[i];
					for(j = len - 1; j > 0;j--){
						if(temp < array[j])
						swap(temp,array[j]);
					}
				}
			}
			*/
			void Insert_sort(int array[],int len){
				int i = 0;
				int j = 0;
				int k = -1;
				int temp = -1;

				for( i = 1; i < len;i++){
					k = i;
					temp = array[k];

					for(j = i - 1; ( j >= 0 ) && ( array[j] > temp );j--){
						array[j + 1] = array[j];
						k = j;
					}
					array[k] = temp;
				}
			}
};

int main(){
	 Solution A;
	 int array[] = { 1,8,9,3,22,4,10,2,6,33,4,50,10,2};
	 int len = sizeof(array) / sizeof(array[0]);
	 cout << "before sort:";
	 A.print(array,len);
	 cout << "after sort:";
	
	 A.Insert_sort(array,len);
	 A.print(array,len);

}

