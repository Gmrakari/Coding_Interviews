/*
 * Date:2021-04-22 06:50
 * file:ListNode *tmp && stack<ListNode *> st;
 */

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
	int m_val;
	ListNode *m_next;

	ListNode() : m_val(0),m_next(nullptr) {}
	ListNode(int x) : m_val(x),m_next(nullptr) {}
	ListNode(int x,ListNode *m_next) : m_val(x),m_next(m_next) {}
};

ListNode* Reverse(ListNode *pHead)
{
	if(pHead == nullptr)
		return nullptr;

	ListNode *pre = nullptr;
	ListNode *cur = pHead;

	while(cur != nullptr)
	{
		ListNode *tmp = cur->m_next;
		cur->m_next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}

ListNode *stack_reverse(ListNode *head)
{
	if(head == nullptr)
		return nullptr;

	stack<ListNode *> st;
	while(head)
	{
		st.push(head);
		head = head->m_next;
	}
	ListNode *newhead = st.top();
	ListNode *newNode = newhead;
	st.pop();
	
	while(!st.empty())
	{
		newNode->m_next = st.top();
		st.pop();
		newNode = newNode->m_next;
	}
	newNode->m_next = nullptr;

	return newhead;
}

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);

	head->m_next = node1;
	node1->m_next = node2;
	node2->m_next = node3;
	node3->m_next = node4;
	node4->m_next = nullptr;

	/*
	ListNode *res;
	res = Reverse(head);
	
	while(res)
	{
		cout << res->m_val << " ";
		res = res->m_next;
	}
	cout << endl;

	ListNode *res2 = Reverse(res);

	while(res2)
	{
		cout << res2->m_val << " ";
		res2 = res2->m_next;
	}
	cout << endl;
*/


	ListNode *stack_reverse(ListNode *head);

	ListNode *tmp = stack_reverse(head);
	while(tmp)
	{
		cout << tmp->m_val << " ";
		tmp = tmp->m_next;
	}
	cout << endl;
}
