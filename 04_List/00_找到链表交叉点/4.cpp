

/*
 * Date:2021-05-31 11:47
 * filename:4.cpp
 *
 */
#include <iostream>
#include <new>
using namespace std;

class ListNode {
public:
	int val;
	ListNode* m_Next;
	ListNode() : val(0),m_Next(nullptr) {}
	ListNode(int x) : val(x),m_Next(nullptr) {}
	ListNode(int x,ListNode *m_Next) : val(x),m_Next(m_Next) {}
};

unsigned int GetListLength(ListNode *phead) {
	if (phead == nullptr) return 0;
	int nLength = 0;
	while(phead) {
		++nLength;
		phead = phead->m_Next;
	}
	return nLength;
}

ListNode* findFirstCommonNode(ListNode *pHead1,ListNode *pHead2) {
	// if(pHead1 || pHead2) return nullptr;
	// 这两句的区别还是有的
	// 留意一下
	if(pHead1 == nullptr || pHead2 == nullptr) return nullptr;
	ListNode *pListLong = pHead1;
	ListNode *pListShort = pHead2;

	int nLength1 = GetListLength(pListLong);
	int nLength2 = GetListLength(pListShort);
	int DiffLen = nLength1 - nLength2;

	if (nLength1 < nLength2) {
		pListLong = pHead2;
		pListShort = pHead1;
		DiffLen = nLength2 - nLength1;
	}

	for (int i = 0; i < DiffLen;i++) {
			pListLong = pListLong->m_Next;
	}

	while (pListShort != nullptr &&
				 pListLong != nullptr &&
				 pListShort != pListLong) {
		pListLong = pListLong->m_Next;
		pListShort = pListShort->m_Next;
	}
	ListNode *common = pListLong;
	return common;
} 

int main() {
	ListNode *common1 = new ListNode(8,nullptr);
	ListNode *common2 = new ListNode(7,common1);

	ListNode *node4 = new ListNode(4,common2);
	ListNode *node3 = new ListNode(3,node4);
	ListNode *node2 = new ListNode(2,node3);
	ListNode *node1 = new ListNode(1,node2);

	ListNode *node7 = new ListNode(6,common2);
	ListNode *node6 = new ListNode(5,node7);

	ListNode *left = node1;

	ListNode *right = node6;

	ListNode *com = findFirstCommonNode(left,right);

	cout << "left:";
	while(left) {
		cout << left->val << ' ';
		left = left->m_Next;
	}
	cout << endl;

	cout << "right:";
	while (right) {
		cout << right->val << ' ';
		right = right->m_Next;
	}
	cout << endl;

	cout << "common:";
	while (common2) {
		cout << common2->val << ' ';
		common2 = common2->m_Next;
	}
	cout << endl;

	cout << "findFirstCommonNode:";
	while(com) {
		cout << com->val << " ";
		com = com->m_Next;
	}

	cout << endl;




}
