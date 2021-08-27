
/*
 * Date:2021-08-27 23:29
 * filename:00_Muban.cpp
 *
 */

#include <iostream>
using namespace std;

struct ListNode
{
	int 	m_data;
	ListNode *m_pNext;
	ListNode() : m_data(0), m_pNext(NULL) {}
	ListNode(int m_data) : m_data(m_data), m_pNext(NULL) {}
	ListNode(int m_data, ListNode *m_pNext) : m_data(m_data), m_pNext(m_pNext) {}
};

ListNode* ReverseList(ListNode* pHead)
{
	 if (pHead == NULL) 
		 return NULL;

	 ListNode *pReverHead = NULL;
	 ListNode *pNode = pHead;
	 ListNode *pPrev = NULL;

	 while (pNode != NULL) {
		 ListNode *pNext = pNode->m_pNext;
		 if (pNext == NULL) 
			 pReverHead = pNode;
		 pNode->m_pNext = pPrev;
		 pPrev = pNode;
		 pNode = pNext;
	 }
	 return pReverHead;
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
	return 0;
}

