#include<iostream>
#include<system_error>
#include"21Stringcpp.h"
#include"21Pointer.h"
using namespace std;

int main()
{
	String s("Hello String!");
	s.display();

	//ÆÕÍ¨Ö¸Õë
	/*String * ps = &s;
	ps->display();*/

	//Pointer p1("C++");
	//p1->display();

	try
	{
		Pointer p1("C++");
		p1->display();

		Pointer p2;
		p2->display();
	}
	catch (String const & error)
	{
		error.display();
	}
	system("pause");
	return 0;
}