#pragma once
#ifndef __M_LINKLIST_H_
#define __M_LINKLIST_H_

#include <bits/stdc++.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(),next(NULL) {} 
	ListNode(int x) : val(x),next(NULL) {} 
	ListNode(int x,ListNode *next) : val(x),next(next) {} 
};

ListNode* init();

//LC 203
ListNode* removeElements(ListNode* head, int val);

//LC 206
ListNode* reverse(ListNode* head);

#endif
