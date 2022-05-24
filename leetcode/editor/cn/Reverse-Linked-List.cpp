/*
*
** @filename:206Reverse Linked List
** @date:2022-05-24 09:05:59
*  @author:gmrakari
*
*/

#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode *pReverseHead = NULL;
        ListNode *pNode = head;
        ListNode *pPrev = NULL;

        while (pNode) {
            ListNode *pNext = pNode->next;
            if (pNext == NULL) {
                pReverseHead = pNode;
            }
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;
    }
    ListNode* reverseList_2(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode *p = head->next;
        head->next = NULL;
        while (p) {
            ListNode *cur = p;
            p = p->next;
            cur->next = head->next;
            head->next = cur;
        }
        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

void list_test() {
    ListNode *node5 = new ListNode(5, NULL);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    ListNode *list1 = node1;

    Solution list;
    ListNode *reversehead = list.reverseList(list1);

    while (reversehead) {
        cout << reversehead->data << " ";
        reversehead = reversehead->next;
    }
    cout << endl;
}

void list_test_2() {
    ListNode *node5 = new ListNode(5, NULL);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    ListNode *list1 = new ListNode();
    list1->next = node1;

    Solution list;
    ListNode *reversehead = list.reverseList_2(list1);

    while (reversehead) {
        cout << reversehead->data << " ";
        reversehead = reversehead->next;
    }
    cout << endl;
}

int main()
{
    list_test();
    list_test_2();
}