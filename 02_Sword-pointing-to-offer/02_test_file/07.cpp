#include <iostream>
#include <stack>
using namespace std;

//两个栈模拟队列


class Solution
{
public:
	void push(int node)
	{
		stack1.push(node);
	}

	int pop()
	{
		while(stack1.size() != 1)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		int value = stack1.top();
		stack1.pop();
		while( !stack2.empty() )
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		return value;
	}

	bool empty()
	{
		return (stack1.empty() == true && stack2.empty() == true );
	}

private:
	std::stack<int> stack1;//保存元素
	std::stack<int> stack2;//辅助栈
};

int main(int argc,const char* argv[])
{
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while(s.empty() != true)
	{
		cout << s.pop() << " ";
	}
	cout << endl;
}
