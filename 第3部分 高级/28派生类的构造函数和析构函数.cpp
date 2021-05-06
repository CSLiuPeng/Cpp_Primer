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
		cout << "Base1�еĹ��캯��������!" << endl;
	}

	~Base1()
	{
		cout << "Base1�е�*****��������*****������!" << endl;
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
		cout << "Base2�еĹ��캯��������!" << endl;
	}

	~Base2()
	{
		cout << "Base2�е�*****��������*****������!" << endl;
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
		cout << "Base3�еĹ��캯��������!" << endl;
	}

	~Base3()
	{
		cout << "Base3�е�*****��������*****������!" << endl;
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
		cout << "Member�Ĺ��캯��������!" << endl;
	}
	~Member()
	{
		cout << "Member�е�*****��������*****������!" << endl;
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
		cout << "Derived�Ĺ��캯��������!" << endl;
	}

	/*~Derived()
	{
		cout << "Derived�е�*****��������*****������!" << endl;
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

	cout << "�����������У�" << endl;
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
