
#include <iostream> 
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL) { }
	ListNode(int val) : val(val), next(NULL) { }
	ListNode(int val, ListNode* next) : val(val), next(next) { }
};

template<class T>
struct display {
	void operator()(const T& x) {
		cout << x << ' ';
	}
};

ListNode* init(){
	ListNode *node5 = new ListNode(5, NULL);
	ListNode *node4 = new ListNode(4, node5);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);
	ListNode *node0 = new ListNode(0, node1);
	
	ListNode* head = node0;
	return head;
}

ListNode *Reverse(ListNode* pHead) {
	if (pHead == NULL)
		return NULL;
	
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	
	while (pNode) {
		ListNode* pNext = pNode->next;
		if (pNext == NULL) {
			pReverseHead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead; 
}

ListNode *reverse_stack(ListNode* pHead) {
	if (pHead == NULL)
		return NULL;
	stack<ListNode *> st;
	//st.push(pHead);
	while (pHead) {
		st.push(pHead);
		pHead = pHead->next; 
	}
	
	ListNode *newhead = st.top();
	ListNode *newnode = newhead;
	
	st.pop();
	while (!st.empty()) {
		newnode->next = st.top();
		st.pop();
		newnode = newnode->next; 
	}
	newnode->next = NULL;
	return newhead;
}

vector<ListNode *> vec_init(){
	vector<ListNode *> vec;
	
	ListNode *node3 = new ListNode(3, NULL);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);
	
	ListNode *list1 = node1;
	
	ListNode *node5 = new ListNode(5, NULL);
	ListNode *node4 = new ListNode(4, node5);
	
	ListNode *list2 = node4;
	
	ListNode *node12 = new ListNode(12, NULL);
	ListNode *node11 = new ListNode(11, node12);
	ListNode *node10 = new ListNode(10, node11);
	ListNode *node9 = new ListNode(9, node10);
	ListNode *node8 = new ListNode(8, node9);
	ListNode *node7 = new ListNode(7, node8);
	
	ListNode *list3 = node7;
	
	vec.push_back(list1);
	vec.push_back(list2);
	vec.push_back(list3);
	
	for_each(vec.begin(),vec.end(),display<ListNode *>());
	cout << endl;
} 

//vector<ListNode*> 

void traval(ListNode* pHead){
	while (pHead) {
		cout << pHead->val << ' ';
		pHead = pHead->next;
	}
	cout << endl;
}

int main(){
	ListNode *res1 = init();
	//res1 = init();
	cout <<"res1 before:";
	traval(res1);
	res1 = Reverse(res1);
	cout <<"res1 after:";
	traval(res1);
	
	ListNode *res2 = init();
	cout <<"res2 before:";
	traval(res2);
	res2 = reverse_stack(res2);
	cout <<"res2 after:";
	traval(res2);
	
	vec_init();
}
