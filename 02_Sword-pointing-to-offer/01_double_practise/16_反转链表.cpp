

/*
 * Date:2021-06-27 23:09
 * filename:016_反转链表.cpp
 *
 */

#include <iostream>
using namespace std;

class ListNode {
public:
	int m_nKey;
	ListNode* m_pNext;
	ListNode() : m_nKey(0), m_pNext(NULL) {}
	ListNode(int m_nKey) : m_nKey(m_nKey), m_pNext(NULL) {}
	ListNode(int m_nKey, ListNode *m_pNext) : m_nKey(m_nKey), m_pNext(m_pNext) {}
};

/*
 * 让pNode的下一个结点指向上一个节点
 * 更新上一个节点为当前节点(pPre = pNode)
 * 更新当前节点为下一个节点 pNode = pNext;
 */

ListNode* ReverseList(ListNode* pHead) {
	if (pHead == NULL) return NULL;
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode) {
		ListNode* pNext = pNode->m_pNext;
		if (pNext == NULL) {
			pReverseHead = pNode;
		}
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}

/*
 * Date:2021-07-21 11:40
 */

/*
 * 让pNode的下一个结点指向上一个节点
 * 更新上一个节点为当前节点(pPre = pNode)
 * 更新当前节点为下一个节点 pNode = pNext;
 */

ListNode* ReverseList_2(ListNode *pHead) {
	if (pHead == NULL) {
		return NULL;
	}
	ListNode *pReverseHead = NULL;
	ListNode *pNode = pHead;
	ListNode *pPrev = NULL;

	while (pNode) {
		ListNode *pNext = pNode->m_pNext;
		if (pNext == NULL) {
			pReverseHead = pNode;
		}
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}

int main() {
	/*
	ListNode *node3 = NULL,*node2 = NULL,*node1 = NULL,*head = NULL;
	node1->m_nKey = 1;
	node2->m_nKey = 2;
	node3->m_nKey = 3;

	node1->m_pNext = node2;
	node2->m_pNext = node3;
	node3->m_pNext = NULL;
	*/
	ListNode *node3 = new ListNode(3,NULL);
	ListNode *node2 = new ListNode(2,node3);
	ListNode *node1 = new ListNode(1,node2);
	ListNode *head;

	head = ReverseList_2(node1);
	while (head) {
		cout << head->m_nKey << ' ';
		head = head->m_pNext;
	}
	cout << endl;

}
