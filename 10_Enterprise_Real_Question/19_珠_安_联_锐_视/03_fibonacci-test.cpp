

/*
 * Date:2021-09-28 21:00
 * filename:03_fibonacci-test.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

long long calc_fib(int n) {
	if (n <= 0) return 1;
	if (n == 1) return 1;
	return calc_fib(n - 1) + calc_fib(n - 2);
}

long long fib_2(int n) {
	int res[] = {1, 1};
	if (n < 2) {
		return res[n];
	}
	long long fibNMinOne = 1;
	long long fibNminTwo = 1;

	long long fibN = 0;
	for (int i = 2;i <= n; i++) {
		fibN = fibNMinOne + fibNminTwo;
		fibNminTwo = fibNMinOne;
		fibNMinOne = fibN;
	}
	return fibN;
}

long long caler_fib(int n) {
	if (n == 0 || n == 1) return 1;
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

void test() {
	for (int i = 0;i <= 5;i++) {
		cout << calc_fib(i) << endl;
	}
}

void test_2() {
	for (int i = 0; i <= 5; i++) {
		cout << fib_2(i) << endl;
	}

	cout << "caler_fib-test:" << endl;
	for (int i = 0; i <= 5;i++) {
		cout << caler_fib(i) << endl;
	}
}

int main() {
	test();
	cout << "test2:" << endl;
	test_2();
}
