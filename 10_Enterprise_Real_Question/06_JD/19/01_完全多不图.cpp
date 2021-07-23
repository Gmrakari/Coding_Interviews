

/*
 * Date:2021-07-23 16:56
 * filename:01_完全多不图.cpp
 *
 */

/*
	 1、完全多部图
	 【题目描述】
	 给定一张包含 N 个点、M 条边的无向图，每条边连接两个不同的点，且任意两点间最多只有一条边。
	 对于这样的简单无向图，如果能将所有点划分成若干个集合，使得任意两个同一集合内的点之间没有边相连，
	 任意两个不同集合内的点之间有边相连，则称该图为完全多部图。现在你需要判断给定的图是否为完全多部图。

	 输入描述：
	 包含多组数据，每组输入格式为：
	 第一行包含两个整数 N 和 M，1≤N≤1000，0≤M≤N(N-1)/2；
	 接下来 M 行，每行包含两个整数 X 和 Y，表示第 X 个点和第 Y 个点之间有一条边，1≤X，Y≤N。

	 输出描述：
	 每组输出占一行，如果给定的图为完全多部图，输出 Yes，否则输出 No。

	 输入样例：
	 5 7
	 1 3
	 1 5
	 2 3
	 2 5
	 3 4
	 4 5
	 3 5

	 输出样例：
	 Yes
	 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int n, m;
int a[N][N];

int belong[N], cnt;

int main() {
	scanf("%d%d", &n, &m);
	while(m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = 1;
	}
	for (int u = 1; u <= n; ++u) {
		if (belong[u]) continue;
		belong[u] = ++cnt;
		for (int v = u + 1; v <= n; ++v) {
			if (!a[u][v]) {
				if (belong[v] != 0) {
					puts("No");
					return 0;
				}
				belong[v] = cnt;
			}
		}
	}
	for (int u = 1; u <= n; ++u) {
		for (int v = u + 1; v <= n; ++v) {
			if (belong[u] == belong[v] && a[u][v] ||
					belong[u] != belong[v] && !a[u][v]) {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	return 0;
}
