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

bool lessLenght(const string & s1, const string & s2)
{
	return s1.length() < s2.length();
}

int main()
{
	deque<int> ideq;

	for (size_t i = 0; i < 10; i++)
	{
		ideq.push_back(i);
	}
	for (size_t i = 0; i < 10; i++)
	{
		ideq.push_back(i);
	}

	for (deque<int>::iterator iter = ideq.begin();
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	sort(ideq.begin(), ideq.end());

	for (deque<int>::iterator iter = ideq.begin();
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	sort(ideq.begin(), ideq.end(), greater<int>());

	for (deque<int>::iterator iter = ideq.begin();
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	vector<string> svec, svec2;

	svec.push_back("1xxx");
	svec.push_back("2x");
	svec.push_back("3xxxx");
	svec.push_back("4xx");
	svec.push_back("5");
	svec.push_back("6xx");
	svec.push_back("7");
	svec.push_back("8xxxxx");

	svec2 = svec;

	for (vector<string>::iterator iter = svec.begin(); 
	iter != svec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	sort(svec.begin(), svec.end(), lessLenght);

	for (vector<string>::iterator iter = svec.begin();
	iter != svec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	stable_sort(svec2.begin(), svec2.end(), lessLenght);
	for (vector<string>::iterator iter = svec2.begin();
	iter != svec2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	system("pause");
	return 0;
}