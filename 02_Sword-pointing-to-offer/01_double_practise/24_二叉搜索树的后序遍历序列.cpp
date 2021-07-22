

/*
 * Date:2021-07-22 13:49
 * filename:24_二叉搜索树的后序遍历序列.cpp
 *
 */

// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。


/*
 * 以数组{5, 7, 6, 9, 11, 10, 8}为例，后序遍历结果的最后一个数字8就是根结点的值
 * 在这个数组中，前3个数字5，7和6都比8小，是值为8的节点的左子树结点;
 * 后3个数字，9, 11和10都比8大，是值为8的节点的右子树结点
 *
 * 递归实现确定 5, 7和6,最后一个数字6是左子树的根节点的值
 * 数字5比6小，是值为6的结点的左子结点，而7则是它的右子结点
 *
 * 同样在序列9, 11, 10中，最后一个数字10是右子树的根结点，数字9比10小，是值为10的结点的左子结点，
 * 而11则是它的右子结点
 *
 */
#include <iostream>
using namespace std;

bool VerifySquenceOfBST(int sequence[], int length) {
	if (sequence == NULL || length <= 0) return false;

	int root = sequence[length - 1];

	//在二叉搜索树中左子树的结点小于根结点
	int i = 0;
	for (; i < length - 1;++i) {
		if (sequence[i] > root) 
			break;
	}

	//在二叉搜索树中右子树的结点大于根结点
	int j = i;
	for (; j < length - 1;++j) {
		if (sequence[j] < root) 
			return false;
	}

	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0) 
		left = VerifySquenceOfBST(sequence, i);

	//判断右子树是不是二叉搜索树
	bool right = true;
	if (i < length - 1)
		right = VerifySquenceOfBST(sequence + i, length - i - 1);

	return (left && right);
}
