#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Item_Base
{
private:
	string isbn;

protected:
	double price;

public:
	Item_Base() = default;
	Item_Base(const  string & book, double p) :isbn(book), price(p) {}
	~Item_Base() {}

	string book() const
	{
		return isbn;
	}

	virtual double net_price(int n) const
	{
		return n * price;
	}
};

class Bulk_Item :public Item_Base
{
private:
	rsize_t min_qty;
	double discount;

public:
	Bulk_Item() = default;
	//派生类的构造函数
	Bulk_Item(const string & book, double p, size_t qty, double dis)
		:Item_Base(book, p), min_qty(qty), discount(dis) {}

	double net_price(size_t cnt) const
	{
		if (cnt > discount)
		{
			return cnt * (1 - discount) * price;
		}
		else
		{
			return cnt * price;
		}
	}

protected:

};

void print_total(ostream & os, Item_Base * item, size_t n)
{
	os << "ISBN: " << item->book() << " " << "number sold: " << n 
		<< " " << "price: " << item->net_price(n) << endl;
}

int main()
{
	//定义一个指针数组
	Item_Base * books[6];
	//指向基类的指针数组既可以指向基类，也可以指向派生类
	books[0] = new Item_Base("0-x-123456-0", 10.00);
	books[1] = new Bulk_Item("0-x-123456-1", 20.00, 2, 0.20);

	books[2] = new Item_Base("0-x-123456-3", 30.00);
	books[3] = new Bulk_Item("0-x-123456-4", 40.00, 4, 0.30);

	books[4] = new Item_Base("0-x-123456-5", 50.00);
	books[5] = new Bulk_Item("0-x-123456-6", 60.00, 6, 0.40);

	int num[6] = {2,4,5,1,7,8};

	Item_Base * a = new Item_Base("0-x-123456-0", 15.00);
	Item_Base * b = new Bulk_Item("0-x-123456-1", 25.00, 20, 0.20);

	print_total(cout, a, 2);
	print_total(cout, b, 3);
	cout << endl << endl;

	for ( int i = 0; i < 6; i++)
	{
		print_total(cout, books[i], num[i]);
	}

	system("pause");
	return 0;
}