

/*
 * Date:2021-07-22 15:46
 * filename:03_香槟塔.cpp
 *
 */

/*
 *

【题目描述】
节日到啦，牛牛和妞妞邀请了好多客人来家里做客。
他们摆出了一座高高的香槟塔，牛牛负责听妞妞指挥，往香槟塔里倒香槟。
香槟塔有个很优雅的视觉效果就是如果这一层的香槟满了，就会从边缘处往下一层流去。
妞妞会发出两种指令，指令一是往第 x 层塔内倒体积为 v 的香槟，指令二是询问第 k 层塔香槟的体积为多少。
告诉你香槟塔每层香槟塔的初始容量，你能帮牛牛快速回答妞妞的询问吗？

输入描述:
第一行为两个整数 n，m。表示香槟塔的总层数和指令条数。
第二行为n个整数 ai，表示每层香槟塔的初始容量。
第三行到第 2+m 行有两种输入，一种输入是"2 x v"表示往第 x 层倒入体积为 v 的香槟；
另一种输入是"1 k"表示询问第 k 层当前有多少香槟。

1 <= n, m <= 1000。
1 <= n ,m <= 200000，1 <= ai ,v <= 1000000000。

输出描述:
对于每个询问，输出一个整数，表示第 k 层香槟的容量。

输入样例 1：
1 2
8
2 1 9
1 1

输出样例 1：
8

输入样例 2：
5 4
1 2 2 10 1
1 3
2 2 5
2 4 3
1 4

输出样例 2：
0
4
 *
*/

/*
 * 解题思路
 * 每层塔建立一个mark标记指向离他最近的未装满的曾，执行2操作时对当前层的mark进行添加，
 * 如果加满移至下一个mark.使用并查集路径压缩的思想不断把mark下移。执行1操作时直接输出结果
 *
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200015;
int mark[MAXN], a[MAXN], b[MAXN];
int _find(int x) {
	if (x == 0) return x;
	if (a[x] != b[x]) return x;
	return mark[x] = mark[x + 1] = _find(mark[x + 1]);
}

int main() {
	int n, m, x, y, d;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[i] = 0;
		mark[i] = i;
	}
	int op;
	while (m--) {
		scanf("%d", &op);
		if (op == 2) {
			scanf("%d%d", &x, &y);
			while(y) {
				x = _find(x);
				if (x == 0) break;
				d = min(a[x] - b[x], y);
				b[x] += d;
				y -= d;
			}
		}
		else {
			scanf("%d", &x);
			printf("%d\n", b[x]);
		}
	}
	return 0;
}

