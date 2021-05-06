#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class  Sales_item
{
private:
	string isbn;
	unsigned units_sold;
	double revenue;

public:
	//定义默认构造函数
	Sales_item() = default;

	//定义构造函数
	Sales_item(const string & book,   unsigned  count, double amount)
		:isbn(book), units_sold(count), revenue(amount) {}

	//复合运算符重载
	Sales_item & operator +=(const Sales_item &);

	Sales_item & operator -=(const Sales_item &);


	//拷贝构造函数
	Sales_item(const Sales_item &);

	//拷贝赋值操作符
	Sales_item & operator =(const Sales_item &);

	//析构函数
	~Sales_item() {}

	//输出操作符重载
	friend ostream & operator<<(ostream &, Sales_item & );

	//输入操作符重载
	friend istream & operator >>(istream & , Sales_item &);
};

//复合运算符重载定义
Sales_item & Sales_item::operator+=(const Sales_item & rhs)
{
	// TODO: 在此处插入 return 语句
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_item & Sales_item::operator-=(const Sales_item & rhs)
{
	// TODO: 在此处插入 return 语句
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}
//拷贝 复制构造函数
Sales_item::Sales_item(const Sales_item & orign)
	:isbn(orign.isbn), units_sold(orign.units_sold), revenue(orign.revenue)
{
}

//拷贝赋值操作符
Sales_item & Sales_item::operator=(const Sales_item & obj)
{
	// TODO: 在此处插入 return 语句
	isbn = obj.isbn;
	units_sold = obj.units_sold;
	revenue = obj.revenue;
	return *this;
}

//加法运算符重载
Sales_item operator +(Sales_item & lhs, Sales_item & rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

//减法运算符重载
Sales_item operator -(Sales_item & lhs, Sales_item & rhs)
{
	Sales_item ret(lhs);
	ret -= rhs;
	return ret;
}

//输出操作符重载
ostream & operator<<(ostream & out, Sales_item & s)
{
	out << s.isbn << ", " << s.units_sold << " , " << s.revenue;
	return out;
}

//输入运算符重载
istream & operator >>(istream & in, Sales_item & m)
{
	in >> m.isbn >> m.units_sold >> m.revenue;
	return in;
}

int main()
{
	Sales_item item1(string("0-x-123-456-789-xx-y"), 20, 100);
	Sales_item item2(string("0-x-123-456-789-xx-y"), 5, 25);

	cout << item1 + item2 << endl;

	Sales_item  item3, item4;

	cin >> item3 >> item4;
	cout << item3 - item4 << endl;

	system("pause");
	return 0;
}
