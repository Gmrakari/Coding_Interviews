

/*
 * Date:2022-03-23 14:05
 * filename:07_树的深度.cpp
 *
 */
#include<iostream>
using namespace std;
//构建二叉树
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	int treeDepth(TreeNode *root) {
		if (!root) return 0;
		return std::max(treeDepth(root->left) + 1, treeDepth(root->right) + 1);
	}
};
