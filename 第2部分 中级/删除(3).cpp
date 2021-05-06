#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

//����һ��ν�ʺ���
bool differentOne(int elem1, int elem2)
{
	return elem1 - 1 == elem2 || elem1 + 1 == elem2;
}

int main()
{
	int source[] = {1,4,4,6,1,2,2,3,1,6,6,6,5,7,5,4,4};
	int sourceNum = sizeof(source) / sizeof(source[0]);

	cout << "�����е�Ԫ����: " << endl;
	for (size_t i = 0; i < sourceNum; i++)
	{
		cout << source[i] << " ";
	}
	cout << endl<<endl;

	list<int> ilist;
	copy(source, source+sourceNum, back_inserter(ilist));

	cout << "�б��е�Ԫ����:" << endl;
	for (list<int>::iterator iter = ilist.begin(); 
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//ɾ����ͬ��Ԫ��
	list<int>::iterator pos;
	pos = unique(ilist.begin(), ilist.end());

	cout << "ɾ��������������ͬ��Ԫ��:" << endl;
	for (list<int>::iterator iter = ilist.begin();
	iter != pos; ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//���¸���Ԫ�أ����ڴ�ʱlist���գ������ò��������
	copy(source, source + sourceNum, ilist.begin());

	cout << "�б��е�Ԫ����:" << endl;
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	pos = unique(ilist.begin(), ilist.end(), greater<int>());

	for (list<int>::iterator iter = ilist.begin();
	iter != pos; ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	copy(source, source + sourceNum, ilist.begin());

	cout << "�б��е�Ԫ����:" << endl;
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	unique_copy(ilist.begin(), ilist.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	unique_copy(ilist.begin(), ilist.end(),
		ostream_iterator<int>(cout, " "),
		differentOne);
	cout << endl << endl;

	system("pause");
	return 0;
}