
#include <stdio.h>
#include <stdlib.h>

void Meger(int src[],int des[],int low,int mid,int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while( i <= mid && j <= high )
	{
		if( src[i] < src[j] )
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while( i <= mid )
	{
		des[k++] = src[i++];
	}

	while( j <= high )
	{
		des[k++] = src[j++];
	}
}

void MSort(int src[],int des[],int low,int mid,int max)
{
		//只有一个元素的时候就直接返回
		if(low == high)
			des[low] = src[low];

		else
		{
			int mid = (mid + high) / 2;
			int *space = (int *)malloc(sizeof(int)* max);

			if( space != NULL )
			{
				MSort(src,space,low,mid,max);
				MSort(src,space,mid + 1,high,max);
				Meger(space,des,low,mid,high);
			}
		}
		free(space);
}

void Meger_Sort(int array[],int len)
{
	MSort(array,array,0,len - 1,len);
}
