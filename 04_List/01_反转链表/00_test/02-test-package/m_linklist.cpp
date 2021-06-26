
#include "include/linklist.h"

ListNode* init() {
	ListNode *node5 = new ListNode(5,NULL);
	ListNode *node4 = new ListNode(4,node5);
	ListNode *node3 = new ListNode(3,node4);
	ListNode *node2 = new ListNode(2,node3);
	ListNode *node1 = new ListNode(1,node2);
	ListNode *head = new ListNode();
	head->next = node1;
	
	return head;
}

ListNode *reverse(ListNode *L) {
	if (L == nullptr) return nullptr;
	ListNode *p = L->next;
	L->next = nullptr;
	while (p) {
		ListNode *cur = p;
		p = p->next;
		cur->next = L->next;
		L->next = cur;
	}
	return L->next; 
}
