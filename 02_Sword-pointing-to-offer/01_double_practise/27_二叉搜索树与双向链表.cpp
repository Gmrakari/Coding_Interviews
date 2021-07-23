

/*
 * Date:2021-07-23 11:05
 * filename:027_二叉搜索树与双向链表.cpp
 *
 */

/*
#题意
题目描述

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。

*/
#include <iostream>
using namespace std;

struct BinaryTreeNode{
	int 			m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*
 * 在转换成排序双向链表时，原先指向左子结点的指针调整为链表中指向前一个结点的指针，
 * 原先指向右子结点的指针调整为链表中指向后一个结点的指针
 *
 * 中序遍历树中的每个结点，中序遍历算法的特点是按照从小到大的顺序遍历二叉树的每个结点
 * 当遍历到根的时候，
 * 左子树连接左子树最大的一个结点(即左子树的右结点)
 * 右子树连接右子树最小的一个结点(即右子树的左结点)
 *
 */

/*
 * 用递归实现左子树和右子树的转换
 */

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree) {
	void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);

	BinaryTreeNode *pLastNodeInList = NULL;
	ConvertNode(pRootOfTree, &pLastNodeInList);

	//pLastNodeInList 指向双向链表的尾结点,我们需要返回头结点
	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL) 
		pHeadOfList = pHeadOfList->m_pLeft;

	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
	if (pNode == NULL) return ;
	BinaryTreeNode *pCurrent = pNode;

	if (pCurrent->m_pLeft != NULL)
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
		(*pLastNodeInList)->m_pRight = pCurrent;

	*pLastNodeInList = pCurrent;

	if (pCurrent->m_pRight != NULL) 
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}
