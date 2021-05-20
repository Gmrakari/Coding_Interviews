

/*
 * Date:2021-05-17 15:55
 * filename:00_two-queue-to-stack.cpp
 *
 */

/*
 * 在任意时刻我们都需要保证一个队列是空的，因此我们可以固定队列2在任何时刻都为空。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void push(int x)
	{
		queue2.push(x);
		while(!queue1.empty())
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		swap(queue1,queue2);
	}
	int pop()
	{
		int node = queue1.front();
		queue1.pop();

		return node;
	}
	bool empty()
	{
		return (queue1.empty() && queue2.empty());
	}
private:
	queue<int> queue1,queue2;
};

int main()
{
	Solution su;
	su.push(1);
	su.push(2);
	su.push(3);
	su.push(4);

	while(!su.empty())
	{
		cout << su.pop() << " ";
	}
	cout << endl;
}
