#include<iostream>
#include<system_error>
#include<string>
#include<set>

using namespace std;

//定义输出函数
template<typename Contents>
void printCounter(const Contents & c)
{
	Contents::const_iterator i;
	for (i = c.begin(); i != c.end(); ++i)
	{
		cout << *i << endl;
	}
	cout << endl << endl;
}

int main()
{
	set<int>			a;
	multiset<int>	ma;

	a.insert(12);
	a.insert(5);
	a.insert(54);
	a.insert(-23);
	a.insert(-32);

	//set中的数据不能重复
	cout << "Sort Set: " << endl;
	printCounter(a);

	ma.insert(a.begin(),a.end());
	ma.insert(12);
	ma.insert(3000);

	cout << "相同的数字个数为：" << endl;
	cout << ma.count(12) << endl << endl;

	cout << "Sort Multiset: " << endl;
	printCounter(ma);

	set<int>::iterator i_find = ma.find(12);//不能通过find修改
	if (i_find != ma.end())
	{
		cout << "找到了" << *i_find << endl;
	}
	
	cout << "删除之前的数据是: " << endl;
	printCounter(ma);
	cout << "请输入要删除的数据: " << endl;
	int deleteElem = 0;
	cin >> deleteElem;
	ma.erase(deleteElem);
	cout << "删除之后的数据是: " << endl;
	printCounter(ma);

	system("pause");
	return 0;
}