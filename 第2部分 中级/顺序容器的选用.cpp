#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;
	list<int> l;
	deque<int> d;

	v.push_back(10);
	v.push_back(90);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	++iter;
	++iter;
	cout << *iter;
	cout << endl;

	v.insert(iter,70);
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i<<" ";
	}
	//cout << *iter;
	cout << endl;
	sort(v.begin(),v.end());

	iter = v.begin();
	++iter;
	v.erase(iter);
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}