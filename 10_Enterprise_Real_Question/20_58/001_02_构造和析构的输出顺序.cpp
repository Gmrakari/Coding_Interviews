

/*
 * Date:2021-10-10 19:17
 * filename:001_02_构造和析构的输出顺序.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class A {
public:
	A() { cout << "A";}
	~A() { cout << "~A";}
};

class B : public A {
public:
	B() { cout << "B"; }
	~B() { cout << "~B"; }
};

int main() {
	A *c = new B[2];
	delete[] c;
	return 0;
}
