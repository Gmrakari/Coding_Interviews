

/*
 * Date:2021-10-10 20:24
 * filename:001_11_false_true_三目条件运算.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	bool result = false ? false : false == false? true : false;
	cout << result << endl;
}
