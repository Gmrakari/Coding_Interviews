#include <iostream>
#include <stack>
using namespace std;

/*
 * Date:2021-04-21 08:36
 * Author:Gmrakari
 * Filename:2.cpp
 *
 */


class Solution
{
public:
	void push(int node)
	{
		instack.push(node);
	}

	void transfer(stack<int> &s1,stack<int> &s2)
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		
	}

	int pop()
	{
		transfer(instack,outstack);

		int node = outstack.top();
		outstack.pop();

		transfer(instack,outstack);

		return node;
	}

	bool empty()
	{
		return instack.empty() && outstack.empty();
	}

private:
	stack<int> instack;
	stack<int> outstack;
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
