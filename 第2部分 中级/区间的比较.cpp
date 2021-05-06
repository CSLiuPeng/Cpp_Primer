#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

//���һ��ν�ʺ���
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

	//ʹ��equal()�����Ƚϴ�С
	//�ж����������е�Ԫ���Ƿ����
	cout << "ʹ��equal()�����Ƚϴ�С:" << endl<<endl;
	if (equal(ivec.begin(), ivec.end(), ilist.begin()))
	{
		cout << "�����������! " << endl;
	}
	else
	{
		cout << "�������䲻���! " << endl;
	}
	cout << endl << endl;

	//ʹ�ú���ν�ʵıȽϺ���
	if (equal(ivec.begin(), ivec.end(), ilist.begin(), 
		bothEvenOrOdd))
	{
		cout << "��������������ż����Ӧ! " << endl;
	}
	else
	{
		cout << "��������������ż������Ӧ! " << endl;
	}
	cout << endl << endl;

	//ʹ��mismatch()�����Ƚϴ�С
	cout << "ʹ��mismatch()�����Ƚϴ�С: " << endl << endl;
	pair<vector<int>::iterator, list<int>::iterator> value;
	value = mismatch(ivec.begin(), ivec.end(),ilist.begin());

	if (value.first == ivec.end())
	{
		cout << "û���ҵ�����ȵ���." << endl;
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
		cout << "û�ҵ�! (always less-or-equal)" << endl;
	}
	else
	{
		cout << "�ҵ���:(not less-or-equal) " 
			<< *value.first << " ," << *value.second << endl;
	}
	cout << endl << endl << endl;

	//���С�������㷨
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

	cout << "����֮��Ľ��:" << endl;
	for_each(vectlist.begin(), vectlist.end(), printFunction);

	system("pause");
	return 0;
}