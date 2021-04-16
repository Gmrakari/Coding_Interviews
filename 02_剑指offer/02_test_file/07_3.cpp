#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
		void push(int node)
		{
			stack1.push(node);
		}
	
		void exchange(stack<int> &a,stack<int> &b)
		{
			while(a.size())
			{
				b.push(a.top());
				a.pop();
			}
		}

		int pop()
		{
			exchange(stack1,stack2);
			int res = stack2.top();
			stack2.pop();

			exchange(stack2,stack1);

			return res;
		}

		bool empty()
		{
			return (stack1.empty() == true && stack2.empty());
		}

private:
		stack<int> stack1;
		stack<int> stack2;

};

int main(int argc,char* argv[])
{
	Solution su;
	su.push(1);
	su.push(2);
	su.push(3);
	su.push(4);
	su.push(5);

	while(su.empty() != true)
	{
		cout << su.pop() << " ";
	}

	cout << endl;
}
