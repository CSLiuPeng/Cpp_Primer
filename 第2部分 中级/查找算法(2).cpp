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

	cout << "˫�˶����е�Ԫ����: ";
	for (deque<int>::iterator deqiter = ideq.begin();
	deqiter != ideq.end(); ++deqiter)
	{
		cout << *deqiter << " ";
	}
	cout << endl;

	deque<int>::iterator posdeq;
	//���������Ķ����
	posdeq = search_n(ideq.begin(),ideq.end(),5,3);
	if (posdeq != ideq.end())
	{
		cout <<"�ҵ��������ļ�����,λ����: " 
			<< distance(ideq.begin() , posdeq)+1 << endl;
	}
	else
	{
		cout << "û�ҵ����������ֳ���!" << endl;
	}

	posdeq = search_n(ideq.begin(), ideq.end(), 5, 3, greater<int>());
	if (posdeq != ideq.end())
	{
		cout << "�ҵ���,λ����: "
			<< distance(ideq.begin(), posdeq) + 1 << endl;
	}
	else
	{
		cout << "û�ҵ����������ֳ���!" << endl;
	}

	system("pause");
	return 0;
}