

/*
 * Date:2021-08-17 13:40
 * filename:01_IsBalanceTree.cpp
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct BinTreeNode {
	int data;
	struct BinTreeNode* lchild;
	struct BinTreeNode* rchild;
};

namespace method_1 {
	int BinaryTreeHigh(BinTreeNode* root) {
		if (root == NULL) return 0;
		int lchild_len = BinaryTreeHigh(root->lchild);
		int rchild_len = BinaryTreeHigh(root->rchild);

		//二叉树的高度为左子树和右子树中高的那个高度加1;
		return lchild_len > rchild_len ? lchild_len + 1 : rchild_len + 1;
	}

	int IsBalanceTree_R(BinTreeNode* root) {
		//空树是平衡树
		//平衡二叉树是指以当前结点为根的左右子树高度不得超过1
		if (root == NULL) return 1;

		//左子树深度
		int left_high = BinaryTreeHigh(root->rchild);

		//右子树深度
		int right_high = BinaryTreeHigh(root->lchild);

		int gap = right_high - left_high;
		//深度超过1不是
		if (gap > 1 || gap < -1) return 0;

		//递归判断子树
		return IsBalanceTree_R(root->lchild) && IsBalanceTree_R(root->rchild);
	}
}

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
