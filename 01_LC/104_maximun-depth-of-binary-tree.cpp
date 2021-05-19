

/*
 * Date:2021-05-19 11:17
 * filename:104_maximun-depth-of-binary-tree.cpp
 *
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

/* Recursive */
//每次递归 找出root->left,root->right最大值
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

/*
 * Solution2 :DFS(Depth First Search) 
 *
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
		if(root == nullptr)
			return 0;

		queue<TreeNode *> Que;
		Que.push(root);
		int ret = 0;
		while(!Que.empty())
		{
			int QueSize = Que.size();
			while(QueSize > 0)
			{
				TreeNode *node = Que.front();
				Que.pop();
				if(node->left)
					Que.push(node->left);
				if(node->right)
					Que.push(node->right);
				QueSize -= 1;
			}
			ret += 1;
		}
		return ret;
    }
};
