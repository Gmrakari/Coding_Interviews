

/*
 * Date:2021-07-27 17:14
 * filename:02_链表拆分.cpp
 *
 */

/*
	 【题目描述】
	 设 C={a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的 hc 单链表存放，设计一个算法，
	 将其拆分为两个线性表，使得奇数位保持正序，偶数位转化为逆序。
	 即：A={a1,a2,...,an}，B={bn,...,b2,b1}

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int m_data;
	ListNode *m_pNext;
	ListNode() : m_data(0),m_pNext() {  }
	ListNode(int m_data) : m_data(m_data), m_pNext(NULL) {  }
	ListNode(int m_data, ListNode *m_pNext) : m_data(m_data), m_pNext(m_pNext) {  }
};

ListNode *reverse(ListNode *pHead) {
	if (pHead == NULL)
		return NULL;

	ListNode *pNode = pHead;
	ListNode *ReverseHead = NULL;
	ListNode *pPrev = NULL;

	while (pNode) {
		ListNode *node = pNode->m_pNext;
		if (pNode->m_pNext == NULL) {
			ReverseHead = pNode;
		}
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = node;
	}
	return ReverseHead;
}

ListNode *single_and_double(ListNode *hc) {
	ListNode *merge_list(ListNode *phead1, ListNode *phead2);
	ListNode *reverse(ListNode *pHead);
	if (hc == NULL) 
		return NULL;

	ListNode *pNode = hc;
	ListNode *sList = new ListNode();
	ListNode *dList = new ListNode();
	ListNode *sList_head = sList;
	ListNode *dList_head = dList;

	while (pNode) {
		if (pNode->m_data & 1) {
			ListNode* node = new ListNode(pNode->m_data);
			sList->m_pNext = node;
			sList = sList->m_pNext;
		}
		else {
			ListNode* node = new ListNode(pNode->m_data);
			dList->m_pNext = node;
			dList = dList->m_pNext;
		}
		pNode = pNode->m_pNext;
	} 
	/*
		 if (sList_head == sList) {
		 return dList_head->m_pNext;
		 }
		 if (dList_head == dList) {
		 return sList_head->m_pNext;
		 }
		 */
	//sList->m_pNext = dList_head->m_pNext;
	ListNode *reverse_list = reverse(dList_head);
	
	ListNode *mergelist = merge_list(sList_head, reverse_list);
	return mergelist;
}

ListNode* addList(ListNode *pHead1, ListNode *pHead2) {
	if (pHead1 == NULL || pHead2 == NULL) 
		return NULL;
	ListNode *com = pHead1;
	while (pHead1 && pHead2) {
		if (pHead1->m_data <= pHead2->m_data) {
			com->m_pNext = pHead1;
			com = pHead1;
			pHead1 = pHead1->m_pNext;
		}
		else {
			com->m_pNext = pHead2;
			com = pHead2;
			pHead2 = pHead2->m_pNext;
		}
	}
	com->m_pNext = pHead1 ? pHead1 : pHead2;
	return com;
}

ListNode *merge_list(ListNode *phead1, ListNode *phead2) {
	if(phead1 == NULL && phead2 == NULL) 
		return NULL;

	if (phead1 == NULL) return phead2;
	else if (phead2 == NULL) return phead1;

	ListNode* p_mergeListhead = NULL;
	if (phead1->m_data <= phead2->m_data) {
		p_mergeListhead = phead1;
		p_mergeListhead->m_pNext = merge_list(phead1->m_pNext, phead2);
	}
	else {
		p_mergeListhead = phead2;
		p_mergeListhead->m_pNext = merge_list(phead1, phead2->m_pNext);
	}
	return p_mergeListhead;
}

int main() {
	ListNode *node5 = new ListNode(5, NULL);
	ListNode *node4 = new ListNode(4, node5);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);
	ListNode *head = node1;

	//	ListNode *single_and_double(ListNode *hc);
	//	head = single_and_double(head);
	/*
		 while (head) {
		 cout << head->m_data << ' ';
		 head = head->m_pNext;
		 }
		 cout << endl;
		 */

	ListNode *node7 = new ListNode(7, NULL);	
	ListNode *node6 = new ListNode(6,node7);	
	ListNode *head2 = node6;
//	ListNode *add = merge_list(head, head2);
	ListNode *add = single_and_double(head);

	while (add) {
		cout << add->m_data << ' ';
		add = add->m_pNext;
	}
	cout << endl;
	return 0;
}
