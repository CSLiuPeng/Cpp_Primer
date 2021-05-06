#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<algorithm>
#include<functional>
#include<string>
#include<iterator>

using namespace std;

int main()
{
	list<string> slist;

	slist.push_back("hello");
	slist.push_back("world");
	slist.push_back("C++ Primer");

	fill(slist.begin(), slist.end(), "hao");

	for (list<string>::iterator iter = slist.begin();
	iter != slist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	list<string> slist2;

	fill_n(back_inserter(slist2), 9, "LP");
	for (list<string>::iterator iter = slist2.begin();
	iter != slist2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	fill_n(ostream_iterator<float>(cout, " "), 10, 6.9);
	cout << endl<<endl;

	fill(slist2.begin(), slist2.end(), "again");
	for (list<string>::iterator iter = slist2.begin();
	iter != slist2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	fill_n(slist2.begin(), slist2.size()-3, "before");
	for (list<string>::iterator iter = slist2.begin();
	iter != slist2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	list<string>::iterator pos1, pos2;
	pos1 = slist2.begin();
	pos2 = slist2.end();

	fill(++pos1, --pos2, "Andrew");
	for (list<string>::iterator iter = slist2.begin();
	iter != slist2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	list<int> ilist;

	generate_n(back_inserter(ilist), 10, rand);
	for (list<int>::iterator iter = ilist.begin(); 
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	generate(ilist.begin(), ilist.end(), rand);
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	system("pause");
	return 0;
}