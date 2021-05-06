#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Sales_item
{
private:
	string isbn; //���
	unsigned units_sold;  //��������
	double revenue; //�����ܽ��
public:
	//���캯��
	Sales_item(const string  & book, unsigned   units,  double  amount)
		:isbn(book), units_sold(units), revenue(amount) { }

	//����ƽ���۸�
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

	//�ж������������Ƿ���ͬ
	bool same_isbn(const Sales_item & rhs) const
	{
		return isbn == rhs.isbn;
	}

	//���ۼ�¼����
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
	Person a("Lucy", "��Ŵ��123��");

	Person b = a;
	cout << a.getName()<< ", " << a.getAddress() << endl;

	cout << b.getAddress() << ", " << b.getName() << endl;

	cout << "���гɹ�!" << endl;

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