

/*
 * Date:2021-07-22 09:49
 * filename:19_二叉树的镜像.cpp
 *
 */

/*
 * 题目
 * 完成一个函数，输入一个二叉树，该函数输出它的镜像
 */

#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode() : m_nValue(0), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode(int m_nValue) : m_nValue(m_nValue), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode(int m_nValue, BinaryTreeNode *m_pLeft, BinaryTreeNode* m_pRight) : m_nValue(m_nValue), m_pLeft(m_pLeft), m_pRight(m_pRight) {}

};

void inorder_print(BinaryTreeNode *pRoot) {
	if (pRoot == NULL) return ;
	if (pRoot != NULL) {
		cout << pRoot->m_nValue << ' ';
		inorder_print(pRoot->m_pLeft);
		inorder_print(pRoot->m_pRight);
	}
}

void floor_print(BinaryTreeNode *pRoot) {
	if (pRoot == NULL) return ;
	queue<BinaryTreeNode *> m_queue;
	m_queue.push(pRoot);
	while (!m_queue.empty()) {
		cout << m_queue.front()->m_nValue << ' ';
		if (m_queue.front()->m_pLeft) {
			m_queue.push(m_queue.front()->m_pLeft);
		}
		if (m_queue.front()->m_pRight) {
			m_queue.push(m_queue.front()->m_pRight);
		}
		m_queue.pop();
	}
	cout << endl;
}

void MirrorRecursively(BinaryTreeNode* pNode) {
	if (pNode == NULL) return ;
	if (pNode->m_pLeft == NULL && pNode->m_pRight == NULL) return ;

	//swap left & right
	BinaryTreeNode *pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	if (pNode->m_pLeft) 
		MirrorRecursively(pNode->m_pLeft);
	if (pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}

int main() {
	BinaryTreeNode *node5 = new BinaryTreeNode(5, NULL, NULL);
	BinaryTreeNode *node7 = new BinaryTreeNode(7, NULL, NULL);
	BinaryTreeNode *node9 = new BinaryTreeNode(9, NULL, NULL);
	BinaryTreeNode *node11 = new BinaryTreeNode(11, NULL, NULL);
	BinaryTreeNode *node10 = new BinaryTreeNode(10, node9, node11);
	BinaryTreeNode *node6 = new BinaryTreeNode(6, node5,node7 );
	BinaryTreeNode *root = new BinaryTreeNode(8, node6, node10);

	BinaryTreeNode *pRoot = root;

	/*
		 inorder_print(pRoot);
		 cout << endl;
		 */
	void floor_print(BinaryTreeNode *pRoot);
	cout << "original:";
	floor_print(pRoot);
	cout << endl;
	void MirrorRecursively(BinaryTreeNode* pNode);
	MirrorRecursively(pRoot);
	
	cout << "mirror: ";
	floor_print(pRoot);
}
