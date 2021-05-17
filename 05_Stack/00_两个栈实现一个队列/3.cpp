

/*
 * Date:2021-05-17 15:42
 * filename:3.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class su
{
public:
	void push(int x)
	{
		instack.push(x);	
	}

	void transfer(stack<int> &instack,stack<int> &outstack)
	{
		while(!instack.empty())
		{
			outstack.push(instack.top());
			instack.pop();
		}
	}
	int pop()
	{
		transfer(instack,outstack);
		int node = outstack.top();
		outstack.pop();
		return node;
	}

	bool empty()
	{
		return (instack.empty() && outstack.empty());
	}
private:
	stack<int> instack;
	stack<int> outstack;
};

int main()
{
	su m_stack_to_queue;
	m_stack_to_queue.push(1);
	m_stack_to_queue.push(2);
	m_stack_to_queue.push(3);
	m_stack_to_queue.push(4);
	m_stack_to_queue.push(5);

	while(!m_stack_to_queue.empty())
	{
		cout << m_stack_to_queue.pop() << " ";
	}
	cout << endl;

}
