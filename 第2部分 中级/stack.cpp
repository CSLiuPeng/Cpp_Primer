#include<iostream>
#include<system_error>
#include<stack>
#include<list>
#include<vector>
using namespace std;

int main()
{
	stack<int, deque<int>>	a;
	stack<int, vector<int>>    b;
	stack<int, list<int>>			c;
	stack<int>						d;		//默认是用deque做适配器

	d.push(9);
	d.push(8);
	d.push(7);
	d.push(6);
	d.push(5);
	d.push(4);
	d.push(3);
	d.push(2);
	d.push(1);
	
	cout << "The number of stack is: " << d.size() << endl;
	//while (d.size() != 0)
	while (d.empty() == false)
	{
		int x = d.top();
		cout << x << endl;
		d.pop();
	}
	cout << "The number of stack is: " << d.size() << endl;

	system("pause");
	return 0;
}