

/*
 * Date:2021-09-05 09:13
 * filename:02_latex爱好者.cpp
 *
 */

/*
 * 
【题目描述】
latex 自然是广大研究人员最喜欢使用的科研论文排版工具之一。
月神想在 iPhone 上查阅写好的 paper，但是无赖 iPhone 上没有月神喜欢使用的阅读软件，
于是月神也希望像 tex 老爷爷 Donald Knuth 那样自己动手 do it yourself 一个。
在 DIY 这个阅读软件的过程中，月神碰到一个问题，已知 iPhone 屏幕的高为 H，宽为 W，
若字体大小为 S(假设为方形），则一行可放 W / S(取整数部分）个文字，一屏最多可放 H / S （取整数部分）行文字。
已知一篇 paper 有 N 个段落，每个段落的文字数目由 a1, a2, a3,...., an 表示，月神希望排版的页数不
多于 P 页（一屏显示一页），那么月神最多可使用多大的字体呢？
1 <= W, H, ai <= 1000
1 <= P <= 1000000

输入描述:
每个测试用例的输入包含两行。
第一行输入 N,P,H,W
第二行输入 N 个数 a1,a2,a3,...,an 表示每个段落的文字个数。

输出描述:
对于每个测试用例，输出最大允许的字符大小 S

备注: :
以上所有输入、输出均为整数。
且所有测试用例均保证有解。
两个段落之前不空行，并且段落顶格写。

输入样例：
1 10 4 3
10

2 10 4 3
10 10

输出样例：
3
2
*/

/*
 * 思路:
 * 二分答案，然后进行可行性判断
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, P, W, H;
int Paragraph[10000];

bool HandleCase();

int main() {
	while (HandleCase()) {

	}


}

bool OK(int S);

bool HandleCase() {
	if (!(cin >> N >> P >> W >> H)) {
		return false;
	}
	for (int i = 0;i < N; ++i) {
		cin >> Paragraph[i];
	}

	int l = 1, r = min(W, H), m;
	while (l < r) {
		m = (l + r) >> 1;
		if (OK(m)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	while (!OK(l)) --l;

	cout << l << endl;
	return true;
}

bool OK(int S) {
	int iEachLine = W / S;
	int iLine = H / S;
	int TotalLine = 0;
	if (iEachLine  <= 0 || iLine <= 0)
		return false;

	for (int i = 0; i < N; ++i) {
		if (iEachLine == 1) {
			TotalLine += Paragraph[i];
		}
		else {
			TotalLine += (Paragraph[i] + iEachLine - 1) / iEachLine;
		}
	}
	return (TotalLine + iLine - 1) / iLine <= P;
}
