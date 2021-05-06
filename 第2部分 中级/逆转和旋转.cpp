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

	for (size_t i = 0; i <= 9 ; i++)
	{
		ivec.push_back(i);
	}

	cout << "��ת֮ǰ������:" << endl;
	for (vector<int>::iterator iter = ivec.begin(); 
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//��ת����
	reverse(ivec.begin(), ivec.end());

	cout << "��ת֮�������:" << endl;
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	reverse_copy(ivec.begin(), ivec.end(), 
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	reverse(ivec.begin(), ivec.end());

	//�����ת
	//rotate(ivec.begin(), ivec.begin()+2, ivec.end());
	//rotate(ivec.begin(), ivec.end()-2, ivec.end());
	rotate(ivec.begin(), find(ivec.begin(), ivec.end(), 5), 
		ivec.end());

	cout << "���ת֮�������:" << endl;
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	//--------------------------The 2nd example-----------

	cout << "---------The 2nd example-----------" << endl;

	set<int> iset;

	for (size_t i = 0; i <=9 ; i++)
	{
		iset.insert(i);
	}

	for (set<int>::iterator iter = iset.begin(); 
	iter != iset.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl << endl;

	set<int>::iterator pos = iset.begin();
	//����д�� pos = pos +2;
	advance(pos, 2);
	rotate_copy(iset.begin(), pos, iset.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	pos = iset.end();
	advance(pos, -2);
	rotate_copy(iset.begin(), pos, iset.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	rotate_copy(iset.begin(), iset.find(5), iset.end(),
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	system("pause");
	return 0;
}