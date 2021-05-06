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
	vector<int> a;
	vector<int> b;
	vector<int> c;

	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);

	b.push_back(100);
	b.push_back(200);
	b.push_back(300);
	b.push_back(400);
	b.push_back(500);
	b.push_back(600);

	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	c.push_back(4);
	c.push_back(5);

//	a.swap(b);
//	a = b;
	a.assign(c.begin(), c.end());
	for (vector<int>::iterator iter = a.begin(); 
	iter != a.end(); ++iter)
	{
		cout << *iter << " "<<endl;
	}
	cout << endl;

	list<string> slist;
	vector<char * > cvec;

	slist.push_back("james");
	slist.push_back("robert");
	slist.push_back("tom");
	slist.push_back("louis");
	slist.push_back("bejamin");
	slist.push_back("easic");

	cvec.push_back("C");
	cvec.push_back("C++");
	cvec.push_back("Java");
	cvec.push_back("C#");
	cvec.push_back("Python");

	slist.assign(cvec.begin(), cvec.end());
//	cvec.assign(slist.begin(), slist.end());	类型必须兼容
	//assign类型必须兼容，swap类型必须相同
	slist.assign(10, "peng liu");
	for (list<string>::iterator iter = slist.begin(); 
	iter != slist.end(); ++iter)
	{
		cout << *iter << " " << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}