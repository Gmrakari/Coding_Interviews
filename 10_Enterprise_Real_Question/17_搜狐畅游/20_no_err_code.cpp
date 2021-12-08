

/*
 * Date:2021-12-08 14:31
 * filename:20_no_err_code.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

long long f(int a, int b) {
	long long u = a * b;
	return u;
}

void Demo() {
	short *pShort = new short;
	free(pShort);
	pShort = NULL;
}

void fun_c() {
	map<int, int> b;
	b[1] = 1;
	b[2] = 3;
	int i = 0;
	for (auto it = b.begin(); it != b.end(); it++) {
		b[i] = i;
		++i;
	}
	//b[i] = i;
	//++i;
	//0->0
	//1->1
	//2->3
	
	//b[i++] = i;
	//0->1
	//1->2
	//2->3


	for (map<int,int>::iterator ite = b.begin(); ite != b.end(); ite++) {
		cout << ite->first << "->" << ite->second << endl;
	}
}

/*
void fun_d() {
	char* p = buf;
	memset(p, 0, sizeof(p));
}
*/

int main() {
	fun_c();

}
