

/*
 * Date:2021-06-30 22:40
 * filename:5.cpp
 *
 */
#include <iostream>
#include <stack>
using namespace std;

class m_Stack {
public:
	void push(int x) {
		in_stack.push(x);
	}
	void transfer(stack<int>& in_stack, stack<int>& out_stack) {
		while(!in_stack.empty()) {
			out_stack.push(in_stack.top());
			in_stack.pop();
		}
	}

	int pop() {
		transfer(in_stack, out_stack);
		int tmp = out_stack.top();
		out_stack.pop();
		return tmp;
	}

	bool empty() {
		return (in_stack.empty() && out_stack.empty());
	}
private:
	stack<int> in_stack;
	stack<int> out_stack;
};

int main () {
	m_Stack so;
	so.push(1);
	so.push(2);
	so.push(3);
	so.push(4);

	while (!so.empty()) {
		cout << so.pop() << endl;
	}
}
