#include <iostream>
using namespace std;

void print(int array[],int len)
{
	for( int i = 0; i < len;i++ )
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void ShellSort(int array[],int len)
{
	int k = -1;
	int temp = -1;
	int gap = len;

	do
	{
		gap = gap / 3 + 1;
		for(int i = gap; i < len; i += gap)
		{
			k = i;
			temp = array[k];

			for(int j = i - gap;(j >= 0 && (array[j] > temp));j -= gap)
			{
				array[j + gap] = array[j];
				k = j;
			}
			array[k] = temp;
		}
	}while( gap > 1 );
}

int main(int argc,const char* argv[])
{
	int array[] = { 8,3,6,11,0,2,60,3};
	int len = sizeof(array)/sizeof(array[0]);

	print(array,len);

	ShellSort(array,len);

	print(array,len);
}
