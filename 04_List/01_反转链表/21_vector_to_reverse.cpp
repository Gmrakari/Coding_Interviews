
/*
 * Date:2021-08-27 23:29
 * filename:00_Muban.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode
{
	int 	m_data;
	ListNode *m_pNext;
	ListNode() : m_data(0), m_pNext(NULL) {}
	ListNode(int m_data) : m_data(m_data), m_pNext(NULL) {}
	ListNode(int m_data, ListNode *m_pNext) : m_data(m_data), m_pNext(m_pNext) {}
};

vector<int> ReverseList(ListNode* pHead)
{
	if (pHead == NULL)
		return vector<int>();

	vector<int> ret;

	ListNode *pNode = pHead;
	while (pNode) {
		ret.push_back(pNode->m_data);
		pNode = pNode->m_pNext;
	}
	
	reverse(ret.rbegin(),ret.rend());
	return ret;
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
	vector<int> ret = ReverseList(res1);
	vector<int>::iterator ite = ret.begin();
	while (ite != ret.end()) {
		cout << *ite << " ";
		++ite;
	}
	return 0;
}

