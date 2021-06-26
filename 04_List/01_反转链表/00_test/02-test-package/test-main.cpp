#include <iostream>
#include "include/linklist.h"
using namespace std;

int main() {
	ListNode *head = init();
	head = reverse(head);
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;	
	return 0;
}
