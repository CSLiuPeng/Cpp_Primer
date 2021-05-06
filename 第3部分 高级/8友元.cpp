#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Screen
{
public:
	typedef std::string::size_type  index;

	//���캯��
	Screen(int ht = 0, int wd = 0)
		:contents(ht * wd , ' '), cursor(0), height(ht), width(wd){}

	//������Ԫ����
	friend int countArea(Screen & s);

	//������Ԫ��
	friend class Screen_management;

	int area()
	{
		return height * width;
	}

private:
	string contents;
	index cursor;
	int height, width;
};

//������Ԫ����
int countArea(Screen & s)
{
	return s.height * s.width;
}

//��Ԫ��
class Screen_management
{
public:
	void recolate(int r, int c, Screen & s)
	{
		s.height += r;
		s.width += c;
	}
};

int main()
{
	Screen a(10 , 100);
	Screen_management sm;
	
	sm.recolate(20, 50 , a);

	cout << "��Ԫ��������Ԫ��ʾ��!" << endl;
	cout << a.area() << endl;
	cout << countArea(a) << endl;

	system("pause");
	return 0;
}