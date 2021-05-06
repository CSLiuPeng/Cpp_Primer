#include<iostream>
#include<string>
#include<system_error>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

int main()
{
	string s1;
	cout << s1 << endl;

	string  s2(5, 'a');
	cout << s2 << endl;

	string s3 = s2;
	cout << s3 << endl;

	string s4(s3.begin(),s3.begin() + s3.size()/2);
	cout << s4 << endl;

	char * cp = "hello";
	char c_array[] = {"This!!!!"};
	char no_array[] = {'a', 'b'};

	string ss1(cp);
	cout << ss1 << endl;

	string ss2(c_array, 4);
	cout << ss2 << endl;

	string ss3(c_array+4, 4);
	cout << ss3 << endl;
	
	//没有下面的这种写法
	/*string ss4(no_array);
	cout << ss4 << endl;*/

	string ss5(no_array, 2);
	cout << ss5 << endl;

	s1 = "HelloWorld";
	cout << s1 << endl;

	string s6(s1,0, 2);
	cout << s6 << endl;

	string s7(s1, 3);
	cout << s7 << endl;

	system("pause");
	return 0;
}