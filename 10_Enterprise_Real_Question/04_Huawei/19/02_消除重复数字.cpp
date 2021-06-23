

/*
 * Date:2021-06-23 23:21
 * filename:02_消除重复数字.cpp
 *
 */

#include <iostream>
#include <string>

using	namespace std;

int main() {
	string s;
	while ( cin >> s ) {
		string res;
		for (int i = 1; i <(int) s.size();i++) {
			if (res.find(s[i]) == string::npos) {
				res += s[i];
			} else {
				int t = res.find(s[i]);
				if ((t + 1) < (int)res.size()) {
					if (res[t] < res[t + 1]) {
						res.erase(t, 1);
						res += s[i];
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
	
}
