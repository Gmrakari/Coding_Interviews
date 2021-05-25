
/*
 * Date:2021-05-25 22:45
 * filename:4.cpp
 *
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MyStack {
public:
	void push(int x) {
		stack1.push(x);	
	}
	void transfer(stack<int>& in,stack<int>& out) {
		while(!in.empty()) {
			out.push(in.top());
			in.pop();
		}
	}
	int pop() {
		transfer(stack1,stack2);
		int node = stack2.top();
		stack2.pop();
		return node;
	}
	bool empty() {
		return (stack1.empty() && stack2.empty()); 
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main() {
	MyStack sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);

	while(!sta.empty()) {
		cout << sta.pop() << ' ';
	} 
	cout << endl;
	return 0;
}
