

/*
 * Date:2021-07-16 11:04
 * filename:05_从尾到头打印链表.cpp
 *
 */

/*
 链表结点定义
 */
struct ListNode
{
	int 	  m_nValue;
	ListNode* m_pNext;
};

/*
#题意
题目描述

输入一个链表，从尾到头打印链表每个节点的值。

输入描述:

输入为链表的表头

输出描述:

输出为需要打印的“新链表”的表头

*/


void PrintListReversingly_Iteratively(ListNode* pHead) {
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != NULL) {
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty()) {
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		node.pop();
	}
}

/* 既然想到了栈来实现这个函数，而递归的本质上就是一个栈的结构，
 * 于是很自然地又想到了用递归来实现。
 * 要实现反过来输出链表，我们每访问到一个结点的时候，先递归输出它后面的结点，再输出该节点自身
 * 这样的输出结果就反回来了
 */
void PrintListReversingly_Recursively(ListNode* pHead) {
	if (pHead != NULL) {
		if (pHead->m_pNext != NULL) {
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t",pHead->m_nValue);
	}
}


