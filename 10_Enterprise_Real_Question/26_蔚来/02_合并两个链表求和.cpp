

/*
 * Date:2022-02-26 18:07
 * filename:02_合并两个链表求和.cpp
 *
 */

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

namespace gmrakari {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};
	class Solution {
		public:
			ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
				if (l1 == NULL || l2 == NULL)
					return NULL;
				int sum1 = 0, sum2 = 0;
				int sum;
				int lenl1 = GetListLength(l1);
				int lenl2 = GetListLength(l2);
				int i = 0, j = 0;

				
				while (l1) {
					sum1 += l1->val * pow(10, (lenl1 - (lenl1 - i)));
					l1 = l1->next;
					i++;
				}
				while (l2) {
					sum2 += l2->val * pow(10, (lenl2 - (lenl2 - j)));
					l2 = l2->next;
					j++;
				}
				ListNode *list = new ListNode();
				list->next = NULL;

				sum = sum1 + sum2;

				while (sum != 0) {
					list = addNode(list, sum % 10);
					sum /= 10;
				}
				return list;
			}
			int GetListLength(ListNode *list) {
				int nLength = 0;
				while (list) {
					++nLength;
					list = list->next;
				}
				return nLength;
			}
			ListNode* addNode(ListNode* list, int value) {
				ListNode *newNode = new ListNode();
				newNode->next = NULL;
				newNode->val = value;

				ListNode *p = new ListNode();
				p = list;
				if (list == NULL) {
					list = newNode;
				}
				else {
					while (p->next != NULL)
						p = p->next;
					p->next = newNode;
				}
				return list;
			}
	};
}

int main() {
	gmrakari::Solution test;
	gmrakari::ListNode *p3 = new gmrakari::ListNode(2, nullptr);
	gmrakari::ListNode *p2 = new gmrakari::ListNode(4, p3);
	gmrakari::ListNode *p1 = new gmrakari::ListNode(3, p2);

	gmrakari::ListNode *k3 = new gmrakari::ListNode(5, nullptr);
	gmrakari::ListNode *k2 = new gmrakari::ListNode(6, k3);
	gmrakari::ListNode *k1 = new gmrakari::ListNode(4, k2);

	gmrakari::ListNode *l1 = p1;
	gmrakari::ListNode *l2 = k1;
	gmrakari::ListNode *list;
	list = test.addTwoNumbers(l1, l2);

	while (list) {
		cout << list->val << " ";
		list = list->next;
	}
	cout << endl;
}



