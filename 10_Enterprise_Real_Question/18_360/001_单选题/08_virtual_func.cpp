

/*
 * Date:2021-10-12 09:46
 * filename:08_virtual_func.cpp
 *
 */

#include <iostream>
using namespace std;

class B {
public:
	virtual void show() { cout << "$";}
};

class A : public B {
public:
	void show() { cout << "*";}
};

class C : public B {
public:
	void show() {cout << "#";}
};

int main() {
	A d1;
	C d2;
	B p = d1;
	p.show();
	B q = d2;
	q.show();
	cout << endl;
	return 0;
}

