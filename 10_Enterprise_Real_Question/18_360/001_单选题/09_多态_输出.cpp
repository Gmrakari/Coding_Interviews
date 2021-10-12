

/*
 * Date:2021-10-12 10:18
 * filename:09_多态_输出.cpp
 *
 */

#include <iostream>
using namespace std;

void Max();
void Max(int a) {
	cout << "1" << endl;
}

void Max(const char* a, const char* b) {
	cout << "2" << endl;
}

void Max(double a, double = 1.2) {
	cout << "3" << endl;
}

int main() {
	Max(2.4);
	return 0;
}
