

/*
 * Date:2021-06-22 21:40
 * filename:002_add-two-numbers.cpp
 *
 */

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
    int getlistlength(ListNode *head) {
        if (head == nullptr) return 0;
        int nLength = 0;
        while (head) {
            ++nLength;
            head = head->next;
        }
        return nLength;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr ) return nullptr;
        int nLengthLong = getlistlength(l1);
        int nLengthShort = getlistlength(l2);

        int nLengthDiff = nLengthLong - nLengthShort;

        ListNode *p;
        ListNode *q;
        if (nLengthLong > nLengthShort) {
            for (int i = 1; i <= nLengthDiff;i++) {
                q->next = new ListNode(0);
                q = q->next;
            }
        } else {
            for (int i = 1; i <= nLengthShort - nLengthLong;i++) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }

        p = l1;
        q = l2;

        bool count = false;
        ListNode *newhead = new ListNode(-1);
        ListNode *cur = newhead;
        int i = 0;
        while (p && q) {
            i = count + p->val + q->val;
            cur->next = new ListNode(i % 10);
            count = i >= 10 ? true : false;
            cur = cur->next;
            p = p->next;
            q = q->next;
        }
        if (count) {
            cur->next = new ListNode(1);
            cur = cur->next;
        }
        return newhead->next;
    }
};

