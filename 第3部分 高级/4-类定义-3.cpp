#include<iostream>
#include<system_error>
#include<string>

using namespace std;

class Screen;//���������û�ж���

class Record//�������࣬�����ඨ�壬����������
{
public:
	typedef std::size_t size;

	string getName() const
	{
		return name;
	}

	size getCount() const
	{
		return byte_count;
	}

	//���幹�캯��
	Record() :byte_count(0) {}

	//���캯��������
	Record(size s) :byte_count(s) {}
	Record(std::string s): byte_count(0), name(s) {}

private:
	size byte_count;
	string name;
};

int main()
{
	Record r;//�ڶ�ջ�ϴ�������
	class Record r;//�Ƚϴ�ͳ��д��
	Record * p = new Record;//�ڶ��϶�̬�Ĵ�������

	//���ܶ�δ������ඨ�����
	//���ǿ��Ը�δ������ඨ��ָ�������
	Screen *scr;
	cout << "����һ��!" << endl;

	system("pause");
	return 0;
}