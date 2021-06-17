

#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#include <iostream>
#include <algorithm>
#include <stack>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0),next(NULL) {} 
	ListNode(int x) : val(x),next(NULL) {} 
	ListNode(int x,ListNode *next) : val(x),next(next) {} 
};

ListNode* removeElements(ListNode* head, int val);
ListNode* reverse(ListNode* head);

#endif
