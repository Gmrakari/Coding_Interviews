

/*
 * Date:2022-03-22 09:23
 * filename:03_review_reverse_list.cpp
 *
 */

#include <iostream>

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL){}
	ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
public:
	ListNode* reverse(ListNode *phead) {
		if (phead == NULL)
			return NULL;

		ListNode *tmp;
		ListNode *cur = phead;
		ListNode *prev = NULL;

		while (cur) {
			tmp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tmp;
		}
		return prev;
	}
	void traval(ListNode *phead) {
		if (phead == NULL) return ;
		while(phead) {
			std::cout << phead->val << " ";
			phead = phead->next;
		}
		std::cout << std::endl;
	}

	ListNode* recursion_reverse_list(ListNode *phead) {
		if (phead == NULL)
			return NULL;
		if (phead->next == NULL)
			return phead;

		ListNode *tmp = recursion_reverse_list(phead->next);
		phead->next->next = phead;
		phead->next = NULL;

		return tmp;
	}

	ListNode* insert(ListNode *phead, int data) {
		if (phead == NULL) return NULL;
		while (phead->next) {
			phead = phead->next;
		}

		ListNode *newnode = new ListNode(data, NULL);
		phead->next = newnode;
		newnode->next = NULL;
		return phead;	
	}
	ListNode* m_delete(ListNode *phead, int data) {
		if (phead == NULL) 
			return NULL;

		//删除头节点
		while (phead != NULL && phead->val == data) {
			ListNode *tmp = phead;
			phead = tmp->next;
			delete tmp;
		}

		//删除非头节点
		ListNode *cur = phead;
		while (cur->next != NULL && cur->next != NULL) {
			if (cur->next->val == data) {
				ListNode *tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else {
				cur = cur->next;
			}
		}
		return phead;
	}	
	ListNode* remove_ele(ListNode *phead, int val) {
		if (phead == NULL)
			return NULL;

		ListNode *cur = phead;
		while (cur->next != NULL) {
			if (cur->next->val == val) {
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}
		return phead->val == val ? phead->next : phead;
	}
		
};

ListNode *init() {
	ListNode *node5 = new ListNode(5, NULL);
	ListNode *node4 = new ListNode(4, node5);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);

	ListNode *head = node1;

	return head;
}

int main() {
	Solution test;
	ListNode *phead = init();
	test.traval(phead);
	//phead = test.reverse(phead);
	phead = test.recursion_reverse_list(phead);
	test.traval(phead);

	phead = init();
	for (int i = 6; i < 8; i++) {
		test.insert(phead, i);
	}
	std::cout << "insert:" << std::endl;
	test.traval(phead);

	std::cout << "delete:" << std::endl;
	test.m_delete(phead, 1);
	test.traval(phead);
}

