

/*
 * Date:2021-07-17 09:45
 * filename:06_重建二叉树.cpp
 *
 */

/*
#题意
题目描述

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

输入

前序遍历序列{1,2,4,7,3,5,6,8}

中序遍历序列{4,7,2,1,5,3,8,6}

则重建二叉树并返回。
*/

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
	BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);
	if (preorder == NULL || inorder == NULL || length <= 0) 
		return NULL;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
	//前序遍历序列的第一个数字是根节点的值
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_pLeft = root->m_pRight = NULL;

	if (startPreorder == endPreorder) {
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else 
			throw std::exception("Invalid input");
	}

	//在中序遍历中找到根节点的值
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue) 
		throw std::exception("Invalid input");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0) {
		//构建左子树
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder) {
		//构建右子树
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

/*
 * 在函数ConstructCore中，我们先根据前序遍历序列的第一个数字创建根结点，接下来在中序遍历中找到根结点的位置
 * 这样就能确定左、右子树结点的数量。在前序遍历和中序遍历的序列中划分了左、右子树结点的值之后，我们就可以
 * 调用函数ConstructCore，去分别构建它的左右子树
 */
