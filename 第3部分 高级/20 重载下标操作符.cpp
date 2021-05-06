#include<iostream>
#include<system_error>

using namespace std;

class String
{
private:
	char * ptrChars;
	static String  errorMessage;

public:
	String(char const * chars = " ");//���캯��
	char & operator[](std::size_t index) throw (String);//�ɱ��Ա�������������
	char operator[](std::size_t index) const throw (String);//������Ա�������������
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

//�ɱ��Ա�������������
char & String::operator[](std::size_t index) throw (String)
{
	cout << "unconst" << endl;
	// TODO: �ڴ˴����� return ���
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
