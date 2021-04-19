
#include <bits/stdc++.h>
#include <malloc.h>
#include <algorithm>

using namespace std;

class ListNode
{
public:
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};

ListNode* init()
{
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->val = 1;

	ListNode *node1 = (ListNode *)malloc(sizeof(ListNode));
	node1->val = 2;

	ListNode *node2 = (ListNode *)malloc(sizeof(ListNode));
	node2->val = 3;

	ListNode *node3 = (ListNode *)malloc(sizeof(ListNode));
	node3->val = 4;

	ListNode *node4 = (ListNode *)malloc(sizeof(ListNode));
	node4->val = 5;

	ListNode *node5 = (ListNode *)malloc(sizeof(ListNode));
	node5->val = 6;

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = nullptr;

	return head;
}

ListNode* Reverse(ListNode *head)
{
/*
	if(head == nullptr || head->next == nullptr) return nullptr;

	ListNode* pre = nullptr;
	ListNode* cur = head;
	ListNode* after = head->next;

	while(cur != nullptr)
	{
		cur->next = pre;
		pre = cur;
		cur = after;
		if(after != nullptr)
			after = after->next;
	}
	return pre;
*/
	if(head == nullptr)
		return nullptr;

	ListNode *s;

	for(s= nullptr; head;swap(s,head))
		swap(s,head->next);

	return s;
}

int main()
{
	ListNode *head = init();

	Reverse(head);

	while(head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}
