#include<iostream>
#include<system_error>
#include<string>

using namespace std;

int main()
{
	string s1("abcdefg");
	string s2("abcedfg");
	if (s1.compare(s2) > 0)
	{
		cout << "s1 more bigger!" << endl;
	}
	else
	{
		cout << "s2 more bigger! " << endl;
	}
	system("pause");
	return 0;
}