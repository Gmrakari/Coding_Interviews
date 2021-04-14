

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
        if(head == nullptr)
            return nullptr;
        ListNode *prev = nullptr;			//前指针结点
        ListNode *cur = head;				//当前指针结点

      	//每次循环，都将当前结点指向它前面的结点，然后当前结点和前结点后移
        while(cur != nullptr)
        {
            ListNode *nextTmp = cur->next; 	//临时结点，暂存当前结点的下一个结点，用于后移
            cur->next = prev;				//将当前结点指向它前面的结点
            prev = cur;						//前指针后移
            cur = nextTmp;					//当前指针后移
        }
        return prev;
    }
}; 

/**
 * 栈的做法
 *
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        stack<ListNode *> s;

        //将当前链表放到栈中
        while(head != nullptr)
        {
            s.push(head);
            head = head->next;
        }

        ListNode *newhead = s.top();
        ListNode *pNode = newhead;
        s.pop();

        //栈不为空的时候
        while(!s.empty())
        {
            pNode->next = s.top();
            s.pop();
            pNode = pNode->next;
        }
        pNode->next = nullptr;
        return newhead;
    }
}; 

