#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	list<int> ilist;

	int x = 0;
	int length = 0;
	cout << "length: " ;
	cin >> length;
	cout<< " x: ";
	cin >>x;

	for (size_t i = 0; i < length; i++)
	{
		ilist.insert(ilist.end(), i);
	}

	for (list<int>::iterator liter = ilist.begin(); 
	liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl << endl;

	if (binary_search(ilist.begin(), ilist.end(), x))
	{
		cout <<x<< "�ҵ��ˣ�" << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}

	vector<int> ivec;

	ivec.push_back(0);
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	ivec.push_back(5);

	//��������Ĳ����㷨�����������������
	if (includes(ilist.begin(), ilist.end(), ivec.begin(), ivec.end()))
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}

	system("pause");
	return 0;
}