

/*
 * Date:2021-12-02 16:44
 * filename:virtual_fun_继承.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class A {
public:
	virtual void x() = 0;
};

class B : public A {
public:
	virtual void x(int a) {}
};


int main() {
	A *a = new B;
	delete a;
}
