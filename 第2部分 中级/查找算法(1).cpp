#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	list<int> ilist;

	for (int i = 0; i < 10; ++i)
	{
		ilist.insert(ilist.end(), i );
	}

	for (int i = 0; i < 10; ++i)
	{
		ilist.insert(ilist.end(), i);
	}

	for (list<int>::iterator liter = ilist.begin();
	liter != ilist.end(); ++ liter)
	{
		cout << *liter << " ";
	}
	cout << endl;

	list<int>::iterator pos1;

	pos1 = find(ilist.begin(), ilist.end(), 4);
	cout << "查找的数字第一次出现的位置是: " << (*pos1) +1 << endl;

	list<int>::iterator pos2;
	
	if (pos1 != ilist.end())//查找pos2的位置s
	{
		//需要特别注意第二个位置迭代器的起始位置
		pos2 = find(++pos1, ilist.end(),4); 
	}

	//显示两个迭代器之间的数据
	if (pos1 != ilist.end() && pos2 != ilist.end())
	{
		cout << "两个迭代器之间的数据是: ";
		//显示两个端点元素
		--pos1;
		++pos2;
		for (list<int>::iterator liter = pos1; liter != pos2; ++ liter)
		{
			cout  << *liter << " ";
		}
		cout << endl;
	}
	cout << endl << endl<<endl;

	//-------------------下面使用find_if函数-------------------------

	vector<int> ivec;

	for (size_t i = 1; i <= 20; i++)
	{
		ivec.push_back(i);
	}

	cout << "向量里面的数据是: " << endl;
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++ iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	vector<int>::iterator pos;

	pos = find_if(ivec.begin(), ivec.end(), bind2nd(greater<int>(), 2));
	cout << *pos << endl;

	pos = find_if(ivec.begin(),ivec.end(),not1(bind2nd(modulus<int>(), 3)));
	cout << *pos << endl;
	
	//-----------------------------使用set集合进行相关查找---------------------

	set<int> iset;
	//将元素插入集合中之后，集合中的元素会自动排序
	iset.insert(45);
	iset.insert(321);
	iset.insert(145);
	iset.insert(15);
	iset.insert(-45);
	iset.insert(-154);
	iset.insert(897);

	cout << "集合中的元素是: ";
	for (set<int>::iterator siter = iset.begin();
	siter != iset.end(); ++siter)
	{
		cout << *siter << " ";
	}
	cout << endl;

	int num;
	cin >> num;
	set<int>::iterator spos;
	//对有序数据find函数采用的是类似二分查找的方法，效率特别高
	spos = iset.find(num);
	if (spos != iset.end())
	{
		cout << "已经找到该数据!" << endl;
	}
	else
	{
		cout << "没有要找的数据!" << endl;
	}

	//------------------用string对find函数进行操作------------
	string s("Anabamas");
	size_t strpos = s.find("ba");

	if (strpos != string::npos)
	{
		cout << "找到了，位置是: " << *pos << endl;
	}
	else
	{
		cout << "没找到!" << endl;
	}

	system("pause");
	return 0;
}