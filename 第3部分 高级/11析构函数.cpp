#include<iostream>
#include<system_error>
#include<string>

using namespace std;
class MyClass
{
public:
	//必须使用析构函数的情况
	MyClass() :ptrString(new std::string), i(0), d(0)
	{
		cout << "构造函数被调用!" << endl;
	}

	~MyClass();

	//复制构造函数的声明
	MyClass(const MyClass & others);

	//复制赋值操作符的声明
	MyClass & operator = ( const MyClass &rhs);
private:
	std::string *ptrString;
	int i;
	double d;
};

//复制构造函数的定义
MyClass::MyClass(const MyClass & others)
{
	ptrString = new string;
	*(ptrString) = *(others.ptrString);
	i = others.i;
	d = others.d;
}

//复制赋值操作符的声明
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
	cout << "析构函数被调用!" << endl;
	delete ptrString;
}

int main()
{
	
//	MyClass m;
	cout << "测试一下!" << endl;

	MyClass * mc = new MyClass;
	delete mc;

	system("pause");
	return 0;
}