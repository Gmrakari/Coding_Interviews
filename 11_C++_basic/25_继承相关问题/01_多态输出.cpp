

/*
 * Date:2021-12-25 22:50
 * filename:01_多态输出.cpp
 *
 */

#include <bits/stdc++.h>
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
		cout << "Wang, my age = " << this->age << endl;
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
	int *p = (int*)(&kitty); //p->(cat)kitty;
	int *q = (int*)(&jd);    //q->(dog)jd;
	p[0] = q[0];						//p = q; // p->(dog)jd;
	pa = &kitty;						//dog::print_age(); 
	pa->print_age();
	return 0;
}

//output:
//Wang, my age = 1
