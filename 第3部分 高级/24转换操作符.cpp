#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Dog
{
private:
	int age;
	double weight;
	string name;

public:
	Dog() = default;
	Dog(int a, double w, string n) :age(a), weight(w), name(n) {}

	//定义转换函数实现转换操作符
	operator int() const
	{
		return age;
	}

	operator double() const
	{
		return weight;
	}
};

int main()
{
	int a = 100, b;
	b = a;
	cout << b << endl;

	Dog d(3, 25.56, "bark");
	b = d;
	cout << b << endl;

	system("pause");
	return 0;
}