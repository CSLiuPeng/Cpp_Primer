#include<iostream>
#include<system_error>
#include<list>
using namespace std;

void printListCounters(list<int> & inputList)
{
	cout << "{";
	list<int>::const_iterator citer;
	for (citer = inputList.begin(); citer != inputList.end(); ++citer)
	{
		cout << *citer << " " ;
	}
	cout << "}";
	cout << endl;
}

int main()
{
	list<int> a;
	
	a.push_front(10);
	a.push_front(20);
	a.push_front(30);
	a.push_front(40);

	a.push_back(0);

	/*a.insert(a.begin(),50);
	a.insert(a.end(),5,1);*/

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	/*list<int>::iterator iter;
	for (iter = a.begin(); iter != a.end(); ++iter)
	{
		cout << *iter<<" "<<endl;
	}
	cout << endl;*/

	list<int>::iterator iElementValue = a.insert(a.begin(),2);

	printListCounters(a);
	cout << endl;

	a.erase(iElementValue);
	printListCounters(a);
	cout << endl;

	a.reverse();
	printListCounters(a);
	cout << endl;

	a.sort();
	printListCounters(a);
	
	system("pause");
	return 0;
}