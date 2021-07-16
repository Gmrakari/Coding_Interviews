

/*
 * Date:2021-05-21 18:46
 * filename:04_nixudui.cpp
 *
 */

/*
 * 作为程序员的小 Q，他的数列和其他人的不太一样，他有2^n个数
 * 老板问了小 Q 一共 m 次，每次给出一个整数q^i(1 <= i <= m), 要求小Q把这些数
 * 每2^q*i分为一组，然后把每组进行翻转，小Q想知道每次操作后整个序列中的逆序对个数是多少呢?
 *
 *
 * 例如:
 * 对于序列 1 3 4 2，逆序对有(4, 2),(3, 2),总数量为 2。
 * 翻转之后为 2 4 3 1，逆序对有(2, 1),(4, 3), (4, 1), (3, 1),总数量为4。
 *
 * 输入描述:
 * 第一行一个数n
 * 第二行2^n个数，表示初始的序列(1 <= 初始化序列 <= 10^9 )
 * 第三行一个数m
 * 第四行m个数表示q^i
 *
 * 输出描述:
 * m 行每行一个数表示答案。
 *
 *
 * 输入例子:
 * 2
 * 2 1 4 3
 * 4
 * 1 2 0 2
 *
 * 输出例子:
 * 0
 * 6
 * 6
 * 0
 *
 * 例子1说明
 * 初始序列 2 1 4 3
 * 2 ^q1 = 2->
 * 第一次:1 2 3 4 -> 逆序对数为0
 * 2^q2 = 4->
 * 第二次:4 3 2 1 -> 逆序对数为6
 * 2^q3 = 1->
 * 第三次: 4 3 2 1 -> 逆序对数为6
 * 2^q4 = 4->
 * 第四次:1 2 3 4 -> 逆序对数为0
 */

/*
 * 分治
 * 所有2^i上的逆序对，只要记录2i - 1 和另一半2*i - 1 之间的逆序对，
 * 例如2341里面，2^1上有一个,2^2上一共3个,但是有一个在2^1中算过了，所以就是2个
 *
 *
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;
typedef long long LL;
const int inf = 0x3f3f3f3f;
LL sum[22][2];
int n,a[1 << 21];

void dfs(int l, int r, int deep) {
	if(l >= r)
		return ;
	int mid = (l + r) >> 1;
	dfs(l, mid, deep - 1);
	dfs(mid + 1, r, deep -1);
	for (int i = l; i <= mid; i++) {
		int temp = lower_bound(a + mid + 1, a + r + 1, a[i]) - ( a + mid + 1 );
		sum[deep][0] += (LL)temp;
		temp = r - mid - (upper_bound(a + mid + 1, a + r + 1, a[i]) - (a + mid + 1));
		sum[deep][1] += (LL)temp;
	}
	sort(a + l, a + r + 1);
}

int main() {
	scanf("%d",&n);
	int y = (1 << n);
	for (int i = 1; i <= y; i++) scanf("%d", a + i);
	dfs(1, y, n);
	int q,x;
	scanf("%d",&q);
	while (q--) {
			scanf("%d",&x);
			while (x) {
				swap(sum[x][0],sum[x][1]);
				x--;
			}
			LL ans = 0;
			for (int i = 1; i <= n; i++) ans += sum[i][0];
			printf("%lld\n",ans);
		}
		return 0;
}
