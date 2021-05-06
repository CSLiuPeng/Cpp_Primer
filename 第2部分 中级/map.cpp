#include<iostream>
#include<system_error>
#include<map>
#include<string>

using namespace std;

int main()
{
	map<int, string>			a;
	multimap<int, string>	ma;

	//insert value (��һ�ַ���)         key(��)->value(ֵ)
	a.insert(map<int , string>::value_type(1 , "One"));
	a.insert(map<int , string>::value_type(2 , "Two"));
	a.insert(map<int,  string>::value_type(3 ,  "Three"));

	//insert value (�ڶ��ַ���)   
	a.insert(make_pair(-1 , "Minus one"));

	//insert value(�����ַ���)
	a.insert(pair<int , string>(1000 ,"One Thousand"));

	//insert value(�����ַ���)
	a[1000000] = "One Million";

	cout << "The count of map is: " << a.size() << endl;

	map<int, string>::const_iterator i;
	for ( i = a.begin(); i != a.end(); i++)
	{
		cout << "Key: " << i->first
			<< " Value: " << i->second << endl;
	}
	cout << endl << endl;
	//��map����򵥵Ĳ���
	cout << a[3] << endl;
	cout << endl << endl;

	ma.insert(multimap<int , string>::value_type(3 , "Three"));
	ma.insert(multimap<int , string>::value_type(5 , "Five"));
	ma.insert(make_pair(-1 , "Minus One"));
	ma.insert(pair<int , string>(1000 , "One Thousand"));
	ma.insert(pair<int, string>(1000, "One Thousand"));
	//ma[2000] = "Two thousand"; multimap���ܶ������ֲ���

	cout << "The  count of multimap is: " << ma.size() << endl;
	multimap<int, string>::const_iterator im;
	for (im = ma.begin(); im != ma.end(); ++ im)
	{
		cout << "Key: " << im->first 
			<< " Value: " << im->second << endl;
	}
	cout << endl;
	cout << "The same value have: " << ma.count(1000) << endl;
	cout << endl << endl;

	//ʹ�ò��Һ���
	multimap<int, string>::const_iterator ci;
	ci = ma.find(5);
	if ( ci != ma.end())
	{
		cout << "�ҵ��ˣ�" << endl;
		cout << "Key: " << ci->first 
			<< " Value: " << ci->second << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}
	cout << endl << endl;

	//ɾ��Ԫ��
	//��һ�ַ���
	if (ma.erase(-1) > 0)
	{
		cout << "Delete success!" << endl;
	}

	//�ڶ��ַ���
	multimap<int, string>::iterator iter = ma.find(3);
	if (iter != ma.end())
	{
		ma.erase(iter);
		cout << "Delete success!" << endl;
	}
	cout << endl << endl;

	//�����ַ���
	//ɾ�����Ԫ��
	ma.erase(ma.lower_bound(1000) , ma.upper_bound(1000));
	cout << endl;
	system("pause");
	return 0;
}