

/*
 * Date:2021-07-28 18:00
 * filename:02_计算原子的个数.cpp
 *
 */

/*
 *
【题目描述】
给出一个字符串格式的化学分子式，计算原子的个数
每个化学元素都是由一个大写字母，或者一个大写字母后跟着若干个小写字母组成，
例如 H 是一个化学元素，Mg 也是一个化学元素。
每个分子式中，原子的个数写在元素后面，如果原子个数是 1，那么原子个数省略。
例如 H2O 和 H2O2 都是有效的分子式，但 H1O2 不是有效分子式。
每个分子式中包含若干括号，为简单起见，分子式中只有小括号。
每次输入一个分子式，对每个给定的分子式，求出每个原子的个数，按照原子字母表的顺序排列，并输出。

输入描述:
输入分子式为
H2O
Mg(OH)2
K4(ON(SO3)2)2

输出描述:
分别输出
H2O
H2MgO2
K4N2O14S4

输入样例:
K4(ON(SO3)2)2
输出样例:
K4N2O14S4

*/

#include <bits/stdc++.h>
using namespace std;

string countOfAtoms(string formula) {
	string res = "";
	stack<map<string, int>> st;
	map<string, int> cur;
	int n = formula.size(), pos = 0;

	while (pos < n) {
		if (formula[pos] == '(') {
			++pos;
			st.push(move(cur));
		}
		else if (formula[pos] == ')') {
			int i = ++pos;
			while (pos < n && isdigit(formula[pos])) 
				++pos;
			int multiple = stoi(formula.substr(i, pos - i));
			for (auto a : cur)
				st.top()[a.first] += a.second * multiple;
			cur = move(st.top());
			st.pop();
		}
		else {
			int i = pos++;
			while (pos < n && islower(formula[pos]))
				++pos;
			string elem = formula.substr(i, pos - i);
			i = pos;
			while (pos < n && isdigit(formula[pos]))
				++pos;
			string cnt = formula.substr(i, pos - i);
			cur[elem] += cnt.empty() ? 1 : stoi(cnt);
		}
	}

	for (auto a : cur) 
		res += a.first + (a.second == 1 ? "" : to_string(a.second));

	return res;
}

int main() {
	string formula, result;
	cin >> formula;

	result = countOfAtoms(formula);
	cout << result << endl;
	return 0;
}
