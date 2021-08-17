

/*
 * Date:2021-08-17 11:45
 * filename:02_商品交易.cpp
 *
 */

/*
 * 【题目描述】
珐达采下个月要去鸥洲各国考察一趟，采购流通神秘石并从中搞点油水。
珐达采会按顺序依次经过序号分别为 1, 2, 3, …,n 的鸥洲国家，
在第 i 个国家神秘石的流通价格为 Ai 鸥。因为行程紧张，在每个国家的停留时间有限，
所以他只能花费 Ai 鸥买入一块神秘石，或者卖出一块手中的神秘石获得 Ai 鸥，
或者什么都不做，而且因为神秘石的保存需要极其先进的高级材料容器，其材料稀有且制作困难，
珐达采只有一份容器，故无论何时珐达采手里最多只能拥有一块神秘石。
珐达采想知道最终能从中获利最大多少鸥。因为交易需要手续费，所以珐达采还想知道在获利最大收益的
同时，最少需要交易多少次。因为珐达采是大财阀，所以你可以认为他一开始金钱无限。

输入描述：
第一行一个数 n。（1≤n≤100000）
第二行 n 个数，第 i 个数表示 Ai。（1≤Ai≤1e9）

输出描述：
共一行，两个数，分别代表最大收益和对应的最少交易次数。

输入样例：
5
9 7 10 1 5

输出样例：
7 4

买入一次9      max = -9
卖出9 买入7 2  max = -9 + 2 = -7
卖出7 买入10 -3 max = -7 - 3 = -10
卖出10 买入1 9 max = 
卖出1 买入5 -4
9 + 2 - 7 + 9
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;
LL f[N];
int g[N];
int n;

int main() {
	scanf("%d", &n);
	LL p = -(1LL << 60), tran = 0, x = 0, ans = 0, anst = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		if (p + x > 0) 
			f[i] = p + x, g[i] = tran + 2;
		else
			f[i] = g[i] = 0;
		LL ptmp = ans - x, ttmp = anst;
		if (ptmp > p || (ptmp == p && ttmp < tran)) {
			p = ptmp;
			tran = ttmp;
		}
		if (f[i] > ans || (f[i] == ans && g[i] < anst)) {
			ans = f[i];
			anst = g[i];
		}
	}
	cout << ans << ' ' << anst << endl;
	return 0;
}
