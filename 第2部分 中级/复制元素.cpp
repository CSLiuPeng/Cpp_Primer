#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<algorithm>
#include<functional>
#include<iterator>
#include<string>

using namespace std;

int main()
{
	cout << "----------------------The first example---------------------------" << endl << endl;

	list<int> ilist;

	for (size_t i = 0; i < 10; i++)
	{
		ilist.push_back(i);
	}

	cout << "列表中的元素是: ";
	for (list<int>::iterator liter = ilist.begin(); 
	liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl<<endl;

	vector<int> ivec(ilist.size() * 2);

	cout << "向量中的元素是: ";
	for (vector<int>::iterator viter = ivec.begin(); 
	viter != ivec.end(); ++viter)
	{
		cout << *viter << " ";
	}
	cout << endl << endl;

	cout << "第一次拷贝之后: ";
	copy(ilist.begin(), ilist.end(),ivec.begin());
	for (vector<int>::iterator viter = ivec.begin();
	viter != ivec.end(); ++viter)
	{
		cout << *viter << " ";
	}
	cout << endl << endl;

	cout << "第二次拷贝之后: ";
	copy_backward(ilist.begin(), ilist.end(), ivec.end());
	for (vector<int>::iterator viter = ivec.begin();
	viter != ivec.end(); ++viter)
	{
		cout << *viter << " ";
	}
	cout << endl << endl;

	cout << "----------------------The second example---------------------------" << endl<<endl;

	vector<int> ivec2;
	list<int> ilist2;

	for (size_t i = 0; i < 20; i++)
	{
		ivec2.push_back(i);
	}
	
	copy(ivec2.begin(), ivec2.end(), back_inserter(ilist2));
	for (list<int>::iterator listiter = ilist2.begin();
	listiter != ilist2.end(); ++listiter)
	{
		cout << *listiter << " ";
	}
	cout << endl << endl;

	copy(ivec2.begin(), ivec2.end(), 
		ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	copy(ivec2.rbegin(), ivec2.rend(), ilist2.begin());
	copy(ilist2.begin(), ilist2.end(), 
		ostream_iterator<int>(cout, " "));
	cout << endl<<endl;

	cout << "----------------------The third example---------------------------" << endl << endl;

	vector<char> cvect(15, '*');

	for (int c = 'a'; c < 'f'; ++c)
	{
		cvect.push_back(c);
	}

	cvect.insert(cvect.end(), 15, '*');
	for (vector<char>::iterator vciter = cvect.begin(); 
	vciter != cvect.end(); ++vciter)
	{
		cout << *vciter << " ";
	}
	cout << endl;

	vector<char> c1(cvect.begin(), cvect.end());
	copy(cvect.begin()+15,cvect.begin()+21, c1.begin()+5);
	for (vector<char>::iterator vciter1 = c1.begin();
	vciter1 != c1.end(); ++vciter1)
	{
		cout << *vciter1 << " ";
	}
	cout << endl;

	vector<char> c2(cvect.begin(), cvect.end());

	copy_backward(cvect.begin() + 15, 
		cvect.begin() + 21, c2.begin() + 31);
	for (vector<char>::iterator vciter2 = c2.begin();
	vciter2 != c2.end(); ++vciter2)
	{
		cout << *vciter2 << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}