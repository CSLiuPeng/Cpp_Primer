#include<iostream>
#include<system_error>
#include<set>
#include<algorithm>
#include<functional>

using namespace std;

template<typename Counters>
void printCounts(const Counters & c)
{
	Counters::iterator iter;
	for (iter = c.begin(); iter != c.end(); ++iter)
	{
		cout << *iter << endl;
	}
}

int main()
{
	set<int , greater<int>>						a;
	set<int, less<int>>		b;//	set<int>	aµÄÔ­ĞÍ

	a.insert(9);
	a.insert(7);
	a.insert(6);
	a.insert(4);
	a.insert(1);
	a.insert(8);
	a.insert(3);
	a.insert(5);
	a.insert(2);

	printCounts(a);

	system("pause");
	return 0;
}