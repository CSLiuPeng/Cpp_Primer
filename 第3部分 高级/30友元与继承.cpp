#include<iostream>
#include<system_error>
#include<string>

using namespace std;

//友元关系不能继承，在需要时候的明确指出

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