
#include <iostream>
using namespace std;

/*
 * Date:2021-03-06 08:30
 * Author:Gmrakari
 * Filename:1.cpp
 *
 */

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//思路：

//计算出长度
//找到长的链表
//长 & 短 的一起走 一起比较
//如果存在
//返回共同链表
//否则返回NULL

ListNode* findFirstCommonNode(ListNode *pHead1,ListNode *pHead2)
{
	unsigned int GetListLength(ListNode* pHead);
	int nLength1 = GetListLength(pHead1);
	int nLength2 = GetListLength(pHead2);

	int nLengthDif = nLength1 - nLength2;

	ListNode* pListLong = pHead1;
	ListNode* pListShort = pHead2;

	if(nLength1 < nLength2)
	{
		pListLong = pHead2;
		pListShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	for(int i = 0; i < nLengthDif;i++)
	{
		pListLong = pListLong->m_pNext;
	}

	while(pListLong != NULL && 
		pListShort != NULL &&
		pListLong != pListShort)
	{
		pListLong = pListLong->m_pNext;
		pListShort = pListShort->m_pNext;
	}
	ListNode* common = pListLong;
	
	return common;

}
unsigned int GetListLength(ListNode* pHead)
{
	int nLength = 0;
	if(pHead == NULL)
	{
		return 0;
	}
	while(pHead)
	{
		++nLength;
		pHead = pHead->m_pNext;
	}
	return nLength;
}

int main(int argc,const char* argv[])
{
	ListNode common[2];
	common[0].m_nKey = 6;
	common->m_pNext = &common[1];
	common[1].m_nKey = 7;
	common[1].m_pNext = NULL;

	ListNode left[3];
	left[0].m_nKey = 1;
	left[0].m_pNext = &left[1];
	
	left[1].m_nKey = 2;
	left[1].m_pNext = &left[2];

	left[2].m_nKey = 3;
	left[2].m_pNext = &common[0];


	ListNode right[2];
	right[0].m_nKey = 4;
	right[0].m_pNext = &right[1];

	right[1].m_nKey = 5;
	right[1].m_pNext = &common[0];


	unsigned int GetListLength(ListNode* pHead);

	ListNode* findFirstCommonNode(ListNode *pHead1,ListNode *pHead2);

	ListNode *node;

	node = findFirstCommonNode(right,left);
	while(node != NULL)
	{
		cout << node->m_nKey << ' ';
		node = node->m_pNext;
	}
	cout << endl;
	return 0;
}
