

/*
 * Date:2021-09-02 19:19
 * filename:56_链表中环的入口结点.cpp
 *
 */

/*
 * #题目描述
一个链表中包含环，请找出该链表的环的入口结点。

*/

/*
 * 在有环的链表中找到环的入口结点的步骤:
 * 1、指针p1,p2在初始化时都指向链表的头结点;
 * 2、由于环中有n个结点，指针p1先在链表上向前移动n步
 * 3、指针p1和p2以相同的速度在链表上向前移动直到它们相遇。他们相遇的结点就是环的入口结点
 */
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *m_pNext;

	ListNode() :val(0), m_pNext(NULL) {}
	ListNode(int val) : val(val), m_pNext(NULL) {}
	ListNode(int val, ListNode* m_pNext) : val(val), m_pNext(m_pNext) {}
};

ListNode* MeetingNode(ListNode *pHead) {
	if (pHead == NULL) 
		return NULL;

	ListNode* pSlow = pHead->m_pNext;
	if (pSlow == NULL)
		return NULL;

	ListNode* pFast = pSlow->m_pNext;
	while (pFast != NULL && pSlow != NULL) {
		if (pFast == pSlow)
			return pFast;

		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if (pFast != NULL) 
			pFast = pFast->m_pNext;
	}
	return NULL;
}

ListNode* EntryNodeOfLoop(ListNode* pHead) {
	ListNode *meetingNode = MeetingNode(pHead);
	if (meetingNode == NULL)
		return NULL;

	//get the number of nodes in loop
	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;

	while (pNode1->m_pNext != meetingNode) {
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}

	//move pNode1
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; ++i) 
		pNode1 = pNode1->m_pNext;

	//move pNode1 and pNode2
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2) {
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	return pNode1;
}
