
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
	int nLength1 = GetListLength(pHead1);
	int nLength2 = GetListLength(pHead2);

	int nLengthDif = nLength1 - nLength2;

	ListNode* pListNodeLong = pHead1;
	ListNode* pListNodeShort = pHead2;

	if(nLength1 < nLength2)
	{
		nLengthDif = nLength2 - nLength1;
		pListNodeLong = pHead2;
		pListNodeShort = pHead1;
	}

	for(int i = 0; i < nLengthDif;i++)
	{
		pListNodeLong = pListNodeLong->m_pNext;
	}

	while(pListNodeLong != NULL &&
		pListNodeShort != NULL &&
		pListNodeLong != pListNodeShort)
	{
		pListNodeLong = pListNodeLong->m_pNext;
		pListNodeShort = pListNodeShort->m_pNext;
	}
	ListNode* common = pListNodeLong;
	return common;
}
unsigned int GetListLength(ListNode* pHead)
{
	if(pHead == NULL)
		return 0;
	int nLength = 0;
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
	//left[2].m_pNext = &common[0];
	left[2].m_pNext = NULL;


	ListNode right[2];
	right[0].m_nKey = 4;
	right[0].m_pNext = &right[1];

	right[1].m_nKey = 5;
	//right[1].m_pNext = &common[0];
	right[1].m_pNext = NULL;


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
