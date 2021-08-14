

/*
 * Date:2021-08-14 17:18
 * filename:02_水壶问题.cpp
 *
 */

/*
 *

【题目描述】
有两个容量分别为 x 升和 y 升的水壶以及无限多的水。
请判断能否通过使用这两个水壶，从而可以得到恰好 z 升的水？
如果可以，最后请用以上水壶中的一或两个来盛放取得的 z 升水。

你允许进行以下三种操作：
1.装满任意一个水壶
2.清空任意一个水壶
3.从一个水壶向另外一个水壶倒水，直到装满或者倒空

输入描述：
三个数

输出描述：
布尔格式 True/False

*/

/*
 * dfs 枚举所有操作
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;
const int inf = 0x3f3f3f3f;
int x, y, z;
int vis[N][N];

int dfs(int a, int b) {
	if (a == z || b == z) {
		return 1;
	}

	vis[a][b] = 1;
	int ans = 0;
	if (!vis[x][b]) {
		ans |= dfs(x, b);
	}

	if (!vis[a][y]) {
		ans |= dfs(a, y);
	}

	if (!vis[x][0]) {
		ans |= dfs(x, 0);
	}

	if (!vis[0][y]) {
		ans |= dfs(0, y);
	}

	int pour = min(b, x - a);
	int na = a + pour;
	int nb = b - pour;

	if (!vis[na][nb]) {
		ans |= dfs(na, nb);
	}

	pour = min(a, y - b);
	na = a - pour;
	nb = b + pour;


	if (!vis[na][nb]) {
		ans |= dfs(na, nb);
	}
	return ans;
}


int main() {
	scanf("%d%d%d", &z, &x, &y);
	puts(dfs(0,0) ? "True" : "False");
	return 0;
}
