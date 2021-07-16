

/*
 * Date:2021-07-16 11:50
 * filename:02_字符串计数.cpp
 *
 */

/*
 * 
【题目描述】
给定一个仅由小写字母组成且长度不超过 106 的字符串，将首字符移到末尾并记录所得的字符串，
不断重复该操作，虽然记录了无限个字符串,但其中不同字符串的数目却是有限的，那么一共记录
了多少个不同的字符串？

输入描述:
输入给定的字符串。

输出描述:
输出记录的不同字符串的数目。

输入样例:
abab

输出样例:
2

*/

/*
 *【解题思路】
 利用 kmp 算法的next数组，可以求出字符串的最小循环周期T
 也可以将字符串在后面复制一次，用字符串hash和std::map统计
 */

#include <bits/stdc++.h>
#define N 1000007
using namespace std;
char s[N];
int nxt[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	nxt[0] = -1;
	for (int i = 0,j = -1; i < n;) {
		if (j == -1 || s[i] == s[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	if (n % (n - nxt[n])) printf("%d", n);
	else printf("%d", n - nxt[n]);
}



