#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>

/*
 * Date:2021-04-06 13:40
 * Project:Reverse LinkList
 * Copy by : a_xiu
 */


using namespace std;

struct node
{
	int data;
	struct node* next;
	node(int _data):data(_data),next(nullptr)
	{}
};

struct node* init()
{
	node* head = new node(1);
	node* node1 = new node(2);
	node* node2 = new node(3);
	node* node3 = new node(4);
	node* node4 = new node(5);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;

	return head;
}

struct node* reverse(node* head)
{
	struct node* pre = new node(-1);
	struct node* temp = new node(-1);

	pre = head;
	temp = head->next;
	pre->next = nullptr;

	struct node* cur = new node(-1);
	cur = temp;

	while( cur != nullptr)
	{
		temp = cur;
		cur = cur->next;
		temp->next = pre;
		pre = temp;
	}
	return pre;
}

ListNode* ReverseList(ListNode* pHead)
{
	//head insert
	if(pHead == nullptr || pHead->next == nullptr)
		return pHead;
	ListNode dummyNode = ListNode(0);
	ListNode* pre = &(dummyNode);
	pre->next = pHead;
	ListNode* cur = pHead->next;
	pHead->next = nullptr;

	//pre = cur;
	ListNode* temp = nullptr;
	while(cur != nullptr)
	{
		temp = cur;
		cur = cur->next;
		temp->next = pre->next;
		pre->next = temp;
	}
	return dummyNode.next;
}

int main()
{
	auto head = init();
	head = reverse(head);

	while( head != nullptr )
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}
