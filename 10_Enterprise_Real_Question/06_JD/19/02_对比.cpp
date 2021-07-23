

/*
 * Date:2021-07-23 17:10
 * filename:02_对比.cpp
 *
 */

/*
	 【题目描述】
	 现有n个物品，每个物品有三个参数ai,bi,ci，
	 定义i物品不合格品的依据是：若存在物品j，且aj > ai, bj > bi, cj > ci，则称i物品为不合格品。
	 现给出 n 个物品的 a,b,c 参数，请你求出不合格品的数量。

	 输入描述： 
	 第一行包含一个整数 n(1<=n<=500000),表示物品的数量。接下来有 n 行，每行有三个整数，表示第 i 个物品的三个参数

	 输出描述： 
	 输出包含一个整数，表示不合格品的数量。

	 输入样例： 
	 3
	 1 4 2
	 4 3 2
	 2 5 3

	 输出样例： 
	 1

	 样例解释： 
	 物品 1 的 a,b,c 均小于物品 3 的 a,b,c,因此 1 为不合格品。

*/

/*
 * 解题思路:
 * 三维偏序问题。
 * 先对第一维排序，然后降序处理
 * 对于第二三维，可以用一个平衡树(std::multiset)维护一个外围包络，
 * 这样可以快速判断一个点的右上方有点(使用lower_bound),有的话，即为不合格产品
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 5;
int n;

struct node {
	int a, b, c;
	void read() {
		scanf("%d%d%d", &a, &b, &c);
	}
	bool operator< (const node &rhs) const {
		return a < rhs.a;
	}
}a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		a[i].read();
	}

	sort(a, a + n);
	queue<pair<int, int>> Q;
	int last = -1, ans = 0;
	multiset<pair<int, int>> s;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i].a != last) {
			while(Q.size()) {
				auto u = Q.front();
				Q.pop();
				auto it = s.lower_bound(u);
				if (it == s.end() || it->second < u.second) {
					it = s.insert(u);
					while (it != s.begin()) {
						auto tmp = it;
						--tmp;
						if (tmp->second <= u.second) {
							s.erase(tmp);
						}
						else {
							break;
						}
					}
				}
			}
			last = a[i].a;
		}
		pair<int, int> p(a[i].b, a[i].c);
		auto it = s.lower_bound(p);
		if (it == s.end() || it->second <= p.second) {
			Q.push(p);
		}
		else {
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
