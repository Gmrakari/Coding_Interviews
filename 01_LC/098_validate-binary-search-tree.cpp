

/*
 * Date:2021-05-07 13:35
 * filename:098_validate-binary-search-tree.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode *left,TreeNode *right) : val(x),left(left),right(right) {}
};

class Solution
{
public:
	bool isValidBST(TreeNode* root){
		if(root == nullptr)
			return false;
		vector<int> vec;
		isValidBST(root->left);
		if(root->val != nullptr)
		{
			vec.push_back(root->val);
		}
		isValidBST(root->right);
	}

	bool BubbleSort(vector<int> &vec)
	{
		int exchange = 1;
		for(int i = 0;(i < vec.size() && exchange);++i)
		{
			exchange = 0;
			for(int j = vec.size() - 1;j > 0;--j)
			{
				if(vec[j] < vec[j - 1])
					return false;
				else
				{
					exchange = 1;
				}
			}
		}
		return true;
	}
}
