

/*
 * Date:2021-07-22 13:39
 * filename:23_从上往下打印二叉树.cpp
 *
 */


#include <iostream>
#include <queue>
using namespace std;


struct BinaryTreeNode{
	int 			m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

	BinaryTreeNode() : m_nValue(0), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode(int m_nValue) : m_nValue(m_nValue), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode(int m_nValue, BinaryTreeNode* m_pLeft, BinaryTreeNode* m_pRight) : m_nValue(m_nValue), m_pLeft(m_pLeft), m_pRight(m_pRight) {}
};

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot) {
	if (pTreeRoot == NULL) return ;

	queue<BinaryTreeNode *> m_queue;
	m_queue.push(pTreeRoot);

	while (!m_queue.empty()) {
		cout << m_queue.front()->m_nValue << ' ';
		if (m_queue.front()->m_pLeft)
			m_queue.push(m_queue.front()->m_pLeft);

		if (m_queue.front()->m_pRight) 
			m_queue.push(m_queue.front()->m_pRight);
		m_queue.pop();
	}
	cout << endl;
}

int main() {
	BinaryTreeNode *node5 = new BinaryTreeNode(5, NULL, NULL);
	BinaryTreeNode *node7 = new BinaryTreeNode(7, NULL, NULL);
	BinaryTreeNode *node9 = new BinaryTreeNode(9, NULL, NULL);
	BinaryTreeNode *node11 = new BinaryTreeNode(11, NULL, NULL);
	BinaryTreeNode *node6 = new BinaryTreeNode(6, node5, node7);
	BinaryTreeNode *node10 = new BinaryTreeNode(10, node9, node11);
	BinaryTreeNode *root = new BinaryTreeNode(8, node6, node10);

	BinaryTreeNode *pRoot = root;
	PrintFromTopToBottom(pRoot);

}
