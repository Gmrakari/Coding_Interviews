

/*
 * Date:2021-10-19 21:11
 * filename:01_有效的括号.cpp
 *
 */


/*
 * Leetcode 20.有效的括号
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

 * 有效字符串需满足：

 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 * 
 示例 1：

 输入：s = "()"
 输出：true

 示例 2：

 输入：s = "()[]{}"
 输出：true

 示例 3：

 输入：s = "(]"
 输出：false

 示例 4：

 输入：s = "([)]"
 输出：false
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isValid(string s) {
			int n = s.size();
			if (n % 2 == 1) {
				return false;
			}

			unordered_map<char, char> pairs = {
				{')', '('},
				{']', '['},
				{'}', '{'}
			};

			stack<char> stk;
			for (char ch : s) {
				//在pairs容器中查找以ch键的键值对的个数。
				if (pairs.count(ch)) {
					if (stk.empty() || stk.top() != pairs[ch]) {
						return false;
					}
					stk.pop();
				}
				else {
					stk.push(ch);
				}
			}
			return stk.empty();
		}
};

namespace m_stack {
	class Solution {
		public:
			bool isValid(string s) {
				stack<char> stk;
				for (auto c : s) {
					if (c == '(' || c == '{' || c == '[') stk.push(c);
					else if (c == ')' && stk.size() && stk.top() == '(')
						stk.pop();
					else if (c == '}' && stk.size() && stk.top() == '(')
						stk.pop();
					else if (c == ']' && stk.size() && stk.top() == '(')
						stk.pop();
					else 
						return false;
				}
				return stk.size() == 0;
			}
	};
}
