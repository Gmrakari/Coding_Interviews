

/*
 * Date:2021-10-28 10:03
 * filename:04_stack_output.cpp
 *
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<string> s;
	s.push("123" + "123");
	cout << s.top();
	return 0;
}
