#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Sales_item
{
private:
	string isbn; //书号
	unsigned units_sold;  //销售数量
	double revenue; //销售总金额
public:
	//构造函数
	Sales_item(const string  & book, unsigned   units,  double  amount)
		:isbn(book), units_sold(units), revenue(amount) { }

	//计算平均价格
	double average_price()  const 
	{
		if (units_sold)
		{
			return  revenue / units_sold;
		}
		else
		{
			return 0;
		}
	}

	//判断两本书的书号是否相同
	bool same_isbn(const Sales_item & rhs) const
	{
		return isbn == rhs.isbn;
	}

	//销售记录叠加
	void add_units(const Sales_item & rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
	}
};

class Person 
{
private:
	string name;
	string address;
public:
	Person(const string & nm, const string & ad): name(nm), address(ad)
	{
		/*name = nm;
		address = ad;*/
	}

	string getName() const
	{
		return name;
	}

	string getAddress() const
	{
		return address;
	}
};

int main()
{
	Person a("Lucy", "解放大道123号");

	Person b = a;
	cout << a.getName()<< ", " << a.getAddress() << endl;

	cout << b.getAddress() << ", " << b.getName() << endl;

	cout << "运行成功!" << endl;

	cout << "-------------2nd example-------------" << endl;

	Sales_item x(string("1-273-981-7"), 5, 60.00);
	Sales_item y(string("1-273-981-7"), 10, 120.00);

	if (x.same_isbn(y))
	{
		x.add_units(y);
	}

	cout << x.average_price() << endl;
	system("pause");
	return 0;
}