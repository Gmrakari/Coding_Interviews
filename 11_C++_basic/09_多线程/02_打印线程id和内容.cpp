

/*
 * Date:2021-10-26 19:58
 * filename:02_打印线程id和内容.cpp
 *
 */

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 4

void *printfun(void *threadid) {
	//对传入的参数进行强制类型转换，由无类型指针变为整型数指针，然后再读取
	int tid = *((int*)threadid);
	cout << "run printfun 线程id:" << tid << endl;
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
	int indexes[NUM_THREADS];//用数组来保存i的值
	int rc;
	int i;
	for (i = 0;i < NUM_THREADS;i++) {
		cout << "main():创建线程, " << i << endl;
		indexes[i] = i;//先保存i的值

		//传入的时候必须强制转换void*类型，即无类型指针
		rc = pthread_create(&threads[i], NULL, printfun, (void*)&(indexes[i]));
		if (rc) {
			cout << "err无法创建: " << rc << endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
