#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class String
{
private:
	char * ptrChars;

public:
	String(char const * chars = " ");
	String(String const & str);
	~String();

	void display() const;
	//前置返回引用
	String & operator++();//前置自增运算符
	//后置返回拷贝
	String const operator++(int );//后置自增运算符
};

int main()
{
	String a("abcdefgh");
	a.display();
	a++;
	a.display();

	++a;
	a.display();

	system("pause");
	return 0;
}

String::String(char const * chars)
{
	chars = chars ? chars : " ";
	ptrChars = new char[std::strlen(chars) + 1];
	std::strcpy(ptrChars, chars);
}

String::String(String const & str)
{
	ptrChars = new char[std::strlen(str.ptrChars) + 1];
	std::strcpy(ptrChars , str.ptrChars);
}

String::~String()
{
	delete[] ptrChars;
}

void String::display() const
{
	cout << ptrChars << endl;
}

String & String::operator++()
{
	// TODO: 在此处插入 return 语句
	for (size_t i = 0; i < std::strlen(ptrChars); i++)
	{
		++ptrChars[i];
	}
	return *this;
}

String const String::operator++(int)
{
	String copy(*this);
	++(*this);
	return copy;
}
