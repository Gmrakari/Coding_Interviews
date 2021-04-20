
/*
 * Date:2021-04-20 11:00
 * filename:bucket-sort.cpp
 * copy by:www.runoob.com
 */

/*
 *
桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
为了使桶排序更加高效，我们需要做到这两点：

在额外空间充足的情况下，尽量增大桶的数量
使用的映射函数能够将输入的 N 个数据均匀的分配到 K 个桶中
同时，对于桶中元素的排序，选择何种比较排序算法对于性能的影响至关重要。

*/

#include <bits/stdc++.h>
using namespace std;

const int BUCKET_NUM = 1000;

struct ListNode
{
	explicit ListNode(int i = 0):m_Data(i),m_Next(NULL) {}
	ListNode *m_Next;
	int m_Data;
};

ListNode* insert(ListNode* head,int val)
{
	ListNode dummyNode;
	ListNode *newNode = new ListNode(val);

	ListNode *pre,*curr;
	dummyNode.m_Next = head;
	pre = &dummyNode;
	curr = head;

	while(curr != NULL && curr->m_Data <= val)
	{
		pre = curr;
		curr = curr->m_Next;
	}
	newNode->m_Next = curr;
	pre->m_Next = newNode;
	
	return dummyNode.m_Next;
}

ListNode* Merge(ListNode *head1,ListNode *head2)
{
	ListNode dummyNode;
	ListNode *dummy = &dummyNode;
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->m_Data <= head2->m_Data)
		{
			dummy->m_Next = head1;
			head1 = head1->m_Next;
		}
		else
		{
			dummy->m_Next = head2;
			head2 = head2->m_Next;
		}
		dummy = dummy->m_Next;
	}
	if(head1 != NULL) dummy->m_Next = head1;
	if(head2 != NULL) dummy->m_Next = head2;

	return dummyNode.m_Next;
}

void BucketSort(int arr[],int len)
{
	vector<ListNode *> buckets(BUCKET_NUM,(ListNode *)(0));
	for(int i = 0; i < len;++i)
	{
		int index= arr[i] / BUCKET_NUM;
		ListNode *head = buckets.at(index);
		buckets.at(index) = insert(head,arr[i]);
	}
	ListNode *head = buckets.at(0);
	for(int i = 1;i < BUCKET_NUM;++i)
	{
		head = Merge(head,buckets.at(i));
	}
	for(int i = 0; i < len;++i)
	{
		arr[i] = head->m_Data;
		head = head->m_Next;
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
	int array[] = {12,125,1,74,3,723,90,100,40,32,0,8};
	int len = sizeof(array) / sizeof(array[0]);
	
	print(array,len);

	BucketSort(array,len);

	print(array,len);

	return 0;

}
