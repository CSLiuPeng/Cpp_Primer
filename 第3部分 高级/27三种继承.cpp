#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class A
{
public:
	int a;
	A() :a(10), b(20), c(30) {}

	void test()
	{
		cout << a << " " << b << " " << c << endl;
	}
private:
	int b;
protected:
	int c;
};

class B1:public A
{
public:
	void test1()
	{
		cout << a << endl;
	//	cout << b << endl;
		cout << c << endl;
	}
};

class B2 : private A
{
public:
	void test2()
	{
		cout << a << endl;
	//	cout << b << endl;
		cout << c << endl;
	}
};

class B3 :protected A
{
public:
	void test3()
	{
		cout << a << endl;
	//	cout << b << endl;
		cout << c << endl;
	}
};

int main()
{
	B1 b1;
	cout << b1.a << endl;
	b1.test1();

	B2 b2;
//	cout << b2.a << endl;
	b2.test2();

	B3 b3;
	//cout << b3.a << endl;
	b3.test3();

	system("pause");
	return 0;
}