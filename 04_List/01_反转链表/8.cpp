

/*
 * Date:2021-05-26 21:18
 * filename:8.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	
	ListNode() : val(0),next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
class Solution {
public:
	ListNode* reverse(ListNode *head) {
		if(head == nullptr) return nullptr;

		ListNode *pre = nullptr;
		ListNode *cur = head;

		while(cur != nullptr) {
		
		//	cur->next = tmp;
		//	cur = tmp;
		//  tmp->next = cur->next;
		//	cur = cur->next;
			
			ListNode *tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
};

*/

ListNode* reverse(ListNode *head) {
	if(head == nullptr) return nullptr;

	ListNode *pre = nullptr;
	ListNode *cur = head;

	while(cur != nullptr) {
		/*
		cur->next = tmp;
		cur = tmp;
		tmp->next = cur->next;
		cur = cur->next;
		*/
		ListNode *tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}

int main() {
	ListNode* node5 = new ListNode(5);
	ListNode* node4 = new ListNode(4);
	ListNode* node3 = new ListNode(3);
	ListNode* node2 = new ListNode(2);
	ListNode* node = new ListNode(1);

	node->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	//ListNode* head = node;

//	Solution su;
//	su.reverse(node);	

	reverse(node);

	while(node) {
		cout << node->val << ' ';
		node = node->next;
	}
	/*
	su.reverse(head);

	while(head) {
		cout << head->val << ' ';
		head = head->next;
	}
	*/
	cout << endl;
}
