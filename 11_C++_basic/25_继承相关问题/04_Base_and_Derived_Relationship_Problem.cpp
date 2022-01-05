

/*
 * Date:2022-01-05 10:37
 * filename:04_Base_and_Derived_Relationship_Problem.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Base {
public:
	Base() {
		echo();
	}
	virtual void echo() {
		printf("Base");
	}
};

class Derived : public Base {
public:
	Derived() {
		echo();
	}
	virtual void echo {
		printf("Derived");
	}
};

int main() {
	Base* base = new Derived();
	base->echo();
	return 0;
}
