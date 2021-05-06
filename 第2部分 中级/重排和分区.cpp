#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>
#include<iterator>
#include<set>

using namespace std;

int main()
{
	vector<int> ivec;

	for (size_t i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}

	for (vector<int>::iterator iter = ivec.begin(); 
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	random_shuffle(ivec.begin(), ivec.end());

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	vector<int>::iterator pos1;
	//稳定分区
	/*pos2 = stable_partition(ivec.begin(), ivec.end(),
		not1(bind2nd(modulus<int>(), 2)));*/
	//不稳定分区
	pos1 = partition(ivec.begin(), ivec.end(), 
		not1(bind2nd(modulus<int>(), 2)));

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	system("pause");
	return 0;
}