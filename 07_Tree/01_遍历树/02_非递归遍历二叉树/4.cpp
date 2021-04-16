
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

typedef struct BiTNode
{
	int data;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode,*BiTree;

BiTNode* goLeft(BiTNode *root,stack<BiTNode *> &s)
{
	if(root == NULL)
		return NULL;

	/*

	while(root)
	{
		if(root->lchild != NULL)
		{
			s.push(root->lchild);
			root = root->lchild;
		}
	}
	return root;

	*/

	while(root->lchild != NULL)
	{
		s.push(root);
		root = root->lchild;
	}
	return root;
}

void Inorder(BiTNode *root)
{
	stack<BiTNode *> s;
	BiTNode *t = goLeft(root,s);
	
	/*

	while(root)
	{
		cout << root->data << " ";
		if(root->rchild != NULL)
		{
			t = goLeft(t->rchild,s);
		}
		else if(!s.empty())
		{
			
		}
		
	}

	*/

	while(t)
	{
		cout << t->data << " ";
		if(t->rchild != NULL)
		{
			t = goLeft(t->rchild,s);
		}
		else if(!s.empty())
		{
			t = s.top();
			s.pop();
		}
		else
		{
			t = NULL;
		}
	}
}

int main()
{
	BiTNode tree[5];

	tree[0].data = 1;
	tree[0].lchild = &tree[1];
	tree[0].rchild = &tree[2];

	tree[1].data = 2;
	tree[1].lchild = &tree[3];
	tree[1].rchild = &tree[4];

	tree[2].data = 3;
	tree[2].lchild = NULL;	
	tree[2].rchild = NULL;	

	tree[3].data = 4;
	tree[3].lchild = NULL;	
	tree[3].rchild = NULL;	

	tree[4].data = 5;
	tree[4].lchild = NULL;	
	tree[4].rchild = NULL;	
	
	Inorder(tree);
	printf("\n");

}
