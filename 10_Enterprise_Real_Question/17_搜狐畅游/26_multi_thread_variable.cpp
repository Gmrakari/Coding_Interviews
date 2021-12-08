

/*
 * Date:2021-12-08 15:01
 * filename:26_multi_thread_variable.cpp
 *
 */

#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int total = 0;//全局变量


void* ThreadProc(void* arg) {
	usleep(1);
	for (int i = 0; i <= 50; i++) {
		pthread_mutex_lock(&mutex);
		total += 1;
		std::cout << "ThreadProc:" << pthread_self() << "\t" << "total:" << total << std::endl;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void* ThreadProc_A(void* arg) {
	usleep(1);
	for (int i = 1;i <= 50;i++) {
		pthread_mutex_lock(&mutex);
		total += 1;
		std::cout << "ThreadProc_A:" << pthread_self() << "\t" << "total:" << total << std::endl;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void* ThreadProc_B(void* arg) {
	usleep(1);
	for (int i = 1; i <= 50; i++) {
		pthread_mutex_lock(&mutex);
		total += 1;
		std::cout << "ThreadProc_B:" << pthread_self() << "\t" << "total:" << total << std::endl;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main() {
	pthread_t t1, t2;

	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&t1, NULL, ThreadProc_A, NULL);
	pthread_create(&t2, NULL, ThreadProc_B, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex);

	std::cout << total << std::endl;

	return 0;
}
