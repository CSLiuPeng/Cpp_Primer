#include<iostream>
#include<system_error>
#include<string>

using namespace std;

//����һ����
class Person
{
public:
	//���幹�캯��
	Person(const string & nm, const string & addr) 
		: name(nm), address(addr){}

	string getName() const
	{
	//	return name;
		return this->name;
	}

	string getAddress() const
	{
	//	return address;
		return this->address;
	}

private:
	string name;
	string address;

};

//����һ����Ļ��
class Screen
{
public:
	//�Զ�������
	typedef std::string::size_type  index;

	//���캯��
	Screen(index ht = 0, index wd = 0)
		:content(ht * wd, '*'), cursor(0), heigth(ht), width(wd) {}

	char get() const
	{
		return content[cursor];
	}

	char get(index r, index c) const 
	{
		index row = r * width;
		return content[row + c];
	}

private:
	string content;
	index cursor;
	index heigth, width;
};

int main()
{
	cout << "����һ��!" << endl;
	
	Person p("�ŷ�","��ɽ���128��");
	Person p2("����","��Ŵ��235��");

	cout << p.getName() << endl;
	cout << p2.getName() << endl;

	system("pause");
	return 0;
}