

#include <bits/stdc++.h>

using namespace std;

int fib(int n) {

	if ( n == 0 || n == 1) {
		return n;
	}
	
	int res = 0;
	vector<int> vec(1000);
	vec[0] = 1;
	vec[1] = 1;
	
	for (int i = 2;i < n;i++) {
		vec[i] = vec[i - 1] + vec[i - 2];
		res = vec[i];
	}
	return res;
}

int main() {
	for (int i = 1; i < 10; i++) {
		cout << i << "\t" << fib(i) << endl;
	}
	cout << endl;
}
