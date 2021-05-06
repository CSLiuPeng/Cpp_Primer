#include<iostream>
#include<system_error>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

class Sales_item
{
public:
	//普通构造函数

	Sales_item() :units_solds(0), revenue(0.0) //默认构造函数
	{
		cout << "默认构造函数被调用了!" << endl;
	} 

	Sales_item(const string & book) :
		isbn(book), units_solds(0), revenue(0.0)
	{
		cout << "构造函数Sales_item(const string & book) 被调用！" << endl;
	}

	//当一个类的成员是指针的时候
	//必须自己定义复制构造函数和赋值操作符

	//复制构造函数
	Sales_item(const Sales_item & orign) 
		:isbn(orign.isbn), units_solds(orign.units_solds), revenue(orign.revenue) 
	{
		cout << "复制构造函数被调用！" << endl;
	}

	//赋值操作符
	Sales_item & operator =(const Sales_item &rhs)
	{
		cout << "赋值操作符被调用!" << endl;
		isbn = rhs.isbn;
		units_solds = rhs.units_solds;
		revenue = rhs.revenue;
		return *this;
	}

private:
	string isbn; //书号
	int units_solds; //销售数量
	double revenue; //销售金额
};

Sales_item  foo(Sales_item item)
{
	Sales_item temp;
	temp = item;
	return temp;
}

class Noname
{
public:
	//构造函数
	Noname() :pstring(new string), i(0), d(0.0) {}

	//复制构造函数
	Noname(const Noname & others)
		:pstring(new string(*(others.pstring))), i(others.i), d(others.d) 
	{
		cout << "Noname 复制构造函数被调用了!" << endl;
	}

	//赋值操作符
	Noname & operator = (const Noname & rhs)
	{
		cout << "Noname 赋值操作符被调用了!" << endl;
		pstring = new string;
		*pstring = *(rhs.pstring);
		i = rhs.i;
		d = rhs.d;
		return * this;
	}

private:
	string * pstring;
	int i;
	double d;
};

int main()
{
	Sales_item a;
	Sales_item b("0-x-1235-4");

	Sales_item c(b);
	a = b;
	Sales_item iter = string("0-y-123-34532-998");

	cout << endl << "测试一下函数foo：" << endl;

	Sales_item ret;
	ret = foo(iter);

	cout << endl << "测试一下向量vector：" << endl;

	vector<Sales_item> svec(8);

	cout << endl << "测试一下数组: " << endl;

	Sales_item sales[] = {
		string("0-x-123-454-98"),
		string("0-x-123-454-97"),
		string("0-x-123-454-96"),
		string("0-x-123-454-95"),
		Sales_item()
	};

	cout << endl << "测试一下Noname这个类: " << endl;

	Noname x, y;
	Noname z(x);
	x = y;

	system("pause");
	return 0;
}