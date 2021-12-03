

/*
 * Date:2021-09-29 21:09
 * filename:05_单例模式.cpp
 *
 */

/*
 * Singleton 的动机(Motivation)
 *
 * 在软件系统中，经常有这样一些特殊的类，必须保证它们在系统中只存在一个实例，
 * 才能确保它们的逻辑正确性、以及良好的效率
 *
 * 模式定义：
 * 保证一个类仅有一个实例，并提供一个该实例的全局访问点
 *
 */

#include <bits/stdc++.h>

class Single {
public:
	Single() {
		return p;
	}
private:
	static Single *p;
};

class Singleton {
private:
	Singleton();
	Singleton(const Singleton* other);

public:
	static Singleton* getinstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

Singleton* Singleton::getinstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

//线程安全版本
Singleton* Singleton::getinstance() {
	Lock lock;
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}

//双锁
Singleton* Singleton::getinstance() {
	if(m_instance == nullptr) {
		Lock lock;
		if (m_instance == nullptr)
			m_instance = new Singleton();
	}
	return m_instance;
}

//C++11 volatile
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getinstance() {
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(mutex);
		tmp = m_instance.load(std:memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton;
			std::atomic_thread_fence(std::memory_order_release);
			m_instance.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}
