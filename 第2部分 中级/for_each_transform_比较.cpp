#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<functional>
#include<iterator>

using namespace std;

//for_each函数的参数要求用引用
void square(int & elem)
{
	elem *= elem;
}

//transform函数的参数不要求用引用，
//但是函数的类型要求为int型
int square2(int elem2)
{
	elem2 *= elem2;
	return elem2;
}

int main()
{
	vector<int> a;
	vector<int> b;

	for (size_t i = 0; i <=10 ; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}

	cout << "向量a中的元素: " << endl;
	for (vector<int>::iterator iter = a.begin(); 
	iter != a.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	for_each(a.begin(), a.end(), square);

	for (vector<int>::iterator iter = a.begin();
	iter != a.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "向量b中的元素: " << endl;
	for (vector<int>::iterator iter = b.begin();
	iter != b.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	transform(b.begin(), b.end(), b.begin(), square2);
	for (vector<int>::iterator iter = b.begin();
	iter != b.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}