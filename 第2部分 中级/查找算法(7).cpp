#include<iostream>
#include<system_error>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<deque>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	list<int> ilist;
	multiset<int> imuset;

	imuset.lower_bound(5);
	imuset.upper_bound(5);
	imuset.equal_range(5);

	for (int i = 0; i < 10; ++i)
	{
		ilist.push_back(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		ilist.push_back(i);
	}

	ilist.push_back(5);
	ilist.push_back(5);
	ilist.push_back(5);
	ilist.push_back(5);

	//�������е����ݽ�������
	ilist.sort();

	cout << " �����е�������: ";
	for (list<int>::iterator liter = ilist.begin();
	liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl << endl;

	list<int>::iterator pos1,  pos2;
	pos1 = lower_bound(ilist.begin(), ilist.end(), 5);
	pos2 = upper_bound(ilist.begin(), ilist.end(), 5);

	cout << "��һ���ظ������ֳ��ֵ�λ��: "
		<< distance(ilist.begin(), pos1) + 1 << endl;

	cout << "��һ���ظ������ֳ��ֵ�λ�õ���һ��λ��: "
		<< distance(ilist.begin(), pos2) + 1 << endl;
	cout << endl << endl;

	ilist.insert(lower_bound(ilist.begin(), ilist.end(), 6), 4);
	ilist.insert(upper_bound(ilist.begin(), ilist.end(), 7),5);

	cout << " �����е�������: ";
	for (list<int>::iterator liter = ilist.begin();
	liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl << endl;

	pair<list<int>::iterator, list<int>::iterator> range;
	range = equal_range(ilist.begin(), ilist.end(),5);

	cout << distance(ilist.begin(), range.first) + 1 << endl;
	cout << distance(ilist.begin(), range.second)  << endl;

	system("pause");
	return 0;
}