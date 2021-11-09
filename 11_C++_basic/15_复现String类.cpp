

/*
 * Date:2021-11-09 09:22
 * filename:15_复现String类.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

class String {
public:
		//C++的缺省函数
		//1.默认构造函数(不带参数的构造函数)
		//2.析构函数
		//3.赋值函数(operator=) 按字节拷贝
		//4.拷贝构造函数(用一个对象拷贝另外一个对象) (按字节拷贝)
		//
		//注意由于3和4是按字节拷贝，如果类中有指针，会变成浅拷贝，所以注意有指针的时候自己写,通常来说，要么全部接受要么全部重写
		//
		//c++11中加了俩函数变成6个(默认构造＋big five)
		//5、移动构造函数
		//6、移动赋值函数
		//
		//c++引入右值和move，5,6可以提升效率。

	String(const char* str = NULL);//通用构造函数
	String(const String &str);	//拷贝构造函数
	~String();									//析构函数

	String operator+(const String &str) const;//重载+
	String& operator=(const String &str);	//重载=
	String& operator+=(const String &str);		//重载+=
	bool operator==(const String &str) const; //重载==
	char& operator[](int) const;	//重载[]

	size_t size() const;//获取长度
	const char* c_str() const; //获取C字符

	friend istream& operator>>(istream &is, String &str);//输入
	friend ostream& operator<<(ostream &os, const String &str);//输出

private:
	/*
		char* _str;//_size:有效字符的个数,不包含\0
		size_t _size;	//_capacity:能够存放最大有效字符的个数
		size_t _capacity;
		static const size_t npos;//静态成员在类外初始化
	*/
	char *data;//字符串
	size_t length;//长度

	//注:
	//类的成员函数中，加const，表示这个函数不会对类的成员进行任何修改
	//一些函数的输入参数也加了const，表示该函数不会对改变这个参数的值
};

//const size_t String::npos = -1;

String::String(const char *str) {//通用构造函数
	if (!str) {
		length = 0;
		data = new char[1];
		*data = '\0';
	}
	else {
		length = strlen(str);
		data = new char[length + 1];
		strcpy(data, str);
	}
}

/*
String::String(const string &str) {//拷贝构造函数
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.c_str());
}
*/

//析构函数需要进行内存的释放及长度的归零
String::~String() {
	delete[] data;
	length = 0;
}

//重载字符串连接运算，这个运算会返回一个新的字符串
String String::operator+(const String &str) const { //重载+
	String newString;
	newString.length = length + str.size();
	newString.data = new char[newString.length + 1];
	strcpy(newString.data, data);
	strcat(newString.data, str.data);
	return newString;
}

//重载字符串赋值运算，这个运算会改变原有字符串的值，为了避免内存泄漏，这里释放了原先申请的内存再重新申请一块适当大小的内存存放新的字符串
String& String::operator=(const String &str) { //重载=
	if (this == &str)
		return *this;
	delete[] data;
	length = str.length;
	data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}

String& String::operator+=(const String &str) {
	length += str.length;
	char* newData = new char[length + 1];
	strcpy(newData, data);
	strcat(newData, str.data);
	delete[] data;
	data = newData;
	return *this;
}

//定义为内敛函数，加速运行速度
inline bool String::operator==(const String &str) const {
	if (length != str.length)
		return false;
	return strcmp(data, str.data) ? false : true;
}

//重载字符串索引运算符，进行了一个简单的错误处理，当长度太大时自动读取最后一个字符
inline char& String::operator[](int n) const {
	if (n >= (int)length)
		return data[length - 1];	//错误处理
	else
		return data[n];
}

inline size_t String::size() const {
	return length;
}

inline const char* String::c_str() const {
	return data; 
}

istream& operator>>(istream &is, String &str) {
	char temp[1000];
	is >> temp;
	str.length = strlen(temp);
	str.data = new char[str.length + 1];
	strcpy(str.data, temp);
	return is;
}

ostream& operator<<(ostream &os, const String &str) {
	if (str.data != NULL) {
		os << str.data;
	}
	return os;
}

void test() {
	String s;
	cin >> s;
	cout << s << ":" << s.size() << endl;

	char a[] = "hello", b[] = "world!";
	String s1(a), s2(b);
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	
	cout << s1 << "+" << s2 << "=" << s1 + s2 << endl;

	String s3 = s1 + s2;
	cout << "s3:" << s3 << endl;

	if (s1 == s3)
		cout << "First:s1 == s3" << endl;
	s1 += s2;
	if (s1 == s3) 
		cout << "First:s1 == s3" << endl;
}

int main() {
	test();
}
