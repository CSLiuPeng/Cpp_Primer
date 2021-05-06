#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Account
{
public:
	//构造函数
	Account(string  name, double money)
		:owner(name), amount(money) {}

	double getAmount() const
	{
		return amount;
	}

	//返回利率
	static double rate()
	{
		return interestRate;
	}

	//修改利率
	static void changeRate(double rate)
	{
		interestRate = rate;
	}
	//静态的数据成员和成员函数不能使用this指针
private:
	string owner;
	double amount;
	//对数据成员不能直接在类内初始化，但有一种例外情况
	static const int newRate = 20;
	static double interestRate; //定义静态成员,只有一个
};

double Account::interestRate = 0.015; //对static成员进行初始化

int main()
{
	Account a("赵四", 4000);
	Account b("刘能", 6000);

	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;

	cout << a.rate() << endl;
	cout << b.rate() << endl;

//	a.changeRate(0.018);
	//另一种修改利率的方式
	Account::changeRate(0.018);

	cout << a.rate() << endl;
	cout << b.rate() << endl;

	system("pause");
	return 0;
}