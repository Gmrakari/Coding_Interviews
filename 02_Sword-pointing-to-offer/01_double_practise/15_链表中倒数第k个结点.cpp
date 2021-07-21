

/*
 * Date:2021-07-21 11:06
 * filename:15_链表中倒数第k个结点.cpp
 *
 */

/*
#题意
题目描述

输入一个链表，输出该链表中倒数第k个结点。

*/

#include <iostream>

//链表结点定义如下

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/*
 * 第一种思路
 * 假设整个链表有n个结点，那么倒数第k个结点就是从头结点开始的第n - k + 1个结点
 * 如果我们能够得到链表中结点的个数n，那我们只要从头结点开始往后走n - k + 1步就可以了
 *
 * 遍历两次链表，
 * 第一次获取链表的结点的个数，第二次找到倒数第k个结点
 *
 * 第二种思路
 * 定义两个指针
 * 第一个指针从链表的头指针开始遍历向前走k - 1,
 * 第二个指针保持不动;
 *
 * 从第k步开始，第二个指针也开始从链表的头指针开始遍历。
 * 由于两个指针的距离保持在K - 1,当第一个(走在前面的)指针到达链表的尾结点时，第二个指针(走在后面)指针正好是倒数第k个结点
 *
 */

ListNode* FindKthToTail(ListNode *pListHead, unsigned int k) {
	if (pListHead == NULL || k == 0)
		return NULL;
	/*
		 unsigned int nLength = 0;

		 while (pListHead) {
		 ++nLength;
		 }

		 if (nLength < k) {
		 return NULL;
		 }

*/
	ListNode *pAhead = pListHead;
	ListNode *pBehind = pListHead;

	for (unsigned int i = 0; i < k - 1; i++) {
		if (pAhead->m_pNext != NULL) {
			pAhead = pAhead->m_pNext;
		}
		else {
			return NULL;
		}
	}

	while (pAhead->m_pNext != NULL) {
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}
