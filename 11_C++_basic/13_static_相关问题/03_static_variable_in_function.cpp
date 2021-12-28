

/*
 * Date:2021-12-28 10:43
 * filename:03_static_variable_in_function.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

unsigned int GetTestNum() {
	static unsigned int a = 0;
	static unsigned int b = 1;

	int c = a + b;
	a = b;
	b = c;
	return c;
}

int main(int argc, char* argv[]) {
	for (int i = 0;i < 9; i++) {
		GetTestNum();
	}
	cout << GetTestNum() << endl;
}
