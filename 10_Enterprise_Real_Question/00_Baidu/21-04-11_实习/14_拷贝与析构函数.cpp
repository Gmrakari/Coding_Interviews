

/*
 * Date:2021-11-09 20:42
 * filename:14_拷贝与析构函数.cpp
 *
 */

#include <iostream>
using namespace std;

class Base {
	public:
		Base() {
			cout << "Constructing Base\n";
		}
		~Base() {
			cout << "Destructing Base\n";
		}
};

class Derived : public Base {
	public:
		Derived() {
			cout << "Constructing Derived\n";
		}
		~Derived() {
			cout << "Destructing Derived\n";
		}
};

int main() {
	Derived *d = new Derived();
	Base *b = d;
	delete d;
	return 0;
}
