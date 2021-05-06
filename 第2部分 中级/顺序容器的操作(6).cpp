#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

int main()
{
	list<string> slist;

	slist.push_back("apple");
	slist.push_back("bill");
	slist.push_back("fish");
	slist.push_back("cat");
	slist.push_back("dog");
	slist.push_back("egg");

	/*slist.pop_front();
	slist.pop_back();*/

	string s("dogs");
	list<string>::iterator iter = find(slist.begin(), slist.end(), s);

	if (iter != slist.end())
	{
		slist.erase(iter);
	}
	else
	{
		cout << "Ã»ÕÒµ½!" << endl;
	}

	//slist.clear();
	//slist.erase(slist.begin(), slist.end());
	for (list<string>::iterator iter = slist.begin(); 
	iter != slist.end(); ++iter)
	{
		cout << *iter << " "<<endl;
	}
	cout << endl;

	system("pause");
	return 0;
}