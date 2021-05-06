#include<iostream>
#include<list>
#include<queue>
#include<deque>
#include<vector>
#include<algorithm>
#include<system_error>

using namespace std;

int main()
{
	deque<int> a;

	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);
	a.push_back(9);

	a.push_front(4);
	a.push_front(3);
	a.push_front(2);
	a.push_front(1);
	a.push_front(0);

    for (size_t nCount = 0;  nCount < a.size(); ++nCount)
	{
		cout << "a["<<nCount<<"]="<<a[nCount]<< endl;
	}
	cout << endl;

	cout << "Delete some elements: " << endl;

	a.pop_front();
	a.pop_back();

	/*for (size_t nCount = 0; nCount < a.size(); ++nCount)
	{
		cout << "a[" << nCount << "]=" << a[nCount] << endl;
	}
	cout << endl;
*/

	//More advance ways,use iterator
	deque<int>::iterator deiter;
//	size_t offset = distance(a.begin(),deiter);
	for (deiter = a.begin(); deiter != a.end(); ++deiter)
	{
		size_t offset = distance(a.begin(), deiter);
		cout <<"a["<<offset<<"]="<< *deiter << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}