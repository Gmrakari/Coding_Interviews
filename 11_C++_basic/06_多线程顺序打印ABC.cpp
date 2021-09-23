

/*
 * Date:2021-09-23 09:42
 * filename:06_多线程顺序打印ABC.cpp
 *
 */

#include <iostream>
#include <thread>
#include <pthread.h>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int ready = 0;

void func1() {
	unique_lock<mutex> ul(mtx);
	int cnt = 0;
	while (cnt < 10) {
		while (ready != 0)
			cv.wait(ul);
		cout << "cnt:" << cnt << " "; 
		cout << "A" << " ";
		ready = 1;
		cnt++;
		cv.notify_all();
	}
}

void func2() {
	unique_lock<mutex> ul(mtx);
	int cnt = 0;
	while (cnt < 10) {
		while (ready != 1) 
			cv.wait(ul);
		cout << "B" << " ";
		cnt++;
		ready = 2;
		cv.notify_all();
	}
}

void func3() {
	unique_lock<mutex> ul(mtx);
	int cnt = 0;

	while (cnt < 10) {
		while (ready != 2) 
			cv.wait(ul);
		cout << "C" << " ";
		cout << endl;
		cnt++;
		ready = 0;
		cv.notify_all();
	}
}

int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);
	t1.join();
	t2.join();
	t3.join();
}
