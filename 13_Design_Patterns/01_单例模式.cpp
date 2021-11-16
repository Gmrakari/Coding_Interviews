

/*
 * Date:2021-11-16 20:29
 * filename:01_单例模式.cpp
 *
 */

class SingletonConfig {
public:
	static SingletonConfig* GetInstance() {
		if (m_objConfig == nullptr) 
			m_objConfig = new SingletonConfig;
		return m_objConfig;
	}

private:
	SingletonConfig() {;}
	SingletonConfig(const SingletonConfig&) {;}
	SingletonConfig& operator=(const SingletonConfig&) { ;};

private:
	static SingletonConfig *m_objConfig;
};

SingletonConfig* SingletonConfig::m_objConfig = nullptr;
