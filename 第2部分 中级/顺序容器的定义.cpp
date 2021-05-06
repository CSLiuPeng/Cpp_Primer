#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
	vector<string> svec;
	list<int> ilist;

	vector<int> ivec;//默认构造函数
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);

	vector<int> ivec2(ivec);//有参构造函数
	cout << "success" << endl;
	system("pause");
	return 0;
}