

/*
 * Date:2021-07-28 16:15
 * filename:50_树中两个结点的最低公共祖先.cpp
 *
 */

#include <bits/stdc++.h>
#include "../include/Tree.h"
#include <list>
#include <cstdio>

using namespace std;


bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode *>& path) {
	if (pRoot == pNode)
		return true;

	path.push_back(pRoot);

	bool found = false;

	vector<TreeNode *>::const_iterator i = pRoot->m_vChildren.begin();
	while (!found && i < pRoot->m_vChildren.end()) {
		found = GetNodePath(*i, pNode, path);
		++i;
	}

	if (!found)
		path.pop_back();

	return found;
}

const TreeNode* GetLastCommonNode(const list<const TreeNode *>& path1, const list<const TreeNode *>& path2) {
	list<const TreeNode *>::const_iterator iterator1 = path1.begin();
	list<const TreeNode *>::const_iterator iterator2 = path2.begin();

	const TreeNode* pLast = NULL;

	while (iterator1 != path1.end() && iterator2 != path2.end()) {
		if (*iterator1 == *iterator2)
			pLast = *iterator1;

		iterator1++;
		iterator2++;
	}
	return pLast;
}

const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2) {
	bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode *>& path);
	if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
		return NULL;

	list<const TreeNode *> path1;
	GetNodePath(pRoot, pNode1, path1);

	list<const TreeNode *> path2;
	GetNodePath(pRoot, pNode2, path2);

	return GetLastCommonNode(path1, path2);
}

/*
 * 代码中GetNodePath用来得到从根结点pRoot开始到达结点pNode的路径，这条路径保存在path中
 *
 * 函数GetCommonNode用来得到两个路径path1和path2的最后一个公共结点
 * 函数GetLastCommonParent先调用GetNodePath得到pRoot到达pNode1的路径path1,再得到pRoot到达pNode2的路径path2，
 * 接着调用GetLastCommonPath得到path1和path2的最后一个公共结点，即我们要找的最低公共祖先
 *
 */

// ====================测试代码====================
void Test(const char* testName, const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2, TreeNode* pExpected)
{
	const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2);
	if(testName != nullptr)
		printf("%s begins: ", testName);

	const TreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

	if((pExpected == nullptr && pResult == nullptr) || 
			(pExpected != nullptr && pResult != nullptr && pResult->m_nValue == pExpected->m_nValue))
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1()
{
	TreeNode* pNode1 = CreateTreeNode(1);
	TreeNode* pNode2 = CreateTreeNode(2);
	TreeNode* pNode3 = CreateTreeNode(3);
	TreeNode* pNode4 = CreateTreeNode(4);
	TreeNode* pNode5 = CreateTreeNode(5);
	TreeNode* pNode6 = CreateTreeNode(6);
	TreeNode* pNode7 = CreateTreeNode(7);
	TreeNode* pNode8 = CreateTreeNode(8);
	TreeNode* pNode9 = CreateTreeNode(9);
	TreeNode* pNode10 = CreateTreeNode(10);

	ConnectTreeNodes(pNode1, pNode2);
	ConnectTreeNodes(pNode1, pNode3);

	ConnectTreeNodes(pNode2, pNode4);
	ConnectTreeNodes(pNode2, pNode5);

	ConnectTreeNodes(pNode4, pNode6);
	ConnectTreeNodes(pNode4, pNode7);

	ConnectTreeNodes(pNode5, pNode8);
	ConnectTreeNodes(pNode5, pNode9);
	ConnectTreeNodes(pNode5, pNode10);

	Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5

int main() {
	Test1();
}
