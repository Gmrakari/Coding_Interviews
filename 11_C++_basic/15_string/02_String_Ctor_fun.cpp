

/*
 * Date:2021-12-01 15:47
 * filename:15_02_String_的构造函数.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

class String {
public:
	String(const char* cstr = 0);
	String(const String& str);
	String& operator=(const String& str);

private:
	char* m_data;
};

inline String::String(const char* cstr) {
	if (cstr) {
		m_data = new char[strlen(cstr) + 1];
		assert(m_data != NULL);
		strcpy(m_data, cstr);

	} else {
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline String::String(const String& str) {
	m_data = new char[strlen(str.m_data) + 1];
	assert(m_data != NULL);
	strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str) {
	if (this == &str)
		return *this;

	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	assert(m_data != NULL);
	strcpy(m_data, str.m_data);

	return *this;
}
