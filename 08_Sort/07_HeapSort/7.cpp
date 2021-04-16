#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Date:2021-03-10 08:30
 * Author:Gmrakari
 * Filename:7.cpp
 *
 */

/*
 * 算法步骤
 * 1、创建一个Heap[0···n - 1]
 * 2、把堆首(最大值)和堆尾交换
 * 3、把堆的尺寸缩小1，并调用shift_down(0),目的是把新的数组顶端数据调整到相应位置
 * 4、重复步骤2，直到的尺寸为1
 */

void max_heapify(int arr[],int start,int end)
{
	//建立父节点指标和子结点指标
	 int dad = start;
	 int son = dad * 2 + 1;

	 //若子结点指标在范围内才做比较
	 while(son <= end)
	 {
			 //先比较两个子结点的大小，选择最大的
			 if(son + 1 < end && arr[son] < arr[son + 1])
					son++;
			 //如果父亲结点大于子结点代表调整完毕，直接跳出函数
			 else if(arr[dad] > arr[son])
					 return ;
			 //否则交换父子内容再继续子结点和孙子结点比较
			 else
			 {
				swap(arr[dad],arr[son]);
				dad = son;
				son = dad * 2 + 1;
			 }
	 }
}
void heap_sort(int arr[],int len)
{
	//初始化，i从最后一个父亲结点开始调整
	for(int i = len / 2 - 1;i >= 0;i--)
	{
		max_heapify(arr,i,len - 1);
	}

	//最后一个元素和堆顶交换
	//然后再调整堆
	
	//先将第一个元素和已经排好的元素前一位做交换，再重新调整(刚调整的元素之前的元素)
	//直到排序完毕
	for(int i = len - 1;i > 0;i--)
	{
		swap(arr[0],arr[i]);
		max_heapify(arr,0,i - 1);
	}

}

void print(int arr[],int len)
{
	for(int i = 0;i < len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 3,5,0,0,1,2,23,1,5,6,71,2,44,2,1,56,7,8,2 };
	int len =(int)sizeof(arr) / sizeof(*arr);
	void print(int arr[],int len);
	
	print(arr,len);
	heap_sort(arr,len);
	print(arr,len);

	return 0;
}
