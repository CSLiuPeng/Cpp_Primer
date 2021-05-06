#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Sales_item
{
public:
	//定义构造函数
	Sales_item(std::string & book):isbn(book) , units_sold(0), revenue(0.0){}

	//构造函数的重载
	Sales_item() :units_sold(0), revenue(0.0) {}

	//构造函数的重载，且对流输入运算符重载
	Sales_item(std::istream & is) 
	{ 
		is >> *this;
	}

	//创建运算符重载函数
	friend istream & operator >>(istream & , Sales_item &);

private:
	std::string isbn;//书号
	unsigned units_sold; //销售数量
	double revenue; //销售金额
};

//重载流输入运算符
inline istream & operator>>(istream & in, Sales_item & s)
{
	double price;//定义单价
	in >> s.isbn >> s.units_sold >> price;
	if (in)
	{
		s.revenue = s.units_sold * price;
	}
	else
	{
		s = Sales_item();
	}
	return in;
}

int main()
{
	system("pause");
	return 0;
}