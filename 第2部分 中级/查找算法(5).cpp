#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;
bool doubles(int elem1, int elem2)
{
	return elem1 * 2 == elem2;
}

int main()
{
	vector<int>	ivec;

	ivec.push_back(5);
	ivec.push_back(7);
	ivec.push_back(0);
	ivec.push_back(1);
	ivec.push_back(3);
	ivec.push_back(3);
	ivec.push_back(4);
	ivec.push_back(3);
	ivec.push_back(6);
	
	cout << "�����е�������: ";
	for (vector<int>::iterator viter = ivec.begin(); 
	viter != ivec.end(); ++viter)
	{
		cout << *viter << " ";
	}
	cout << endl << endl;

	vector<int>::iterator pos;
	//����������ͬ����
	pos = adjacent_find(ivec.begin(), ivec.end());
	if (pos != ivec.end())
	{
		cout << "�ҵ��ˣ�λ����: " 
			<< distance(ivec.begin(), pos) + 1 << endl;
	}
	else
	{
		cout << "û����! " << endl;
	}

	//�ڶ��ַ�����ʹ��ν��
	pos = adjacent_find(ivec.begin(), ivec.end(), doubles);
	if (pos != ivec.end())
	{
		cout << "�ҵ��ˣ�λ����: "
			<< distance(ivec.begin(), pos) + 1 << endl;
	}
	else
	{
		cout << "û����! " << endl;
	}

	system("pause");
	return 0;
}