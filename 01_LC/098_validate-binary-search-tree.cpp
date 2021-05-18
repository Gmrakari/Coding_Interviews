
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


/*
 * Date:2021-05-18 16:45
 * file create on class 
 */

#include <bits/stdc++.h>
/*
 * 思路：用一个vector保存树的节点
 * 如果vec的前一个节点大于后一个节点，那么返回false
 * 否则 返回true
 */
 

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        if(root == nullptr)
            return false;
        vector<int> vec;
        inorder(root,vec);

        for(int i = 1;i < vec.size();i++)
        {
            if(vec[i] < vec[i - 1])
                return false;
        }
        return true;

    }

    void inorder(TreeNode* root,vector<int> &vec)
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
	/*
	TreeNode* node3 = new TreeNode(3,nullptr,nullptr);
	TreeNode* node6 = new TreeNode(6,nullptr,nullptr);
	
	TreeNode* node1 = new TreeNode(1,nullptr,nullptr);
	TreeNode* node4 = new TreeNode(4,node3,node6);
	TreeNode* node5 = new TreeNode(5,node1,node4);

	TreeNode* pRoot = node5;
	*/
	
	TreeNode* node1 = new TreeNode(1,nullptr,nullptr);
	TreeNode* node3 = new TreeNode(3,nullptr,nullptr);
	TreeNode* node2 = new TreeNode(2,node1,node3);
	
	TreeNode* pRoot = node2;
	
	Solution bstree;
	bool ret = bstree.isValidBST(pRoot);
	
	cout <<"ret : " << ret << endl;
	
	
}
