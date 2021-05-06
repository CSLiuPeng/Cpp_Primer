#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	list<int> ilist;

	for (int i = 0; i < 10; ++i)
	{
		ilist.insert(ilist.end(), i );
	}

	for (int i = 0; i < 10; ++i)
	{
		ilist.insert(ilist.end(), i);
	}

	for (list<int>::iterator liter = ilist.begin();
	liter != ilist.end(); ++ liter)
	{
		cout << *liter << " ";
	}
	cout << endl;

	list<int>::iterator pos1;

	pos1 = find(ilist.begin(), ilist.end(), 4);
	cout << "���ҵ����ֵ�һ�γ��ֵ�λ����: " << (*pos1) +1 << endl;

	list<int>::iterator pos2;
	
	if (pos1 != ilist.end())//����pos2��λ��s
	{
		//��Ҫ�ر�ע��ڶ���λ�õ���������ʼλ��
		pos2 = find(++pos1, ilist.end(),4); 
	}

	//��ʾ����������֮�������
	if (pos1 != ilist.end() && pos2 != ilist.end())
	{
		cout << "����������֮���������: ";
		//��ʾ�����˵�Ԫ��
		--pos1;
		++pos2;
		for (list<int>::iterator liter = pos1; liter != pos2; ++ liter)
		{
			cout  << *liter << " ";
		}
		cout << endl;
	}
	cout << endl << endl<<endl;

	//-------------------����ʹ��find_if����-------------------------

	vector<int> ivec;

	for (size_t i = 1; i <= 20; i++)
	{
		ivec.push_back(i);
	}

	cout << "���������������: " << endl;
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++ iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	vector<int>::iterator pos;

	pos = find_if(ivec.begin(), ivec.end(), bind2nd(greater<int>(), 2));
	cout << *pos << endl;

	pos = find_if(ivec.begin(),ivec.end(),not1(bind2nd(modulus<int>(), 3)));
	cout << *pos << endl;
	
	//-----------------------------ʹ��set���Ͻ�����ز���---------------------

	set<int> iset;
	//��Ԫ�ز��뼯����֮�󣬼����е�Ԫ�ػ��Զ�����
	iset.insert(45);
	iset.insert(321);
	iset.insert(145);
	iset.insert(15);
	iset.insert(-45);
	iset.insert(-154);
	iset.insert(897);

	cout << "�����е�Ԫ����: ";
	for (set<int>::iterator siter = iset.begin();
	siter != iset.end(); ++siter)
	{
		cout << *siter << " ";
	}
	cout << endl;

	int num;
	cin >> num;
	set<int>::iterator spos;
	//����������find�������õ������ƶ��ֲ��ҵķ�����Ч���ر��
	spos = iset.find(num);
	if (spos != iset.end())
	{
		cout << "�Ѿ��ҵ�������!" << endl;
	}
	else
	{
		cout << "û��Ҫ�ҵ�����!" << endl;
	}

	//------------------��string��find�������в���------------
	string s("Anabamas");
	size_t strpos = s.find("ba");

	if (strpos != string::npos)
	{
		cout << "�ҵ��ˣ�λ����: " << *pos << endl;
	}
	else
	{
		cout << "û�ҵ�!" << endl;
	}

	system("pause");
	return 0;
}