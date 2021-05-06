#include<iostream>
#include<system_error>
#include<string>

using namespace std;

int main()
{
	string s("Hello World");
	string s2 = s.substr(6,5);
	cout << s2 << endl;

	s = "C++ Primer ";
//	s.append("3rd Edition");
	s.insert(s.size(),"3rd Edition");

	s.replace(11,3,"4th");
	cout << s << endl;

	system("pause");
	return 0;
}