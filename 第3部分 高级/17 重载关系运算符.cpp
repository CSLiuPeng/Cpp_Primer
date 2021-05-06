#include<iostream>
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<system_error>

using namespace std;

class Sales_item
{
private:
	string isbn;
	unsigned units_sold;
	double revenue;
public:
	//默认构造函数
	Sales_item() = default;

	//构造函数
	Sales_item(string & book, unsigned count, double amount)
		:isbn(book), units_sold(count), revenue(amount) {}

	//拷贝构造函数
	Sales_item(const  Sales_item & rhs)
		:isbn(rhs.isbn), units_sold(rhs.units_sold), revenue(rhs.revenue) {}

	//析构函数
	~Sales_item()
	{}

	//拷贝赋值运算符
	Sales_item & operator=(const Sales_item & lhs)
	{
		isbn = lhs.isbn;
		units_sold = lhs.units_sold;
		revenue = lhs.revenue;
		return *this;
	}

	//重载流输入运算符
   	friend istream & operator>>(istream & is,  Sales_item & ths)
	{
		double price;
		is >> ths.isbn  >> ths.units_sold >> ths.revenue;
		//检查输入是否成功
		if (is)
		{
			ths.revenue = ths.units_sold * price;
		}
		else    //如果输入失败，调用默认构造函数进行初始化
		{
			ths = Sales_item();
		}
		return is;
	}

   //重载流输出运算符
   friend ostream & operator<<(ostream & os, const Sales_item & ehs)
   {
	   os << ehs.isbn << " " << ehs.units_sold << " " << ehs.revenue;
	   return os;
   }

   //复合赋值运算符(+=)
   Sales_item &  operator+=(const Sales_item & item)
   {
	   units_sold += item.units_sold;
	   revenue += item.revenue;
	   return *this;
   }

   //重载加法运算符
   friend Sales_item   operator +(const Sales_item & lhs,  const Sales_item & rhs)
   {
	   Sales_item sum = lhs;
	   sum += rhs;
	   return sum;
   }

   //重载复合运算符（-=）
   Sales_item & operator -=(Sales_item & items)
   {
	   units_sold -= items.units_sold;
	   revenue -= items.revenue;
	   return *this;
   }

   //重载减法运算符
   friend Sales_item  operator -(Sales_item & lhs, Sales_item & rhs)
   {
	   Sales_item minus = lhs;
	   minus -= rhs;
	   return minus;
   }

   //重载相等运算符
   friend bool  operator==(const Sales_item & lhs, const Sales_item & rhs)
   {
	   return lhs.isbn == rhs.isbn
		   && lhs.units_sold == rhs.units_sold
		   && lhs.revenue == rhs.revenue;
   }

   //重载不等运算符
   friend bool operator !=(const Sales_item & lhs, const Sales_item & rhs)
   {
	   return !(lhs == rhs);
   }

};

class StrVec 
{
private:
	string * elements;
	int curr;
public:
	//定义下标运算符,非常量版本
	string & operator[](size_t n)
	{
		return elements[n];
	}

	//定义下标运算符，常量版本
	const string & operator[](size_t n) const
	{
		return elements[n];
	}

	//重载递增递减运算符
	//重载前置递增运算符
	StrVec & operator--()//前置
	{
	//	check(curr, "已经到尾了");
	}
};

int main()
{
	system("pause");
	return 0;
}