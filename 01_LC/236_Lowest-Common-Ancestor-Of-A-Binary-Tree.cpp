

/*
 * Date:2021-05-08 11:09
 * filename:236_Lowest-Common-Ancestor-Of-A-Binary-Tree.cpp
 *
 */

#include <bits/stdc++.h>
#include <new>
#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0),left(nullptr),right(nullptr){}
	TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode *left,TreeNode *right) : val(x),left(left),right(right) {}
};

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if(root == nullptr || root == p || root == q)
			return root;
		TreeNode* left =  lowestCommonAncestor(root->left,p,q);
		TreeNode* right = lowestCommonAncestor(root->right,p,q);
		return left == nullptr ? right : right == nullptr ? left : root;
	}
};

int main()
{
	Solution su;

	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	root->left = node1;
	root->right = node2;

	node1->left = nullptr;
	node1->right = nullptr;

	node2->left = nullptr;
	node2->right = nullptr;

	TreeNode* ret = su.lowestCommonAncestor(root,node1,node2);
	cout << "commonancestor is :";
	cout << ret->val << " ";

	cout << endl;

}



