#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	vector<int> ivec;
	list<int> searchList;

	int length;
	cout << "length: ";
	cin >> length;
	for (size_t i = 0; i < length; i++)
	{
		ivec.push_back(i);
	}

	cout << "向量容器中的元素是：";
	for (vector<int>::iterator viter = ivec.begin();
	viter != ivec.end(); ++viter)
	{
		cout <<  *viter <<" ";
	}
	cout << endl;

	searchList.push_back(3);
	searchList.push_back(6);
	searchList.push_back(9);

	vector<int>::iterator pos;
	//找其中的任意一个元素，从第一个起，一次类推
	pos = find_first_of(ivec.begin(), ivec.end(), 
		searchList.begin(), searchList.end());
	if (pos != ivec.end())
	{
		cout << "找到了，位置是: "
			<< distance(ivec.begin(), pos) + 1 << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}

	//使用逆向迭代器
	vector<int>::reverse_iterator rpos;
	rpos = find_first_of(ivec.rbegin(), ivec.rend(), 
		searchList.begin(), searchList.end());
	cout << "逆向查找的结果是: " 
		<< distance(ivec.begin(), rpos.base()) << endl;
	cout << endl << endl;

	//-----------------------使用string相关的操作---------------
	string numberics("0123456789");
	string name("jai323li23");

	string::size_type p = name.find_first_of(numberics);
	cout << "从前往后查找的结果如下: " << endl;
	if (p != string::npos)
	{
		cout << "找到了，下标是: " << p << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}

	p = name.find_last_of(numberics);
	cout << "从后往前查找的结果如下: " << endl;
	if (p != string::npos)
	{
		cout << "找到了，下标是: " << p << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}

	system("pause");
	return 0;
}