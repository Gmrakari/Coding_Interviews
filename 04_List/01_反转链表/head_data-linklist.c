

/*
 * Date:2021-12-11 20:14
 * filename:head_data-linklist.c
 *
 */

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int n_mValue;
	struct ListNode* next;
};

ListNode* reverse(ListNode* phead) {
	if (phead == NULL || phead->next == NULL)
		return NULL;

	ListNode* cur = phead->next;
	phead->next = NULL;

	while (cur) {
		ListNode* node = cur;
		cur = cur->next;
		node->next = phead->next;
		phead->next = node;
	}
	return phead->next;
}

int main() {
	ListNode* node5 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* node4 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* node3 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* node1 = (ListNode*)malloc(sizeof(ListNode));

	node1->n_mValue = 1;
	node2->n_mValue = 2;
	node3->n_mValue = 3;
	node4->n_mValue = 4;
	node5->n_mValue = 5;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = node1;
	
	head = reverse(head);

	while (head != NULL) {
		printf("head->data:%d\n", head->n_mValue);
		head = head->next;
	}

}
