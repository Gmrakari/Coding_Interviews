

/*
 * Date:2021-10-12 10:40
 * filename:12_缺省函数.cpp
 *
 */

#include <iostream>
using namespace std;

class A {
private:
	int i;
	int j;
public:
	A() {
		i = 0;
		j = 0;
	}
	A(int m, int n) {
		i = m;
		j = n;
	}

	void displayA() {
		cout << i << "," << j << endl;
	}

	A operator-() {
		i = -i;
		j = -j;
		return A(i, j);
	}
};

int main() {
	A a(-5, 11);

	-a;

	a.displayA();
	return 0;
}
