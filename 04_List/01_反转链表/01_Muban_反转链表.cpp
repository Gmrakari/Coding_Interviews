#include <iostream>
using namespace std;

struct ListNode
{
	int 	m_nKey;
	ListNode *m_pNext;
};

ListNode* ReverseList(ListNode* pHead)
{

}


ListNode* ReverseList_2(ListNode* pHead)
{

}


int main(int argc,const char* argv[])
{
	ListNode node[6];
	node[0].m_nKey = 0;
	node[0].m_pNext = &node[1];

	node[1].m_nKey = 1;
	node[1].m_pNext = &node[2];

	node[2].m_nKey = 2;
	node[2].m_pNext = &node[3];

	node[3].m_nKey = 3;
	node[3].m_pNext = &node[4];

	node[4].m_nKey = 4;
	node[4].m_pNext = &node[5];

	node[5].m_nKey = 5;
	node[5].m_pNext = NULL;

	ListNode* ReverseList(ListNode* pHead);
	//ListNode* ReverseList_2(ListNode* pHead);


	ListNode *res1,*res2;
//	res1 = ReverseList(node);
	res2 = ReverseList_2(node);

	/*
	while(res1 != NULL)
	{
		cout << res1->m_nKey << " ";
		res1 = res1->m_pNext;
	}
	cout << endl;
	*/


	while(res2 != NULL)
	{
		cout << res2->m_nKey << " ";
		res2 = res2->m_pNext;
	}
	cout << endl;
	
	return 0;
}

