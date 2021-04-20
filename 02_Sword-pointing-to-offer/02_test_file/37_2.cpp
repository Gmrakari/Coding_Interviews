#include <iostream>
using namespace std;
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};


ListNode* findFirstCommonNode(ListNode *pHead1,ListNode *pHead2)
{
	unsigned int GetListLength(ListNode* pHead);

	if(pHead1 == NULL || pHead2 == NULL)
	{
		return NULL;
	}

	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);

	int nLengthDif = nLength1 - nLength2;

	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;

	if(nLength1 < nLength2)
	{
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	for(int i = 0; i < nLengthDif;i++)
	{
		pListHeadLong = pListHeadLong->m_pNext;
	}

	while( pListHeadLong != NULL &&
			pListHeadShort != NULL &&
			pListHeadLong != pListHeadShort)
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}
	ListNode* common = pListHeadLong;
	return common;
}

unsigned int GetListLength(ListNode* pHead)
{
	if(pHead == NULL)
		return -1;

	unsigned int nLength = 0;
	while(pHead)
	{
		nLength++;
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
