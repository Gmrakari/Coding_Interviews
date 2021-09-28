

/*
 * Date:2021-09-14 21:29
 * filename:03_单链表翻转.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(NULL) {}
	ListNode(int val) : val(val), next(NULL) {}
	ListNode(int val, ListNode* next) : val(val), next(next){}
};

ListNode* reverseList(ListNode *pHead) {
	if (pHead == NULL) 
		return NULL;

	ListNode *pPrev = NULL;
	ListNode *pReversePhead = NULL;
	ListNode *pNode = pHead;

	while (pNode) {
		ListNode* pNext = pNode->next;
		if (pNext == NULL) {
			pReversePhead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversePhead;
}

ListNode* init() {
	ListNode* node5 = new ListNode(5, NULL);
	ListNode* node4 = new ListNode(4, node5);
	ListNode* node3 = new ListNode(3, node4);
	ListNode* node2 = new ListNode(2, node3);
	ListNode* node1 = new ListNode(1, node2);
	
	ListNode *head = node1;
	return head;
}

int main() {
	ListNode* node = init();

	node = reverseList(node);

	while (node) {
		cout << node->val << ' ';
		node = node->next;
	}
	cout << endl;
}
