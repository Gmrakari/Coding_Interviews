

/*
 * Date:2021-10-21 08:27
 * filename:234_palindrome-linked-list.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x),next(next) {}
};

ListNode *init() {
	ListNode *node6 = new ListNode(1, NULL);
	ListNode *node5 = new ListNode(2, node6);
	ListNode *node4 = new ListNode(3, node5);
	ListNode *node3 = new ListNode(3, node4);
	ListNode *node2 = new ListNode(2, node3);
	ListNode *node1 = new ListNode(1, node2);

	ListNode *head = node1;
	return head;
}

void print(ListNode *head) {
	if (head == NULL)
		return ;
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}

void traval_node(ListNode *head) {
	if (head == NULL) 
		return ;
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
}

namespace acmer {
	class Solution {
		public:
			bool isPalindrome(ListNode *head) {
				if (head == NULL)
					return false;
				ListNode *slow = head;
				ListNode *fast = head;
				ListNode *pre = head;
				while (fast && fast->next) {
					pre = slow;
					slow = slow->next;
					fast = fast->next->next;
				}
				pre->next = NULL;
				ListNode *p1 = head;
				ListNode *p2 = reverselist(slow);

				while (p1) {
					if (p1->val != p2->val) 
						return false;
					p1 = p1->next;
					p2 = p2->next;
				}
				return true;
			}

			ListNode *reverselist(ListNode *head) {
				if (head == NULL) 
					return NULL;
				ListNode *prev = NULL;
				ListNode *pNode = head;
				ListNode *pReverse = NULL;
				while (pNode) {
					ListNode *pNext = pNode->next;
					if (pNext == NULL) {
						pReverse = pNode;
					}
					pNode->next = prev;
					prev = pNode;
					pNode = pNext;
				}
				return pReverse;
			}
	};
}

namespace carl {
	class Solution {
		public:
			bool isPalindrome(ListNode *head) {
				if (head == NULL)
					return false;

				vector<int> ret;
				while (head) {
					ret.push_back(head->val);
					head = head->next;
				}

				for (int i = 0, j = ret.size() - 1;i < j;i++,j--) {
					if (ret[i] != ret[j])
						return false;
				}
				return true;
			}
			bool isPalindrome_optimize(ListNode *head) {
				if (head == NULL)
					return false;

				ListNode *cur = head;
				int length = 0;
				while (cur) {
					++length;
					cur = cur->next;
				}
				vector<int> vec(length, 0);
				cur = head;
				int index = 0;
				while (cur) {
					vec[index++] = cur->val;
					cur = cur->next;
				}
				for (int i = 0, j = vec.size() - 1;i < j;i++, j--) {
					if (vec[i] != vec[j]) return false;
				}
				return true;
			}
	};
}

void test_acmer() {
	acmer::Solution test;
	ListNode *head = init();
	cout << "isPalindrome:" << test.isPalindrome(head) << endl;

}

void test_carl() {
	carl::Solution test;
	ListNode *head = init();
	cout << "isPalindrome:" << test.isPalindrome(head) << endl;

	head = init();
	cout << "isPalindrome_optimize:" << test.isPalindrome_optimize(head) << endl;
}

int main() {
	cout << "test acmer:" << endl;
	test_acmer();

	/*
	cout << "test carl:" << endl;
	test_carl();
	*/
}
