#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

void FindNumsAppearOnce(int data[],int length,int* num1,int* num2)
{
	bool IsBit1(int num,unsigned int indexBit);
	unsigned int FindFirstBitIs1(int num);

	if(data == NULL || length < 2)
		return ;

	int resultExclusiveOR = 0;
	for(int i = 0;i < length;++i)
		resultExclusiveOR ^= data[i];

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = *num2 = 0;
	for(int j = 0;j < length;++j)
	{
		if(IsBit1(data[j],indexOf1))
			*num1 ^= data[j];
		else
			*num2 ^= data[j];
	}
	while(*num1 != '\0')
	{
		cout << *num1 << " " ;
		//	<< num2[j] << " " ;
		num1++;
		cout << endl;
	}	
	cout << endl;
	//cout << *num1 << " " << *num2 << " ";
	/*
	
	int k = 0;
	int capit = sizeof(num1)/sizeof(*num1) + sizeof(num2) / sizeof(*num2);
	int *arr = new int [capit];

	while(num1)
	{
		arr[k++] = *num1;
		num1++;
	}


	while(num2)
	{
		arr[k++] = *num2;
		num2++;
	}
	for(int i = 0;i < k;i++)
	{	
		cout << arr[i] << " ";
	}
	cout << endl;

	delete[] arr;

	*/
}

//在整数num的二进制表示中找到最右边是1的位,IsBit1的作用是判断在num的二进制表示中从右边数起的indexBit位是不是1
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++ indexBit;
	}
	return indexBit;
}

//判断在num的二进制表示中从右边数起的indexBit位是不是1
bool IsBit1(int num,unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

int main(int argc,const char* argv[])
{
	int data[] = {2,4,3,6,3,2,5,5};

	int len = sizeof(data) / sizeof(data[0]);
	
	int num1 ;
	int num2 ;

	void FindNumsAppearOnce(int data[],int length,int* num1,int* num2);
	FindNumsAppearOnce(data,len,&num2,&num2);

//	cout << num1 << " " << num2 << " ";
	cout << endl;
}

