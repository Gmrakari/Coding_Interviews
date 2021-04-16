#include <iostream>
#include <cstring>
using namespace std;

/*
 * Date:2021-03-11 10:17
 * Author:Gmrakari
 * Filename:00_Muban_CountSort.cpp
 *
 */

/*
 * 计数排序的特征
 * 当输入的元素是n个0到k之间的整数时，它的运行时间是O( n + k )。计数排序不是比较排序，排序的速度快于任何比较排序算法
 *
 * 计数排序对于数据范围很大的数组，需要大量时间和内存。
 *
 * 计数排序是用来排序0到100之间的数字的最好的算法，但它不适合按字母顺序排序人名
 *
 */

/*
 * 算法步骤
 * 1、找出待排序的数组中最大和最小的元素
 * 2、统计数组中每个值为i的元素出现的次数，存入数组c的第i项
 * 3、对所有的计数累加(从C中的第一个元素开始，每一项和前一项相加)
 * 4、反向填充目标数组:将元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
 */

void printArray(int array[],int len)
{
	if( array == nullptr || len <= 0 )
		return ;

	for(int i = 0; i < len;i++)
	{
		cout << array[i] << ' ';
	}
		cout << endl;
}

void CountingSort( int array[],int len,int nMaxNumber )
{
	if(array == nullptr || len <= 1 || nMaxNumber <= 0)
		return ;

	//统计待排数组中每一个元素的个数
	//new出来的数组大小为nMaxNumber + 1，用于统计[0,nMaxNumber]范围内的元素
	int* ArrayCount = new int[nMaxNumber + 1] { 0 };
	for(int i = 0;i < len;i++)
	{
		++ArrayCount[array[i]];
	}

	//计算待排序数组中小于等于第i个元素的个数
	//如果要进行大到小的排序，就计算大于等于第i个元素的个数，也就从后面向前进行累加
	for(int i = 1; i < nMaxNumber + 1;i++)
	{
		ArrayCount[i] += ArrayCount[ i - 1 ];
	}

	//把待排序的数组放到输出数组中，为了保持排序的稳定性，从后向前添加元素
	int* ArrayResult = new int[len];
	for(int i = len - 1;i >= 0;i--)
	{
		int nIndex = ArrayCount[array[i]]- 1;//元素array[i]在输出数组中的下标
		ArrayResult[nIndex] = array[i];

		//因为可能有重复的元素，所以要减1，为下一个重复的元素计算正确的下标
		--ArrayCount[array[i]];
	}

	//交换数据并释放内存空间
	memcpy(array,ArrayResult,sizeof(int) * len);
	delete[] ArrayCount;
	ArrayCount = nullptr;
	delete[] ArrayResult;
	ArrayResult = nullptr;
}

int findMax(int array[],int len)
{
	int max = array[0];
	for(int i = 0; i < len;i++)
	{
		if ( array[i] > max )
		{
			max = array[i];
		}
	}			
	return max;
}

int main(int argc,const char* argv[])
{
	void CountingSort( int array[],int len,int nMaxNumber );
	void printArray(int array[],int len);
	int findMax(int array[],int len);

	int array[] = { 8,3,6,11,1,22,60,2,50,5,0};
	int len = sizeof(array)/sizeof(array[0]);
	int maxIndex = findMax(array,len);

	printArray(array,len);

	CountingSort(array,len,maxIndex);

	printArray(array,len);


}
