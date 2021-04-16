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
