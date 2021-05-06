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
	
	//ǳ���ƣ�p1���ˣ�����p2Ҳ���Ķ���
	p1.set_ptr_val(0);
	cout << p2.get_ptr_val() << endl;
	
	//Ұָ�������
	int * ip = new int(42);
	AHasPtr pt(ip, 10);
	cout << pt.get_ptr_val() << endl;
	delete ip;
	//Ұָ�루����ָ�룩
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

	cout << "�޸�֮��" << endl;
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

	cout << "�޸�֮��" << endl;
	ptr2.set_ptr_val(11);
	ptr2.set_int(24);

	cout << ptr1.get_ptr_val() << ", "
		<< ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", "
		<< ptr2.get_int() << endl;
}

int main()
{
	cout << "ǳ���ƣ�" << endl;
	test_AHasPtr();

	cout <<endl<< "��ƣ�" << endl;
	test_CHasPtr();

	cout << endl << "����ָ�룺" << endl;
	test_BHasPtr();

	system("pause");
	return 0;
}