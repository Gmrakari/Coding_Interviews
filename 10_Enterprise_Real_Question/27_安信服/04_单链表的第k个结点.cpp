

/*
 * Date:2022-03-23 00:03
 * filename:04_单链表的第k个结点.cpp
 *
 */

#include <iostream>

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int val, ListNode *next) : val(val), next(next) {} 
};

class Solution {
public:
	ListNode* get_Kth_node(ListNode *phead, int k) {
		if (phead == NULL || k <= 0) 
			return NULL;

		ListNode *fast = phead;
		ListNode *slow = phead;
		while (k--) {
			if (fast) {
				fast = fast->next;
			}
			else 
				return NULL;
		}

		while (fast) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	void tral(ListNode *phead) {
		if (phead == NULL) 
			return ;

		std::cout << phead->val << std::endl;
	}
};

int main() {
	ListNode *node4 = new ListNode(4, NULL);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);
	ListNode *node0 = new ListNode(0, node1);

	ListNode *phead = node0;

	Solution test;
	int k = 4;
	ListNode *m_list = test.get_Kth_node(phead, k);
	test.tral(m_list);
}


