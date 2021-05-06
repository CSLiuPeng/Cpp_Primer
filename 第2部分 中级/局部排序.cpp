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
	deque<int> ideq;
	vector<int> ivec6(6);
	vector<int> ivec30(30);

	for (size_t i = 3; i < 8; i++)
	{
		ideq.push_back(i);
	}
	for (size_t i = 2; i < 7; i++)
	{
		ideq.push_back(i);
	}
	for (size_t i = 1; i < 6; i++)
	{
		ideq.push_back(i);
	}

	for (deque<int>::iterator iter = ideq.begin();
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	partial_sort(ideq.begin(), ideq.begin()+5, ideq.end());

	for (deque<int>::iterator iter = ideq.begin();
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	partial_sort(ideq.begin(), ideq.begin() + 6, 
		ideq.end(),greater<int>());

	for (deque<int>::iterator iter = ideq.begin();
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	partial_sort_copy(ideq.begin(), ideq.end(), 
		ivec6.begin(), ivec6.end());

	copy(ivec6.begin(), ivec6.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	vector<int>::iterator pos;

	pos = partial_sort_copy(ideq.begin(), ideq.end(),
		ivec30.begin(), ivec30.end(), greater<int>());

	copy(ivec30.begin(), ivec30.end(), 
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	copy(ivec30.begin(), pos, 
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	system("pause");
	return 0;
}