#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct BiTNode{
	int data;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode,*BiTree;

BiTNode* goLeft(BiTNode *T,stack<BiTNode *> &s)
{
	if(T == NULL)
	{
		return NULL;
	}
/*	
	while(T)
	{
		if(T->lchild != NULL)
			s.push(T);
			T = T->lchild;
	}
*/
	while(T->lchild != NULL)
	{
		s.push(T);
		T = T->lchild;
	}
	return T;
}

void Inorder(BiTNode *T)
{
	stack<BiTNode *> s;
	BiTNode *t = goLeft(T,s);
	/*
	while(t)
	{
		t = goLeft(T,s);
		if(t->rchild != NULL)
		{
			goLeft(t->rchild,s);
		}
		else if(!s.empty())
		{
			
		}
		else
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

	cout << "Inorder : " ;
	Inorder(&t1);

	printf("\n");
}

