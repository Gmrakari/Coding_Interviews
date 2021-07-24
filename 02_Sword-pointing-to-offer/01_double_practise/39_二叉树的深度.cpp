

/*
 * Date:2021-07-24 15:27
 * filename:39_二叉树的深度.cpp
 *
 */

/*
 *
#题意
题目描述

输入一棵二叉树，求该树的深度。

从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/
#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

	BinaryTreeNode() : m_nValue(0), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode(int m_nValue) : m_nValue(m_nValue), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode(int m_nValue, BinaryTreeNode* m_pLeft, BinaryTreeNode* m_pRight) : m_nValue(m_nValue), m_pLeft(m_pLeft), m_pRight(m_pRight) {}
};

int TreeDepth(BinaryTreeNode *pRoot) {
	if (pRoot == NULL) 
		return 0;

	int nLeft = TreeDepth(pRoot->m_pLeft);
	int nRight = TreeDepth(pRoot->m_pRight);

	return (nLeft > nRight) ? nLeft + 1 : nRight + 1;
}

int main() {
	BinaryTreeNode *node5 = new BinaryTreeNode(5, NULL, NULL);
	BinaryTreeNode *node7 = new BinaryTreeNode(7, NULL, NULL);
	BinaryTreeNode *node9 = new BinaryTreeNode(9, NULL, NULL);
	BinaryTreeNode *node11 = new BinaryTreeNode(11, NULL, NULL);
	BinaryTreeNode *node6 = new BinaryTreeNode(6, node5, node7);
	BinaryTreeNode *node10 = new BinaryTreeNode(10, node9, node11);
	BinaryTreeNode *root = new BinaryTreeNode(8, node6, node10);

	int ret = 0;
	ret = (TreeDepth(root));	 
	cout << ret << endl;
}
