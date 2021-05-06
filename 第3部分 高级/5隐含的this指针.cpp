#include<iostream>
#include<system_error>
#include<string>

using namespace std;

//定义一个类
class Person
{
public:
	//定义构造函数
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

//定义一个屏幕类
class Screen
{
public:
	//自定义类型
	typedef std::string::size_type  index;

	//构造函数
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
	cout << "测试一下!" << endl;
	
	Person p("张飞","中山大道128号");
	Person p2("刘备","解放大道235号");

	cout << p.getName() << endl;
	cout << p2.getName() << endl;

	system("pause");
	return 0;
}