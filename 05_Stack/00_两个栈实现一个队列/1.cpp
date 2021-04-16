#include <iostream>
#include <stack>
using namespace std;

/*
 * Date:2021-03-10 10:36
 * Author:Gmrakari
 * Filename:1.cpp
 *
 */


class Solution
{
public:
	void push(int node)
	{
		stack1.push(node);
	}

	void tranfer(stack<int> &a,stack<int> &b)
	{
		while(a.size())
		{
			b.push(a.top());
			a.pop();
		}
	}

	int pop()
	{
		tranfer(stack1,stack2);
		int node = stack2.top();
		stack2.pop();

		tranfer(stack2,stack1);

		return node;
	}

	bool empty()
	{
		return (stack1.empty() == true && stack2.empty() == true);
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main(int argc,const char* argv[])
{
	Solution su;
	su.push(1);
	su.push(2);
	su.push(3);
	su.push(4);

	while(su.empty() != true)
	{
		cout << su.pop() << ' ';
	}
	cout << endl;
}
