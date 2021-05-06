#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<functional>
#include<system_error>

using namespace std;

int main()
{
	priority_queue<int, deque<int>>		a;
	priority_queue<int, vector<int>>		b;

	//最小值优先级队列
	priority_queue<int, deque<int>,greater<int>>		q; 

	q.push(5);
	q.push(3);
	q.push(8);
	q.push(2);
	q.push(9);
	q.push(1);

	cout << "The front of priority queue is: " << q.top() << endl;
	cout << "The size  of priority queue is: " << q.size() << endl;

	while (!q.empty())
	{
		cout << "Delete the peer elements: " << q.top() << endl;
		q.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}