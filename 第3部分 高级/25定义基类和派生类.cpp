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
	Item_Base(const  string & book , double p) :isbn(book), price(p) {}
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

class Bulk_Item:public Item_Base
{
private:
	rsize_t min_qty;
	double discount;

public:
	Bulk_Item() = default;
	//派生类的构造函数
	Bulk_Item(const string & book, double p, size_t qty, double dis) 
		:Item_Base(book , p), min_qty(qty), discount(dis){}

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

int main()
{
	Item_Base item1("0-x-123-456-789", 35.9);
	cout << item1.net_price(10) << endl;

	Bulk_Item item2("0-x-123-456-789", 35.9, 20, 0.2);
	cout << item2.net_price(40) << endl;

	system("pause");
	return 0;
}