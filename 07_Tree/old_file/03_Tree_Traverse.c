#include<stdio.h>
 
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
 
typedef struct{
	BiTree data[100];
	int top;
}BiStack;
 
void PostOrder(BiTree T);
 
int main(){
	BiTNode a,b,c,d,e,f,g;        //简单的测试数据
	a.data=1;
	b.data=2;
	c.data=3;
	d.data=4;
	e.data=5;
	f.data=6;
	g.data=7;
	a.lchild=&b;
	a.rchild=&g;
	b.lchild=&c;
	b.rchild=NULL;
	c.lchild=&d;
	c.rchild=&e;
	d.lchild=NULL;
	d.rchild=NULL;
	e.lchild=NULL;
	e.rchild=&f;
	f.lchild=NULL;
	f.rchild=NULL;
	g.lchild=NULL;
	g.rchild=NULL;
	
	
	PostOrder(&a);
	
	return 0;
}
 
void PostOrder(BiTree T){	//入栈所有的左子树以及左子树的右子树直到没有可以访问的右子树后退栈。 
	BiTNode *pre = T;		//记录上一次退栈的结点 
	BiTNode *p=T;			//当前访问结点 
	BiStack s ;
	s.top=0;
	s.data[s.top]=NULL;
	while(p||s.top!=0){
		if(p!=NULL&&pre!=p->lchild&&pre!=p->rchild){	//结点不为空且左孩子和右孩子没有访问过 ，入栈左子树 
			s.data[++s.top]=p;
			p=p->lchild;
		}
		else{					
			p=s.data[s.top];						 
			if(p->rchild!=NULL&&pre!=p->rchild){	//右子树不为空且右孩子没有访问过，入栈右子树结点 
				p=p->rchild;
			}
			else{
				printf("%d ",p->data);			//访问到最后的右子树的结点后，退栈。 
				pre=s.data[s.top];
				p=s.data[--s.top];
			}
		}
	}
	printf("\n");
}
