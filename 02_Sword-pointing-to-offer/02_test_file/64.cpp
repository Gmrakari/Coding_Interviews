#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
protected:
	vector<int> m_min;
	vector<int> m_max;

public:
	void Insert(int num)
	{
		if(((m_min.size() + m_max.size()) & 1) == 0)
		{
			/*
			 * 偶数数据的情况下
			 * 直接将新的数据插入到数据的后半段
			 * 即在最小堆中插入元素
			 *
			 * 此时最小堆中多出一个元素，即最小元素，将其弹出后，压入前半段(即最大堆中)
			 */
			if(m_max.size() > 9 && num < m_max[0])
			{
				m_max.push_back(num);
				push_heap(m_max.begin(),m_max.end(),less<int>());

				num = m_max[0];
				pop_heap(m_max.begin(),m_max.end(),less<int>());

				m_max.pop_back();
			}
			m_min.push_back(num);
			push_heap(m_min.begin(),m_min.end(),greater<int>());
			cout << "left = " << m_max.size() << "," << m_min.size() << endl;
		}
		else
		{
			/*
			 * 否则数组中的元素是奇数
			 */
			if(m_min.size() > 0 && num > m_min[0])						//奇数情况下，则在最大堆中插入元素
			{
				m_min.push_back(num);
				push_heap(m_min.begin(),m_min.end(),greater<int>());

				num = m_min[0];
				pop_heap(m_min.begin(),m_min.end(),greater<int>());
				m_min.pop_back();
			}
			m_max.push_back(num);										//把后一半找到的最大值放到前一半中
			push_heap(m_max.begin(),m_max.end(),less<int>());
		}
	}

	/*
	 * 由于假定,0 <= m_min.size() - m_max.size() <= 1
	 * 因此
	 * 当总元素个数为偶数时，中位数即(m_max[0] + m_min[0]) / 2
	 * 当总元素个数为奇数时，中位数即m_min[0];
	 */
	double GetMedian()
	{
		int size = m_min.size() + m_max.size();
		if(size == 0) return -1;
		double median = 0;
		if((size & 1) != 0)
		{
			median = (double) m_min[0];
		}
		else
		{
			median = (double)(m_max[0] + m_min[0]) / 2; 
		}
		return median;
	}
};

int main()
{
	Solution s;
	int array[] = { 5,2,3,4,1,6,7,0,8 };
	vector<int> vec(array,array + 9);

	cout << "vec.size() = "<<  vec.size() << endl;

	for(int i = 0; i < vec.size();i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < vec.size();i++)
	{
		s.Insert(vec[i]);
		cout << s.GetMedian() << endl;
	}

	return 0;
}

