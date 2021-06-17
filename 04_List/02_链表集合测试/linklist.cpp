#include "linklist.h"

ListNode* init() {
	ListNode *node5 = new ListNode(5,NULL);
	ListNode *node4 = new ListNode(4,node5);
	ListNode *node3 = new ListNode(3,node4);
	ListNode *node2 = new ListNode(2,node3);
	ListNode *node1 = new ListNode(1,node2);
	ListNode *head = node1;
	
	return head;
}

ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL) return NULL;
	
	ListNode *newhead = new ListNode();
	newhead->next = head;
	
	ListNode *pre = newhead;
	ListNode *cur = newhead->next;
	
	while(cur) {
		if (cur->val == val) {
			pre->next = cur->next;
			cur = pre->next;
		}else {
			pre = pre->next;
			cur = cur->next;
		}
	}
	return newhead->next;
}

ListNode* reverse(ListNode* head) {

/*
	if (head == NULL) return NULL;
	stack<ListNode *> st;
	
	while(head) {
		st.push(head);
		head = head->next;
	}	
	
	ListNode *newhead = st.top();
	ListNode *newnode = newhead;
	st.pop();
	
	while(!st.empty()) {
		newnode->next = st.top();
		st.pop();
		newnode = newnode->next;
	}
	newnode->next = NULL;
	return newhead;
*/
} 
