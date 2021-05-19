

/*
 * Date:2021-05-19 11:32
 * filename:111_minimun-depth-of-binary-tree.cpp
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;

        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);

        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left == 0 || right == 0) ? left + right + 1 : min(left,right) + 1;
    }
};
