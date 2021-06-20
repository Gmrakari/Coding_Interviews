

/*
 * Date:2021-06-20 21:18
 * filename:01_整数反转求和.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
	int res = 0;
	while (x) {
		if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
		res = res * 10 + x % 10;
		x = x / 10;
	}
	return res;
}

int reverseAdd(int a,int b) {
	int ret = 0;
	return ret = reverse(a) + reverse(b);
}


int main() {
	int a,b;
	cin >> a >> b;
	cout << reverseAdd(a,b) << endl;
	return 0;
}
