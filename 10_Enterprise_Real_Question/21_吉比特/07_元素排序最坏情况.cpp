

/*
 * Date:2021-10-20 10:37
 * filename:07_元素排序最坏情况.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
struct display {
	void operator()(const T& x) {
		cout << x << ' ';
	}
};

vector<int> init() {
	vector<int> vec;
	for (int i = 0; i < 6;i++) {
		vec.push_back(i);
	}
	return vec;
}

void bubble_sort() {
	int cnt = 0;
	vector<int> vec = init();

	for (int i = 0;i < (int)vec.size();i++) {
		for (int j = 1;j < (int)vec.size();j++) {
			if (vec[j] > vec[j - 1]) {
				cnt++;
				int temp = vec[j];
				vec[j] = vec[j - 1];
				vec[j - 1] = temp;
			}
		}
	}

	cout << "vec:";
	for_each(vec.begin(),vec.end(),display<int>());
	cout << endl;
	cout << "cnt:" << cnt << endl;
}

void select_sort() {
	int cnt = 0;
	vector<int> vec = init();

	int k = -1;
	for (int i = 0;i < (int)vec.size();i++) {
		//拿一个未排序好的元素中，第一个出来
		k = i;
		for (int j = i + 1;j < (int)vec.size();j++) {
			//找出从2到n-1中最大的一个数
			if (vec[k] < vec[j]) {
				k = j;
				cnt++;
			}
		}
		//交换
		int temp = vec[k];
		vec[k] = vec[i];
		vec[i] = temp;
	}

	cout << "vec:";
	for_each(vec.begin(),vec.end(),display<int>());
	cout << endl;
	cout << "cnt:" << cnt << endl;
	
}

int main() {
	cout << "bubble_sort:" << endl;
	bubble_sort();

	cout << "select_sort:" << endl;
	select_sort();

}
