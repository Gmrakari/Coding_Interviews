

/*
 * Date:2021-05-18 20:02
 * filename:102-binary-tree-level-order-traversal.cpp
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int>> res;
        if(root == nullptr)
            return res;

        queue<TreeNode *> que;
        que.push(root);

        while(!que.empty())
        {
            int currentLevelSize = que.size();
            res.push_back(vector<int>());
            for(int i = 1;i <= currentLevelSize;++i)
            {
                auto node = que.front();
                que.pop();
                res.back().push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
        }
        return res;
    }
};
