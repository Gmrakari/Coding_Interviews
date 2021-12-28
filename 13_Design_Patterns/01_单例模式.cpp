

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
		SingletonConfig(const SingletonConfig&);
		SingletonConfig& operator=(const SingletonConfig&);

	private:
		static SingletonConfig *m_objConfig;
};

SingletonConfig* SingletonConfig::m_objConfig = nullptr;


namespace Axiu {

	//By Axiu
	//饿汉模式
	class singlePattern {
		private:
			singlePattern() {};
			static singlePattern *p;

		public:
			static singlePattern *instance();

			class CG {
				public:
					~CG() {
						if (singlePattern::p != nullptr) {
							delete singlePattern::p;
							singlePattern::p = nullptr;
						}
					}
			};
	};
}

namespace Axiu_2 {

	//懒汉模式
	class singlePattern {
		private:
			static singlePattern *p;
			singlePattern() {}

		public:
			static singlePattern *instance();
			class CG {
				public:
					~CG() {
						if (singlePattern::p != nullptr) {
							delete singlePattern::p;
							singlePattern::p = nullptr;
						}
					}
			};
	};

	singlePattern *singlePattern::p = nullptr;
	singlePattern *singlePattern::instance() {
		if (p == nullptr) {
			return new singlePattern();
		}
		return p;
	}
}

//by bolan
namespace m_singleton {
	class Singleton {
	private:
		Singleton();
		Singleton(const Singleton& other);

	public:
		static Singleton *getinstance();
		static Singleton *m_instance;
	};

	Singleton *Singleton::m_instance = nullptr;

	Singleton *Singleton::getinstance() {
		if (m_instance == nullptr) {
			m_instance = new Singleton();
		}
		return m_instance;
	}

}
