#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Screen;//类的声明，没有定义

class Record//完整的类，既是类定义，又是类声明
{
public:
	typedef std::size_t size;

	string getName() const
	{
		return name;
	}

	size getCount() const
	{
		return byte_count;
	}

	//定义构造函数
	Record() :byte_count(0) {}

	//构造函数的重载
	Record(size s) :byte_count(s) {}
	Record(std::string s): byte_count(0), name(s) {}

private:
	size byte_count;
	string name;
};

int main()
{
	Record r;//在堆栈上创建对象
	class Record r;//比较传统的写法
	Record * p = new Record;//在堆上动态的创建对象

	//不能对未定义的类定义对象
	//但是可以给未定义的类定义指针和引用
	Screen *scr;
	cout << "测试一下!" << endl;

	system("pause");
	return 0;
}