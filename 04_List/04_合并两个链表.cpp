

/*
 * Date:2022-03-02 18:34
 * filename:04_合并两个链表.cpp
 *
 */

#include <iostream>
#include <bits/stdc++.h>


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode() : val(0), next(NULL){}
};

ListNode *MergeTwoLists(ListNode *list1, ListNode *list2) {
	if (list1 == NULL || list2 == NULL)
		return NULL;

	if (list1 == NULL) return list2;
	else if (list2 == NULL) return list1;

	ListNode *mergelist = NULL;

	if (list1->val < list2->val) {
		mergelist = list1;
		mergelist->next = MergeTwoLists(list1->next, list2);
	}
	else {
		mergelist = list2;
		mergelist->next = MergeTwoLists(list1, list2->next);
	}

	return mergelist;
}


