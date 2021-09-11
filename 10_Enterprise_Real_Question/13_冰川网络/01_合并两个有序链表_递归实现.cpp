

/*
 * Date:2021-09-10 21:11
 * filename:01_合并两个有序链表_递归实现.cpp
 *
 */

#include <iostream>
using namespace std;
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
	ListNode() : m_nValue(0), m_pNext(NULL) {}
	ListNode(int m_nValue) : m_nValue(m_nValue), m_pNext(NULL) {}
	ListNode(int m_nValue, ListNode *m_pNext) : m_nValue(m_nValue), m_pNext(m_pNext) {}
};

ListNode* Merge(ListNode* pHead1,ListNode* pHead2) {
	if (pHead1 == NULL && pHead2 == NULL)
		return NULL;

	if (pHead1 == NULL) return pHead2;
	else if (pHead2 == NULL) return pHead1;

	ListNode *m_Node = new ListNode(0);
	ListNode* pMergeHead =  m_Node;

	ListNode* listA = pHead1;
	ListNode* listB = pHead2;

	while (listA && listB) {
		if (listA->m_nValue < listB->m_nValue){
			pMergeHead->m_pNext = listA;
			pMergeHead = pMergeHead->m_pNext;
			listA = listA->m_pNext;
		}
		else {
			pMergeHead->m_pNext = listB;
			pMergeHead = pMergeHead->m_pNext;
			listB = listB->m_pNext;
		}
	}

	pMergeHead->m_pNext = listA ? listA : listB;
	return m_Node->m_pNext;
}


ListNode* Merge_2(ListNode* pHead1,ListNode* pHead2) {
	if (pHead1 == NULL && pHead2 == NULL)
		return NULL;

	if (pHead1 == NULL) return pHead2;
	else if (pHead2 == NULL) return pHead1;

	/*
	ListNode *pMergeHead = NULL;
	if (pHead1->m_nValue < pHead2->m_nValue) {
		pMergeHead = pHead1;
		pHead1 = pHead1->m_pNext;
	}
	else {
		pMergeHead = pHead2;
		pHead2 = pHead2->m_pNext;
	}
	*/

	ListNode* pMergeHead = pHead1;
	pHead1 = pHead1->m_pNext;

	ListNode *newmergehead = pMergeHead;
	while (pHead1 && pHead2) {
		if (pHead1->m_nValue < pHead2->m_nValue){
			pMergeHead->m_pNext = pHead1;
			pHead1 = pHead1->m_pNext;
		}
		else {
			pMergeHead->m_pNext = pHead2;
			pHead2 = pHead2->m_pNext;
		}
		pMergeHead = pMergeHead->m_pNext;
	}
	pMergeHead->m_pNext = pHead1 ? pHead1 : pHead2;
	return newmergehead;
}

ListNode *Merge_recursive(ListNode* pHead1, ListNode *pHead2) {
	if (pHead1 == NULL && pHead2 == NULL)
		return NULL;

	if (pHead1 == NULL) return pHead2;
	else if (pHead2 == NULL) return pHead1;

	ListNode *mergehead = NULL;
	if (pHead1->m_nValue < pHead2->m_nValue) {
		mergehead = pHead1;
		mergehead->m_pNext = Merge_recursive(pHead1->m_pNext, pHead2);
	}
	else {
		mergehead = pHead2;
		mergehead->m_pNext = Merge_recursive(pHead1, pHead2->m_pNext);
	}
	return mergehead;
}

void printlist(ListNode *pHead) {
	if (pHead == NULL) return ;
	while (pHead) {
		cout << pHead->m_nValue << ' ';
		pHead = pHead->m_pNext;
	}
	cout << endl;
}

ListNode *init() {
	ListNode *node4 = new ListNode(7, NULL);
	ListNode *node3 = new ListNode(5, node4);
	ListNode *node2 = new ListNode(3, node3);
	ListNode *node1 = new ListNode(1, node2);
	ListNode *pHead1 = node1;
	return pHead1;
}

ListNode *init_2() {
	ListNode *node9 = new ListNode(9, NULL);
	ListNode *node8 = new ListNode(4, node9);
	ListNode *node7 = new ListNode(2, node8);
	ListNode *pHead2 = node7;
	return pHead2;
}

int main() {
	ListNode *res1 = init();
	ListNode *res2 = init_2();

	cout << "printlist res1:";
	printlist(res1);
	cout << endl;

	cout << "printlist res2:";
	printlist(res2);
	cout << endl;

	cout << "mergelist:";
	ListNode* Merge(ListNode* pHead1,ListNode* pHead2);

	ListNode* mergehead = Merge(res1, res2);
	printlist(mergehead);

	cout << "mergelist ret2:" ;
	res1 = init();
	res2 = init_2();
	ListNode* mergehead2 = Merge_2(res1, res2);
	printlist(mergehead2);

	cout << "Merge_recursive:";
	ListNode *Merge_recursive(ListNode* pHead1, ListNode *pHead2);
	res1 = init();
	res2 = init_2();
	ListNode *merge3 = Merge_recursive(res1, res2);
	printlist(merge3);
}
