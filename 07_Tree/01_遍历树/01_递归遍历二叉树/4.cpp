

/*
 * Date:2021-05-08 15:20
 * filename:中序遍历.cpp
 *
 */

#include <bits/stdc++.h>
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
	void inorder(TreeNode *root,vector<int> &vec)
	{
		if(root == nullptr)
			return ;
		inorder(root->left,vec);
		vec.push_back(root->val);
		inorder(root->right,vec);
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

	vector<int> res;
	su.inorder(root,res);

	for(int i = 0;i < res.size();i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;

}



