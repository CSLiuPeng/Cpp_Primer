#include<iostream>
#include<system_error>
#include<string>
#include<cstdlib>

using namespace std;

class MyClass
{
public:
	//构造函数
	MyClass(int pa, char * cstr) 
	{
		a = pa;
		str = new char[100];
		strcpy(str , cstr);
	}

	//析构函数
	~MyClass()
	{
		delete str;
	}

	//复制构造函数
	MyClass(MyClass & obj)
	{
		a = obj.a;
	//	str = obj.str;//浅复制，需要深复制才行
		str = new char[100];
		if (str != 0)
		{
			strcpy(str , obj.str);
		}
	}
	
public:
	int a;
	char * str;//一个数据成员是指针，则需要深复制
	//如果调用了系统资源，则也需要深复制
};

int main()
{
	MyClass mc(100, "hello");

	cout << mc.a << ", " << mc.str << endl;

	MyClass md = mc;

	cout << md.a << ", " << md.str << endl;

	md.a = 8;
	md.str[0] = 'k';

	cout << md.a << ", " << md.str << endl;
	cout << mc.a << ", " << mc.str << endl;


	system("pause");
	return 0;
}