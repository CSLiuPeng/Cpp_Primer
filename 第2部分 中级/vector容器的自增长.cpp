#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> ivec;
	int length = 0;

	cout << "length=";
	cin >> length;
	//����ÿ��������һ�������
	for (size_t i = 0; i < length; i++)
	{
		ivec.push_back(i);
		cout << "�����Ĵ�С��: " << ivec.size() 
			<< ", ������������: " << ivec.capacity() << endl;
	}
	cout << endl << endl;

	//�������ռ�����ָ���Ĵ�С
	ivec.reserve(1000);
	cout << "ֱ�ӷ��������ռ�Ĵ�С" << endl;
	cout << "�����Ĵ�С��: " << ivec.size()
		<< ", ������������: " << ivec.capacity() << endl;

	system("pause");
	return 0;
}