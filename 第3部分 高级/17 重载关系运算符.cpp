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
	//Ĭ�Ϲ��캯��
	Sales_item() = default;

	//���캯��
	Sales_item(string & book, unsigned count, double amount)
		:isbn(book), units_sold(count), revenue(amount) {}

	//�������캯��
	Sales_item(const  Sales_item & rhs)
		:isbn(rhs.isbn), units_sold(rhs.units_sold), revenue(rhs.revenue) {}

	//��������
	~Sales_item()
	{}

	//������ֵ�����
	Sales_item & operator=(const Sales_item & lhs)
	{
		isbn = lhs.isbn;
		units_sold = lhs.units_sold;
		revenue = lhs.revenue;
		return *this;
	}

	//���������������
   	friend istream & operator>>(istream & is,  Sales_item & ths)
	{
		double price;
		is >> ths.isbn  >> ths.units_sold >> ths.revenue;
		//��������Ƿ�ɹ�
		if (is)
		{
			ths.revenue = ths.units_sold * price;
		}
		else    //�������ʧ�ܣ�����Ĭ�Ϲ��캯�����г�ʼ��
		{
			ths = Sales_item();
		}
		return is;
	}

   //��������������
   friend ostream & operator<<(ostream & os, const Sales_item & ehs)
   {
	   os << ehs.isbn << " " << ehs.units_sold << " " << ehs.revenue;
	   return os;
   }

   //���ϸ�ֵ�����(+=)
   Sales_item &  operator+=(const Sales_item & item)
   {
	   units_sold += item.units_sold;
	   revenue += item.revenue;
	   return *this;
   }

   //���ؼӷ������
   friend Sales_item   operator +(const Sales_item & lhs,  const Sales_item & rhs)
   {
	   Sales_item sum = lhs;
	   sum += rhs;
	   return sum;
   }

   //���ظ����������-=��
   Sales_item & operator -=(Sales_item & items)
   {
	   units_sold -= items.units_sold;
	   revenue -= items.revenue;
	   return *this;
   }

   //���ؼ��������
   friend Sales_item  operator -(Sales_item & lhs, Sales_item & rhs)
   {
	   Sales_item minus = lhs;
	   minus -= rhs;
	   return minus;
   }

   //������������
   friend bool  operator==(const Sales_item & lhs, const Sales_item & rhs)
   {
	   return lhs.isbn == rhs.isbn
		   && lhs.units_sold == rhs.units_sold
		   && lhs.revenue == rhs.revenue;
   }

   //���ز��������
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
	//�����±������,�ǳ����汾
	string & operator[](size_t n)
	{
		return elements[n];
	}

	//�����±�������������汾
	const string & operator[](size_t n) const
	{
		return elements[n];
	}

	//���ص����ݼ������
	//����ǰ�õ��������
	StrVec & operator--()//ǰ��
	{
	//	check(curr, "�Ѿ���β��");
	}
};

int main()
{
	system("pause");
	return 0;
}