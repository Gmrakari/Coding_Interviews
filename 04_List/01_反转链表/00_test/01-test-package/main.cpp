#include <iostream>
#include "./include/linklist.h"

using std::cout;
using std::endl;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ListNode* removeElements(ListNode* head, int val);
	ListNode* reverse(ListNode* head);
	ListNode* init();
	
	ListNode *head = init();
	head = removeElements(head,0);
	cout << "remove:";
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	
	/*
	head = init();
	head = reverse(head);
	cout << "reverse:";
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
		
	*/
	head = init();
	cout << "original:";
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;	
	return 0;
}
