

/*
 * Date:2021-05-17 19:26
 * filename:6.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *lchild;
	TreeNode *rchild;

	TreeNode():val(0),lchild(nullptr),rchild(nullptr){}
	TreeNode(int x):val(x),lchild(nullptr),rchild(nullptr) {}
	TreeNode(int x,TreeNode *lchild,TreeNode *rchild):val(x),lchild(lchild),rchild(rchild) {}
};

void without_recurisive_inoder_traversal(TreeNode *pRoot)
{
	if(pRoot == nullptr)
		return ;

	stack<TreeNode *> m_stack;
	TreeNode *node = pRoot;
	while(node || !m_stack.empty())
	{
		while(node)
		{
			m_stack.push(node);
			node = node->lchild;
		}
		if(!m_stack.empty())
		{
			node = m_stack.top();
			cout << node->val << " ";
			m_stack.pop();
			node = node->rchild;
		}
	}
	cout << endl;
}

void inorder(TreeNode *pRoot)
{
	if(pRoot == nullptr)
		return ;
	inorder(pRoot->lchild);
	cout << pRoot->val << " ";
	inorder(pRoot->rchild);
}
void Destroy(TreeNode *pRoot)
{		
	if(pRoot == nullptr)
		return ;
	TreeNode* lchild = pRoot->lchild;
	TreeNode* rchild = pRoot->rchild;
	delete pRoot;
	pRoot = nullptr;
	Destroy(lchild);
	Destroy(rchild);
}

int main()
{
	TreeNode *node1 = new TreeNode(4);
	TreeNode *node2 = new TreeNode(5);
	TreeNode *node3 = new TreeNode(6);
	TreeNode *node4 = new TreeNode(2,node1,node2);
	TreeNode *node5 = new TreeNode(3,node3,nullptr);
	TreeNode *node6 = new TreeNode(1,node4,node5);
	TreeNode *pRoot = node6;

	cout << "without_recurisive_inoder_traversal:";
	without_recurisive_inoder_traversal(pRoot);

	cout << "recurisive inorder traversal :";
	inorder(pRoot);
	cout << endl;

	Destroy(pRoot);

}
