

/*
 * Date:2021-07-22 13:25
 * filename:22_栈的压入弹出序列.cpp
 *
 */

/*
#题意
题目描述

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。

假设压入栈的所有数字均不相等。

例如序列1,2,3,4,5是某栈的压入顺序，

序列4，5,3,2,1是该压栈序列对应的一个弹出序列，

但4,3,5,1,2就不可能是该压栈序列的弹出序列。
*/


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 * 解法一:
 * 如果下一个弹出的数字刚好是栈顶数字，那么直接弹出。
 * 如果下一个弹出的数字不在栈顶，我们把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止。
 * 如果所有的数字都压入栈了仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列
 *
 */

bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
	bool bPossible = false;

	if (pPush != NULL && pPop != NULL && nLength > 0) {
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;
		while(pNextPop - pPop < nLength) {
			while(stackData.empty() || stackData.top() != *pNextPop) {
				if (pNextPush - pPush == nLength)
					break;

				stackData.push(*pNextPush);

				pNextPush++;
			}

			if (stackData.top() != *pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}
		if (stackData.empty() && pNextPop - pPop == nLength) 
			bPossible = true;
	}
	return bPossible;
}

/*
	 模拟法：

	 1、初始化：用指针i指向pushV的第一个位置，指针j指向popV的第一个位置
	 2、如果pushV[i] != popV[j],那么应该将pushV[i]放入栈中,++i;
	 3、否则，pushV[i] == popV[j],说明这个元素是放入栈中立马弹出,所以,++i,++j，
	 然后应该检查popV[j]与栈顶元素是否相等，如果相等，++j，并且弹出栈顶元素

	 4、重复2,3，如果 i == pushV.size()，说明入栈序列访问完，此时检查栈是否为空，如果为空
	 说明匹配，否则不匹配。

*/

class Solution {
	public:
		bool IsPopOrder(vector<int> pushV,vector<int> popV) {

			stack<int> stack;
			int i = 0, j = 0;
			while( i < (int)pushV.size()){
				if(pushV[i] != popV[j]){
					stack.push(pushV[++i]);
				}else{
					++i,++j;
					while (!stack.empty() && stack.top() == popV[j]){
						stack.pop();
						j++;
					}
				}
			}
			return stack.empty();
		}
};

class Solution_2 {
	public:
		bool IsPopOrder(vector<int> pushV,vector<int> popV) {

			if(pushV.size() == 0 || popV.size() == 0) return false;

			vector<int> stack;
			for(int i = 0,j = 0; i < (int)pushV.size();){
				stack.push_back(pushV[i++]);
				while( j < (int)popV.size() && stack.back() == popV[j]){
					stack.pop_back();
					j++;
				}
			}
			return stack.empty();
		}
};

