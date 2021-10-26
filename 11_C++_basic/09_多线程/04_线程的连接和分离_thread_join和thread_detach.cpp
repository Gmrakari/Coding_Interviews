

/*
 * Date:2021-10-26 20:17
 * filename:04_线程的连接和分离_thread_join和thread_detach.cpp
 *
 */

/*
 * pthread_join()子程序阻碍调用程序，直到指定的threadid线程终止为止
 * 当创建一个线程时，它的某个属性会定义它是否是可连接的(joinable)或可分离(detached)
 * 只有创建时定义为可连接的线程才可以被链接
 * 如果线程创建时被定义为可分离的，则它永远也不能被连接
 *
 */

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 10

void *wait(void *t) {
	int i;
	long tid;
	tid = (long)t;

	sleep(1);
	cout << "sleep in thread: " << endl;
	cout << "thread with id:" << tid << " ...exiting" << endl;
	pthread_exit(NULL);
}

int main() {
	int rc;
	int i;
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void *status;

	//初始化并设置线程为可连接的(joinable)
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0;i < NUM_THREADS;i++) {
		cout << "main crreating thread, " << i << endl;
		rc = pthread_create(&threads[i],NULL, wait, (void *)&i);
		if (rc) {
			cout << "error:thread" << rc << endl;
			exit(-1);
		}
	}

	//删除属性,并等待其他线程
	pthread_attr_destroy(&attr);
	for (i = 0;i < NUM_THREADS;i++){
		rc = pthread_join(threads[i], &status);
		if (rc) {
			cout << "err:unable to join, " << rc << endl;
			exit(-1);
		}
		cout << "main complete thread id:" << i;
		cout << " exiting with status:" << status << endl;
	}
	cout << "main program exiting." << endl;
	pthread_exit(NULL);
}
