#include<iostream>
#include<system_error>
#include<string>
#include<set>

using namespace std;

//�����������
template<typename Contents>
void printCounter(const Contents & c)
{
	Contents::const_iterator i;
	for (i = c.begin(); i != c.end(); ++i)
	{
		cout << *i << endl;
	}
	cout << endl << endl;
}

int main()
{
	set<int>			a;
	multiset<int>	ma;

	a.insert(12);
	a.insert(5);
	a.insert(54);
	a.insert(-23);
	a.insert(-32);

	//set�е����ݲ����ظ�
	cout << "Sort Set: " << endl;
	printCounter(a);

	ma.insert(a.begin(),a.end());
	ma.insert(12);
	ma.insert(3000);

	cout << "��ͬ�����ָ���Ϊ��" << endl;
	cout << ma.count(12) << endl << endl;

	cout << "Sort Multiset: " << endl;
	printCounter(ma);

	set<int>::iterator i_find = ma.find(12);//����ͨ��find�޸�
	if (i_find != ma.end())
	{
		cout << "�ҵ���" << *i_find << endl;
	}
	
	cout << "ɾ��֮ǰ��������: " << endl;
	printCounter(ma);
	cout << "������Ҫɾ��������: " << endl;
	int deleteElem = 0;
	cin >> deleteElem;
	ma.erase(deleteElem);
	cout << "ɾ��֮���������: " << endl;
	printCounter(ma);

	system("pause");
	return 0;
}