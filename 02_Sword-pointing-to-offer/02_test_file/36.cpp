#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int InversePairs( int* data,int length)
{
	int InversePairsCore(int* data,int* copy,int start,int end);

	if(data == NULL || length < 0)
		return 0;
	int* copy = new int[length];

	for(int i = 0; i < length;++i)
		copy[i] = data[i];

	int count = InversePairsCore(data,copy,0,length - 1);
	delete[] copy;

	return count;
}

int InversePairsCore(int* data,int* copy,int start,int end)
{
	if(start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;
	int left = InversePairsCore(copy,data,start,start + length);
	int right = InversePairsCore(copy,data,start + length + 1,end);

	//i初始化为前半段最后一个数字的下标
	int i = start + length;

	//j初始化为后半段最后一个数字的下标
	int j = end;

	int indexCopy = end;
	int count = 0;
	while( i >= start && j >= start + length + 1)
	{
		if(data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for(; i >= start;--i)
		copy[indexCopy--] = data[i];

	for(;j >= start + length + 1;--j)
		copy[indexCopy--] = data[j];

	return left + right + count;
}

int BubbleSort(int array[],int len)
{
	int i = 0,j = 0,cnt = 0;
	for(i = 0; i < len;i++)
	{
		for(j = i + 1;j < len;j++)
		{
			if(array[i] > array[j] && i < j)
			{
				printf("arr[%d] = %d > array[%d] = %d \t ",i,array[i],j,array[j]);
				cnt++;
			}
		}
	}
	return cnt;
}

int main(int argc,const char* argv[])
{

	int InversePairs( int* data,int length);
	int ret = 0;
	int array[] = {7,5,6,4};
	int len = sizeof(array) / sizeof(*array);
//	ret = InversePairs(array,len);
//	printf("ret : %d\n",ret);

	ret = BubbleSort(array,len);
	printf("ret : %d\n",ret);

	return 0;

}


