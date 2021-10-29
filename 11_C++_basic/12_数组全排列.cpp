

/*
 * Date:2021-10-29 16:31
 * filename:12_数组全排列.cpp
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
class A {
	public:
		void permutation(vector<T> vec, T low, T high) {
			if (low == high) {
				for (int i = 0;i <= low;i++) {
					cout << vec[i];
				}
				cout << endl;
			}
			else {
				for (int i = low; i <= high;i++) {
					swap(vec[i], vec[low]);
					permutation(vec, low + 1, high);
					swap(vec[i], vec[low]);
				}
			}
		}

};
/*
	 void permutation(vector<int> vec, int low, int high) {
	 if (low == high) {
	 for (int i = 0;i <= low;i++) {
	 cout << vec[i];
	 }
	 cout << endl;
	 }
	 else {
	 for (int i = low; i <= high;i++) {
	 swap(vec[i], vec[low]);
	 permutation(vec, low + 1, high);
	 swap(vec[i], vec[low]);
	 }
	 }
	 }
	 */

vector<int> init() {
	vector<int> vec = {1,2,3,4,5};
	return vec;
}

vector<char> init_string() {
	vector<char> ret = {'a','b','c'};
	return ret;
}


int main() {
	vector<int> ret = init();
	A<int> test;
	test.permutation(ret, 0, ret.size() - 1);

	vector<char> ret_char = init_string();
	A<char> test2;
	test2.permutation(ret_char, 0, ret_char.size() - 1);
	return 0;
}
