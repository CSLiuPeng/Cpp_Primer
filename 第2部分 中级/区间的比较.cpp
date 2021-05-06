#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

//设计一个谓词函数
bool bothEvenOrOdd(int elem1, int elem2)
{
	if (elem1 % 2 == elem2 % 2)
	{
		return true;
	}
	else
	{
		return false;
	}

	//return elem1 % 2 == elem2 % 2;
}

bool lessFunction(list<int> & list1, list<int> & list2)
{
	return lexicographical_compare(list1.begin(), list1.end(),
		list2.begin(), list2.end());
}

void printFunction(list<int> & l)
{
	for (list<int>::iterator iter = l.begin(); iter != l.end(); ++iter )
	{
		cout << *iter << " ";
	}
	cout << endl << endl;
}

int main()
{
	vector<int> ivec;
	list<int> ilist;

	int length;
	/*cout << "Length: ";
	cin >> length;*/

	for (int  i = 1; i <= 6; i++)
	{
		ivec.push_back(i);
	}

	for (int i = 1; i <= 16; i *= 2)
	{
		ilist.push_back(i);
	}
	ilist.push_back(3);

	for (vector<int>::iterator viter = ivec.begin();
	viter != ivec.end(); ++viter)
	{
		cout << *viter << " ";
	}
	cout << endl<<endl;

	for (list<int>::iterator liter = ilist.begin();
	liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl<<endl;

	//使用equal()函数比较大小
	//判断两个区间中的元素是否相等
	cout << "使用equal()函数比较大小:" << endl<<endl;
	if (equal(ivec.begin(), ivec.end(), ilist.begin()))
	{
		cout << "两个区间相等! " << endl;
	}
	else
	{
		cout << "两个区间不相等! " << endl;
	}
	cout << endl << endl;

	//使用含有谓词的比较函数
	if (equal(ivec.begin(), ivec.end(), ilist.begin(), 
		bothEvenOrOdd))
	{
		cout << "两个区间奇数与偶数对应! " << endl;
	}
	else
	{
		cout << "两个区间奇数与偶数不对应! " << endl;
	}
	cout << endl << endl;

	//使用mismatch()函数比较大小
	cout << "使用mismatch()函数比较大小: " << endl << endl;
	pair<vector<int>::iterator, list<int>::iterator> value;
	value = mismatch(ivec.begin(), ivec.end(),ilist.begin());

	if (value.first == ivec.end())
	{
		cout << "没有找到不相等的数." << endl;
	}
	else
	{
		cout << "first mismatch: "<<*value.first 
			<< " and " << *value.second << endl;
	}

	value = mismatch(ivec.begin(), ivec.end(), 
		ilist.begin(), less_equal<int>());
	if (value.first == ivec.end())
	{
		cout << "没找到! (always less-or-equal)" << endl;
	}
	else
	{
		cout << "找到了:(not less-or-equal) " 
			<< *value.first << " ," << *value.second << endl;
	}
	cout << endl << endl << endl;

	//检查小于区间算法
	list<int> c1, c2, c3, c4;

	for (int  i = 0; i <= 5; i++)
	{
		c1.push_back(i);
	}
	
	c4 = c3 = c2 = c1;

	c1.push_back(7);
	c3.push_back(2);
	c3.push_back(0);
	c4.push_back(2);

	printFunction(c1);
	printFunction(c2);
	printFunction(c3);
	printFunction(c4);

	if (lexicographical_compare(c4.begin(),
		c4.end(), c1.begin(), c1.end()))
	{
		cout << "c4<c1" << endl;
	}
	else
	{
		cout << "c4=c1" << endl;
	}
	cout << "--------------------------" << endl;

	vector<list<int>> vectlist;

	vectlist.push_back(c1);
	vectlist.push_back(c2);
	vectlist.push_back(c3);
	vectlist.push_back(c4);
	vectlist.push_back(c3);
	vectlist.push_back(c1);
	vectlist.push_back(c4);
	vectlist.push_back(c2);

	for_each(vectlist.begin(), vectlist.end(), printFunction);
	
	sort(vectlist.begin(), vectlist.end(), lessFunction);

	cout << "排序之后的结果:" << endl;
	for_each(vectlist.begin(), vectlist.end(), printFunction);

	system("pause");
	return 0;
}