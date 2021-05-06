#include<iostream>
#include<system_error>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

class String
{
private:
	char *ptrChars; 

public:
	String(char const * chars = " ");
	String & operator=(String const &);
	void print();

};

int main()
{
	String s("cat");
	String s2("dog");
	s.print();
	s2.print();

	s = s2;
	s.print();
	system("pause");
	return 0;
}

String::String(char const * chars)
{
	chars = chars ? chars : "";
	ptrChars = new char[std::strlen(chars) + 1];
	std::strcpy(ptrChars , chars);
}

String & String::operator=(String const & str)
{
	// TODO: 在此处插入 return 语句
	if (strlen(ptrChars) != strlen(str.ptrChars))
	{
		char * ptrHold = new char[strlen(str.ptrChars) + 1];
		delete[] ptrChars;
		ptrChars = ptrHold;
	}
	std::strcpy(ptrChars, str.ptrChars);
	return  *this;
}

void String::print()
{
	cout << ptrChars << endl;
}
