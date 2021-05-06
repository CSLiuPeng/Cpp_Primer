#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

//定义一个二元谓词函数
bool isEven(int elem, bool even)
{
	if (even)
	{
		return elem % 2 == 0 ;
	}
	else
	{
		return elem % 2 == 1;
	}
}

int main()
{
	int length;
	cout << "length= ";
	cin >> length;

	list<int> ilist;
	deque<int> ideq;

	for (size_t i = 0; i < length; i++)
	{
		ideq.insert(ideq.end(), i);
	}

	for (size_t i = 0; i < length; i++)
	{
		ideq.insert(ideq.end(), i);
	}

	for (size_t i = 2; i < 9; i++)
	{
		ilist.insert(ilist.end(), i);
	}

	cout << "The deque contain of number is: ";
	for (deque<int>::iterator deqiter = ideq.begin();
	deqiter != ideq.end(); ++deqiter)
	{
		cout << *deqiter << " ";
	}
	cout << endl<<endl;

	cout << "The list contain of number is: ";
	for (list<int>::iterator liter = ilist.begin();
	liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl<<endl;

	//查找子序列在双端队列中的位置
	deque<int>::iterator pos;
	//使用search函数进行查找，search查找是从前往后查找
	//相当于从左往右查找
	cout << "search查找："<<endl;
	pos = search(ideq.begin(),ideq.end(),
		ilist.begin(),ilist.end());

	while( pos != ideq.end())
	{
		cout << "找到了，位置是: "
			<< distance(ideq.begin(), pos) + 1 << endl;
		++pos;
		pos = search(pos, ideq.end(),
			ilist.begin(), ilist.end());
	}
	cout << endl << endl;

	//使用find_end(相当于search_end,属于当时的命名bug)函数进行查找，
	//find_end查找是从后往前查找,相当于从右往左查找
	cout << "find_end查找：" << endl;
	deque<int>::iterator pos1;
	pos1 = find_end(ideq.begin(), ideq.end(),
		ilist.begin(), ilist.end());

	if (pos1 != ideq.end())
	{
		cout << "找到了，位置是: "
			<< distance(ideq.begin(), pos1) + 1 << endl;
	}
	cout << endl << endl;

	//--------------------------------------------------------------------------------
	cout << "第二个例子：" << endl;;
	vector<int> ivec;
	for (size_t i = 1; i <= 15; i++)
	{
		ivec.push_back(i);
	}

	for (vector<int>::iterator viter = ivec.begin();
	viter != ivec.end(); ++viter)
	{
		cout << *viter << " ";
	}
	cout << endl;

	bool checkEvenArgs[] = {false, true, false};
	vector<int>::iterator pos2;
	pos2 = search(ivec.begin(), ivec.end(),
		checkEvenArgs, checkEvenArgs+3, isEven);
	if ( pos2 != ivec.end())
	{
		cout << "找到了，位置是: "
			<< distance(ivec.begin(), pos2) + 1 << endl;
	}
	else
	{
		cout << "没找到！" << endl;
	}

	system("pause");
	return 0;
}