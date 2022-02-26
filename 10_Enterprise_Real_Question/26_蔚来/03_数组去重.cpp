

/*
 * Date:2022-02-23 19:48
 * filename:03_数组去重.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param list int整型vector
     * @return int整型vector
     */
    vector<int> unique(vector<int>& list) {
        // write code here
				if (list.size() < 0) return {};
        unordered_set<int> tmp;
        for (auto i : list) {
            tmp.insert(i);
        }

        vector<int> ret;
        vector<int> ans(ret.size(), 0);
        for (auto i : tmp) {
            ret.push_back(i);
        }

				for (auto i : ret) {
					cout << i << " ";
				}
				cout << endl;

				vector<int>::iterator it = ret.end();

				for (it = ret.end() - 1; it != ret.begin(); it--) {
					ans.push_back(*it);
				}
				ans.push_back(ret[0]);

        return ans;
    }

		vector<int> unique_2(vector<int>& list) {
			if (list.size() < 2) 
				return {};

			set<int> m_set(list.begin(), list.end());
			list.assign(m_set.begin(), m_set.end());
			return list;
		}
};

void test_1() {

	vector<int> list = {1,2,3,3,3,3,3,3,1,1,1,2,7,5};
	Solution test;
	vector<int> ret;
	ret = test.unique_2(list);

	for (auto i : ret) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {

	vector<int> list = {1,2,3,3,3,3,3,3,1,1,1,2,7,5};

	Solution test;
	vector<int> ret;
	ret = test.unique(list);

	for (auto i : ret) {
		cout << i << " ";
	}
	cout << endl;

	cout << "Test:" << endl;
	test_1();

}
