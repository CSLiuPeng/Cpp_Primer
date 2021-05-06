#include<iostream>
#include<system_error>
#include<string>
#include"13 plain-ptr.h"
#include"13 value-ptr.h"
#include"13 smart-ptr.h"

using namespace std;

void test_AHasPtr()
{
	int i = 42;
	AHasPtr p1(&i , 42);
	AHasPtr p2 = p1;

	cout << p2.get_ptr_val() << endl;
	
	//浅复制，p1改了，所以p2也被改动了
	p1.set_ptr_val(0);
	cout << p2.get_ptr_val() << endl;
	
	//野指针的例子
	int * ip = new int(42);
	AHasPtr pt(ip, 10);
	cout << pt.get_ptr_val() << endl;
	delete ip;
	//野指针（悬垂指针）
	cout << pt.get_ptr_val() << endl;


}

void test_CHasPtr()
{
	int obj = 0;
	CHasPtr ptr1(obj, 42);
	CHasPtr ptr2 (ptr1);

	cout << ptr1.get_ptr_val() << ", "
		<< ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() <<", " 
		<<ptr2.get_int()<< endl;

	cout << "修改之后：" << endl;
	ptr2.set_ptr_val(10);
	ptr2.set_int(50);

	cout << ptr1.get_ptr_val() << ", "
		<< ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", "
		<< ptr2.get_int() << endl;

}

void test_BHasPtr()
{
	int i = 1;
	BHasPtr ptr1(&i , 42);
	BHasPtr ptr2(ptr1);
	cout << ptr1.get_ptr_val() << ", "
		<< ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", "
		<< ptr2.get_int() << endl;

	cout << "修改之后：" << endl;
	ptr2.set_ptr_val(11);
	ptr2.set_int(24);

	cout << ptr1.get_ptr_val() << ", "
		<< ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", "
		<< ptr2.get_int() << endl;
}

int main()
{
	cout << "浅复制：" << endl;
	test_AHasPtr();

	cout <<endl<< "深复制：" << endl;
	test_CHasPtr();

	cout << endl << "智能指针：" << endl;
	test_BHasPtr();

	system("pause");
	return 0;
}