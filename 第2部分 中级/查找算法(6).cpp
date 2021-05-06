#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	list<int> ilist;

	int x = 0;
	int length = 0;
	cout << "length: " ;
	cin >> length;
	cout<< " x: ";
	cin >>x;

	for (size_t i = 0; i < length; i++)
	{
		ilist.insert(ilist.end(), i);
	}

	for (list<int>::iterator liter = ilist.begin(); 
	liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl << endl;

	if (binary_search(ilist.begin(), ilist.end(), x))
	{
		cout <<x<< "找到了！" << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}

	vector<int> ivec;

	ivec.push_back(0);
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	ivec.push_back(5);

	//有序区间的查找算法，数据区间必须有序
	if (includes(ilist.begin(), ilist.end(), ivec.begin(), ivec.end()))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}

	system("pause");
	return 0;
}