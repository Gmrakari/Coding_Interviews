

/*
 * Date:2021-06-28 08:13
 * filename:10.cpp
 *
 */

/*
 * 为了正确地反转一个链表，需要调整链表中指针的方向
 * tmp都指向前面一个节点
 * 我们需要在最后一个节点的前一个节点把最后一个节点缓存下来
 * 以防止链表断开
 * 我们需要定义3个指针，分别指向当前遍历到的结点，它的前一个节点以及后一个结点
 *
 */

#include <iostream>
using namespace std;

class ListNode {
public:
	int m_data;
	ListNode *m_pNext;
	ListNode() : m_data(),m_pNext() {  }
	ListNode(int m_data) : m_data(m_data), m_pNext(NULL) {  }
	ListNode(int m_data, ListNode *m_pNext) : m_data(m_data), m_pNext(m_pNext) {  }
};

ListNode *ReverseList(ListNode *pHead) {
	if (pHead == NULL) return NULL;
	ListNode *pReverseHead = NULL;
	ListNode *pNode = pHead;
	ListNode *pPre = NULL;

	while (pNode) {
		ListNode *tmp = pNode->m_pNext;
		if (pNode->m_pNext == NULL) {
			 pReverseHead = pNode; 
		}
		pNode->m_pNext = pPre;
		pPre = pNode;
		pNode = tmp;
	}
	return pReverseHead;
}

int main() {
	ListNode *node3 = new ListNode(3,NULL);
	ListNode *node2 = new ListNode(2,node3);
	ListNode *node1 = new ListNode(1,node2);
	ListNode *head = node1;

	head = ReverseList(head);
	while (head) {
		cout << head->m_data << ' ';
		head = head->m_pNext;
	}
	cout << endl;
	return 0;
}
