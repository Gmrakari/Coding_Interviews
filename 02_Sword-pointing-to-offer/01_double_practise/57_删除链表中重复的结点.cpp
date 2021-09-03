

/*
 * Date:2021-09-03 10:39
 * filename:57_删除链表中重复的结点.cpp
 *
 */

/*
 * #题意
题目描述

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。

例如，链表1->2->3->3->4->4->5

处理后为 1->2->5

*/

#include <iostream>
using namespace std;

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
	ListNode() : m_nValue(0), m_pNext(NULL) {}
	ListNode(int m_nValue) : m_nValue(m_nValue), m_pNext(NULL) {}
	ListNode(int m_nValue, ListNode *m_pNext) : m_nValue(m_nValue), m_pNext(m_pNext) {}
};

void deleteDuplication(ListNode** pHead) {
	if (pHead == NULL || *pHead == NULL)
		return ;

	ListNode* pPreNode = NULL;
	ListNode* pNode = *pHead;

	while (pNode != NULL) {
		ListNode *pNext = pNode->m_pNext;
		bool needDelete = false;

		if (pNext != NULL && pNext->m_nValue == pNode->m_nValue) 
			needDelete = true;

		if (!needDelete) {
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else {
			int value = pNode->m_nValue;
			ListNode *pToBeDel = pNode;

			while (pToBeDel != NULL && pToBeDel->m_nValue == value ){
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = NULL;

				pToBeDel = pNext;
			}
			if (pPreNode == NULL)
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;
		}
	}
}

ListNode* init() {
	ListNode *node7 = new ListNode(5, NULL);
	ListNode *node6 = new ListNode(4, node7);
	ListNode *node5 = new ListNode(4, node6);
	ListNode *node4 = new ListNode(3, node5);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);
	ListNode *pHead = node1;
	return pHead;
}

void Traversal(ListNode *head) {
	while (head) {
		cout << head->m_nValue << ' ';
		head = head->m_pNext;
	}
	cout << endl;
}

int main(int argc,const char* argv[])
{

	ListNode *res1 = init();
	void deleteDuplication(ListNode** pHead);
	ListNode **res2 = &res1;
	deleteDuplication(res2);
	Traversal(res1);

	return 0;
}
