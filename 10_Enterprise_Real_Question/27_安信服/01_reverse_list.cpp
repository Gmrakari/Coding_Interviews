

/*
 * Date:2022-03-21 23:16
 * filename:01_reverse_list.cpp
 *
 */

#include <iostream>

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL){}
	ListNode(int val, ListNode *next): val(val), next(next){}
};

class Solution {
public:
	ListNode* reverse(ListNode* phead) {
		if (phead == NULL) return NULL;
		//保存cur的下一个节点
		ListNode* temp;
		ListNode* cur = phead;
		ListNode* prev = NULL;

		while (cur) {
			temp = cur->next; //保存一下cur的下一个节点，因为接下来要改变cur->next;
			cur->next = prev;//翻转操作
			prev = cur;//更新prev和cur
			cur = temp;
		}
		return prev;
	}

	ListNode* m_reverse(ListNode *prev, ListNode *cur) {
		if (cur == NULL) 
			return prev;
		ListNode *tmp = cur->next;
		cur->next = prev;
		return m_reverse(cur, tmp);
	}

	ListNode* reverselist(ListNode* phead) {
		return m_reverse(NULL, phead);
	}

	ListNode* recursion_reverselist(ListNode* phead) {
		if (phead == NULL)
			return NULL;

		if (phead->next == NULL)
			return phead;

		//递归调用，翻转第二个节点开始往后的结点
		ListNode *tmp = recursion_reverselist(phead->next);
		//翻转头节点与第二个节点的指向
		phead->next->next = phead;
		phead->next = NULL;

		return tmp;
	}

	void traval(ListNode* phead) {
		if (phead == NULL) return ;
		while (phead) {
			std::cout << phead->val << " ";
			phead = phead->next;
		}
		std::cout << std::endl;
	}
};

ListNode* init() {
	ListNode *node4 = new ListNode(4, NULL);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);

	ListNode *phead = node1;
	return phead;
}

void test_01() {
	ListNode* phead =  init();
	Solution test;
	std::cout << "before:" << std::endl;
	test.traval(phead);

	phead = test.reverse(phead);

	std::cout << "after:" << std::endl;
	test.traval(phead);
	std::cout << std::endl;
}

void test_02() {
	ListNode* phead = init();
	Solution test;
	std::cout << "way 2 :" << std::endl;
	std::cout << "before:" << std::endl;
	test.traval(phead);

	phead = test.reverselist(phead);
	std::cout << "after:" << std::endl;
	test.traval(phead);
	std::cout << std::endl;
}

void test_03() {
	ListNode* phead = init();
	Solution test;

	std::cout << "Way 3:" << std::endl;
	std::cout << "before:" << std::endl;
	test.traval(phead);

	phead = test.recursion_reverselist(phead);
	std::cout << "after:" << std::endl;
	test.traval(phead);
}

int main() {
	test_01();
	test_02();
	test_03();
}
