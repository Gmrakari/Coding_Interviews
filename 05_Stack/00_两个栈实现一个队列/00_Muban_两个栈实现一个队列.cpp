#include <iostream>
#include <stack>
using namespace std;

/*
 * Date:2021-03-10 10:36
 * Author:Gmrakari
 * Filename:00_Muban_两个栈实现一个队列.cpp
 *
 */


class Solution
{
public:
	void push(int node)
	{
	}


	int pop()
	{
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
