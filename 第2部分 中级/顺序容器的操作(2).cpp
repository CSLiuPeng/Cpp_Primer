#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>
#include<string>

using namespace std;

int main()
{
	/*vector<string> svec;
	list<string> slist;
	deque<string> sdeq;*/

	vector<int> ivec;
	ivec.push_back(10);
	ivec.push_back(20);
	ivec.push_back(30);
	ivec.push_back(40);

	vector<int>::reference a = ivec.front();
	vector<int>::reference b = ivec.back();

	cout << a << endl;
	cout << b << endl;

	cout << endl << endl;

	cout << ivec[0] << endl;
	cout << ivec[1] << endl;
	cout << ivec[2] << endl;
	cout << ivec[3] << endl;

	cout << ivec.at(0) << endl;
	cout << ivec.at(2) << endl;

	try
	{
		cout << ivec.at(200) << endl;
		//cout << ivec[300] << endl;//用[]方法不能抛出异常状况
	}
	catch (out_of_range)
	{
		cout << "范围越界！" << endl;
	}

	//svec.push_back("Bill");
	//svec.push_back("Gates");
	//svec.push_back("Marry");

	//slist.push_back("Bill");
	//slist.push_back("Gates");
	//slist.push_back("Marry");

	//sdeq.push_back("Bill");
	//sdeq.push_back("Gates");
	//sdeq.push_back("Marry");

	//slist.push_front("Primer");
	//slist.push_front("C++");

	//sdeq.push_front("Primer");
	//sdeq.push_front("C++");

	//list<string>::iterator iter;
	//for ( iter = slist.begin(); iter != slist.end(); ++iter)
	//{
	//	cout << * iter<<" ";
	//}
	//cout << endl;

	////iter = slist.begin();
	//slist.insert(iter,"Hello");
	//for (iter = slist.begin(); iter != slist.end(); ++iter)
	//{
	//	cout << *iter << " ";
	//}
	//cout << endl;

	system("pause");
	return 0;
}