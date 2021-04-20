//#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
	bool IsPopOrder(int *pPush,int *pPop,int nLength){
		if(pPush == NULL || pPop == NULL || nLength <= 0) return false;

		stack<int> s;
		s.push(pPush[0]);
		int nPop_index = 0;
		int nPush_index = 1;

		while(nPop_index < nLength){
			while(s.top() != pPop[nPop_index] && nPush_index < nLength){
				s.push(pPush[nPush_index]);
				nPush_index++;
			}

			if(s.top() == pPop[nPop_index]){
				s.pop();
				nPop_index++;
			}else{
				return false;
			}
		}
		return true;
	}
};

int main(){
	int nPush[5] = {1,2,3,4,5};

	int nPop1[5] = {4,5,3,2,1};
	int nPop2[5] = {4,3,5,1,2};
	int nPop3[5] = {5,4,3,2,1};
	int nPop4[5] = {4,5,2,3,1};
	int nPop5[5] = {5,4,3,2,1};

	Solution a;
	cout << a.IsPopOrder(nPush,nPop1,5) << endl;
	cout << a.IsPopOrder(nPush,nPop2,5) << endl;
	cout << a.IsPopOrder(nPush,nPop3,5) << endl;
	cout << a.IsPopOrder(nPush,nPop4,5) << endl;
	cout << a.IsPopOrder(nPush,nPop5,5) << endl;
	return 0;
}
