

/*
 * Date:2021-10-26 19:52
 * filename:01_创建和终止线程.cpp
 *
 */

#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 3

void* fun(void *arg) {
	cout << "start" << endl;
	return 0;
}

int main() {
	//定义线程的id变量，多个变量使用数组
	pthread_t tids[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS;++i) {
		//参数依次是：创建的线程id,线程参数，调用的函数，传入的函数参数
		int ret = pthread_create(&tids[i], NULL, fun, NULL);
		if (ret != 0) {
			cout << "error:" << ret << endl;
		}
	}
	//等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来
	pthread_exit(NULL);
}
