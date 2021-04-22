/*
 * A栈,B栈,这两个栈都是前面提到pop-push-min复杂度都为O(1)的空间换时间的实现
 * 取量值:返回A栈的最值和B栈的最值相比后的最值。复杂度O(1)
 *
 * 入队操作:直接入到B栈中.复杂度O(1)
 * 出队操作:如果A栈不为空，直接A栈出栈，复杂度为O(1),如果A栈为空，那么将B栈内容逐个出栈并且逐个入栈到A中，然后A栈出栈，复杂度O(N)，实际上是B栈的长度
 *
 */

#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <climits>
#include <queue>


const int MAX = 10000;

using namespace std;

class Stack
{
private:
	int stackItem[MAX];
	int link2NextMaxValueIndex[MAX];
	int stackTop;
	int maxValueIndex;

public:
	Stack() : stackTop(-1),maxValueIndex(-1) {}
	int size() { return stackTop + 1; }
	int empty() { return stackTop < 0 ? 1 : 0; }

	void push(int val)
	{
		++stackTop;
		if(stackTop == MAX)
		{
			cout << "The stack has been full!" << endl;
			return ;
		}
		else
		{
			stackItem[stackTop] = val;
			if( max() < val)
			{
				link2NextMaxValueIndex[stackTop] = maxValueIndex;
				maxValueIndex = stackTop;
			}
			else
			{
				link2NextMaxValueIndex[stackTop] = -1;
			}
		}
	}

	int pop()
	{
		int ret;
		if(stackTop == -1)
		{
			cout << "The stack is empty!" << endl;
			return -1;
		}
		else
		{
			ret = stackItem[stackTop];
			if(stackTop == maxValueIndex)
			{
				maxValueIndex = link2NextMaxValueIndex[stackTop];
			}
			--stackTop;

			return ret;
		}
	}

	int max()
	{
		if(maxValueIndex >= 0)
		{
			return stackItem[maxValueIndex];
		}
		else
			return -100;
	}
	
};

class Queue
{
private:
	Stack stackIn;
	Stack stackOut;
public:
	int size()
	{
		return stackIn.size() + stackOut.size();
	}

	int max()
	{
		return std::max(stackIn.max(),stackOut.max());
	}

	void enQueue(int val)
	{
		stackIn.push(val);
	}

	int deQueue()
	{
		if(stackOut.empty() and !stackIn.empty())
		{
			while(!stackIn.empty())
			{
				stackOut.push(stackIn.pop());
			}
		}
		return stackOut.pop();
	}
};

class Solution
{
public:
	vector<int> maxInWindows(const vector<int>& num,unsigned int size)
	{
		unsigned int length = num.size();
		vector<int> res;
		if(length == 0 || size == 0 || length < size)
		{
			return res;
		}

		Queue que;
		for(int i = 0; i < num.size();i++)
		{
			if(que.size() < size)
			{
				que.enQueue(num[i]);
			}
			else
			{
				res.push_back(que.max());

				que.enQueue(num[i]);
				que.deQueue();
			}
		}
		if(que.size() == size)
		{
			res.push_back(que.max());
		}
		return res;
	}
};

int main()
{
	Solution solu;
	int array[] = { 2,3,4,2,6,2,5,1 };
	vector<int> vec(array,array + 8);

	vector<int> res = solu.maxInWindows(vec,3);

	copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));

	return 0;
}
