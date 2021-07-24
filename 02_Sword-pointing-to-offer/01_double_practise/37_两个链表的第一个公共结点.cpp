

/*
 * Date:2021-07-24 14:42
 * filename:37_两个链表的第一个公共结点.cpp
 *
 */

/*
#题意
题目描述

输入两个链表，找出它们的第一个公共结点。

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
	ListNode() : m_nKey(0),m_pNext(NULL) {}
	ListNode(int m_nKey) : m_nKey(m_nKey),m_pNext(NULL) {}
	ListNode(int m_nKey, ListNode *m_pNext) : m_nKey(m_nKey),m_pNext(m_pNext) {}
};

unsigned int GetListLength(ListNode *pHead) {
	int nLength = 0;
	while (pHead) {
		++nLength;
		pHead = pHead->m_pNext;
	}
	return nLength;
}

ListNode* FindFirstCommonNode(ListNode *pHead1,ListNode *pHead2) {
	if (pHead1 == NULL || pHead2 == NULL) 
		return NULL;
	ListNode *LongList = pHead1;
	ListNode *ShortList = pHead2;
	unsigned int nListLong = GetListLength(pHead1);
	unsigned int nListShort = GetListLength(pHead2);
	unsigned int ndiff = nListLong - nListShort;
	if (nListLong < nListShort) {
		LongList = pHead2;
		ShortList = pHead1;
		ndiff = nListShort - nListLong;
	}
	for (unsigned int i = 0; i < ndiff; i++) {
		LongList = LongList->m_pNext;
	}
	while (LongList != NULL && ShortList != NULL
			&& LongList != ShortList) {
		LongList = LongList->m_pNext;
		ShortList = ShortList->m_pNext;
	}
	ListNode *pFirstCommonNode = LongList;
	return pFirstCommonNode;
}

int main () {
	ListNode *comnode7= new ListNode(7, NULL);
	ListNode *comnode6= new ListNode(6, comnode7);
	ListNode *node3 = new ListNode(3, comnode6);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);

	ListNode *node5 = new ListNode(5, comnode6);
	ListNode *node4 = new ListNode(4, node5);

	ListNode *find = NULL;
	find = FindFirstCommonNode(node1, node4);

	while (find) {
		cout << find->m_nKey << " ";
		find = find->m_pNext;
	}
	cout << endl;
	return 0;
}
