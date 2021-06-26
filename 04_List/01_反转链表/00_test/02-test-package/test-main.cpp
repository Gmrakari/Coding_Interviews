#include <iostream>
#include "./include/linklist.h"
#include "m_linklist.cpp"

using std::cout;
using std::endl;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ListNode* removeElements(ListNode* head, int val);
	ListNode* reverse(ListNode* head);
	ListNode* init();
	
	ListNode *head = init();
	head = reverse(head);
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;	
	return 0;
}
