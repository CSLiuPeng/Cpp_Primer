#include<iostream>
#include<system_error>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

class Sales_item
{
public:
	//��ͨ���캯��

	Sales_item() :units_solds(0), revenue(0.0) //Ĭ�Ϲ��캯��
	{
		cout << "Ĭ�Ϲ��캯����������!" << endl;
	} 

	Sales_item(const string & book) :
		isbn(book), units_solds(0), revenue(0.0)
	{
		cout << "���캯��Sales_item(const string & book) �����ã�" << endl;
	}

	//��һ����ĳ�Ա��ָ���ʱ��
	//�����Լ����帴�ƹ��캯���͸�ֵ������

	//���ƹ��캯��
	Sales_item(const Sales_item & orign) 
		:isbn(orign.isbn), units_solds(orign.units_solds), revenue(orign.revenue) 
	{
		cout << "���ƹ��캯�������ã�" << endl;
	}

	//��ֵ������
	Sales_item & operator =(const Sales_item &rhs)
	{
		cout << "��ֵ������������!" << endl;
		isbn = rhs.isbn;
		units_solds = rhs.units_solds;
		revenue = rhs.revenue;
		return *this;
	}

private:
	string isbn; //���
	int units_solds; //��������
	double revenue; //���۽��
};

Sales_item  foo(Sales_item item)
{
	Sales_item temp;
	temp = item;
	return temp;
}

class Noname
{
public:
	//���캯��
	Noname() :pstring(new string), i(0), d(0.0) {}

	//���ƹ��캯��
	Noname(const Noname & others)
		:pstring(new string(*(others.pstring))), i(others.i), d(others.d) 
	{
		cout << "Noname ���ƹ��캯����������!" << endl;
	}

	//��ֵ������
	Noname & operator = (const Noname & rhs)
	{
		cout << "Noname ��ֵ��������������!" << endl;
		pstring = new string;
		*pstring = *(rhs.pstring);
		i = rhs.i;
		d = rhs.d;
		return * this;
	}

private:
	string * pstring;
	int i;
	double d;
};

int main()
{
	Sales_item a;
	Sales_item b("0-x-1235-4");

	Sales_item c(b);
	a = b;
	Sales_item iter = string("0-y-123-34532-998");

	cout << endl << "����һ�º���foo��" << endl;

	Sales_item ret;
	ret = foo(iter);

	cout << endl << "����һ������vector��" << endl;

	vector<Sales_item> svec(8);

	cout << endl << "����һ������: " << endl;

	Sales_item sales[] = {
		string("0-x-123-454-98"),
		string("0-x-123-454-97"),
		string("0-x-123-454-96"),
		string("0-x-123-454-95"),
		Sales_item()
	};

	cout << endl << "����һ��Noname�����: " << endl;

	Noname x, y;
	Noname z(x);
	x = y;

	system("pause");
	return 0;
}