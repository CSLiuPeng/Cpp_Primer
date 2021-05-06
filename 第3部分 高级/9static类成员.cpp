#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Account
{
public:
	//���캯��
	Account(string  name, double money)
		:owner(name), amount(money) {}

	double getAmount() const
	{
		return amount;
	}

	//��������
	static double rate()
	{
		return interestRate;
	}

	//�޸�����
	static void changeRate(double rate)
	{
		interestRate = rate;
	}
	//��̬�����ݳ�Ա�ͳ�Ա��������ʹ��thisָ��
private:
	string owner;
	double amount;
	//�����ݳ�Ա����ֱ�������ڳ�ʼ��������һ���������
	static const int newRate = 20;
	static double interestRate; //���徲̬��Ա,ֻ��һ��
};

double Account::interestRate = 0.015; //��static��Ա���г�ʼ��

int main()
{
	Account a("����", 4000);
	Account b("����", 6000);

	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;

	cout << a.rate() << endl;
	cout << b.rate() << endl;

//	a.changeRate(0.018);
	//��һ���޸����ʵķ�ʽ
	Account::changeRate(0.018);

	cout << a.rate() << endl;
	cout << b.rate() << endl;

	system("pause");
	return 0;
}