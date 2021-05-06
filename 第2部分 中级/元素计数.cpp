#include<iostream>
#include<system_error>
#include<algorithm>
#include<vector>
#include<functional>
#include<set>

using namespace std;

bool isEven(int numbers)
{
	return numbers % 2 == 0;
}

int main()
{
	vector<int> ivec;
	
	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter )
	{
		cout << *iter << " ";
	}
	cout << endl;

	/*ivec.push_back(4);
	ivec.push_back(4);
	ivec.push_back(4);
	ivec.push_back(4);
	ivec.push_back(4);*/

	int num;
	//使用count算法
	num = count(ivec.begin(),ivec.end(),4);
	cout << "The number of 4 is:" << num << endl;

	//使用count_if算法
	//num = count_if(ivec.begin(),ivec.end(),isEven);
	//                                                                            mod % 2 =1 true
	num = count_if(ivec.begin(), ivec.end(), not1( bind2nd( modulus<int>(),2)));
	cout << "The number of function is:" << num << endl;

	//                                                         函数适配器  参数1            参数2
	num = count_if(ivec.begin(), ivec.end(), bind2nd(greater<int>(), 4));
	cout << "Bigger than 4 number is:"<<num << endl;

	multiset<int> mset;
	for (size_t i = 0; i < 20; i++)
	{
		mset.insert(mset.end(),i);
	}

	mset.insert(20);
	mset.insert(20);
	mset.insert(20);
	mset.insert(20);
	mset.insert(20);

	for (multiset<int>::iterator miter = mset.begin();
	miter != mset.end(); ++miter)
	{
		cout  << *miter << " " ;
	}
	cout << endl;

	num = count(mset.begin(),mset.end(),20);
	cout << "The same as 20 have: " << num << endl;

	num = mset.count(20);
	cout << "The same as 20 have: " << num << endl;

	system("pause");
	return 0;
}