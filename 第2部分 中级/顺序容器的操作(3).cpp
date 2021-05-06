//Ë³ĞòÈİÆ÷µÄÉ¾³ı²Ù×÷
#include<iostream>
#include<system_error>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>

using namespace std;

int main()
{
	list<string> slist;

	slist.push_back("C++");
	slist.push_back("language");
	slist.push_back("This");
	slist.push_back("is");
	slist.push_back("for");
	slist.push_back("everyone");

	slist.pop_front();
	slist.pop_back();

	for (list<string>::iterator iter = slist.begin();  iter != slist.end(); ++iter)
	{
		cout << "The character is:" << *iter<<"  " << endl;;
	}

	string s("is");
	list<string>::iterator liter = find(slist.begin(),slist.end(),s);

	if (liter != slist.end())
	{
		cout << "²éÕÒ³É¹¦£¡" << endl;
	}
	else
	{
		cout << "²éÕÒÊ§°Ü" << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}