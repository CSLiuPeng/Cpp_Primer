#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Sales_item
{
private:
	string isbn;
	unsigned units_sold;
	double revenue;

public:
	//构造函数
	Sales_item(string & book, unsigned count,  double amount)
		:isbn(book), units_sold(count),  revenue(amount) {}

	//默认构造函数
	Sales_item() :units_sold(0), revenue(0.0)  {}

	//拷贝构造函数
	Sales_item(const  Sales_item & rhs)
		:isbn(rhs.isbn), units_sold(rhs.units_sold), revenue(rhs.revenue) {}

	//拷贝赋值运算符
	Sales_item & operator =(const  Sales_item & orign);

	//移动构造函数
	Sales_item(Sales_item && lhs) noexcept ;

	//移动赋值操作符
	Sales_item & operator =(Sales_item && rhs) noexcept;

	//析构函数
	~Sales_item() {}

	//重载输出操作符
	friend ostream & operator <<(ostream &, Sales_item & );

	//重载输入运算符
	friend istream & operator >>(istream & , Sales_item &);

	//重载+运算符
	friend Sales_item  operator +(Sales_item & , Sales_item &);

};

Sales_item  operator +(Sales_item & lhs, Sales_item & rhs)
{
	Sales_item sum = lhs;
	sum = sum + rhs;
	return sum;
}

Sales_item & Sales_item::operator =(const  Sales_item & orign)
{
	isbn = orign.isbn;
	units_sold = orign.units_sold;
	revenue = orign.revenue;
	return *this;
}

Sales_item::Sales_item(Sales_item && lhs) noexcept
	:isbn(lhs.isbn), units_sold(lhs.units_sold), revenue(lhs.revenue)
{
	lhs.isbn = nullptr;
//	lhs.isbn = lhs.units_sold = lhs.revenue;
}

Sales_item & Sales_item::operator=(Sales_item && rhs) noexcept
{
	// TODO: 在此处插入 return 语句
	if (this != &rhs)
	{
//		free();
		isbn = rhs.isbn;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		rhs.isbn = nullptr;
//		rhs.isbn = rhs.units_sold = rhs.revenue = nullptr;
	}
	return * this;
}

 istream & operator >>(istream & in, Sales_item & s)
{
	in >> s.isbn >> s.units_sold >> s.revenue;
	return in;
}

 ostream & operator <<(ostream & out, Sales_item & s)
{
	out << s.isbn << ", " << s.units_sold << " , " << s.revenue << endl;
	return out;
}

int main()
{
	Sales_item item(string("0-x-123-978-xx"), 25, 125.00);
	cout <<"item: "<< item << endl;

	Sales_item item2, item3, item4;
	cin >> item2;
	cout <<"item2: "<< item2 << endl;

	item3 = item;
	cout <<"item3: "<< item3 << endl;

	item4 = item + item2;
	cout << "item4: " << item4 << endl;

	system("pause");
	return 0;
}