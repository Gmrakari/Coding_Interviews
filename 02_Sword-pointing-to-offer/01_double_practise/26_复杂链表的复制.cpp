

/*
 * Date:2021-07-23 09:13
 * filename:26_复杂链表的复制.cpp
 *
 */

/*
题意
题目描述

请实现函数ComplexListNode* Clone(ComplexListNode* pHead),复制一个复杂链表。
在复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中的任意结点或者NULL。

*/

#include <iostream>
#include <cstdio>
using namespace std;

struct ComplexListNode
{
	int				 m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
	ComplexListNode() : m_nValue(0), m_pNext(NULL), m_pSibling(NULL) {}
	ComplexListNode(int m_nValue) : m_nValue(m_nValue), m_pNext(NULL), m_pSibling(NULL) {}
	ComplexListNode(int m_nValue, ComplexListNode* m_pNext, ComplexListNode* m_pSibling) : m_nValue(m_nValue), m_pNext(m_pNext), m_pSibling(m_pSibling) {}
};

//方法一:
//第一步复制原始链表上的每个结点N创建N',然后把这些创建出来的结点用m_pNext链接起来。
//同时我们把<N, N'>的配对信息放到一个哈系表中
//第二步还是设置复制链表上每个结点的m_pSibling
//如果在原始链表中结点N的m_pSibling的指向结点S,那么在复制链表中，对应的N'应该指向S'
//由于有了哈系表，我们可以用O(1)的时间根据S找到S'

//方法二:
//第一步仍然是根据原始链表的每个结点N创建对应的N'
//我们把N'链接在N的后面


//1.复制原始链表
void CloneNodes(ComplexListNode* pHead) {
	if (pHead == NULL) return ;
	ComplexListNode* pNode = pHead;
	while (pNode) {
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}

//2.设置复制出来的结点的m_pSibling
//假设原始链表上的N的m_pSibling指向结点S,那么其对应复制出来的N'是N的m_pNext指向的结点
//同样S'也是S的m_pNext指向的结点

void ConnectSiblingNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	while (pNode != NULL){
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != NULL) {
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}

//3.把这个长链表拆分成两个链表:把奇数位置的结点用m_pNext链接起来就是原始链表，
//把偶数位置的结点用m_pNext链接起来就是复制出来的链表
ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;

	if (pNode) {
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	while (pNode != NULL) {
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pClonedHead;
}

ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

ComplexListNode* CreateNode(int nValue)
{
    ComplexListNode* pNode = new ComplexListNode();

    pNode->m_nValue = nValue;
    pNode->m_pNext = NULL;
    pNode->m_pSibling = NULL;

    return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != NULL)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);

        if(pNode->m_pSibling != NULL)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->m_pNext;
    }
}

void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

int main()
{
    Test1();
    return 0;
}
