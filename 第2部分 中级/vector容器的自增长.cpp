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
	//向量每次增加其一半的容量
	for (size_t i = 0; i < length; i++)
	{
		ivec.push_back(i);
		cout << "向量的大小是: " << ivec.size() 
			<< ", 向量的容量是: " << ivec.capacity() << endl;
	}
	cout << endl << endl;

	//将向量空间增大到指定的大小
	ivec.reserve(1000);
	cout << "直接分配向量空间的大小" << endl;
	cout << "向量的大小是: " << ivec.size()
		<< ", 向量的容量是: " << ivec.capacity() << endl;

	system("pause");
	return 0;
}