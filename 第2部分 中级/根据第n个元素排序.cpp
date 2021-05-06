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

	nth_element(ideq.begin(), ideq.begin()+3, ideq.end());
	copy(ideq.begin(), ideq.begin()+4,
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;
	
	nth_element(ideq.begin(), ideq.end() - 4, ideq.end());
	copy(ideq.end() - 4, ideq.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	nth_element(ideq.begin(), ideq.begin() + 3, 
		ideq.end(), greater<int>());
	copy(ideq.begin(), ideq.begin() + 4,
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	deque<int>::iterator pos;

	pos = partition(ideq.begin(), ideq.end(), 
		bind2nd(less_equal<int>(), 3));

	copy(ideq.begin(), pos,
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	system("pause");
	return 0;
}