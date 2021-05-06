#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>
#include<iterator>
#include<set>

using namespace std;

int main()
{
	vector<int> ivec;

	for (size_t i = 3; i < 8; i++)
	{
		ivec.push_back(i);
	}
	for (size_t i = 5; i < 10; i++)
	{
		ivec.push_back(i);
	}
	for (size_t i = 1; i < 5; i++)
	{
		ivec.push_back(i);
	}

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	make_heap(ivec.begin(), ivec.end());

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	pop_heap(ivec.begin(), ivec.end());
	ivec.pop_back();

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	ivec.push_back(17);
	push_heap(ivec.begin(), ivec.end());

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	sort_heap(ivec.begin(), ivec.end());

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	system("pause");
	return 0;
}