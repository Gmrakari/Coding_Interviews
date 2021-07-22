

/*
 * Date:2021-07-22 15:29
 * filename:02_社团主席选举.cpp
 *
 */

/*
 *

【题目描述】
随着又一届学生的毕业，社团主席换届选举即将进行。
一共有 n 个投票者和 m 个候选人，小易知道每一个投票者的投票对象。
但是，如果小易给某个投票者一些糖果，那么这个投票者就会改变他的意向，小易让他投给谁，他就会投给谁。
由于小易特别看好这些候选人中的某一个大神，这个人的编号是1，所以小易希望能尽自己的微薄之力让他当选主席，
但是小易的糖果数量有限，所以请你帮他计算，最少需要花多少糖果让 1 号候选人当选。
某个候选人可以当选的条件是他获得的票数比其他任何候选者都多。

输入描述:
第一行两个整数 n 和 m，表示投票者的个数和候选人的个数。
接下来 n 行，每一行两个整数 x 和 y，x 表示这个投票者的投票对象，y 表示需要花多少个糖果让这个人改变意向。
满足 1 <= n, m <= 3000，1 <= x <= m，1 <= y <= 109。

输出描述:
一个整数，糖果的最小花费。

输入样例 1：
1 2
1 20

输出样例 1：
0

输入样例 2：
5 5
2 5
3 5
4 5
5 6
5 1

输出样例 2：
6
*/

/*
 * 解题思路
 * 暴力枚举这个人需要多少人支持才能当选，每次枚举时，
 * 超出在这个数量以及和这个数量相等的人一定需要被改变，之后数量不足，再从剩下的人中选择
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3005;
vector<int> G[N];
int vis[N];

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	ll ans = 1e18;
	for (int i = 0;i < n;i++) {
		int p,c;
		scanf("%d%d", &p, &c);
		G[p].push_back(c);
		vis[p]++;
	}

	int mx = 0;
	for (int i = 1;i <= m; i++) {
		if (vis[i] > mx) {
			mx = vis[i];
		}
	}

	int cnt = 0;
	for (int i = 1;i <= m; i++) {
		if (vis[i] == mx) cnt++;
	}

	if (cnt == 1 && vis[1] == mx) return 0*puts("0");
	for (int i = 1; i <= m; i++) sort(G[i].begin(), G[i].end());
	for (int i = n; i >= 1; i--) {
		vector<int> r;
		int num = i - vis[1];
		ll sum = 0;
		for (int j = 1; j <= m; j++) {
			if (vis[j] >= i && j != 1) {
				int tmp = vis[j] - i + 1;
				for (int k = 0; k < min(tmp, (int)G[j].size()); k++) {
					r.push_back(G[j][k]);
				}
			}
		}
		for (int j = 0; j < (int)r.size(); j++) {
			num --;
			sum += r[j];
		}
		if (num <= 0) {
			ans = min(ans, sum);
			continue;
		}
		r.clear();
		for (int j = 1; j <= m; j++) {
			if (vis[j] >= i && j != 1) {
				int tmp = vis[j] - i + 1;
				if (tmp >= (int)G[j].size()) continue;
				for (int k = tmp; k < (int)G[j].size(); k++) {
					r.push_back(G[j][k]);
				}
			}
		}
		for (int j = 1; j <= m; j++) {
			if (vis[j] < i && j != 1) {
				for (int k = 0; k < (int)G[j].size(); k++) {
					r.push_back(G[j][k]);
				}
			}
		}
		sort(r.begin(), r.end());
		for(int j = 0; j < (int)r.size(); j++) {
			num--;
			sum += r[j];
			if (num <= 0) break;
		}
		if (num <= 0) ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
