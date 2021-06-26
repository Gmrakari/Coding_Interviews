

/*
 * Date:2021-06-26 15:29
 * filename:06_xiaoQgedan.cpp
 *
 */

/*
 *


小Q有X首长度为A的不同的歌和 Y首长度为B的不同的歌，现在小Q想用这些歌
组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，在不考
虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法

输入描述: 
每个输入包含一个测试用例。
每个测试用例的第一行包含一个整数，表示歌单的总长度
K(1<=K<=1000)

接下来的一行包含四个正整数，分别表示歌的第一种长度 A(A<=10)和数量
X(X<=100)以及歌的第二种长度 B(B<=10)和数量 Y(Y<=100)。保证 A 不等于B

输出描述: 
输出一个整数,表示组成歌单的方法取模。
因为答案可能会很大,输出对1000000007取模的结果

输入例子 1: 

5 
2 3 3 3

输出例子 1: 
9

*/

/*
 * 详解:
 * 01背包问题
 * 问题转化为有x + y种物品，其中x种的容积为a,y种的容积为b,背包容积为k
 * 问背包装满一共有多少种解法?
 */

#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int a, x, b, y, k;
long long dp[1010];
int p[210];
int main() {
	scanf("%d", &k);
	scanf("%d%d%d%d", &a, &x, &b, &y);
	dp[0] = 1;
	for (int i = 1; i <= x;i++) p[i] = a;
	for (int i = x + 1;i <= x + y;i++) p[i] = b;
	for (int i = 1; i <= x + y;i++) {
		for (int j = k;j >= p[i];j--) 
			dp[j] = (dp[j] % mod + dp[j - p[i]] % mod) %mod;
	}
	printf("%lld\n",dp[k] % mod);
	return 0;
}
