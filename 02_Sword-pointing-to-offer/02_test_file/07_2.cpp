#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	
	//栈   杯子 先进后出
	//队列 管道 先进先出

	void push(int node)
	{
		stack1.push(node);
	}

	void copy(stack<int> &a,stack<int> &b)
	{
		while(a.size())
		{
			b.push(a.top());
			a.pop();
		}
	}

	int pop()
	{
		//1 到 2
		//2 top pop
		//2 到 1
		copy(stack1,stack2);
		int res = stack2.top();
		stack2.pop();
		copy(stack2,stack1);

		return res;
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
	Solution solu;
	solu.push(1);
	solu.push(2);
	solu.push(3);
	solu.push(4);

	while(solu.empty() != true)
	{
		cout << solu.pop();
	}
	return 0;
}
