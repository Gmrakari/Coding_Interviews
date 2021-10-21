

/*
 * Date:2021-10-21 17:37
 * filename:09_环形出队.cpp
 *
 */

/*
 * 有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来第几号的那位。
 *
 * 思路： 也是模拟。用一个struct标记每个值，如果数到3时是这个数字，则标记为0，最后输出是1的数字即可。
 *
 */

#include <iostream>
using namespace std;

struct r {
	int num;
	int z;
}a[1000001];

int main() {
	int n;
	while (cin >> n) {
		if (n == 1) {
			cout << 1 << endl;
			break;
		}
		for (int i = 1; i <= n;i++) {
			a[i].num = i;
			a[i].z = 1;
		}
		int t = 0;
		int i = 1;
		int c = 1;
		while (t < n - 1) {
			if (a[i].z == 0) {
				i++;
				if (i == n + 1)
					i = 1;
				continue;
			}
			if (c == 3) {
				a[i].z = 0;
				t++;
				c = 0;
			}
			i++;
			c++;
			if (i == n + 1)
				i = 1;
		}
		for (int i = 1;i <= n;i++) {
			if (a[i].z == 1) {
				cout << a[i].num << endl;
				break;
			}
		}
	}
	return 0;
}
