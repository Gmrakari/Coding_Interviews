

/*
 * Date:2021-09-28 21:25
 * filename:04_反转链表.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int data;
	ListNode* next;
	ListNode() : data(0), next(NULL) {}
	ListNode(int data, ListNode* next) : data(data), next(next) {}
};

ListNode* init() {
	ListNode* node6 = new ListNode(6, NULL);
	ListNode* node5 = new ListNode(5, node6);
	ListNode* node4 = new ListNode(4, node5);
	ListNode* node3 = new ListNode(3, node4);
	ListNode* node2 = new ListNode(2, node3);
	ListNode* node1 = new ListNode(1, node2);

	ListNode* head = node1;
	return head;
}

ListNode* init_2() {
	ListNode* node9 = new ListNode(9, NULL);
	ListNode* node8 = new ListNode(8, node9);
	ListNode* node7 = new ListNode(7, node8);

	ListNode* head = node7;
	return head;
}

ListNode* reverse(ListNode* pHead) {
	if (pHead == NULL) return NULL;

	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	ListNode* pReverseHead = NULL;

	while (pNode) {
		ListNode* pNext = pNode->next;
		if (pNext == NULL) {
			pReverseHead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}

ListNode* addList(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL) return pHead2;
	if (pHead2 == NULL) return pHead1;

	if (pHead1 == NULL && pHead2 == NULL) return NULL;

	ListNode* newhead = NULL;

	if (pHead1->data < pHead2->data) {
		newhead = pHead1;
		newhead->next = addList(pHead1->next, pHead2);
	}
	else {
		newhead = pHead2;
		newhead->next = addList(pHead1, pHead2->next);
	}

	return newhead;
}

void print(ListNode* pHead) {
	if (pHead == NULL) return ;

	while (pHead) {
		cout << pHead->data << ' ';
		pHead = pHead->next;
	}
	cout << endl;
}

void test() {
	ListNode* ret = init();
	cout << "ret:";
	print(ret);
	ret = reverse(ret);
	cout << "after ret:";
	print(ret);

	ListNode* res = init_2();
	cout << "res:";
	print(res);
	res = addList(ret, res);
	cout << "merge res:";
	print(res);
}

int main() {
	test();
}
