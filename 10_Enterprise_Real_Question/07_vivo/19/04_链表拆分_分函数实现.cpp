//
// Created by gmrakari on 7/28/21.
//


/*
	 【题目描述】
	 设 C={a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的 hc 单链表存放，设计一个算法，
	 将其拆分为两个线性表，使得奇数位保持正序，偶数位转化为逆序。
	 即：A={a1,a2,...,an}，B={bn,...,b2,b1}

	 思路:
	 拆分 奇偶链表 
	 翻转偶数链表
	 合并 奇链表 和 翻转后的偶数链表

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int m_data;
    ListNode *m_pNext;
    ListNode() : m_data(0),m_pNext() {  }
    ListNode(int m_data) : m_data(m_data), m_pNext(NULL) {  }
    ListNode(int m_data, ListNode *m_pNext) : m_data(m_data), m_pNext(m_pNext) {  }
};

ListNode *reverse(ListNode *pHead) {
    if (pHead == NULL)
        return NULL;

    ListNode *pNode = pHead;
    ListNode *ReverseHead = NULL;
    ListNode *pPrev = NULL;

    while (pNode) {
        ListNode *node = pNode->m_pNext;
        if (pNode->m_pNext == NULL) {
            ReverseHead = pNode;
        }
        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = node;
    }
    return ReverseHead;
}

ListNode *merge_list(ListNode *phead1, ListNode *phead2) {
    if(phead1 == NULL && phead2 == NULL)
        return NULL;

    if (phead1 == NULL) return phead2;
    else if (phead2 == NULL) return phead1;

    ListNode* p_mergeListhead = NULL;
    if (phead1->m_data & 1) {
        p_mergeListhead = phead1;
        p_mergeListhead->m_pNext = merge_list(phead1->m_pNext, phead2);
    }
    else {
        p_mergeListhead = phead2;
        p_mergeListhead->m_pNext = merge_list(phead1, phead2->m_pNext);
    }
    return p_mergeListhead;
}

ListNode *partition(ListNode *phead) {
    if (phead == NULL)
        return NULL;
    ListNode* evenhead = phead->m_pNext;
    ListNode* odd = phead;
    ListNode* even = evenhead;

    while (even != NULL && even->m_pNext != NULL) {
            odd->m_pNext = even->m_pNext;
            odd = odd->m_pNext;
            even->m_pNext = odd->m_pNext;
            even = even->m_pNext;
    }
    odd->m_pNext = NULL;
    ListNode *re_evenhead = reverse(evenhead);

    ListNode *addhead = merge_list(phead, re_evenhead);
    return addhead;
}

int main() {
    ListNode *node5 = new ListNode(5, NULL);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);
    ListNode *head = node1;

    ListNode *node7 = new ListNode(7, NULL);
    ListNode *node6 = new ListNode(6,node7);
    ListNode *head2 = node6;

    ListNode *partition(ListNode *phead);
    head = partition(head);

    while (head) {
        cout << head->m_data << ' ';
        head = head->m_pNext;
    }
    cout << endl;
    return 0;
}
