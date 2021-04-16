#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

/*
 * Date:2021-03-17 14:16
 * Author:Gmrakari
 * Filename:3.cpp
 *
 */

typedef struct BiTNode
{
	int data;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode,*BiTree;

//步骤1
//如果结点有左子树，该结点入栈
//如果结点没有左子树，访问该结点

//步骤2
//如果结点有右子树(结点访问完毕),根据栈顶指示回退，访问栈顶元素，并访问右子树，重复步骤1
//如果栈空，表示遍历结束

BiTNode* goLeft(BiTNode *root,stack<BiTNode *> &s)
{
	if(root == NULL)
		return NULL;
/*
	while(root)
	{
		if(root->lchild != NULL)
		{
			s.push(root-lchild);
		}
		else
		{
			cout << root->data;
		}
		root = root->lchild;
	}

*/
	while(root->lchild != NULL)
	{
		s.push(root);
		root = root->lchild;
	}
	return root;
}

void InOrder(BiTNode *root)
{
	stack<BiTNode *> s;
	BiTNode* t = goLeft(root,s);

/*
	if(t)
	{
		cout << t->data << " ";
	}
	else if(!s.empty())
	{

	}
	else
	{
		t = NULL;
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


int main(){

	BiTNode t1,t2,t3,t4,t5;
	memset(&t1,0,sizeof(BiTNode));
	memset(&t2,0,sizeof(BiTNode));
	memset(&t3,0,sizeof(BiTNode));
	memset(&t4,0,sizeof(BiTNode));
	memset(&t5,0,sizeof(BiTNode));
	
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.lchild = &t2;
	t1.rchild = &t3;

	t2.lchild = &t4;
	t2.rchild = &t5;
		
	InOrder(&t1);

	printf("\n");
	
}
