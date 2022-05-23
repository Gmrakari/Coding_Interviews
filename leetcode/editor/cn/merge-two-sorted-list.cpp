#include "include/headers.h"

class Solution {
public:
    ListNode *MergeList(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;

        ListNode *MergeHead;
        if (l1->data < l2->data) {
           MergeHead = l1;
           MergeHead->next = MergeList(l1->next, l2);
        } else {
           MergeHead = l2;
           MergeHead->next = MergeList(l1, l2->next);
        }
        return MergeHead;
    }
    ListNode *MergeList_nor(ListNode *l1, ListNode *l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;

        ListNode *phead1 = l1;
        ListNode *phead2 = l2;

        ListNode *pNode = new ListNode(0, NULL);
        ListNode *MergeHead = pNode;
        while (phead1 && phead2) {
            if (phead1->data < phead2->data) {
                MergeHead->next = phead1;
                MergeHead = MergeHead->next;
                phead1 = phead1->next;
            } else {
                MergeHead->next = phead2;
                MergeHead = MergeHead->next;
                phead2 = phead2->next;
            }
        }
        MergeHead->next = phead1 ? phead1 : phead2;
        return pNode->next;
    }
};

void list_test() {
    ListNode *node5 = new ListNode(5, NULL);
    ListNode *node3 = new ListNode(3, node5);
    ListNode *node1 = new ListNode(1, node3);
    ListNode *list1 = node1;

    ListNode *node9 = new ListNode(9, NULL);
    ListNode *node7= new ListNode(7, node9);
    ListNode *node4 = new ListNode(4, node7);
    ListNode *node2 = new ListNode(2, node4);
    ListNode *list2 = node2;

    Solution list;
    ListNode *merhead = list.MergeList(list1, list2);

    while (merhead) {
        cout << merhead->data << " ";
        merhead = merhead->next;
    }
    cout << endl;
}

void list_test_2() {
    ListNode *node5 = new ListNode(5, NULL);
    ListNode *node3 = new ListNode(3, node5);
    ListNode *node1 = new ListNode(1, node3);
    ListNode *list1 = node1;

    ListNode *node9 = new ListNode(9, NULL);
    ListNode *node7= new ListNode(7, node9);
    ListNode *node4 = new ListNode(4, node7);
    ListNode *node2 = new ListNode(2, node4);
    ListNode *list2 = node2;

    Solution list;
    ListNode *merhead = list.MergeList_nor(list1, list2);

    while (merhead) {
        cout << merhead->data << " ";
        merhead = merhead->next;
    }
    cout << endl;
}

int main() {
    //list_test();
    list_test_2();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
