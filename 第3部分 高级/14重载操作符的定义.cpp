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
	//对于C++的内置类型，不需要进行运算符重载
	int a = 10, b = 5;
	cout << a + b << endl;

	//对于自建的类型，如类类型，必须进行运算符重载
	MyClass mc, mc2;
//	cout << mc + mc2 << endl;
	
	system("pause");
	return 0;
}