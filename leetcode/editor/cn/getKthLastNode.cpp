/**
 * 
 * @filename:getKthLastNode.cpp
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/5/25 18:58
 * 
 */

#include "include/headers.h"

class List {
public:
    ListNode* findListkth(ListNode *list, int k) {
        int nListLength = getListLength(list);
        if (list == NULL || k > nListLength) return 0;

        ListNode *node = list;
        for (int i = 0; i < nListLength - k; i++) {
            node = node->next;
        }
        return node;
    }

    int getListLength(ListNode *list) {
        if (list == NULL) return 0;
        int nLength = 0;
        while (list) {
            nLength++;
            list = list->next;
        }
        return nLength;
    }
};

void test() {
    ListNode *node5 = new ListNode(5, NULL);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    ListNode *head = node1;

    List m_list;
    int k = 2;
    ListNode *node;
    node = m_list.findListkth(head, k);
    cout << "node:";
    cout << node->data << endl;
}

int main() {
    test();
}