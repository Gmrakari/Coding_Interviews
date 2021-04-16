#include <iostream>
#include <cstring>
using namespace std;
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

BiTNode* CopyTree(BiTNode *Tree){
	if(Tree == NULL){
		return NULL;
	}
	
	BiTNode* newTree;
	BiTNode* newLChild;
	BiTNode* newRChild;

	if(Tree->lchild != NULL){
		newLChild = CopyTree(Tree->lchild);	
	}else{
		newLChild = NULL;
	}

	if(Tree->rchild != NULL){
		newRChild = CopyTree(Tree->rchild);	
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

void print(BiTNode *root){
	if(root == NULL)
		return ;
	cout << root->data <<" ";
	print(root->lchild);
	print(root->rchild);
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
	
	BiTNode *root = CopyTree(&t1);
	
	print(root);

	printf("\n");
	
}
