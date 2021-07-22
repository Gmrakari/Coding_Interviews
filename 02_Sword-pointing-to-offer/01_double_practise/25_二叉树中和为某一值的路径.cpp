

/*
 * Date:2021-07-22 14:49
 * filename:25_二叉树中和为某一值的路径.cpp
 *
 */

/*
#题意
题目描述

输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径

*/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/*
 * 当用前序遍历的方式访问到某一结点时，我们把该结点添加到路径上，并累加该结点的值。
 * 如果该结点为叶结点并且路径中结点值的和刚好等于输入的整数，则当前的路径符合要求，我们把它打印出来。
 *
 * 如果当前结点不是叶结点，则继续访问它的子结点。当前结点访问结束后，递归函数将自动回到它的父结点。
 * 因为我们在退出之前要在路径上删除当前结点并减去当前结点的值，以确保返回父结点时路径刚好是从根结点到父结点的路径
 *
 * 我们不难看出保存路径的数据结构实际上是一个栈，因为路径要与递归调用状态一致，而递归调用的本质就是一个压栈和出栈的过程
 *
 */

struct BinaryTreeNode{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void FindPath(BinaryTreeNode* pRoot, int expectedSum) {
	void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum);
	if (pRoot == NULL) return ;

	std::vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum) {
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//如果是叶子结点，并且路径上节点的和等于输入的值 打印出这条路径
	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if (currentSum == expectedSum && isLeaf) {
		printf("A path is found: ");
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter) 
			printf("%d ",*iter);

		printf("\n");
	}

	//如果不是叶结点，则遍历它的子结点
	if (pRoot->m_pLeft != NULL) 
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);

	if (pRoot->m_pRight != NULL) 
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

	//在返回到父结点之前，在路径上删除当前结点
	path.pop_back();
}

//我们用标准模板库中的vector实现了一个栈来保存路径，每一次都用push_back在路径的末尾添加结点，
//用pop_back在路径的末尾删除结点，这样保证了栈的先入后出的特性
//
//不用STL的stack是因为stack中只能得到栈顶元素，我们打印路径的时候需要得到路径上所有结点
