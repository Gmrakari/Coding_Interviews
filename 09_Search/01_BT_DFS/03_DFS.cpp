

/*
 * Date:2021-05-17 15:07
 * filename:03_DFS.cpp
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
	TreeNode(int x,TreeNode *lchild,TreeNode *rchild):val(x),lchild(lchild),rchild(rchild){}
};

class Solution
{
public:
	void PrintTree(TreeNode *pRoot)
	{
		if(pRoot == nullptr)
		{
			return ;
		}
		cout << pRoot->val << " ";
		if(pRoot->lchild)
		{
			PrintTree(pRoot->lchild);
		}
		if(pRoot->rchild)
		{
			PrintTree(pRoot->rchild);
		}
	}
	void BFS_Queue(TreeNode *pRoot)
	{
		if(pRoot == nullptr)
			return ;
		queue<TreeNode *> Q;
		Q.push(pRoot);

		while(!Q.empty())
		{
			TreeNode *node = Q.front();
			cout << node->val << " ";
			if(node->lchild)
				Q.push(node->lchild);
			if(node->rchild)
				Q.push(node->rchild);
			Q.pop();
		}
		cout << endl;
	}
	void BFS_Stack(TreeNode *pRoot)
	{
		if(pRoot == nullptr)
			return ;
		stack<TreeNode *> instack;
		instack.push(pRoot);

		while(!instack.empty())
		{
			TreeNode *node = instack.top();
			cout << node->val << " ";
			stack<TreeNode *> outstack;

			if(node->lchild)
				instack.push(node->lchild);
			if(node->rchild)
				instack.push(node->rchild);
		}
		cout << endl;
	}
	void Destroy_Tree(TreeNode *pRoot)
	{
		if(pRoot == nullptr)
			return ;

		delete pRoot;
		pRoot = nullptr;
		Destroy_Tree(pRoot->lchild);
		Destroy_Tree(pRoot->rchild);
	}

};

int main()
{
	Solution m_btree;
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);

	TreeNode *node6 = new TreeNode(6);

	TreeNode *node2 = new TreeNode(2,node4,node5);
	TreeNode *node3 = new TreeNode(3,node6,nullptr);

	TreeNode *node1 = new TreeNode(1,node2,node3);

	TreeNode *pRoot = node1;
	
	cout << "inorder traversal binarytree:";
	m_btree.PrintTree(pRoot);
	cout << endl;

	cout << "BFS_Queue:";
	m_btree.BFS_Queue(pRoot);

	cout <<"BFS_Stack:";
	m_btree.BFS_Stack(pRoot);
	

}
