

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
		printf("Base\n");
	}
};

class Derived : public Base {
public:
	Derived() {
		echo();
	}
	virtual void echo() {
		printf("Derived\n");
	}
};

int main() {
	Base* base = new Derived();
	base->echo();
	return 0;
}

//output:
//Base
//Derived
//Derived

//因为new Derived() 先构造父类的构造函数即Base()中的echo();
//然后构造派生类中的构造函数即Derived::echo();
//然后base是Base*的一个对象，在Base中echo被定义为虚函数，表现出多态，实际上调用的是
//(*(p->vptr)[n])(p) or (*p->vptr[n])(p);
//即Derived::echo();
//Derived::echo(&base)
