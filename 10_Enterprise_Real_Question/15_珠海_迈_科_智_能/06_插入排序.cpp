

/*
 * Date:2021-09-15 10:32
 * filename:06_插入排序.cpp
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct display {
	void operator()(const T& x) {
		cout << x << ' ';
	}
};

vector<int> insert_sort(vector<int>& vec) {
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	for (i = 1;i < (int)vec.size(); i++) {
		k = i;
		temp = vec[k];
		for (j = i - 1; (j >= 0) && (vec[j] > temp); j--) {
			vec[j + 1] = vec[j];
			k = j;
		}
		vec[k] = temp;
	}
	return vec;
}

vector<int> init() {
	vector<int> vec;
	for (int i = 10;i > 0;--i) {
		vec.emplace_back(i);
	}
	return vec;
}

int main() {
	vector<int> vec;
	vec = init();

	cout << "未排序:";
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;

	cout << "Inser sort: ";
	vec = insert_sort(vec);
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;

} 
