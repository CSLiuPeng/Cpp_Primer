#include<iostream>
#include<system_error>
#include<string>
#include<list>
#include<vector>
#include<deque>
#include<set>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

int main()
{
	list<int> ilist;

	for (size_t i = 1; i <= 6; i++)
	{
		ilist.push_back(i);
	}

	for (size_t i = 1; i <= 9; i++)
	{
		ilist.push_back(i);
	}

	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	multiset<int> iset;

	remove_copy_if(ilist.begin(), ilist.end(), 
		inserter(iset, iset.end()), bind2nd(less<int>(), 4));

	for (multiset<int>::iterator iter = iset.begin(); 
	iter != iset.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	remove_copy(ilist.begin(), ilist.end(), 
		ostream_iterator<int>(cout, " "), 3);
	cout << endl << endl;

	remove_copy_if(ilist.begin(), ilist.end(), 
		ostream_iterator<int>(cout, " "),
		bind2nd(greater<int>(),5));
	cout << endl << endl;

	system("pause");
	return 0;
}