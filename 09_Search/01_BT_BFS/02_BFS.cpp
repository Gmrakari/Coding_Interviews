

/*
 * Date:2021-05-16 19:36
 * filename:01_DFS.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *lchild;
	TreeNode *rchild;

	TreeNode() :val(0),lchild(nullptr),rchild(nullptr) {}
	TreeNode(int x):val(x),lchild(nullptr),rchild(nullptr) {}
	TreeNode(int x,TreeNode *lchild,TreeNode *rchild):val(x),lchild(lchild),rchild(rchild) {}
};

void DestroyTree(TreeNode *pRoot)
{
	if(pRoot == nullptr)
		return ;

	TreeNode* lchild = pRoot->lchild;
	TreeNode* rchild = pRoot->rchild;

	delete pRoot;
	pRoot = nullptr;

	DestroyTree(lchild);
	DestroyTree(rchild);
}

//queue dfs
void BFS(TreeNode *pRoot)
{
	if(pRoot == nullptr)
		return ;

	queue<TreeNode *> Que;
	Que.push(pRoot);

	while(!Que.empty())
	{
		TreeNode *node = Que.front();
		cout << node->val << " ";
		if(node->lchild != nullptr)
		{
			Que.push(node->lchild);
		}

		if(node->rchild != nullptr)
		{
			Que.push(node->rchild);
		}
		Que.pop();
	}
	cout << endl;
}

void Stack_BFS(TreeNode *pRoot)
{
	if(pRoot == nullptr)
		return ;
	stack<TreeNode *> inStack,outStack;
	inStack.push(pRoot);
	TreeNode *node = inStack.top();
	while(node->lchild && node->rchild)
	{
		//3 time
		if(node->lchild != nullptr)
		{
			inStack.push(node->lchild);
		}
		if(node->rchild != nullptr)
		{
			inStack.push(node->rchild);
		}
	}

	while(!inStack.empty())
	{
		outStack.push(inStack.top());
		inStack.pop();
	}

	while(!outStack.empty())
	{
		TreeNode *tmp = outStack.top();
		cout << tmp->val << " ";
		outStack.pop();
	}
	cout << endl;
}

void PrintTree(TreeNode *pRoot)
{
	if(pRoot == nullptr)
		return ;

	cout << pRoot->val << " ";
	if(pRoot->lchild != nullptr)
	{
		PrintTree(pRoot->lchild);
	}

	if(pRoot->rchild != nullptr)
	{
		PrintTree(pRoot->rchild);
	}
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
	void PrintTree(TreeNode *pRoot);
	void BFS(TreeNode *pRoot);

	PrintTree(pRoot);
	cout << endl;

	BFS(pRoot);
	PrintTree(pRoot);

	cout << endl;
	void Stack_BFS(TreeNode *pRoot);

	cout << endl << "Stack_BFS:";
	Stack_BFS(pRoot);

	cout << endl;

	DestroyTree(pRoot);
	return 0;
	
}