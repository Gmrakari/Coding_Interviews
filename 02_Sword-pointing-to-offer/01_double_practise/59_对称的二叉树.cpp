

/*
 * Date:2021-12-09 09:24
 * filename:59_对称的二叉树.cpp
 *
 */


/*
题目描述

请实现一个函数，用来判断一颗二叉树是不是对称的。

注意，如果一个二叉树和它的的镜像是一样的，那么它是对称的

*/

#include <bits/stdc++.h>

struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

	BinaryTreeNode() : m_nValue(0), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode(int m_nValue) : m_nValue(m_nValue), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode(int m_nValue, BinaryTreeNode* m_pLeft, BinaryTreeNode* m_pRight) 
		: m_nValue(m_nValue), m_pLeft(m_pLeft), m_pRight(m_pRight) {}
};

BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* node = new BinaryTreeNode();
	node->m_nValue = value;
	node->m_pLeft = NULL;
	node->m_pRight = NULL;

	return node;
}

void ConnectNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if (pRoot == NULL) 
		return ;

	pRoot->m_pLeft = pLeft;
	pRoot->m_pRight = pRight;
}

void DestroyTree(BinaryTreeNode* pRoot) {
	if (pRoot != NULL) {
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = NULL;

		delete(pLeft);
		delete(pRight);
	}
}

bool isSymmetrical(BinaryTreeNode* pRoot) {
	bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
	return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
	if(pRoot1 == NULL && pRoot2 == NULL)
		return true;

	if (pRoot1 == NULL || pRoot2 == NULL) 
		return false;

	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
		&& isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

void Test(char* TestName, BinaryTreeNode* pRoot) {
	if (TestName != NULL) {
		printf("%s begin:", TestName);

		bool flag = isSymmetrical(pRoot);
		if (flag == true) {
			printf("isSymmetrical");
		}
		else {
			printf("isNotSymmetrical");
		}
	}
	printf("\n");
}

void Test_1() {
	char str[] = "Test1";

	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(5);

	ConnectNode(pNode1, pNode2, pNode3);
	ConnectNode(pNode2, pNode4, pNode5);
	ConnectNode(pNode3, pNode6, pNode7);
	
	Test(str, pNode1);
	DestroyTree(pNode1);
}

void Test_2() {
	char test[] = "Test2";
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(5);

	ConnectNode(pNode1, pNode2, pNode3);
	ConnectNode(pNode2, pNode4, pNode5);
	ConnectNode(pNode3, pNode6, pNode7);

	Test(test, pNode1);
	DestroyTree(pNode1);
}

void Test_3() {
	char test[] = "Test3";
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(7);

	ConnectNode(pNode1, pNode2, pNode3);
	ConnectNode(pNode2, pNode4, pNode5);
	ConnectNode(pNode3, pNode6, NULL);

	Test(test, pNode1);
	DestroyTree(pNode1);
}

int main() {
	Test_1();
	Test_2();
	Test_3();
}
