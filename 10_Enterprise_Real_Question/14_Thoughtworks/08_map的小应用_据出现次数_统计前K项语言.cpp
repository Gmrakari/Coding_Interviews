

/*
 * Date:2021-11-11 20:40
 * filename:08_map的小应用_据出现次数_统计前K项语言.cpp
 *
 */

#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;


typedef map<string, int>::iterator CountIte;
struct compare {
	bool operator()(CountIte lhs, CountIte rhs) {
		return lhs->second > rhs->second;
	}
};

void get_topK_gramar(const vector<string>& v, int k) {
	//统计vector中各种相同key出现的次数
	map<string, int> countMap;
	for (int i = 0;i < (int)v.size();++i) {
		countMap[v[i]]++;
	}

	//定置仿函数，以每种编程语言出现次数进行排序
	//不能用set来排序，因为它会去重，即其具有相同value值的某种语言过滤掉
	multiset<CountIte, compare> sortSet;
	CountIte cit = countMap.begin();

	while (cit != countMap.end()) {
		sortSet.insert(cit);
		++cit;
	}

	multiset<CountIte, compare>::iterator it1 = sortSet.begin();
	for (; it1 != sortSet.end();++it1) {
		if (k--) {
			cout << (*it1)->first << ":" << (*it1)->second << endl;
		}
	}
}

void test_map_question() {
	vector<string> v;
	v.push_back("python");

	v.push_back("python" );
	v.push_back("PHP" );
	v.push_back("PHP" );
	v.push_back("PHP" );
	v.push_back("PHP" );
	v.push_back("Java" );
	v.push_back("PHP" );
	v.push_back("C/C++" );
	v.push_back("C/C++" );
	v.push_back("python" );
	v.push_back("Java" );
	v.push_back("Java" );
	//统计语言次数,或者前K种语言
	get_topK_gramar(v, 3);
}

int main() {
	test_map_question();
}


