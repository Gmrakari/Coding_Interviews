#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

/*
 * Date:2021-03-30 11:11
 * Author:Gmrakari
 * Project:without_recursion_traversal_bitree
 * Filename:01.cpp
 * 
 */

struct BiTNode
{
	int val;
	BiTNode *lchild;
	BiTNode *rchild;

	BiTNode():val(0),lchild(nullptr),rchild(nullptr){}
	BiTNode(int x):val(x),lchild(nullptr),rchild(nullptr) {}
	BiTNode(int x,BiTNode *lchild,BiTNode *rchild):val(x),lchild(lchild),rchild(rchild) {}
};

class BiTree
{
public:
	BiTNode* init()
	{
		BiTNode *node1 = new BiTNode(4);
		BiTNode *node2 = new BiTNode(5);
		BiTNode *node3 = new BiTNode(6);
		BiTNode *node4 = new BiTNode(2,node1,node2);
		BiTNode *node5 = new BiTNode(3,node3,nullptr);
		BiTNode *node6 = new BiTNode(1,node4,node5);
		BiTNode *pRoot = node6;

		return pRoot;
	}
	void Destroy(BiTNode *)
	{
		BiTNode* pRoot = init();
		if(pRoot == nullptr)
			return ;
		BiTNode* lchild = pRoot->lchild;
		BiTNode* rchild = pRoot->rchild;

		delete pRoot;
		pRoot = nullptr;

		Destroy(lchild);
		Destroy(rchild);
	}
	void Without_Recursive_traversal()
	{
		BiTNode* pRoot = init();
		if(pRoot == nullptr)
			return ;
		stack<BiTNode *> m_stack;
		BiTNode* node = pRoot;
		while(!m_stack.empty() || node)
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
};


int main()
{
	BiTree m_tree;
	cout << "inoder:";
	m_tree.Without_Recursive_traversal();
	//m_tree.Destroy();
	return 0;
}
