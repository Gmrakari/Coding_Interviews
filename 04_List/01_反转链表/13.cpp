

/*
 * Date:2021-08-18 15:07
 * filename:13.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	
	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode *head) {
	if (head == NULL) return NULL;
	stack<ListNode *> my_stack;
	my_stack.push(head);
	while (head) {
		my_stack.push(head);
		head = head->next;
	}

	ListNode *newhead = my_stack.top();
	ListNode *newnode = newhead;
	my_stack.pop();

	while (!my_stack.empty()) {
		newnode->next = my_stack.top();
		newnode = newnode->next;
		my_stack.pop();
	}
	newnode->next = NULL;
	return newhead;
}

int main() {
	ListNode* node5 = new ListNode(5);
	ListNode* node4 = new ListNode(4);
	ListNode* node3 = new ListNode(3);
	ListNode* node2 = new ListNode(2);
	ListNode* node = new ListNode(1);

	node->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	node = reverse(node);

	while(node) {
		cout << node->val << ' ';
		node = node->next;
	}
	cout << endl;
}
