#include<iostream>
#include<system_error>
#include<string>

using namespace std;

//��Ԫ��ϵ���ܼ̳У�����Ҫʱ�����ȷָ��

class Base
{
public:
	friend class Find;

protected:
	int i;
};

class Find
{};

class D1 :public Base
{
private:
	int j;
public:
	int men(D1 b)
	{
		return b.i;
	}

};

class D2 :public Find
{};

int main()
{
	system("pause");
	return 0;
}