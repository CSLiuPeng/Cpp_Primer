#include<iostream>
#include<list>
#include<queue>
#include<deque>
#include<system_error>

using namespace std;

int main()
{
	queue<int, queue<int>>	a;
	queue<int, list<int>>		b;
	queue<int>						q; //默认形式为queue<int, queue<int>>	a;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "The total of queue size is: " << q.size() << endl;
	cout << "The front of queue element is: " << q.front() << endl;
	cout << "The back of queue element is: " << q.back() << endl;

	cout << endl;
	q.pop();
	
	cout << "The total of queue size is: " << q.size() << endl;
	cout << "The front of queue element is: " << q.front() << endl;

	while (q.size() != 0)
	{
		cout << "Delete the element : " << q.front() << endl;
		q.pop();
	}

	if (q.empty())
	{
		cout << "The queue have already empty." << endl;
	}

	system("pause");
	return 0;
}