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

int main()
{
	list<int> ilist;

	for (size_t i = 1; i <= 7; i++)
	{
		ilist.push_back(i);
	}

	for (size_t i = 4; i <=9 ; i++)
	{
		ilist.push_back(i);
	}

	cout << "替换之前的元素: " << endl;
	for (list<int>::iterator iter = ilist.begin(); 
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	replace_copy(ilist.begin(), ilist.end(), 
		ostream_iterator<int>(cout, " "), 5 , 55);
	cout << endl;

	//替换元素
	cout << "替换之后的元素: " << endl;
	replace(ilist.begin(), ilist.end(), 6, 42);
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	replace_if(ilist.begin(), ilist.end(), 
		bind2nd(less<int>(), 5), 0);
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl<<endl;

	replace_copy_if(ilist.begin(), ilist.end(), 
		ostream_iterator<int>(cout, " "), 
		bind2nd(less<int>(), 5), 42);
	cout << endl << endl;

	replace_copy_if(ilist.begin(), ilist.end(),
		ostream_iterator<int>(cout, " "),
		bind2nd(modulus<int>(), 2), 0);
	cout << endl << endl;

	system("pause");
	return 0;
}