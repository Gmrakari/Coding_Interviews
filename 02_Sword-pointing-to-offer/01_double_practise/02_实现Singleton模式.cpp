

/*
 * Date:2021-07-16 10:11
 * filename:02_实现Singleton模式.cpp
 *
 */

/* 设计一个类，我们只能生成该类的一个实例 */

/* 不好的解法一:只适用于单线程环境 */

public sealed class Singleton1 {
	private Singleton1() {  

	}
	
	private static Singleton1 instance = null;
	public static Singleton1 Instance {
		get {
			if (instance == null)
				instance = new Singleton1();
			return instance;
		}
	}
}

/* 不好的解法二:虽然在多县城环境中能工作但效率不高 */
public sealed class Singleton2 {
	private Singleton2() {

	}

	private static readonly object syncObj = new object();
	private static Singleton2 instance = null;
	public static Singleton2 Instance {
		get {
			lock(syncObj) {
				if (instance == null )
					instance = new Singleton2();
			}
			return instance;
		}
	}
}

/* 可行的解法，加同步锁前后两次判断实例是否已存在 */
public sealed class Singleton3 {
	private Singleton3() {

	}
	private static object synObj = new object();

	private static Singleton3 instance = null;
	public static Singleton3 Instance {
		get {
			if (instance == null) {
				lock(syncObj) {
					if (instance == null) 
						instance = new Singleton3();
				}
			}
			return instance;
		}
	}
}

/* By axiu */
/* 恶汉模式 */
class singlePattern {
private:
	singlePattern() {};
	static singlePattern* p;

public:
	static singlePattern* instance();

	class CG {
		public:
			~CG() {
				if (singlePattern::p != nullptr) {
					delete singlePattern::p;
					singlePattern::p = nullptr;
				}
			}
	};
	singlePattern* singlePattern::p = new singlePattern();
	singlePattern* singlePattern::instance() {
		return p;
	}
};

/* 懒汉模式 */
class singlePattern {
private:
	static singlePattern* p;
	singlePattern() {}

public:
	static singlePattern* instance();
	class CG {
	public:
		~CG() {
			if (singlePattern::p != nullptr) {
				delete singlePattern::p;
				singlePattern::p = nullptr;
			}
		}
	};
	singlePattern* singlePattern::p = nullptr;
	singlePattern* singlePattern::instance() {
		if (p == nullptr) {
			return new singlePattern();
		}
		return p;
	}
}
