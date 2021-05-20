

/*
 * Date:2021-05-20 15:28
 * filename:22_generate-parenthese.cpp
 *
 */

/*
 * 暴力
 * 生成所有序列
 * 检查是否有效
 * 模式识别:子问题的原问题具有相同结构,考虑自上而下的递归
 */


class Solution {
public:
	bool valid(const string& str) {
		int balance = 0;
		for(char c : str) {
			if (c == '(') {
				++balance;
			} else {
				--balance;
			}
			if (balance < 0) {
				return false;
			}
		}
		return balance == 0;
	}
	
	void generate_all(string& current, int n,vector<string>& result) {
		if (n == current.size()) {
			if (valid(current)) {
				return result.push_back(current);
			}
			return ;
		}
		current += '(';
		generate_all(current, n,result);
		current.pop_back();
		current += ')';
		generate_all(current, n,result);
		current.pop_back();
	}

    vector<string> generateParenthesis(int n) {
    	vector<string> result;
		string current;
		generate_all(current, n * 2, result);
		return result;
	}
};


/*
 * 回溯
 * 关键字:有效序列
 * 模式识别:确保每一步都能产生有效序列,利用回溯搜索其他可能的解
 */

class Solution {
public:
	void generateParenthesisHelper(int left,int right,string parenthesis,vector<string>& answer) {
		//定义递归出口
		if (left == 0 && right == 0) {
			answer.push_back(parenthesis);
			return ;
		}
		//尝试放入左括号
		if (left > 0) {
			parenthesis += '(';
			generateParenthesisHelper(left - 1, right, parenthesis, answer);
			//回溯
			parenthesis.erase(parenthesis.size() - 1, 1);
		}
		//尝试放右括号
		if (right > left) {
			parenthesis += ')';
			generateParenthesisHelper(left, right - 1, parenthesis, answer);
		}
	}
		
    vector<string> generateParenthesis(int n) {
		vector<string> answer;
		string parenthesis = "";
		generateParenthesisHelper(n, n, parenthesis, answer);
		return answer;
    }
};
