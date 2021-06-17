#include <iostream>
#include "linklist.h"
using std::cout;
using std::endl;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	ListNode *node5 = new ListNode(5,NULL);
	ListNode *node4 = new ListNode(4,node5);
	ListNode *node3 = new ListNode(3,node4);
	ListNode *node2 = new ListNode(2,node3);
	ListNode *node1 = new ListNode(1,node2);
	ListNode *head = node1;
	
	ListNode* removeElements(ListNode* head, int val);
	ListNode* reverse(ListNode* head);
	
	
	head = removeElements(head,0);
	cout << "remove:";
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	
	head = node1;
	head = reverse(head);
	cout << "reverse:";
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;	
	
	return 0;
}
