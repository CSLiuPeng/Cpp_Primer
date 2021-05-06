#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

//����һ����Ԫν�ʺ���
bool isEven(int elem, bool even)
{
	if (even)
	{
		return elem % 2 == 0 ;
	}
	else
	{
		return elem % 2 == 1;
	}
}

int main()
{
	int length;
	cout << "length= ";
	cin >> length;

	list<int> ilist;
	deque<int> ideq;

	for (size_t i = 0; i < length; i++)
	{
		ideq.insert(ideq.end(), i);
	}

	for (size_t i = 0; i < length; i++)
	{
		ideq.insert(ideq.end(), i);
	}

	for (size_t i = 2; i < 9; i++)
	{
		ilist.insert(ilist.end(), i);
	}

	cout << "The deque contain of number is: ";
	for (deque<int>::iterator deqiter = ideq.begin();
	deqiter != ideq.end(); ++deqiter)
	{
		cout << *deqiter << " ";
	}
	cout << endl<<endl;

	cout << "The list contain of number is: ";
	for (list<int>::iterator liter = ilist.begin();
	liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl<<endl;

	//������������˫�˶����е�λ��
	deque<int>::iterator pos;
	//ʹ��search�������в��ң�search�����Ǵ�ǰ�������
	//�൱�ڴ������Ҳ���
	cout << "search���ң�"<<endl;
	pos = search(ideq.begin(),ideq.end(),
		ilist.begin(),ilist.end());

	while( pos != ideq.end())
	{
		cout << "�ҵ��ˣ�λ����: "
			<< distance(ideq.begin(), pos) + 1 << endl;
		++pos;
		pos = search(pos, ideq.end(),
			ilist.begin(), ilist.end());
	}
	cout << endl << endl;

	//ʹ��find_end(�൱��search_end,���ڵ�ʱ������bug)�������в��ң�
	//find_end�����ǴӺ���ǰ����,�൱�ڴ����������
	cout << "find_end���ң�" << endl;
	deque<int>::iterator pos1;
	pos1 = find_end(ideq.begin(), ideq.end(),
		ilist.begin(), ilist.end());

	if (pos1 != ideq.end())
	{
		cout << "�ҵ��ˣ�λ����: "
			<< distance(ideq.begin(), pos1) + 1 << endl;
	}
	cout << endl << endl;

	//--------------------------------------------------------------------------------
	cout << "�ڶ������ӣ�" << endl;;
	vector<int> ivec;
	for (size_t i = 1; i <= 15; i++)
	{
		ivec.push_back(i);
	}

	for (vector<int>::iterator viter = ivec.begin();
	viter != ivec.end(); ++viter)
	{
		cout << *viter << " ";
	}
	cout << endl;

	bool checkEvenArgs[] = {false, true, false};
	vector<int>::iterator pos2;
	pos2 = search(ivec.begin(), ivec.end(),
		checkEvenArgs, checkEvenArgs+3, isEven);
	if ( pos2 != ivec.end())
	{
		cout << "�ҵ��ˣ�λ����: "
			<< distance(ivec.begin(), pos2) + 1 << endl;
	}
	else
	{
		cout << "û�ҵ���" << endl;
	}

	system("pause");
	return 0;
}