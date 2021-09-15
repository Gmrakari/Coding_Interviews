

/*
 * Date:2021-09-15 09:57
 * filename:04_二叉树的递归遍历.cpp
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

void inorder(TreeNode *pRoot) {
	if (pRoot == NULL)
		return ;

	inorder(pRoot->lchild);
	cout << pRoot->val << ' ';
	inorder(pRoot->rchild);
}

void preorder(TreeNode* pRoot) {
	if (pRoot == NULL)
		return ;

	cout << pRoot->val << ' ';
	preorder(pRoot->lchild);
	preorder(pRoot->rchild);
}

void postorder(TreeNode* pRoot) {
	if (pRoot == NULL) 
		return ;

	postorder(pRoot->lchild);
	postorder(pRoot->rchild);
	cout << pRoot->val << ' ';
}

int main() {
	TreeNode* pRoot = init();

	cout << "preorder:";
	preorder(pRoot);
	cout << endl;

	pRoot = init();
	cout << "inorder:";
	inorder(pRoot);
	cout << endl;

	pRoot = init();
	cout << "postorder:";
	postorder(pRoot);
	cout << endl;

}
