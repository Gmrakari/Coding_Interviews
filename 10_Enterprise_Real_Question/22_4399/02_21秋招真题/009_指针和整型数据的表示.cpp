

/*
 * Date:2021-10-22 16:24
 * filename:009_指针和整型数据的表示.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	int *p;

	//*p = *x; // indirection requires pointer operand ('int' invalid)
	//p = x; // assigning to 'int *' from incompatible type 'int'; take the address with & (FixIt)
	//*p = &x; // assigning to 'int' from incompatible type 'int *'; remove & (FixIt)

	p = &x; //ok

}
