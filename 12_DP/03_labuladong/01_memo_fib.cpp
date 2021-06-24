

/*
 * Date:2021-06-24 23:00
 * filename:01_memo_fib.cpp
 *
 */

int fib(int N) {
	if ( N < 1 ) return 0;
	vector<int> memo(N + 1, 0);
	return helper(memo, N);
}

int helper(vector<int>& memo, int n) {
	if (n == 1 || n == 2) return 1;
	if (memo[n] != 0) return memo[n];
	memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
	return memo[n];
}


