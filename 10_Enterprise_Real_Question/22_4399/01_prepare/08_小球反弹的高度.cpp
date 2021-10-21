

/*
 * Date:2021-10-21 17:31
 * filename:08_小球反弹的高度.cpp
 *
 */

/*
 * 一球从100米高度自由落下，每次落地后反跳回原高度的一半；
 * 再落下，求它在第n次落地时，共经过多少米？第n次反弹多高？（n<=10）
 *
 *
 * 思路:
 *  模拟。用两个值分别记录小球总路线长度和每次弹起来的高度。
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		double ans = 100;
		double ans1 = 0;
		while (n) {
			ans1 = ans1 + ans;
			ans = ans / 2;
			n--;
			if (n != 0)
				ans1 = ans1 + ans;
		}

		printf("%.6f %.6f\n", ans1, ans);
	}
	return 0;
}
