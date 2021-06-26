#include "./include/linklist.h"

ListNode* init() {
	ListNode *node5 = new ListNode(5,NULL);
	ListNode *node4 = new ListNode(4,node5);
	ListNode *node3 = new ListNode(3,node4);
	ListNode *node2 = new ListNode(2,node3);
	ListNode *node1 = new ListNode(1,node2);
	ListNode *head = node1;
	
	return head;
}

ListNode* reverse(ListNode* head) {
	if (head == nullptr) return nullptr;
	ListNode* pre = head;
	ListNode* cur = nullptr;

	while (cur) {
		ListNode *node = pre->next;
		pre->next = cur;
		cur = pre;
		pre = node;
	}
	return cur;
} 
