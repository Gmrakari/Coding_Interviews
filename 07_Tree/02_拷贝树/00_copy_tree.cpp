
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;


void Order(BiTNode *root){
	if(root == NULL)
		return ;

	printf("%d\t",root->data);
	Order(root->lchild);
	Order(root->rchild);
}

BiTNode* Copy(BiTNode* Tree){
	if(Tree == NULL)
		return NULL;
	BiTNode* newTree;
	BiTNode* newLChild;
	BiTNode* newRChild;

	if(Tree->lchild != NULL){
		newLChild = Copy(Tree->lchild);
	}else{
		newLChild = NULL;
	}

	if(Tree->rchild != NULL){
		newRChild = Copy(Tree->rchild);
	}else{
		newRChild = NULL;
	}

	newTree = (BiTNode *)malloc(sizeof(BiTNode));
	if(newTree == NULL){
		return NULL;
	}
	newTree->lchild = newLChild;
	newTree->rchild = newRChild;
	newTree->data = Tree->data;

	return newTree;
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
	
	printf("old Tree:");
	Order(&t1);
	printf("\n");

	printf("new Tree:");
	BiTNode *root = Copy(&t1);
	Order(root);
	printf("\n");


	return 0;
}
