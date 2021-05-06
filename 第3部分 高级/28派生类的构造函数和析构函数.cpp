#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Base1
{
private:
	int b1;

public:
	Base1(int i) :b1(i)
	{
		cout << "Base1中的构造函数被调用!" << endl;
	}

	~Base1()
	{
		cout << "Base1中的*****析构函数*****被调用!" << endl;
	}
	void Print() const
	{
		cout << "b1= " << b1 << endl;
	}
};

class Base2
{
private:
	int b2;

public:
	Base2(int i) :b2(i)
	{
		cout << "Base2中的构造函数被调用!" << endl;
	}

	~Base2()
	{
		cout << "Base2中的*****析构函数*****被调用!" << endl;
	}
	void Print() const
	{
		cout << "b2= " << b2 << endl;
	}
};

class Base3
{
private:
	int b3;

public:
	Base3() :b3(0)
	{
		cout << "Base3中的构造函数被调用!" << endl;
	}

	~Base3()
	{
		cout << "Base3中的*****析构函数*****被调用!" << endl;
	}
	void Print() const
	{
		cout << "b3= " << b3 << endl;
	}
};

class Member
{
private:
	int m;

public:
	Member(int i) :m(i)
	{
		cout << "Member的构造函数被调用!" << endl;
	}
	~Member()
	{
		cout << "Member中的*****析构函数*****被调用!" << endl;
	}

	int  GetM()
	{
		return m;
	}
};

class Derived :public Base1, public Base2, public Base3
{
public:
	Derived(int i, int j , int k, int l):Base1(i), Base2(j), mem(k), d(l)
	{
		cout << "Derived的构造函数被调用!" << endl;
	}

	/*~Derived()
	{
		cout << "Derived中的*****析构函数*****被调用!" << endl;
	}*/
	void Print();

private:
	int d;
	Member mem;
};

int main()
{
	Derived d(1,2,3,4);
	d.Print();

	cout << "函数正常运行！" << endl;
	system("pause");
	return 0;
}

void Derived::Print()
{
	Base1::Print();
	Base2::Print();
	Base3::Print();
	cout << mem.GetM() << endl;
	cout <<"d= "<< d << endl;
}
