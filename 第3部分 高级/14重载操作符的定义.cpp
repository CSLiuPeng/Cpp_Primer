#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();
	
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
	//����C++���������ͣ�����Ҫ�������������
	int a = 10, b = 5;
	cout << a + b << endl;

	//�����Խ������ͣ��������ͣ�����������������
	MyClass mc, mc2;
//	cout << mc + mc2 << endl;
	
	system("pause");
	return 0;
}