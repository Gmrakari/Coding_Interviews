
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
		if(root != nullptr)
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
};

void inorder(TreeNode *root)
{
	if(root == nullptr)
		return;
	vector<int> vec;
	inorder(root->left);
	vec.push_back(root->val);
	inorder(root->right);

	for(auto it = vec.begin();it != vec.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void print(TreeNode *root)
{
	if(root == nullptr)
		return ;
}

int main()
{
	Solution su;
	TreeNode* root;
	TreeNode* node1;
	TreeNode* node2;
	TreeNode* node3;
	TreeNode* node4;

	root->left = node1;
	root->right = node2;
	node1->left = nullptr;
	node1->right = nullptr;

	node2->left = node3;
	node2->right = node4;
	
	node3->left = nullptr;
	node3->right = nullptr;
	node4->left = nullptr;
	node4->right = nullptr;

	root->val = 5;
	node1->val = 1;
	node2->val = 4;
	node3->val = 3;
	node4->val = 6;

	printf("test:");
	inorder(root);


	return 0 ;

}

/*
 * Update:2021-05-07-20:14
 * correct
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        vector<int> vec;
        inorder(root,vec);
        for(int i = 1;i < vec.size();i++)
        {
            if(vec[i] <= vec[i - 1])
            {
                return false;
            }
        }
        return true;

    }
    void inorder(TreeNode *root,vector<int> &vec)
    {
        if(root == nullptr)
            return ;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
};
