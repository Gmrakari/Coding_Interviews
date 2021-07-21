

/*
 * Date:2021-07-21 10:17
 * filename:13_在O(1)时间删除链表结点.cpp
 *
 */

/*
#题目
给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。

*/
#include <iostream>
#include <cstdio>

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/*
 * 第一种思路，从头结点开始遍历，找到需要删除的结点的上一个结点
 * 将上一个结点的指针指向需要删除结点的下一个结点，释放需要删除的结点
 *
 * 第二种思路，找到需要删除的结点i，将需要删除的结点的下一个节点j覆盖在需要删除结点i上
 * 把需要删除的结点i指向j下一个结点上，此时删除结点j，其效果刚好是把结点i给删除了
 *
 * 如果链表中只有一个结点，而我们又要删除链表的头结点(也就是尾结点),此时我们在删除结点之后，
 * 还需要把链表的头结点设置为NULL
 */

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
	if (!pListHead || !pToBeDeleted) 
		return ;

	//要删除的节点不是尾结点
	if (pToBeDeleted->m_pNext != NULL) {
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	
	//链表只有一个结点，删除头节点(也就是尾结点)
	else if (*pListHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}

	//链表中有多个结点，删除尾结点
	else {
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
