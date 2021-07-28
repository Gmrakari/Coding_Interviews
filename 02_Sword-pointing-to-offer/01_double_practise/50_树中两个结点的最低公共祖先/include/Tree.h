

/*
 * Date:2021-07-28 16:30
 * filename:Tree.h
 *
 */

#ifndef __TREE_H
#define __TREE_H

#include <vector>

struct TreeNode
{
    int                       m_nValue;
    std::vector<TreeNode*>    m_vChildren;
};

//__declspec( dllexport ) TreeNode* CreateTreeNode(int value);
TreeNode* CreateTreeNode(int value);
//__declspec( dllexport ) void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild);
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild);
//__declspec( dllexport ) void PrintTreeNode(const TreeNode* pNode);
void PrintTreeNode(const TreeNode* pNode);
//__declspec( dllexport ) void PrintTree(const TreeNode* pRoot);
void PrintTree(const TreeNode* pRoot);
//__declspec( dllexport ) void DestroyTree(TreeNode* pRoot);
void DestroyTree(TreeNode* pRoot);

#endif
