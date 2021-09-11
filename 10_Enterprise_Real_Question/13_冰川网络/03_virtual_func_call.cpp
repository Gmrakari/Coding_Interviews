

/*
 * Date:2021-09-11 10:20
 * filename:03_virtual_func_call.cpp
 *
 */

#include <iostream>

class A {
public:
	virtual void test() { printf("A test\n"); }
};

class B : public A {
public:
	void func() { test(); }
	virtual void test() { printf("B test\n"); }
};

class C : public B {
public:
	virtual void test() { printf("C test\n"); }
};

int main() {
	C c;
	((B*)(&c))->func();
	((B)c).func();
}
