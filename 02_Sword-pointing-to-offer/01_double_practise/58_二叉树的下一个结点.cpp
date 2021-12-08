

/*
 * Date:2021-12-08 21:13
 * filename:58_二叉树的下一个结点.cpp
 *
 */

/*
 * 题目:
 * 给定一个二叉树和其中的一个结点，如何找到中序遍历顺序的下一个结点?
 * 树中的结点除了有两个分别指向左右子树结点的指针以外，还有一个指向父结点的指针
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode*	m_pRight;
	BinaryTreeNode* m_pParent;

	BinaryTreeNode() : m_nValue(0), m_pLeft(NULL), m_pRight(NULL), m_pParent(NULL) {}
	BinaryTreeNode(int m_nValue) : m_nValue(m_nValue), m_pLeft(NULL), m_pRight(NULL), m_pParent(NULL) {}
	BinaryTreeNode(int m_nValue, BinaryTreeNode* m_pLeft, BinaryTreeNode* m_pRight, BinaryTreeNode* m_pParent)
		: m_nValue(m_nValue), m_pLeft(m_pLeft), m_pRight(m_pRight), m_pParent(m_pParent) {}
};

BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* node = new BinaryTreeNode();
	node->m_nValue = value;
	node->m_pLeft = NULL;
	node->m_pRight = NULL;
	node->m_pParent = NULL;

	return node;
}

void ConnectTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if (pParent != NULL) {
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;

		if (pLeft != NULL) 
			pLeft->m_pParent = pParent;
		if (pRight != NULL) 
			pRight->m_pParent = pParent;
	}
}

void PrintTreeNode(BinaryTreeNode* pNode) {
	if (pNode != NULL) {
		printf("value of this node is: %d\n", pNode->m_nValue);

		if (pNode->m_pLeft != NULL) 
			printf("value of its left child is: %d\n",pNode->m_pLeft->m_nValue);
		else
			printf("left child is null.\n");

		if (pNode->m_pRight != NULL) 
			printf("value of its right child is: %d\n", pNode->m_pRight->m_nValue);
		else 
			printf("right child is null.\n");
	}
	else {
		printf("this node is null.\n");
	}
	printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot) {
	PrintTreeNode(pRoot);

	if (pRoot != NULL) {
		if (pRoot->m_pLeft != NULL) 
			PrintTree(pRoot->m_pLeft);
		if (pRoot->m_pRight != NULL)
			PrintTree(pRoot->m_pRight);
	}
}

void DestroyTree(BinaryTreeNode* pRoot) {
	if (pRoot != NULL) {
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = NULL;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

void Test(char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected) {

}

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
	if (pNode == NULL) 
		return NULL;

	BinaryTreeNode* pNext = NULL;

	if (pNode->m_pRight != NULL) {
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != NULL)
			pRight = pRight->m_pLeft;
		pNext = pRight;
	}
	else if (pNode->m_pParent != NULL) {
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != NULL && pCurrent == pParent->m_pRight) {
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}

int main() {

}


