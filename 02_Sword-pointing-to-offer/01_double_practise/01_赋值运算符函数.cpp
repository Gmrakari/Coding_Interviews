

/*
 * Date:2021-07-16 09:45
 * filename:01_赋值运算符函数.cpp
 *
 */

/*
 * 题目:如下为类型CMyString的声明，请为该类型添加赋值运算符函数
 */

class CMyString {
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

private:
	char* m_pData;
};

/*
 * 注意的点:
 * 1、是否把返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用(即*this)。
 * 只有返回一个引用，才可以允许连续赋值。否则如果函数的返回值是void,应用该赋值运算符将不
 * 能做连续赋值。假设有3个CMyString的对象:str1、str2、str3，在程序中语句str1=str2=str3将
 * 不能通过编译
 * 2、是否把传入的参数的类型声明为常量引用。如果传入的参数不是引用而是实例，那么从形参到实参
 * 会调用一次复制构造函数。把参数声明为引用可以避免这样的无谓消耗，能提高代码的效率。同时，
 * 我们在赋值运算符函数内不会改变传入的实例的状态，因此应该为传入的引用参数加上const关键字
 * 3、是否释放实例自身已有的内存。如果我们忘记在分配新内存之前释放自身已有的空间，程序将出现内存泄露
 * 4、是否判断传入的参数和当前的实例(*this)是不是同一个实例。如果是同一个，则不进行赋值操作，
 * 直接返回。如果事先不判断就进行赋值，那么在释放实例自身的内存的时候就会导致严重的问题：当*this
 * 和传入的参数是同一个实例时，那么一旦释放了自身的内存，传入的参数的内存也同时被释放了，因此再也找不到需要赋值
 * 的内容了。
 *
 */

CMyString& CMyString::operator =(const CMyString &str) {
	if (this == &str)
		return *this;

	delete []m_pData;
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

/* 考虑异常安全性的解法，高级程序员必备 */

/*
 * 两种方法:
 * 先用new分配新内容再用delete释放已有的内容。这样只在分配内容成功之后再释放原来的内容，
 * 也就是分配内存失败时我们能确保CMyString的实例不会被修改。
 *
 * 我们还有一个更好的方法就是先创建一个临时实例，再交换临时实例和原来的实例
 *
 */
CMyString& CMyString::operator =(const CMyString &str) {
	if (this != &str) {
		CMyString strTemp(str);
		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

/*
 * 我们先创建一个临时实例strTemp,接着把strTemp.m_pData和实例自身的m_pData做交换。
 * 由于strTemp是一个局部变量，但程序运行到if的外面时也就出了该变量的作用域，就会自动
 * 调用strTemp的析构函数,把strTemp.m_pData所指向的内存释放掉。由于strTemp.m_pData指向
 * 的内存就是实例之前m_pData的内存，这就相当于自动调用析构函数释放实例的内存
 *
 */


