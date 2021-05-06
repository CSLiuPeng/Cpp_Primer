#include<iostream>
#include<system_error>
#include<string>

using namespace std;

int main()
{
	string name("AnnaBelle");
	string::size_type pos1 = name.find("na");
//	cout << pos1 << endl;
	if (pos1 == string::npos)
	{
		cout << "Don't find the substring." << endl;
	}
	else
	{
		cout << "The position is: "<<pos1 << endl;
	}

	name = "c2b1da5e2d3";
	string names("0123456789");
	/*string::size_type pos2 = name.find_first_of(names);
	if (pos2 == string::npos)
	{
		cout << "Don't find the substring! " << endl;
	}
	else
	{
		cout << "The pos is: " << pos2 << endl;
	}*/

	//展示一个厉害的查找
	string::size_type pos2 = 0;
	while ((pos2 = name.find_first_of(names ,pos2))
		!= string::npos)
	{
		cout << name[pos2] << endl;
		++pos2;
	}
	
	cout << endl;

	string letters("abcdefgABCDEFG");
	string::size_type pos3 = 0;
	while ((pos3 = name.find_first_of(letters, pos3))
		!= string::npos)
	{
		cout << name[pos3] << endl;
		++pos3;
	}

	system("pause");
	cout << endl;
}