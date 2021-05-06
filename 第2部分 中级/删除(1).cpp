#include<iostream>
#include<system_error>
#include<string>
#include<list>
#include<vector>
#include<deque>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

int main()
{
	list<int> ilist;

	for (size_t i = 1; i <=6 ; i++)
	{
		ilist.push_front(i);
		ilist.push_back(i);
	}

	for (list<int>::iterator iter = ilist.begin(); 
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl<<endl;

	//ʹ��remove���߼�ɾ��
	//removeɾ��ֻ���߼��ϵĸ��ǣ���δ����ɾ������
	remove(ilist.begin(), ilist.end(), 3);
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//��һ������������ɾ��
	list<int>::iterator end;
	end = remove(ilist.begin(), ilist.end(), 2);
	for (list<int>::iterator iter = ilist.begin();
	iter != end; ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;
	cout << "һ��ɾ����" << distance(end, ilist.end()) 
		<< "��Ԫ��."<< endl<<endl;

	//ʵ��ɾ��Ԫ��
	ilist.erase(end, ilist.end());
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	vector<int> ivec;

	for (size_t i = 2; i <= 6; i++)
	{
		ivec.push_back(i);
	}

	for (size_t i = 4; i <= 9; i++)
	{
		ivec.push_back(i);
	}

	for (size_t i = 1; i <= 7; i++)
	{
		ivec.push_back(i);
	}

	for (vector<int>::iterator iter = ivec.begin(); 
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	ivec.erase(remove(ivec.begin(), ivec.end(), 5), ivec.end());

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	ivec.erase(remove_if(ivec.begin(), ivec.end(), 
		bind2nd(less<int>(), 4)), ivec.end());

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	system("pause");
	return 0;
}