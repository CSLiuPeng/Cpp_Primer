#include<iostream>
#include<system_error>
#include<string>
#include<memory>
#include"40smart_point.h"

using namespace std;

class Dog
{};

void demo()
{
	auto_ptr<double> pd(new double);
	*pd = 285;
	cout << *pd << endl;

	auto_ptr<Dog> pDog(new Dog);
//	Smart_Pointer<Dog> spDog(new Dog);
}

int main()
{
	demo();

	system("pause");
	return 0;
}