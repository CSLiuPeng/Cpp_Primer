#include<iostream>
#include<system_error>
#include<string>
#include<cstdlib>

using namespace std;

class MyClass
{
public:
	//���캯��
	MyClass(int pa, char * cstr) 
	{
		a = pa;
		str = new char[100];
		strcpy(str , cstr);
	}

	//��������
	~MyClass()
	{
		delete str;
	}

	//���ƹ��캯��
	MyClass(MyClass & obj)
	{
		a = obj.a;
	//	str = obj.str;//ǳ���ƣ���Ҫ��Ʋ���
		str = new char[100];
		if (str != 0)
		{
			strcpy(str , obj.str);
		}
	}
	
public:
	int a;
	char * str;//һ�����ݳ�Ա��ָ�룬����Ҫ���
	//���������ϵͳ��Դ����Ҳ��Ҫ���
};

int main()
{
	MyClass mc(100, "hello");

	cout << mc.a << ", " << mc.str << endl;

	MyClass md = mc;

	cout << md.a << ", " << md.str << endl;

	md.a = 8;
	md.str[0] = 'k';

	cout << md.a << ", " << md.str << endl;
	cout << mc.a << ", " << mc.str << endl;


	system("pause");
	return 0;
}