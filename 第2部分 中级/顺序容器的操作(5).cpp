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
	vector<int> ivec;

	ivec.push_back(10);
	ivec.push_back(20);
	ivec.push_back(30);

	cout << ivec.front ()<< endl;
	cout << ivec.back() << endl;

	vector<int>::reference a = ivec.front();
	vector<int>::reference b = ivec.back();

	cout << a << " " << b << endl;

	cout << *ivec.begin() << endl;
	cout << *(--ivec.end() ) << endl;

	vector<int>::reference c = *ivec.begin();
	vector<int>::reference d = *(--ivec.end());

	cout << c << " " << d << endl;

	cout << ivec[0] << endl;
	cout << ivec[1] <<endl;
	cout << ivec[2] << endl;

	cout << ivec.at(0) << endl;
	cout << ivec.at(1) << endl;
	cout << ivec.at(2) << endl;

	try
	{
		cout << ivec.at(300) << endl;
	}
	catch (out_of_range)
	{
		cout << "出错了，下标越界!" << endl;
	}

	list<int> ilist;
	ilist.push_back(10);
	ilist.push_back(30);

	//ilist没有c[n], c.at[n]这样的操作
	if (! ilist.empty())
	{
		cout << ilist.front() <<endl;
		cout << ilist.back() <<endl;
	}
	system("pause");
	return 0;
}