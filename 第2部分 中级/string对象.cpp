#include<iostream>
#include<system_error>
#include<string>

using namespace std;

int main()
{
	/*char * cp = "This is for everyone!";
	string s1(cp);
	cout << s1 << endl;;

	char character_array[] = "perfect";
	string s2(character_array, 3);
	cout << s2 << endl;*/

	string s1("hello");
	string s2("abcdef");

	string::iterator p = s1.begin();

	p++;
	s1.insert(p,'A');
	cout << s1 << endl;

	s1.insert(p,3,'B');
	cout << s1 << endl;

	string::iterator b = s2.begin();
	string::iterator e = s2.end();
//	p = s1.begin();
	s1.insert(p,b,e);
	cout << s1 << endl;

	s1 = "hello";
	cout << s1 << endl;

	s1.assign(b,e);//赋值操作，用一对迭代器替换原来的字符串
	cout << s1 << endl;

	s1.assign(8,'K');
	cout << s1 << endl;

	s1 = "abcdef";
	p = s1.begin();
	s1.erase(p);
	cout << s1 << endl;

//	p = s1.begin();
	p++;
	p++;
	string::iterator p2 = s1.end();
	p2--;
	s1.erase(p, p2);
	cout << s1 << endl;

	s1 = "hello";
	s2 = "abc";
	s1.insert(0,3,'A');
	cout << s1 << endl;

	s1.insert(5,s2);
	cout << s1 << endl;

	s2 = "123456";
	s1.insert(0,s2,2,3);
	cout << s1 << endl;
	
	char * cp = "stately plump buck";
	s1.assign(cp,7);
	cout << s1 << endl;

	s1.assign(cp);
	cout << s1 << endl;

	s1 = "hello";
	s1.insert(0,cp,7);
	cout << s1 << endl;

	s1 = "abc";
	s1.erase(0, 1).insert(0,"A");
	cout << s1<<endl;

	system("pause");
	return 0;
}