#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
	vector<int> a;
	const vector<int> ca(a);
	list< int > b;
	deque<int> c;

	vector<int > ::size_type a1;
	vector<int>::iterator a2;
	vector<int>::const_iterator a3;
	vector<int>::reverse_iterator a4;
	vector<int>::const_reverse_iterator a5;
	vector<int>::difference_type a6;
	//vector<int>::value_type a7;
	//vector<int>::reference a8;
	//vector<int>::const_reference a9;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	b.push_back(10);
	b.push_back(20);
	b.push_back(30);

	//for (int i = 0; i < a.size(); ++i)
	for (vector<int> ::size_type i = 0; i < a.size(); ++i)
		//���Ӹ߼���д�������Ա���������͵�����
	{
		cout << a[i] << endl;
	}

	vector<int>::iterator firsta = a.begin();
	vector<int>::iterator lasta = a.end();//ָ�����һ������һ��Ԫ��

//	vector<int>::const_iterator cfirsta = ca.begin();
//	cout << "�������� cfrista:" << *cfirsta << endl;
//	vector<int>::const_iterator clasta = ca.end();
	/*while (cfirsta != clasta)
	{
		cout << "������ cfirsta: " << *cfirsta << endl;
		++cfirsta;
	}*/
//	cout << "������ firsta:" << *firsta << endl;
//	cout << "������ lasta:" << *lasta << endl;
	while (firsta != lasta)
	{
		cout << "firsta: " <<*firsta<< endl;
		++firsta;
	}

	/*vector<int>::reverse_iterator rfirsta = a.begin();
	vector<int>::reverse_iterator rlasta = a.end();
	while (rfirsta != rlasta)
	{
		cout << "rfirsta: " << *rfirsta << endl;
		++rfirsta;
	}*/

	list<int > ::size_type b1;
	list<int>::iterator b2;
	list<int>::const_iterator b3;
	list<int>::reverse_iterator b4;
	list<int>::const_reverse_iterator b5;
	list<int>::difference_type b6;
	/*list<int>::value_type b7;
	list<int>::reference b8;
	list<int>::const_reference b9;*/

	deque<int > ::size_type c1;
	deque<int>::iterator c2;
	deque<int>::const_iterator c3;
	deque<int>::reverse_iterator c4;
	deque<int>::const_reverse_iterator c5;
	deque<int>::difference_type c6;
	/*deque<int>::value_type c7;
	deque<int>::reference c8;
	deque<int>::const_reference c9;
*/
	cout << "success!" << endl;
	system("pause");
	return 0;
}