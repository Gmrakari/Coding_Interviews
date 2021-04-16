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

BiTNode *goLeft(BiTNode *T,stack<BiTNode *> &s){
	if(T == NULL){
		return NULL;
	}
	while(T->lchild != NULL){
		s.push(T);
		T = T->lchild;
	}
	return T;

}

void InOrder(BiTNode *T){
	
	stack<BiTNode *> s;
	/*
	if(T == NULL)
		return NULL;

	if(T->lchild == NULL){
		cout << T->data;
	}
	else{
		s.push(T->lchild);	
	}
	*/

	BiTNode *t = goLeft(T,s);
	while(t){
	std::cout << t->data << "  ";

		if(t->rchild != NULL){
			t = goLeft(t->rchild,s);
		}
		else if(!s.empty()){
			t = s.top();
			s.pop();
		}else{
			t = NULL;
		}
	}
}

int main(){
	BiTNode t1,t2,t3,t4,t5;
	memset(&t1,0,sizeof(BiTNode));
	memset(&t3,0,sizeof(BiTNode));
	memset(&t2,0,sizeof(BiTNode));
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
	std::cout << endl;

}
