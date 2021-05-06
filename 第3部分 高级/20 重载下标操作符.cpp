#include<iostream>
#include<system_error>

using namespace std;

class String
{
private:
	char * ptrChars;
	static String  errorMessage;

public:
	String(char const * chars = " ");//构造函数
	char & operator[](std::size_t index) throw (String);//可变成员函数运算符重载
	char operator[](std::size_t index) const throw (String);//常量成员函数运算符重载
	void print();
};

int main()
{
	String s("hello");

	cout << s[1] << endl;
	s[0] = 'a';
	s.print();

	String const s2("dog");
	cout << s2[2] << endl;

	system("pause");
	return 0;
}

String::String(char const * chars)
{
	chars = chars ? chars : " ";
	ptrChars = new char[std::strlen(chars) + 1];
	std::strcpy(ptrChars, chars);
}

//可变成员函数运算符重载
char & String::operator[](std::size_t index) throw (String)
{
	cout << "unconst" << endl;
	// TODO: 在此处插入 return 语句
	if (index >= std::strlen(ptrChars))
	{
		throw errorMessage;
	}
	return ptrChars[index];
}

char String::operator[](std::size_t index) const throw(String)
{
	cout << "const" << endl;
	if (index >= std::strlen(ptrChars))
	{
		throw errorMessage;
	}
	return ptrChars[index];
//	return 0;
}

void String::print()
{
	cout << ptrChars << endl;
}

class String String::errorMessage("subscribe out of message!");
