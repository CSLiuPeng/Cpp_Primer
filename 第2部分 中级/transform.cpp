#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

int main()
{
	vector<int> ivec;
	list<int> ilist;

	for (size_t i = 1; i < 10; i++)
	{
		ivec.push_back(i);
	}

	for (vector<int>::iterator iter = ivec.begin(); 
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	transform(ivec.begin(), ivec.end(), 
		ivec.begin(), negate<int>());

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	transform(ivec.begin(), ivec.end(), back_inserter(ilist), 
		bind2nd(multiplies<int>(), 10));

	for (list<int>::iterator iter = ilist.begin(); 
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	transform(ilist.begin(), ilist.end(), 
		ostream_iterator<int>(cout, " "), negate<int>());
	cout << endl;

	transform(ivec.begin(), ivec.end(), 
		ivec.begin(), ivec.begin(), multiplies<int>());

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	transform(ivec.begin(), ivec.end(), 
		ivec.rbegin(), back_inserter(ilist), plus<int>());

	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}