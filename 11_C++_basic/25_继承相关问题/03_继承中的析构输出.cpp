

/*
 * Date:2022-01-05 10:04
 * filename:03_继承中的析构输出.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class A {
public:
	~A() {
		fprintf(stderr, "A");
	}
};

class B : public A {
public:
	~B() {
		fprintf(stderr, "B");
	}
};

int main(int argc, char *argv[]) {
	B b;
	return 0;
}
