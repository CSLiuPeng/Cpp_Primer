#include<iostream>
#include<system_error>
#include<vector>
#include<list>
#include<deque>

using namespace std;

int main()
{
	vector<string> svec;
	list<int> ilist;

	vector<int> ivec;//Ĭ�Ϲ��캯��
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);

	vector<int> ivec2(ivec);//�вι��캯��
	cout << "success" << endl;
	system("pause");
	return 0;
}