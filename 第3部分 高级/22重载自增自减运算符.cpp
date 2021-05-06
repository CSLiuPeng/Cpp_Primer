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
	//ǰ�÷�������
	String & operator++();//ǰ�����������
	//���÷��ؿ���
	String const operator++(int );//�������������
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
	// TODO: �ڴ˴����� return ���
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
