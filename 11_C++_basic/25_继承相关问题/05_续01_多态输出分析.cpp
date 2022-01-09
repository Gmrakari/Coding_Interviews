

/*
 * Date:2022-01-09 22:51
 * filename:05_续01_多态输出分析.cpp
 *
 */

#include <iostream>
using namespace std;

class animal {
protected:
	int age;
public:
	virtual void print_age(void) = 0;
};

class dog : public animal {
public:
	dog() {
		this->age = 2;
	}
	~dog() {

	}

	virtual void print_age(void) {
		cout << "Wang. my age = " << this->age << endl;
	}
};

class cat : public animal {
public:
	cat() {
		this->age = 1;
	}
	~cat() {

	}

	virtual void print_age(void) {
		cout << "Miao, my age = " << this->age << endl;
	}
};

int main() {
	cat kitty;
	dog jd;
	animal *pa;
	int *p = (int *)(&kitty);
	int *q = (int *)(&jd);
	cout << q[1] << endl;
	cout << q[1] << endl;
	p[1] = q[1];
	pa = &kitty;
	pa->print_age();
	return 0;
}
