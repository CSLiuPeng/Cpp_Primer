#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<set>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	deque<int> ideq;

	int length;
	cout << "length= ";
	cin >> length;

	for (size_t i = 0; i < length; i++)
	{
		ideq.push_back(i);
	}

	ideq.push_back(3);
	ideq.push_back(3);
	ideq.push_back(3);
	ideq.push_back(3);
	ideq.push_back(3);

	cout << "双端队列中的元素是: ";
	for (deque<int>::iterator deqiter = ideq.begin();
	deqiter != ideq.end(); ++deqiter)
	{
		cout << *deqiter << " ";
	}
	cout << endl;

	deque<int>::iterator posdeq;
	//查找连续的多个数
	posdeq = search_n(ideq.begin(),ideq.end(),5,3);
	if (posdeq != ideq.end())
	{
		cout <<"找到了连续的几个数,位置是: " 
			<< distance(ideq.begin() , posdeq)+1 << endl;
	}
	else
	{
		cout << "没找到有连续数字出现!" << endl;
	}

	posdeq = search_n(ideq.begin(), ideq.end(), 5, 3, greater<int>());
	if (posdeq != ideq.end())
	{
		cout << "找到了,位置是: "
			<< distance(ideq.begin(), posdeq) + 1 << endl;
	}
	else
	{
		cout << "没找到有连续数字出现!" << endl;
	}

	system("pause");
	return 0;
}