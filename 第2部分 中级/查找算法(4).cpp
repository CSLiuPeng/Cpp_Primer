#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	vector<int> ivec;
	list<int> searchList;

	int length;
	cout << "length: ";
	cin >> length;
	for (size_t i = 0; i < length; i++)
	{
		ivec.push_back(i);
	}

	cout << "���������е�Ԫ���ǣ�";
	for (vector<int>::iterator viter = ivec.begin();
	viter != ivec.end(); ++viter)
	{
		cout <<  *viter <<" ";
	}
	cout << endl;

	searchList.push_back(3);
	searchList.push_back(6);
	searchList.push_back(9);

	vector<int>::iterator pos;
	//�����е�����һ��Ԫ�أ��ӵ�һ����һ������
	pos = find_first_of(ivec.begin(), ivec.end(), 
		searchList.begin(), searchList.end());
	if (pos != ivec.end())
	{
		cout << "�ҵ��ˣ�λ����: "
			<< distance(ivec.begin(), pos) + 1 << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}

	//ʹ�����������
	vector<int>::reverse_iterator rpos;
	rpos = find_first_of(ivec.rbegin(), ivec.rend(), 
		searchList.begin(), searchList.end());
	cout << "������ҵĽ����: " 
		<< distance(ivec.begin(), rpos.base()) << endl;
	cout << endl << endl;

	//-----------------------ʹ��string��صĲ���---------------
	string numberics("0123456789");
	string name("jai323li23");

	string::size_type p = name.find_first_of(numberics);
	cout << "��ǰ������ҵĽ������: " << endl;
	if (p != string::npos)
	{
		cout << "�ҵ��ˣ��±���: " << p << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}

	p = name.find_last_of(numberics);
	cout << "�Ӻ���ǰ���ҵĽ������: " << endl;
	if (p != string::npos)
	{
		cout << "�ҵ��ˣ��±���: " << p << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}

	system("pause");
	return 0;
}