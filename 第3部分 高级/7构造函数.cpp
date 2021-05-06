#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Sales_item
{
public:
	//���幹�캯��
	Sales_item(std::string & book):isbn(book) , units_sold(0), revenue(0.0){}

	//���캯��������
	Sales_item() :units_sold(0), revenue(0.0) {}

	//���캯�������أ��Ҷ����������������
	Sales_item(std::istream & is) 
	{ 
		is >> *this;
	}

	//������������غ���
	friend istream & operator >>(istream & , Sales_item &);

private:
	std::string isbn;//���
	unsigned units_sold; //��������
	double revenue; //���۽��
};

//���������������
inline istream & operator>>(istream & in, Sales_item & s)
{
	double price;//���嵥��
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