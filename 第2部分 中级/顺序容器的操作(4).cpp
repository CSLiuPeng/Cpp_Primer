//˳�������ĸ�ֵ�뽻��
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

	vector<int> a;
	vector<int> b;
	
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);

	b.push_back(100);
	b.push_back(200);
	b.push_back(300);

	a.swap(b);
	for (vector<int>::iterator iter = b.begin(); iter != b.end();++iter)
	{
		//cout << "������Ľ����:" << endl;
		cout << *iter << endl;
	}

	system("pause");
	return 0;
}