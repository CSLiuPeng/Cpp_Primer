#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
	vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);

	vector<int>::iterator first = a.begin();
	vector<int>::iterator last = a.end();
	while (first != last)
	{
		cout << "first:" << *first << endl;
		first++;
	}
	system("pause");
	return 0;
}