

/*
 * Date:2021-09-15 10:13
 * filename:05_二叉树的中序非递归遍历.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* lchild;
	TreeNode* rchild;

	TreeNode() : val(0), lchild(NULL), rchild(NULL) {}
	TreeNode(int val) : val(val), lchild(NULL), rchild(NULL) {}
	TreeNode(int val, TreeNode* lchild, TreeNode* rchild) : val(val), lchild(lchild), rchild(rchild) {}
};

TreeNode* init() {
	TreeNode *node7 = new TreeNode(7, NULL, NULL);
	TreeNode *node6 = new TreeNode(6, NULL, NULL);
	TreeNode *node5 = new TreeNode(5, NULL, NULL);
	TreeNode *node4 = new TreeNode(4, NULL, NULL);
	TreeNode *node3 = new TreeNode(3, node6, node7);
	TreeNode *node2 = new TreeNode(2, node4, node5);
	TreeNode *node1 = new TreeNode(1, node2, node3);

	TreeNode *pRoot = node1;
	return pRoot;
}

void Travaltree(TreeNode* pRoot) {
	if (pRoot == NULL)
		return ;

	stack<TreeNode *> st;

	TreeNode* node = pRoot;
	while (node || !st.empty()) {
		while (node) {
			st.push(node);
			node = node->lchild;
		}
		if (!st.empty()) {
			node = st.top();
			cout << node->val << ' ';
			st.pop();
			node = node->rchild;
		}
	}
	cout << endl;
}

void Travaltree_2(TreeNode* pRoot) {
	if (pRoot == NULL) 
		return ;

	stack<TreeNode *> st;

	TreeNode* node = pRoot;

	while (node || !st.empty()) {
		while (node) {
			st.push(node);
			node = node->lchild;
		}
		if (!st.empty()) {
			node = st.top();
			cout << node->val << ' ';
			st.pop();
			node = node->rchild;
		}
	}
	cout << endl;
}

int main() {
	TreeNode* pRoot = init();
	cout << "二叉树的中序非递归遍历: ";
	Travaltree(pRoot);

	cout << "二叉树的中序非递归遍历: ";
	Travaltree_2(pRoot);
}
