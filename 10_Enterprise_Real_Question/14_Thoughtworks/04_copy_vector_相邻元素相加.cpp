

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
	
	//int len = array.size() % 2 == 0 ? array.size() : array.size() + 1;
	vector<int> ret;
	vector<int> nu;
	int temp = 0,j = 0;
	while (array.size() > 2) {
		for (int i = 0;i < (int)array.size() / 2;i++) {
			temp = array[j] + array[j + 1];
			j += 2;
			ret.push_back(temp);
		}
		j = 0;
		array.swap(ret);
		ret.swap(nu);

		for_each(array.begin(), array.end(),display<int>());
		cout << endl;
	}
	cout << "array[0]:" << array[0]  << " "<< "array[1]:" << array[1] << endl;
	return array[0]*array[0] + array[1] * array[1];
}

vector<int> init() {
	vector<int> vec = {1,2,3,4,5,6};
	return vec;
}

void test() {
	vector<int> vec = init();
	cout << sumOfAdjacentElements(vec) << endl;

}

void test_vector() {
	vector<int> vec1 = {1,2,3,4,5};
	vector<int> ret = {8,9};

	ret.swap(vec1);

	for_each(ret.begin(),ret.end(), display<int>());
	cout << endl;

	vector<int> vec2 = {1};

	ret.swap(vec2);
	cout << "ret size:" << ret.size() << endl;
	for_each(ret.begin(),ret.end(), display<int>());


	cout << endl;
}

int main() {
	test();
	//test_vector();
}




