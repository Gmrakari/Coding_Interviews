

/*
 * Date:2021-11-02 19:43
 * filename:10_base_derive_constructor和deconstructor顺序.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class base {
	public:
		base() {
			std::cout << "base construct" << std::endl;
		}
		~base() {
			std::cout << "base deconstruct" << std::endl;
		}
};

class derive : public base {
	public:
		derive() {
			std::cout << "derive construct" << std::endl;
		}
		~derive() {
			std::cout << "derice deconstruct" << std::endl;
		}
};

int main(){
	base *d = new derive();
}
