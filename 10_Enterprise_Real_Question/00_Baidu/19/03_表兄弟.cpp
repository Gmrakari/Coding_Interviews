

/*
 * Date:2021-07-16 12:00
 * filename:03_表兄弟.cpp
 *
 */

/*
【题目描述】

每个人的家族关系可以表示成为一棵树，显而易见，家族关系中不会有环的存在。
假设家族关系树中的每条边的权值都为 1， 我们称 x 是 y 的 k 祖先，
当且仅当在家族关系树中 x 是 y 的祖先且 x 到y 的距离是 k。
我们称 x 和 y 为 k 表兄弟，当且仅当 x 和 y 的 k 祖先为同一人。 
现在给出一个家族关系，共有 n 个家族成员，因为历史记录的缺失，
所有可能并不知道有些人的父亲是谁(最后的结果可能是 若干个树)，给出 m 个询问，
每个询问包含一个 x 和一个 k，请你找出 x 成员的 k 表兄弟的数量。

输入描述:
输入第一行是一个整数 n(1≤n≤105）表示家族关系树中成员数量。
第二行有 n 个数，中间用空格隔开，第 i 个数 fi 表示 i 号成员的父亲为fi，
如果 fi 为 0，表示不知道 i 号成员父亲是谁。第三行包含一个整数 m(1≤m≤105),表示询问的数量。
接下来有 m 行，每行有两个正整数 x，k，中间用空格隔开，表示
询问 x 成员的 k 表兄弟有多少个。

输出描述:
对于每一个询问，输出一个整数，表示 x 成员的 k 表兄弟数量，中间用空格隔开。

输入样例:
10
0 1 2 0 1 5 6 3 3 0
1 0
9 1
5 4
2 2
10 1
8 4
7 1
3 2
5 2
4 2
3 1

输出样例:
1 0 0 0 0 0 1 0 0 0

*/

/*
 * 利用倍增法可以在O(logn)的时间内找到u点的k祖先anc.
 * 问题转化为求anc的所有k后代
 *
 * 可以先求出这个森林的dfs序,然后将同一深度的点存到一个std::vector中
 * 对于一个祖先anc,在深度为dep[u]的vector中二分查找in[anc]和out[anc]，即可求得所有的k后代
 * 减去u本身就是u的k表兄弟数量
 *
 */
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+20;
vector<int> v[N],d[N];
int n, m, pa[N], par[N][23], h[N], st[N], fi[N], x1, y2, x, y, p, cnt = 0;

void dfs(int s) {
	int y;
	st[s]=++cnt;
	d[h[s]].push_back(st[s]);
	for (int i = 0;i < (int)v[s].size();i++) {
		y = v[s][i];
		h[y] = h[s] + 1;
		dfs(y);
	}
	fi[s] = cnt;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pa[i];
		if (pa[i] != 0) {
			v[pa[i]].push_back(i);
			par[i][0] = pa[i];
		}
		else
			par[i][0] = i;
	}
	cnt = 0;
	for (int i = 1;i <= n; i++) {
		if (pa[i] == 0) {
			h[i] = 0;
			dfs(i);
		}
	}

	for (int i = 1;i <= 20; i++) {
		for (int j = 1; j <= n;j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
	cin >> m;
	for (int i = 1;i <= m; i++) {
		cin >> x >> p;
		y = x;
		for (int j = 20; j >= 0; j--) {
			if (p & (1 << j))
				y = par[y][j];
		}
		if (h[x] - p < 0) {
			cout << 0 << ' ';
			continue;
		}
		x1 = st[y];
		y2 = fi[y];
		x1 = lower_bound(d[h[x]].begin(), d[h[x]].end(), x1) - d[h[x]].begin();
		y2 = lower_bound(d[h[x]].begin(), d[h[x]].end(), y2) - d[h[x]].begin();
		x1 = y2 - x1 - 1;
		cout << x1 << ' ';
	}
	return 0;
}
