

/*
 * Date:2021-11-11 19:38
 * filename:07_计票程序.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct compare {
	bool operator() (map<string, int>::iterator lhs, map<string,int>::iterator rhs) {
		return lhs->second > rhs->second;
	}
};

void countVotes(vector<string> validCandidates, vector<string> voteCasted) {
	//validCandidates 表示有效的候选人,voteCasted 输入的投票数据
	
	if (validCandidates.size() == 0 || voteCasted.size() == 0)
		return ;
	
	map<string, int> m_validCandidatesCount;

	for (int i = 0;i < (int)voteCasted.size();++i) {
		map<string, int>::iterator it = m_validCandidatesCount.find(voteCasted[i]);
		if (it != m_validCandidatesCount.end()) {
			++it->second;
		}
		else {
			m_validCandidatesCount.insert(make_pair(voteCasted[i], 1));
		}
	}

	//20-28 行代码 等于 m_validCandidatesCount[voteCasted[i]]++;

	multiset<map<string, int>::iterator, compare> sortSet;
	map<string,int>::iterator cit = m_validCandidatesCount.begin();
	while (cit != m_validCandidatesCount.end()) {
		sortSet.insert(cit);
		++cit;
	}
	
	multiset<map<string, int>::iterator, compare>::iterator it1 = sortSet.begin();
	for (;it1 != sortSet.end();++it1) {
		cout << (*it1)->first << ":" << (*it1)->second << endl;
	}
	
	it1 = sortSet.begin();
	cout << "Winer:" << (*it1)->first << endl;

}

void test() {
	vector<string> vec2;
	vector<string> vec;
	vec.push_back("A");
	vec.push_back("B");
	vec.push_back("C");
	vec.push_back("D");
	vec.push_back("A");
	vec.push_back("A");

	vec2.push_back("A");
	vec2.push_back("B");
	vec2.push_back("C");

	countVotes(vec2,vec);
}

int main() {
	test();

}
