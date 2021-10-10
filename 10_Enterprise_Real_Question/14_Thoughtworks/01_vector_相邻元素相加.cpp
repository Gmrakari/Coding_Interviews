

/*
 * Date:2021-10-10 15:58
 * filename:01_vector_相邻元素相加.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

template <class T>
struct display {
	void operator()(const T& x) {
		cout << x << ' ';
	}
};

int sumOfAdjacentElements(vector<int> array) {
	if (array.size() == 0) 
		return 0;

	vector<int> vec;
	int result = 0;
	int j = 0;
	for (int i = 0;i < (int)array.size() / 2;i += 2) {
		vec[j++] = array[i] + array[i + 1];
	}
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;
	return result;
}

vector<int> init() {
	vector<int> vec = {1,2,3,4,5,6};
	return vec;
}

void test() {
	vector<int> vec = init();
	sumOfAdjacentElements(vec);
}

void test_vector() {
	vector<int> array = {1,2,3,4,5,6};
	vector<int> vec;
	//vector<int> vec(array.size() / 2);
	for (int i = 0; i < (int)array.size(); i += 2) {
		int temp = array[i] + array[i + 1];
		vec.push_back(temp);
	}
	//for_each(array.begin(), array.end(), display<int>());
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;
}

vector<int> merge_vector(vector<int>& array) {
	vector<int> res(array.size() / 2);
	int len = array.size() / 2;
	while ( len > 2) {
		for (int i = 0;i < (int)array.size();i += 2) {
			int k = 0;
			res[k++] = array[i] + array[i + 1];
		}
	}
	return res;
}

void mer_test() {
	vector<int> res = init();
	int len = res.size();
	while (len > 2) {
		res = merge_vector(res);
		len = res.size();
	}
	for_each(res.begin(), res.end(), display<int>());		
	cout << endl;
}

int main() {
	mer_test();

}




