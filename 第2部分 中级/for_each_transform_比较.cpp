#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

//for_each�����Ĳ���Ҫ��������
void square(int & elem)
{
	elem *= elem;
}

//transform�����Ĳ�����Ҫ�������ã�
//���Ǻ���������Ҫ��Ϊint��
int square2(int elem2)
{
	elem2 *= elem2;
	return elem2;
}

int main()
{
	vector<int> a;
	vector<int> b;

	for (size_t i = 0; i <=10 ; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}

	cout << "����a�е�Ԫ��: " << endl;
	for (vector<int>::iterator iter = a.begin(); 
	iter != a.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	for_each(a.begin(), a.end(), square);

	for (vector<int>::iterator iter = a.begin();
	iter != a.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "����b�е�Ԫ��: " << endl;
	for (vector<int>::iterator iter = b.begin();
	iter != b.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	transform(b.begin(), b.end(), b.begin(), square2);
	for (vector<int>::iterator iter = b.begin();
	iter != b.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}