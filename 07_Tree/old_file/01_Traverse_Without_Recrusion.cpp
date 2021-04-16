#include <iostream>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;

struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
};

typedef struct BiTNode BiTNode;
typedef struct BiTNode *BiTree;

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
	BiTNode *t = goLeft(T,s);

	while(t){
		printf("%d ",t->data);

		if(t->rchild != NULL){
			t = goLeft(t->rchild,s);
		}else if(!s.empty()){
			t = s.top();
			s.pop();
		}else{
			t = NULL;
		}
	}
}

int main(){
	BiTNode t1,t2,t3,t4,t5;
	memset(&t1,0,sizoef(BiTNode));
	memset(&t2,0,sizoef(BiTNode));
	memset(&t3,0,sizoef(BiTNode));
	memset(&t4,0,sizoef(BiTNode));
	memset(&t5,0,sizoef(BiTNode));

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.lchild = &t2;
	t1.rchild = &t3;

	t2.lchild = &t4;
	t2.rchild = &t5;

	cout << "非递归中序遍历:" ;
	InOrder(&t1);
	cout << endl;
}
