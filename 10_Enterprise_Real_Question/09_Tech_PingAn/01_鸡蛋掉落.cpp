

/*
 * Date:2021-08-14 17:10
 * filename:01_鸡蛋掉落.cpp
 *
 */

/*
 * 【题目描述】
你有 K 个鸡蛋，并可以使用一栋从 1 到 N 共有 N 层楼的建筑。每个蛋的功能都是一样的，
如果一个蛋碎了，你就不能再把它掉下去。你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼
层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。每次移动，你可以取一个鸡蛋（如
果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
你的目标是确切地知道 F 的值是多少。无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

输入描述：
输入两个数，（第一个数为 K，第二个数为 N）

输出描述：
返回最小移动次数

输入样例:
1,2

输出样例:
2

*/

/*
 * 动态规划
 * dp[k][n] 表示k个鸡蛋n层楼至少要试几次
 * 枚举丢的楼层i,则dp[k][n] = min(dp[k][n - i], dp[k - 1][i - 1]) (对应没碎与碎)
 *
 */

#include <bits/stdc++.h>
using	namespace std;

const int N = 100 + 5;
const int inf = 0x3f3f3f3f;

int n, k;
int dp[N][N];
int dfs(int k, int n) {
	if (k == 1) {
		return n;
	}

	if (n <= 1) {
		return 0;
	}

	int &ans = dp[k][n];
	if (~ans) return ans;

	for (int i = 1; i <= n; ++i) {
		int tmp = min(dfs(k, n - i), dfs(k - 1, i - 1)) + 1;
		ans = min(ans, tmp);
	}
	return ans;
}

int main() {
	scanf("%d%d", &k, &n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(k, n));
	return 0;
}
