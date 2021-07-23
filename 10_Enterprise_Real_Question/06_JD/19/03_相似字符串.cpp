

/*
 * Date:2021-07-23 17:31
 * filename:03_相似字符串.cpp
 *
 */

/*
 *

【题目描述】
对于仅由小写字母组成的字符串 A 和 B，如果存在一个小写字母 a 到 z 的排列，
使得将 A 中所有字母 a 替换为排列的第一个字母，所有字母 b 替换为排列的第二个字母……
所有字母 z 替换为排列的最后一个字母之后，A 和 B 完全相同，那么称字符串 A 和 B 相似，如 abcc 和 xyaa。
现在给定仅由小写字母组成且长度不超过 105 的字符串 S 和 T，求 S 中有多少子串与 T 相似？

输入描述：
第一行和第二行分别输入字符串 S 和 T。

输出描述：
输出字符串 S 中与 T 相似的子串数目。

输入样例：
ababcb
xyx

输出样例：
3

样例解释：
S 中与 T 相似的子串分别是 aba、bab、bcb，总共 3 个。

*/

/*
 * 解题思路:
 * 统计T的每个字符的数量,存为长26的vector,排序后，作为模式串。
 * 使用滑动窗口统计S中长度为|T|的字串中每种字符的数量，拷贝一份并排序后，与模式串相同既算匹配成功
 * 复杂度O(|S|*26*long26)
 *
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;
int n, m;
char s[N], t[N];
int main() {
	scanf("%s%s", s, t);
	n = strlen(s);
	m = strlen(t);
	if (n < m) {
		puts("0");
		return 0;
	}

	vector<int> cnt(26), ptn(26);
	for (int i = 0; i < m; ++i) {
		++cnt[s[i] - 'a'];
		++ptn[t[i] - 'a'];
	}

	sort(ptn.begin(), ptn.end());
	int ans = 0;
	for (int i = m; i < n; ++i) {
		vector<int> tmp = cnt;
		sort(tmp.begin(), tmp.end());
		if (tmp == ptn) ++ans;
		++cnt[s[i] - 'a'];
		--cnt[s[i - m] - 'a'];
	}
	vector<int> tmp = cnt;
	sort(tmp.begin(), tmp.end());
	if (tmp == ptn) ++ans;
	printf("%d\n", ans);
	return 0;
}
