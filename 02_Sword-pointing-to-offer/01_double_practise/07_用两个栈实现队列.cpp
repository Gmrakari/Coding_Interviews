

/*
 * Date:2021-07-17 10:18
 * filename:07_用两个栈实现队列.cpp
 *
 */

/*
栈的应用 操作系统会给每一个线程创建一个栈用来存储函数调用时各个函数的参数、返回地址及临时变量

栈的特点 后进先出 -- 最后被压入（push）栈的元素会第一个被弹出（pop）

队列的特点先进先出，即第一个进入队列的元素将会第一个出来

#题意

题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。
队列中的元素为int类型。
*/

#include <iostream>
#include <stack>
#include <exception>
using namespace std;

template <typename T>class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& element) {
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead() {
	if (stack2.size() <= 0) {
		while (stack1.size() > 0) {
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new std::exception("queue is empty");

	T head = stack2.top();
	stack2.pop();

	return head;
}
