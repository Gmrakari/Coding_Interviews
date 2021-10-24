

/*
 * Date:2021-10-24 13:46
 * filename:20_9_二叉树按中序遍历得到一个递增序列.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *left;
	struct node *right;
	int val;
}node;

node *root = NULL;

void insert_tree(node *tr, int val) {
	node *p = (node*)malloc(sizeof(node));

	p->val = val;
	p->left = NULL;
	p->right = NULL;

	while (tr) {
		if (val > tr->val) {
			if (tr->right) {
				tr = tr->right;
			}
			else {
				tr->right = p;
				break;
			}
		}
		else {
			if (tr->left) 
				tr = tr->left;
			else {
				tr->right = p;
				break;
			}
		}
	}
}

void inorder(node *tr) {
	if (tr == NULL) 
		return ;

	inorder(tr->left);
	printf("%d",tr->val);
	inorder(tr->right);
}

node* createtree(int val) {
	node *tmp = (node*)malloc(sizeof(node));
	if (tmp == NULL) 
		return NULL;
	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void insert(node* &root, int key) {
	if (!root) {
		root = createtree(key);
	}
	else if (key > root->val)
		insert(root->right, key);
	else
		insert(root->left, key);
}


int main() {
	int x;
	while ((scanf("%d", &x)) == 1 && x) {
		insert(root, x);
	}
	inorder(root);
	return 0;
}
