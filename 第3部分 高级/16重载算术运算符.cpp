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
	//����Ĭ�Ϲ��캯��
	Sales_item() = default;

	//���幹�캯��
	Sales_item(const string & book,   unsigned  count, double amount)
		:isbn(book), units_sold(count), revenue(amount) {}

	//�������������
	Sales_item & operator +=(const Sales_item &);

	Sales_item & operator -=(const Sales_item &);


	//�������캯��
	Sales_item(const Sales_item &);

	//������ֵ������
	Sales_item & operator =(const Sales_item &);

	//��������
	~Sales_item() {}

	//�������������
	friend ostream & operator<<(ostream &, Sales_item & );

	//�������������
	friend istream & operator >>(istream & , Sales_item &);
};

//������������ض���
Sales_item & Sales_item::operator+=(const Sales_item & rhs)
{
	// TODO: �ڴ˴����� return ���
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_item & Sales_item::operator-=(const Sales_item & rhs)
{
	// TODO: �ڴ˴����� return ���
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}
//���� ���ƹ��캯��
Sales_item::Sales_item(const Sales_item & orign)
	:isbn(orign.isbn), units_sold(orign.units_sold), revenue(orign.revenue)
{
}

//������ֵ������
Sales_item & Sales_item::operator=(const Sales_item & obj)
{
	// TODO: �ڴ˴����� return ���
	isbn = obj.isbn;
	units_sold = obj.units_sold;
	revenue = obj.revenue;
	return *this;
}

//�ӷ����������
Sales_item operator +(Sales_item & lhs, Sales_item & rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

//�������������
Sales_item operator -(Sales_item & lhs, Sales_item & rhs)
{
	Sales_item ret(lhs);
	ret -= rhs;
	return ret;
}

//�������������
ostream & operator<<(ostream & out, Sales_item & s)
{
	out << s.isbn << ", " << s.units_sold << " , " << s.revenue;
	return out;
}

//�������������
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
