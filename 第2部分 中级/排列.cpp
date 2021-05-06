#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<set>
#include<string>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

int main()
{
	vector<int> ivec;

	for (size_t i = 1; i <= 10; i++)
	{
		ivec.push_back(i);
	}
	
	cout << "向量中的数据:" << endl;
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "按从小到大的排列组合" << endl;
	while (next_permutation(ivec.begin(), ivec.end()))
	{
		for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl << endl;
	}

	cout << "--------------------------------" << endl;

	vector<int> ivec2;

	for (size_t i = 10; i >=1; i--)
	{
		ivec2.push_back(i);
	}

	cout << "向量中的数据:" << endl;
	for (vector<int>::iterator iter = ivec2.begin();
	iter != ivec2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "按从大到小的排列组合" << endl;
	while (prev_permutation(ivec2.begin(), ivec2.end()))
	{
		for (vector<int>::iterator iter = ivec2.begin();
		iter != ivec2.end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl << endl;
	}

	system("pause");
	return 0;
}