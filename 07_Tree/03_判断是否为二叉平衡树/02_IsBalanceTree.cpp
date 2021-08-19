

/*
 * Date:2021-08-19 10:00
 * filename:02_IsBalanceTree.cpp
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct BinTreeNode {
	int data;
	struct BinTreeNode* lchild;
	struct BinTreeNode* rchild;
	BinTreeNode():data(0),lchild(nullptr),rchild(nullptr){}
	BinTreeNode(int x):data(x),lchild(nullptr),rchild(nullptr) {}
	BinTreeNode(int x,BinTreeNode *lchild,BinTreeNode *rchild):data(x),lchild(lchild),rchild(rchild) {}
};

namespace method_2_best {
	int IsBalanceTree_op(BinTreeNode *root, int *pdepth) {
		if (root == NULL) {
			*pdepth = 0;
			return 1;
		}

		//按照后序遍历去判断,先判断左右子树，然后记录以当前结点为根树的深度
		int left, right;
		if (IsBalanceTree_op(root->lchild, &left) && IsBalanceTree_op(root->rchild, &right)) {
			int gap = right - left;
			if (gap <= 1 && gap >= -1) {
				*pdepth = left > right ? left + 1 : right + 1;
				return 1;
			}
		}
		return 0;
	}
}

BinTreeNode *init_is_balance_tree() {
	//BinTreeNode
	BinTreeNode *node4 = new BinTreeNode(4, nullptr, nullptr);
	BinTreeNode *node5 = new BinTreeNode(5, nullptr, nullptr);
	BinTreeNode *node6 = new BinTreeNode(6, nullptr, nullptr);
	BinTreeNode *node2 = new BinTreeNode(2,node4,node5);
	BinTreeNode *node3 = new BinTreeNode(3,node6,nullptr);
	BinTreeNode *node1 = new BinTreeNode(1,node2,node3);
	BinTreeNode *pRoot = node1;

	return pRoot;
}

BinTreeNode *init_is_not_balance_tree() {
	//BinTreeNode
	BinTreeNode *node6 = new BinTreeNode(6, nullptr, nullptr);
	BinTreeNode *node4 = new BinTreeNode(4, node6, nullptr);
	BinTreeNode *node5 = new BinTreeNode(5, nullptr, nullptr);
	BinTreeNode *node2 = new BinTreeNode(2,node4,node5);
	BinTreeNode *node3 = new BinTreeNode(3, nullptr,nullptr);
	BinTreeNode *node1 = new BinTreeNode(1,node2,node3);
	BinTreeNode *pRoot = node1;

	return pRoot;
}

int main() {

	BinTreeNode *is_balance = init_is_balance_tree();
	BinTreeNode *is_not_balance = init_is_not_balance_tree();

	int i = 3;
	int *pdepth = &i;
	int ret = 0;
	ret = method_2_best::IsBalanceTree_op(is_balance, pdepth);
	cout << ret << endl;//1

	ret = method_2_best::IsBalanceTree_op(is_not_balance, pdepth);
	cout << ret << endl;//0

}
