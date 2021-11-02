

/*
 * Date:2021-11-02 19:41
 * filename:09_sizeof_union大小.cpp
 *
 */

#include <iostream>
using namespace std;

union {
	char flag[3];
	short value;
}sampleUnion;

int main() {
	cout << "sizeof(sampleUnion):" << sizeof(sampleUnion) << endl;
}
