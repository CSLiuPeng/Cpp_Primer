#include<iostream>
#include<system_error>
#include<algorithm>
#include<vector>
#include<functional>
#include<set>
#include<deque>

using namespace std;

int absLess(int elem1, int elem2)
{
	return abs(elem1) < abs(elem2);
}

int main()
{
	deque<int> ideq;
	
	for (size_t i = 0; i < 20; i++)
	{
		ideq.insert(ideq.end(), i);
	}

	for (int j = -30; j < 0; ++j)
	{
		ideq.insert(ideq.begin(), j);
	}

	for (deque<int>::iterator diter = ideq.begin();
	diter != ideq.end(); ++diter)
	{
		cout << *diter << " ";
	}
	cout << endl;

	cout << "这一组数中最小的数字是:"
		<< *min_element(ideq.begin(), ideq.end())<<endl;

	deque<int>::iterator result = max_element(ideq.begin(), ideq.end());
	cout << "最大的元素值是: " << *result << endl;

	cout << "这一组数中绝对值最小的数字是:"
		<< *min_element(ideq.begin(), ideq.end(),absLess) << endl;

	cout << "这一组数中绝对值最大的数字是:"
		<< abs(*max_element(ideq.begin(), ideq.end(), absLess)) << endl;

	system("pause");
	return 0;
}