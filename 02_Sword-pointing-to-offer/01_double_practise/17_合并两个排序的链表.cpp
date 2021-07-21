

/*
 * Date:2021-07-21 11:49
 * filename:17_合并两个排序的链表.cpp
 *
 */

/*
#题意
题目描述

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

样例输入

p1:1 3 5 7

p2:9 2 4

样例输出

1 2 3 4 5 7 9

*/

#include <iostream>
using namespace std;
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
	ListNode() : m_nValue(0), m_pNext(NULL) {}
	ListNode(int m_nValue) : m_nValue(m_nValue), m_pNext(NULL) {}
	ListNode(int m_nValue, ListNode *m_pNext) : m_nValue(m_nValue), m_pNext(m_pNext) {}
};

ListNode* Merge(ListNode* pHead1,ListNode* pHead2) {
	if (pHead1 == NULL && pHead2 == NULL)
		return NULL;

	if (pHead1 == NULL) return pHead2;
	else if (pHead2 == NULL) return pHead1;

	ListNode* pMergeHead = NULL;

	if (pHead1->m_nValue < pHead2->m_nValue) {
		pMergeHead = pHead1;
		pMergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	}
	else {
		pMergeHead = pHead2;
		pMergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}
	return pMergeHead;
}

void printlist(ListNode *pHead) {
	if (pHead == NULL) return ;
	while (pHead) {
		cout << pHead->m_nValue << ' ';
		pHead = pHead->m_pNext;
	}
	cout << endl;
}

int main() {

	ListNode *node4 = new ListNode(7, NULL);
	ListNode *node3 = new ListNode(5, node4);
	ListNode *node2 = new ListNode(3, node3);
	ListNode *node1 = new ListNode(1, node2);

	ListNode *node9 = new ListNode(9, NULL);
	ListNode *node8 = new ListNode(4, node9);
	ListNode *node7 = new ListNode(2, node8);

	ListNode *pHead1 = node1;
	ListNode *pHead2 = node7;

	void printlist(ListNode *pHead);
	ListNode* Merge(ListNode* pHead1,ListNode* pHead2);
	printlist(pHead1);
	printlist(pHead2);

	ListNode *Mergerhead = Merge(pHead1, pHead2);
	printlist(Mergerhead);
}
