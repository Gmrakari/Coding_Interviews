

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

BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
	if (pNode == NULL) 
		return NULL;

	BinaryTreeNode* pNext = NULL;

	/*
	 * 如果一个节点有右子树，那么它的下一个结点是它右子树的最左结点
	 */
	if (pNode->m_pRight != NULL) {
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != NULL)
			pRight = pRight->m_pLeft;
		pNext = pRight;
	}
	/*
	 * 没有右子树，如果结点是它的父结点的左子节点，那么它的下一个结点就是它的父结点
	 */
	else if (pNode->m_pParent != NULL) {
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;

		/*
		 * 如果一个结点既没有右子树，而且它还是它父结点的右子结点
		 * 可以沿着指向父结点的指针一直向上遍历，直到找到一个是它父结点的左子结点的结点
		 */
		while (pParent != NULL && pCurrent == pParent->m_pRight) {
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}

void Test(char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected) {
	if (testName != NULL)
		printf("%s begins:", testName);
	BinaryTreeNode* pNext = GetNext(pNode);
	if (pNext == expected)
		printf("Passed\n");
	else
		printf("Failed\n");
}

void Test1_7() {
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNode(pNode8, pNode6, pNode10);
	ConnectTreeNode(pNode6, pNode5, pNode7);
	ConnectTreeNode(pNode10, pNode9, pNode11);
	ConnectTreeNode(pNode7, pNode3, pNode4);

	char str[] = "Test1";
	char str2[] = "Test2";
	char str3[] = "Test3";
	char str4[] = "Test4";
	char str5[] = "Test5";
	char str6[] = "Test6";

	Test(str, pNode5, pNode6); //5->6
	Test(str2, pNode9, pNode10);//9->10
	Test(str3, pNode4, pNode8);//4->8
	Test(str4, pNode11, NULL);//11->null
	Test(str5, pNode6, pNode3);//6->3
	Test(str6, pNode8, pNode9);//8->9

	DestroyTree(pNode8);
}

int main() {
	Test1_7();
}


