#include<iostream>
#include<system_error>
#include<string>

using namespace std;
class MyClass
{
public:
	//����ʹ���������������
	MyClass() :ptrString(new std::string), i(0), d(0)
	{
		cout << "���캯��������!" << endl;
	}

	~MyClass();

	//���ƹ��캯��������
	MyClass(const MyClass & others);

	//���Ƹ�ֵ������������
	MyClass & operator = ( const MyClass &rhs);
private:
	std::string *ptrString;
	int i;
	double d;
};

//���ƹ��캯���Ķ���
MyClass::MyClass(const MyClass & others)
{
	ptrString = new string;
	*(ptrString) = *(others.ptrString);
	i = others.i;
	d = others.d;
}

//���Ƹ�ֵ������������
MyClass & MyClass::operator=(const MyClass & rhs)
{
	ptrString = new string;
	*(ptrString) = *(rhs.ptrString);
	i = rhs.i;
	d = rhs.d;
	return *this;
}

MyClass::~MyClass()
{
	cout << "��������������!" << endl;
	delete ptrString;
}

int main()
{
	
//	MyClass m;
	cout << "����һ��!" << endl;

	MyClass * mc = new MyClass;
	delete mc;

	system("pause");
	return 0;
}