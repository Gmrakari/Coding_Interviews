
/*
 * Date:2021-09-03 10:20
 * filename:15.cpp
 *
 */

#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int 	m_data;
	ListNode *m_pNext;
	ListNode() : m_data(0), m_pNext(NULL) {}
	ListNode(int m_data) : m_data(m_data), m_pNext(NULL) {}
	ListNode(int m_data, ListNode *m_pNext) : m_data(m_data), m_pNext(m_pNext) {}
};

/*
template <class T>
struct display {
	void operator() (const T& x) {
		cout << x << ' ';
	}
};

*/

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL) 
		return NULL;

	ListNode *pPrev = NULL;
	ListNode *pReverseHead = NULL;
	ListNode *pNode = pHead;

	while (pNode) {
		ListNode *pNext = pNode->m_pNext;
		if (pNext == NULL) 
			pReverseHead = pNode;

		//pPrev->m_pNext = pNode;
		pNode->m_pNext = pPrev;
		//pNode = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}

ListNode* ReverseList_Stack(ListNode *pHead) {
	if (pHead == NULL) 
		return NULL;

	stack<ListNode *> my_sta;
	while (pHead) {
		my_sta.push(pHead);
		pHead = pHead->m_pNext;
	}

	ListNode *newHead = my_sta.top();
	ListNode *newNode = newHead;

	my_sta.pop();

	while (!my_sta.empty()) {
		newNode->m_pNext = my_sta.top();
		my_sta.pop();
		newNode = newNode->m_pNext;
	}
	newNode->m_pNext = NULL;
	return newHead;
}

ListNode* init() {
	ListNode *node5 = new ListNode(5, NULL);
	ListNode *node4 = new ListNode(4, node5);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);
	ListNode *pHead = node1;
	return pHead;
}

void Traversal(ListNode *head) {
	while (head) {
		cout << head->m_data << ' ';
		head = head->m_pNext;
	}
	cout << endl;
}

int main(int argc,const char* argv[])
{

	ListNode *res1 = init();
	res1 = ReverseList(res1);
	while(res1 != NULL)
	{
		cout << res1->m_data << " ";
		res1 = res1->m_pNext;
	}
	cout << endl;

	ListNode *res2 = init();
	res2 = ReverseList_Stack(res2);

	Traversal(res2);

	return 0;
}

