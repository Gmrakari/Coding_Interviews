

/*
 * Date:2021-07-28 12:18
 * filename:48_不能被继承的类.cpp
 *
 */

/*
 * #2 题意
题目描述

设计一个不能被继承的类

Java中有final表示一个类型不能被继承

C#中也有定义sealed修饰的类不能被继承


常规的解法：把构造函数设为私有函数


*/


class SealedClass1 {
	public:
		static SealedClass1* GetInstance() {
			return new SealedClass1();
		}

		static void DeleteInstance(SealedClass1* pInstance) {
			delete pInstance;
		}

	private:
		SealedClass1() {}
		~SealedClass1() {}
};



/*
 * 新奇的解法:利用虚拟继承
 *
 */

template <typename T> class MakeSealed {
	friend T;

	private:
		MakeSealed() {}
		~MakeSealed() {}
};

class SealedClass2 : virtual public MakeSealed<SealedClass2> {
public:
	SealedClass2() {}
	~SealedClass2() {}
};


