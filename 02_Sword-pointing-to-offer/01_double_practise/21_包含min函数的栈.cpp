

/*
 * Date:2021-07-22 11:53
 * filename:21_包含min函数的栈.cpp
 *
 */

// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
// 在该栈中，调用min、push及pop的时间复杂度都是O(1)。


//引入m_data数据栈 和 m_min辅助栈
//辅助栈保存每次的最小元素(之前的最小元素和新压入栈的元素两者的较小值)都保存起来放在另外一个辅助栈里

#include <iostream>
#include <cstdio>
#include <stack>
#include <assert.h>

template <typename T> class StackWithMin
{
	public:
		StackWithMin() {}
		virtual ~StackWithMin() {}

		T& top();
		const T& top() const;

		void push(const T& value);
		void pop();

		const T& min() const;

		bool empty() const;
		size_t size() const;

	private:
		std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
		std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
};

template<typename T> void StackWithMin<T>::push(const T& value) {
	m_data.push(value);

	if (m_min.size() == 0 || value < m_min.top()) 
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template<typename T> void StackWithMin<T>::pop() {
	assert(m_data.size() > 0 && m_min.size() > 0);

	m_data.pop();
	m_min.pop();
}

template<typename T> const T& StackWithMin<T>::min() const {
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}

template <typename T> T& StackWithMin<T>::top()
{
	return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
	return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
	return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
	return m_data.size();
}

void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
	if(testName != nullptr)
		printf("%s begins: ", testName);

	if(stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

int main() {
	StackWithMin<int> stack;

	stack.push(3);
	Test("Test1", stack, 3);
}
