

/*
 * Date:2021-06-14 20:51
 * filename:9.cpp
 *
 */

#include <iostream>
#include <stack>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;

	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x),next(next) {}
};


class Solution {
public:
	ListNode *init() {
		ListNode *node4 = new ListNode(4,nullptr);
		ListNode *node3 = new ListNode(3,node4);
		ListNode *node2 = new ListNode(2,node3);
		ListNode *node1 = new ListNode(1,node2);

		ListNode *head = node1;
	
		return head;
	}

	ListNode *stack_reverse(ListNode *phead) {
		if (phead == nullptr) return nullptr;
		stack<ListNode *> st;
		while (phead) {
			st.push(phead);
			phead = phead->next;
		}

		ListNode *newhead = st.top();
		ListNode *newnode = newhead;
		st.pop();

		while (!st.empty()) {
			newnode->next = st.top();
			st.pop();
			newnode = newnode->next;
		}
		newnode->next = nullptr;

		return newhead;
	}
	ListNode *node_reverse(ListNode *phead) {
		if (phead == nullptr) return nullptr;
		ListNode *cur = phead;
		ListNode *pre = nullptr;
		ListNode *node = nullptr;

		while (cur) {
			node = cur->next;
			cur->next = pre;
			pre = cur;
			cur = node;
		}
		return pre;
	}
	ListNode *for_reverse(ListNode *phead) {
		if (phead == nullptr) return nullptr;
		ListNode *p;
		for (p = nullptr;phead;swap(p, phead)) {
			swap(p,phead->next);
		}
		return p;
	}	
};

int main() {
	Solution su;

	ListNode *head = su.init();
	ListNode *head2 = su.init();
	ListNode *head3 = su.init();

	head = su.stack_reverse(head);
	head2 = su.node_reverse(head2);
	head3 = su.for_reverse(head3);

	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;

	while (head2) {
		cout << head2->val << ' ';
		head2 = head2->next;
	}
	cout << endl;

	while (head3) {
		cout << head3->val << ' ';
		head3 = head3->next;
	}
	cout << endl;
	return 0;
}

