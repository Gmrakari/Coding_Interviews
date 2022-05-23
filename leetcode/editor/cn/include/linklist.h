/**
 * 
 * @filename:linklist.h
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/5/23 14:28
 * 
 */

#ifndef CODING_INTERVIEWS_LINKLIST_H
#define CODING_INTERVIEWS_LINKLIST_H

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(NULL) {}
    ListNode(int data) : data(data), next(NULL) {}
    ListNode(int data, ListNode *next) : data(data), next(next) {}
};

#endif //CODING_INTERVIEWS_LINKLIST_H
