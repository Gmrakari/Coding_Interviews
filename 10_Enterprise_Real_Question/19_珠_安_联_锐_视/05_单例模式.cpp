

/*
 * Date:2021-09-29 21:09
 * filename:05_单例模式.cpp
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

