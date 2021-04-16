#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

void InOrder(BiTNode *root){
	if(root == NULL)
		return ;
	InOrder(root->lchild);
	printf("%d\t",root->data);
	InOrder(root->rchild);
}

void PreOrder(BiTNode *root)
{
	if(root == NULL)
		return ;
	printf("%d\t",root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void PostOrder(BiTNode *root)
{
	if(root == NULL)
		return ;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%d\t",root->data);
}


int TreeDepth(BiTNode *root)
{
	if(root == NULL)
		return 0;

	int nLeft = TreeDepth(root->lchild);

	int nRigth = TreeDepth(root->rchild);

	return (nLeft > nRigth) ? (nLeft + 1 ) : (nRigth + 1);
}

int main(){
	void PreOrder(BiTNode *root);
	void InOrder(BiTNode *root);
	void PostOrder(BiTNode *root);

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
	
	
	printf("PreOrder: ");
	PreOrder(&t1);
	printf("\n");

	printf("InOrder:  ");
	InOrder(&t1);
	printf("\n");

	printf("PostOrder:");
	PostOrder(&t1);
	printf("\n");


	/*
	printf("without Order Tree:");
	InOrder(&t1);
	printf("\n");
	*/

	int TreeDepth(BiTNode *root);
	int ret = TreeDepth(&t1);
	printf("ret :%d\n",ret);

}
