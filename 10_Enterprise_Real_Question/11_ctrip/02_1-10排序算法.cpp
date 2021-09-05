

/*
 * Date:2021-08-18 16:45
 * filename:02_1-10排序算法.cpp
 *
 */

/*
 * 【题目描述】
请使用 random() 函数，生成 10 个随机数，并对它进行降序排序 ，要求有效率。
注意：不允许使用代码库提供的 sort() 之类现成的排序函数。

输出描述: :
1
2
2
4
5
5
6
6
8
10
备注:
因为是 random 产生，所以只要排序对就行

输入样例：
1

输出样例：
1

说明：因为是 random 产生，所以只要排序对就行

*/

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &vec, int low, int high) {
	int pv = vec[low];

	while (low < high) {
		while (low < high && pv >= vec[high]) {
			high--;
		}
		swap(vec[low], vec[high]);
		while (low < high && pv <= vec[low]) {
			low++;
		}
		swap(vec[low], vec[high]);
	}
	return low;
}

void q_sort(vector<int> &vec, int low, int high) {
	if (low < high) {
		int pivot = partition(vec, low, high);
		q_sort(vec, low, pivot - 1);
		q_sort(vec, pivot + 1, high);
	}
}

vector<int> QuickSort(vector<int> &vec) {
	int size_len = vec.size() - 1;
	q_sort(vec, 0, size_len);
	return vec;
}

template <class T>
struct display{
	void operator()(const T& x) const {
		cout << x << ' ';
	}
};

class Solution {
public:
	void quickSort(vector<int>& vec, int low, int high)  {
		if (low >= high)
			return ;

		int i = low;
		int j = high;
		int key = vec[low];
		while (i < j) {
			while (i < j && vec[j] > key) {
				j--;
			}
			while (i < j && vec[i] < key) {
				i++;
			}
			if (i < j) {
				int p = vec[i];
				vec[i] = vec[j];
				vec[j] = p;
			}
		}
		int t = vec[i];
		vec[i] = vec[low];
		vec[low] = t;
		quickSort(vec, low, i - 1);
		quickSort(vec, i + 1, high);
	}
};


int main() {
	vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(random() % 10);
	}
	cout << "generate random element:";
	for (int i = 0; i <(int)vec.size(); i++) {
		cout << vec[i] << ' ';
	}
	cout << endl;

	cout << "sort:";
	QuickSort(vec);
	for (int i = 0; i <(int)vec.size(); i++) {
		cout << vec[i] << ' ';
	}
	cout << endl;

	vector<int> soVec;
	for (int i = 0; i < 10; i++) {
		soVec.emplace_back(random() % 10);
	}
	cout << "SoVec generate random element:";
	/*
	for (int i = 0; i < (int)soVec.size(); i++) {
		cout << soVec[i] << ' ';
	}
	cout << endl;
	*/
	for_each(soVec.begin(), soVec.end(), display<int>());
	cout << endl;

	cout << "sort:";
	Solution so;
	so.quickSort(soVec, 0, soVec.size() - 1);
	for_each(soVec.begin(), soVec.end(), display<int>());
	cout << endl;

}
