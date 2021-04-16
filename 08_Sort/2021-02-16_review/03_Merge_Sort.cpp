#include <iostream>
#include <algorithm>
#include <stdlib.h>
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
			void Merge(int src[],int des[],int low,int mid,int high){
				int i = low;
				int j = mid + 1;
				int k = low;

				while( ( i <= mid ) && ( j <= high )){
					if( src[i] < src[j] ){
						des[k++] = src[i++];
					}
					else{
						des[k++] = src[j++];
					}
				}
				
				while( i <= mid ){
					des[k++] = src[i++];
				}

				while( j <= high ){
					des[k++] = src[j++];
				}
			}
			void MSort(int src[],int des[],int low,int high,int max){
				if(low == high){
					des[low] = src[low];
				}
				else{
					int mid = ( mid + high) / 2;
					int *space = (int *)malloc(sizeof(int) * max);

					//递归进行两路 两路的划分
					//当剩下一个元素的时候，递归划分结束，然后是merge归并操作

					if( space != NULL ){
						MSort(src,space,low,mid,max);
						MSort(src,space,mid + 1,high,max);
						MSort(space,des,low,mid,high);
					}
					free(space);
				}
			}
			void MergeSort(int array[],int len){
				MSort(array,array,0,len - 1,len);
			}
};

int main(){
	 Solution A;
	 int array[] = { 1,8,9,3,22,4,10,2,6,33,4,50,10,2};
	 int len = sizeof(array) / sizeof(array[0]);
	 cout << "before sort:";
	 A.print(array,len);
	 cout << "after sort:";
	
	 A.MergeSort(array,len);
	 A.print(array,len);

}

