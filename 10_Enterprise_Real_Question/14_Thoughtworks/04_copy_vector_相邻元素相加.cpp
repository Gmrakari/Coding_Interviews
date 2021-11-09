

/*
 * Date:2021-11-09 20:53
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

/*
 * 判断长度，然后不断进行缩减
 */
int sumOfAdjacentElements(vector<int> array) {
	if (array.size() == 0) 
		return 0;
	
	int len = array.size() % 2 == 0 ? array.size() : array.size() + 1;
	vector<int> ret;
	while(array.size() > 2) {
		for (int i = 0,j = 0,k = 0; i < (int)array.size();i++) {
			array[k++] = array[j] + array[j + 1];
			j += 2;

		}
	}

	return 0;
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
	cout << endl;
}

int main() {
	test();
}




