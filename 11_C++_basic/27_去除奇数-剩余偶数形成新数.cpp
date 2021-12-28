

/*
 * Date:2021-12-26 09:10
 * filename:te.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

unsigned long fun(unsigned long n) {
	unsigned long x = 0;
	int t;
	while (n) {
		t = n % 10;
		if (t % 2 == 0) 
			x = x * 10 + t;
		n = n / 10;
	}
	return x;
}

int main() {
	cout << fun(23520) << endl;
}
