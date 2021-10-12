

/*
 * Date:2021-10-12 10:29
 * filename:10_static_variable.cpp
 *
 */

#include <iostream>
using namespace std;

class T {
public:
	T() { c++; }
	~T() { c--; }
	static void count() { cout << c << endl; }
	void show1() { c += 2; }
private:
	static int c;

};

int T::c = 0;

int main() {
	T ob1;
	T::count();
	ob1.show1();
	return 0;
}
