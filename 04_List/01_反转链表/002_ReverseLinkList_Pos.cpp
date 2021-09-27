#include <bits/stdc++.h>
using namespace std;
/*
 * Date:2021-09-27 14:03
 * file:分段逆转单链表
 * 
 */
  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct ListNode {
	int data;
	ListNode* next;
	ListNode() : data(0), next(NULL) {}
	ListNode(int data) : data(data), next(NULL) {}
	ListNode(int data, ListNode* next) : data(data), next(next) {}
};

ListNode* init(){
	ListNode *node6 = new ListNode(6, NULL);
	ListNode *node5 = new ListNode(5, node6);
	ListNode *node4 = new ListNode(4, node5);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);
	
	ListNode *pHead = node1;
	return pHead;
}

int GetLinkListLength(ListNode *pHead) {
	int length = 0;
	while (pHead) {
		++length;
		pHead = pHead->next; 
	}
	return length;
} 
ListNode* Sectional_LinkListReverse(ListNode* pHead, int pos) {
	if (pHead == NULL || pos < 0) {
		return NULL;
	}
	int length = GetLinkListLength(pHead);
	
	ListNode* pReverseHead = NULL;
	ListNode* pPrev = NULL;
	ListNode* currentNode = pHead;
	ListNode* newhead = NULL;
	ListNode* pNode = pHead;
	
	for (int i = 0; i < pos; i++ ){
		currentNode = currentNode->next;
	}
	while (pos--) {
		ListNode* pNext = pNode->next;
		if (pNext == currentNode) {
			pReverseHead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	/*
	while (pReverseHead) {
		pReverseHead->next =  currentNode;
		pReverseHead = pReverseHead->next;
	}
	*/
	return pReverseHead;
}

void Traval(ListNode *node) {
	if (node == NULL) return ;
	
	while (node) {
		cout << node->data << ' ';
		node = node->next;
	} 
	cout << endl;
}

int main(int argc, char** argv) {
	
	ListNode* head = init();
	Traval(head);
	//head = Sectional_LinkListReverse(head, 3);
	Traval(head);
	return 0;
}
