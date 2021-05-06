#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

//定义一个谓词函数
bool differentOne(int elem1, int elem2)
{
	return elem1 - 1 == elem2 || elem1 + 1 == elem2;
}

int main()
{
	int source[] = {1,4,4,6,1,2,2,3,1,6,6,6,5,7,5,4,4};
	int sourceNum = sizeof(source) / sizeof(source[0]);

	cout << "数组中的元素是: " << endl;
	for (size_t i = 0; i < sourceNum; i++)
	{
		cout << source[i] << " ";
	}
	cout << endl<<endl;

	list<int> ilist;
	copy(source, source+sourceNum, back_inserter(ilist));

	cout << "列表中的元素是:" << endl;
	for (list<int>::iterator iter = ilist.begin(); 
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//删除相同的元素
	list<int>::iterator pos;
	pos = unique(ilist.begin(), ilist.end());

	cout << "删除连续的两个相同的元素:" << endl;
	for (list<int>::iterator iter = ilist.begin();
	iter != pos; ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//重新复制元素，由于此时list不空，不必用插入迭代器
	copy(source, source + sourceNum, ilist.begin());

	cout << "列表中的元素是:" << endl;
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	pos = unique(ilist.begin(), ilist.end(), greater<int>());

	for (list<int>::iterator iter = ilist.begin();
	iter != pos; ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	copy(source, source + sourceNum, ilist.begin());

	cout << "列表中的元素是:" << endl;
	for (list<int>::iterator iter = ilist.begin();
	iter != ilist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	unique_copy(ilist.begin(), ilist.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	unique_copy(ilist.begin(), ilist.end(),
		ostream_iterator<int>(cout, " "),
		differentOne);
	cout << endl << endl;

	system("pause");
	return 0;
}