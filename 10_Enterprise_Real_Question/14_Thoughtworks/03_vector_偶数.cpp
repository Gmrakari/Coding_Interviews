

/*
 * Date:2021-09-11 20:32
 * filename:jioushu.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct display {
	void operator()(const T& x) {
		cout << x << ' ';
	}
};

class Solution {
	public:
		vector<int> odd(vector<int>& array) {
			auto it = array.begin();
			for (it = array.begin(); it != array.end(); it++) {
				if ((*it) & 1) {
					array.erase(it);
				}
			}
			return array;
		}
		vector<int> odd_2(vector<int>& arr){
			vector<int> res;
			int j = 0;
			for (int i = 0; i < (int)arr.size();i++) {
				if (arr[i] % 2 == 0) {
					res[j++] = arr[i];
				}	
			}
			return res;
		}

		void print(vector<int>& vec) {
			for (auto it = vec.begin(); it != vec.end(); it++) {
				cout << *it << ' ';
			}
			cout << endl;
		}
};


int main() {
	vector<int> vec = {1,2,3,4,5,6,7,8};
	vector<int> vec_2 = {1,2,3,4,5,6,7,8};

	cout << "vec:";
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;

	Solution fun1;
	
	cout << "oushu_1:";
	fun1.odd(vec);
	fun1.print(vec);

	Solution fun2;
	cout << "oushu_2:";
	fun2.odd_2(vec_2);
	fun2.print(vec_2);
}

/*
 * 总结:
 * 除去奇数可以用位运算 
 * if ( *node & 1 ) {
 *	为真的话
 * }
 * 那么就是个奇数，否则是一个偶数
 *
 *
 */
