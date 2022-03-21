

/*
 * Date:2022-03-21 23:52
 * filename:02_single_list_insert_and_delete.cpp
 *
 */


#include <iostream>
#include <stdlib.h>

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL){}
	ListNode(int val, ListNode *next): val(val), next(next){}
};

class Solution {
public:
	ListNode* insert(ListNode *list, int val) {
		if (list == NULL)
			return NULL;

		ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
		newnode->val = val;
		while (list->next != NULL) {
			list = list->next;
		}
		list->next = newnode;
		newnode->next = NULL;
		return list;
	}
	void traval(ListNode* phead) {
		if (phead == NULL) return ;
		while (phead) {
			std::cout << phead->val << " ";
			phead = phead->next;
		}
		std::cout << std::endl;
	}
};

ListNode* init() {
	ListNode *node4 = new ListNode(4, NULL);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);

	ListNode *phead = node1;
	return phead;
}
void test_01() {
	ListNode* phead =  init();
	Solution test;
	std::cout << "before:" << std::endl;
	test.traval(phead);
	int val_1 = 5, val_2 = 6;
	test.insert(phead, val_1);
	test.insert(phead, val_2);

	std::cout << "after:" << std::endl;
	test.traval(phead);
	std::cout << std::endl;
}
int main() {
	test_01();
}
