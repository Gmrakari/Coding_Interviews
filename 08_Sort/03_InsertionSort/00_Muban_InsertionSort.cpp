#include <iostream>
using namespace std;

/*
 * 拿出来
 * 满足条件的元素往后移动
 */

void InsertionSort(int array[],int len)
{
	int k = -1;
	int temp = -1;

	for(int i = 1; i < len;i++)
	{
		k = i;
		temp = array[k];
		for(j = i - 1;(j >= 0) && (array[j] > temp);j--)
		{
			array[j + 1] = array[j];
			k = j;
		}
		array[k] = temp;
	}
}

int main(int argc,const char* argv[])
{

}
