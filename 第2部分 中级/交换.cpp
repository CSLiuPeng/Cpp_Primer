#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<algorithm>
#include<functional>
#include<string>

using namespace std;

int main()
{
	vector<int> ivec1;
	vector<int> ivec2;

	ivec1.push_back(1);
	ivec1.push_back(2);
	ivec1.push_back(3);

	ivec2.push_back(10);
	ivec2.push_back(20);
	ivec2.push_back(30);

	ivec1.swap(ivec2);

	for (vector<int>::iterator iter = ivec1.begin(); 
	iter != ivec1.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	vector<int> ivec;
	deque<int> ideq;

	for (size_t i = 1; i <=9 ; i++)
	{
		ivec.push_back(i);
	}

	for (size_t i = 11; i <= 23; i++)
	{
		ideq.push_back(i);
	}

	cout << "交换之前: " << endl;
	for (vector<int>::iterator iter = ivec.begin(); 
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	for (deque<int>::iterator iter = ideq.begin(); 
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//交换数据
	deque<int>::iterator pos;
	pos = swap_ranges(ivec.begin(), ivec.end(), ideq.begin());

	cout << "交换之后: " << endl;
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	for (deque<int>::iterator iter = ideq.begin();
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	if (pos != ideq.end())
	{
		cout << "第一个未交换的数据是: " << *pos << endl;
	}
	cout << endl << endl;

	swap_ranges(ideq.begin(), ideq.begin() + 3, ideq.rbegin());
	for (deque<int>::iterator iter = ideq.begin();
	iter != ideq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	system("pause");
	return 0;
}