

/*
 * Date:2021-05-20 20:02
 * filename:01-two-queue-to-stack.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
		queue2.push(x);	
		while(!queue1.empty())
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		swap(queue1,queue2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		int node = queue1.front();
		queue1.pop();
		return node;
    }
    
    /** Get the top element. */
    int top() {
		int r = queue2.front();
		return r;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return (queue1.empty() && queue2.empty());
    }
private:
	queue<int> queue1;
	queue<int> queue2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
	MyStack sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);

	while(!sta.empty())
	{
		cout << sta.pop() << " ";
	}
	cout << endl;
	return 0;
}
