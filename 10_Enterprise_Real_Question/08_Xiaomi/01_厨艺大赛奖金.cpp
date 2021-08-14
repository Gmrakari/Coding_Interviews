

/*
 * Date:2021-08-14 08:12
 * filename:01_厨艺大赛奖金.cpp
 *
 */

/*
 * 【题目描述】
小米食堂每年都会举办一次厨艺大赛，假设参赛的厨师一共有 n 位（n < 1000），比赛结束后
没有公布评分，但是站在领奖台上的一排厨师中每位厨师都能看到与自己相邻的厨师（左或者右）里评分
比自己低（看不到比自己分数高的人的分数）的评分。比赛结束之后要发奖金，以 1K 为单位，每位厨师至
少会发 1K 的奖金，另外，如果一个厨师发现自己的奖金没有高于比自己评分低的厨师的奖金，就会不满意，
作为比赛组织方，小米食堂至少需要发放多少奖金才能让所有厨师满意。

输入描述: :
每组数据为 n+1 个正整数单空格分割，其中第一个数为参赛厨师的人数，后面 n 个数为每位厨师的得分（0-100）

输出描述: :
输出至少需要多少 K 的奖金

输入样例: :
10 60 76 66 76 85 55 61 71 84 62

输出样例: :
20

*/

#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

int calcMinBonus(vector<int>& score) {
	vector<int> bonus(score.size());
	for (int i = 0; i < (int)bonus.size(); i++)
		bonus[i] = 1;

	for (int i = 0; i < (int)score.size() - 1; i++) {
		if (score[i + 1] > score[i]) {
			bonus[i + 1] = bonus[i] + 1;
		}
	}

	for (int i = score.size() - 1; i > 1; i--) {
		if (score[i - 1] > score[i] && bonus[i - 1] <= bonus[i]) {
			bonus[i - 1] = bonus[i] + 1;
		}
	}

	int sum = 0;
	for (int ele : bonus) {
		sum += ele;
	}
	return sum;
}

vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1] ; //不要忘了
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while(p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}

	return res;
}

int ToInt(const string &str) {
	return atoi(str.c_str());
}


int main() {
	int calcMinBonus(vector<int>& score);

	int res;
	vector<int> _score;

	std::string str;
	std::string pattern = " ";
	getline(std::cin, str);
	std::vector<string> ret = split(str, pattern);

	std::transform(ret.begin(), ret.end(), std::back_inserter(_score), ToInt);

	res = calcMinBonus(_score);

	cout << res << endl;
}
