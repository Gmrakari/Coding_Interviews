

/*
 * Date:2021-09-05 08:57
 * filename:01_魔法深渊.cpp
 *
 */

/*
 * 【题目描述】
前几个月放映的头号玩家简直火得不能再火了，作为一个探索终极 AI 的研究人员，月神自然去看了此神剧。
由于太过兴奋，晚上月神做了一个奇怪的梦，月神梦见自己掉入了一个被施放了魔法的深渊，月神想要爬上此深渊。
已知深渊有 N 层台阶构成（1 <= N <= 1000)，并且每次月神仅可往上爬 2 的整数次幂个台阶(1、2、4、....)，
请你编程告诉月神，月神有多少种方法爬出深渊

输入描述:
输入共有 M 行，(1<=M<=1000)
第一行输入一个数 M 表示有多少组测试数据，
接着有 M 行，每一行都输入一个 N 表示深渊的台阶数

输出描述:
输出可能的爬出深渊的方式
备注:
为了防止溢出，可将输出对 10^9 + 3 取模

输入样例：
4
1
2
3
4

输出样例：
1
2
3
6
*/

/*
 * 思路:
 * 第6个台阶可以从2,4,5一次性到达，把dp[2],dp[3],dp[4],dp[5]求和即可
 * 第1000个台阶可以从488(1000 - 512), 744(1000 - 256),...,999一次性到达，把dp[488]+...+dp[999]求和即可
 *
 */
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long lld;
const lld MOD = 1000000003;

vector<lld> P2;

lld Ans[1001];

void CalcValue();

int main() {
	CalcValue();
	int iCase;
	cin >> iCase;
	int n;
	while (iCase--) {
		cin >> n;
		cout << Ans[n] << endl;
	} 
}

void CalcValue() {
	for (int i = 0; i < 10; ++i) {
		P2.push_back(1 << i);
	}

	Ans[0] = 1;
	for (int i = 1; i < 1001; ++i) {
		Ans[i] = 0;
		for (int j = 0; j < (int)P2.size(); ++j) {
			if ((int)P2[j] > i) {
				break;
			}
			Ans[i] += Ans[i - P2[j]];
			Ans[i] %= MOD;
		}
	}
}

