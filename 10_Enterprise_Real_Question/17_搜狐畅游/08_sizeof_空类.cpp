

/*
 * Date:2021-10-26 10:08
 * filename:08_sizeof_空类.cpp
 *
 */

#include <iostream>
using namespace std;

class c {
	public:
		void func() {}
};

int main() {
	printf("%ld\n",sizeof(c));
	return 0;
}
