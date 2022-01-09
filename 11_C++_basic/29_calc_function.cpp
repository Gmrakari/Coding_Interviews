

/*
 * Date:2022-01-09 23:09
 * filename:29_calc_function.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int n = 300;
int solve(int x) {
	return x * (n - x);
}

int Function(unsigned int n) {
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
		return n;
}


int main() {
	int l = 1, r = n;
	int mid1, mid2;
	int t = 50;
	while (t--) {
		mid1 = l + (r >> 1);
		mid2 = mid1 + (r >> 1);
		if (solve(mid1) > solve(mid2)) {
			r = mid2;
		}
		else {
			l = mid1;
		}
	}
	cout << l << endl;
	int k = 1^((1 << 31) >> 31);
	cout << k << endl;

	cout << "Function call:" << Function(197) << endl;
	return 0;
}
