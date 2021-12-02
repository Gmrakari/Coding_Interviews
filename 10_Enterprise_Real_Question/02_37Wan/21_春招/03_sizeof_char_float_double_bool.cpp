

/*
 * Date:2021-12-02 17:03
 * filename:03_sizeof_char_float_double_bool.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct x {
	char a;//1 ->4
	float b; //4
	double c;//8
	bool d; //1 ->4
};

//4 + 4 + 8 + 4 = 20 + 4 -->24

int main() {
	cout << sizeof(x) << endl;
}
