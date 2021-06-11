#include <bits/stdc++.h>

/*
 * Date:2021-06-11 23:09
 * filename:7.cpp
 */

using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode *reverse_1(ListNode *phead) {
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

ListNode *reverse_2(ListNode *phead) {
	if (phead == nullptr) return nullptr;
	ListNode *p;
	for (p = nullptr;phead;swap(p, phead)) {
		swap(p,phead->next);
	}
	return p;
}

ListNode *reverse_3(ListNode *phead) {
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

int main() {
	ListNode *node4 = new ListNode(4,nullptr);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);

	/*
	ListNode *head = node1;
	ListNode *node = reverse_1(head);
	while (node) {
		cout << node->val << ' ';
		node = node->next;
	}
	cout << endl;
	
	*/

	/*

	ListNode *head2 = node1;
	ListNode *re_node = reverse_2(head2);
	while (re_node) {
		cout << re_node->val << ' ';
		re_node = re_node->next;
	}
	cout << endl;

	*/

	ListNode *head3 = node1;
	ListNode *m_node = reverse_3(head3);
	while (m_node) {
		cout << m_node->val << ' ';
		m_node = m_node->next;
	}
	cout << endl;

	return 0;
}


