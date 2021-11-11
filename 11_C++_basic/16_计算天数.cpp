

/*
 * Date:2021-11-11 19:12
 * filename:16_计算天数.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct data {
	int year;
	int month;
	int day;
}Data;

bool isRunYears(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else 
		return false;
}

int fun(struct data &cal) {
	int count = 0;
	int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if (isRunYears(cal.year)) 
		monthday[1] = 29;

	cout << monthday[1] << endl;
	for (int i = 0;i < cal.month - 1;i++) {
		count += monthday[i];
	}
	return count + cal.day;
}

int main() {
	struct data cal = {2013,12,2};
	//scanf("%d%d%d",&cal.year,&cal.month,&cal.day);
	cout << fun(cal) << endl; 
}


