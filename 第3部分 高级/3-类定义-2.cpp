#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Screen 
{
private:
	string content;
	string::size_type cursor;
	string::size_type height, weight;
public:
	//C++允许自己定义类型别名
	typedef string::size_type index;

	//定义构造函数
	Screen(int ht = 0, int wd = 0)
		:content(ht * wd, '$'), cursor(0), height(ht), weight(wd)
	{}

	//构造函数
	Screen(index ht, index wd, const string & conts);

	//获取光标所在位置的内容，定义类的成员函数
	char get() const
	{
		return content[cursor];
	}

	//获取坐标位置的内容，重载类的成员函数
	char get(index r, index c) const 
	{
		string::size_type row = r * weight;
		return content[row + c];
	}
};

Screen::Screen(index ht, index wd, const string & conts)
	:content(conts), cursor(0), height(ht),  weight(wd) {}

int main()
{
	Screen a(10, 100);

	cout << a.get() << endl;
	cout << a.get(2, 50) << endl;

	cout << "测试一下!" << endl;

	Screen b(3, 6 ,"hello screen class");

	cout << b.get() << endl;
	cout << b.get(1, 5) << endl;

	system("pause");
	return 0;
}