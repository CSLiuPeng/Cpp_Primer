#include<iostream>
#include<system_error>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

void print(int elem)
{
	cout << elem << " ";
}

template <class T>
class addValue {
private:
	T theValue;
public:
	addValue(const T & v) :theValue(v) {}

	void operator() (T & elems) const 
	{
		 elems += theValue;
	}
};

class MeanValue
{
private:
	long num;
	long sum;
public:
	MeanValue() :num(0), sum(0) {}

	void operator() (int elem)
	{
		++num;
		sum += elem;
	}

	double value()
	{
		return static_cast<double> (sum) / static_cast <double>(num);
	}

	operator double()
	{
		return static_cast<double> (sum) / static_cast <double>(num);
	}
};

int main()
{
	vector<int> ivec;

	int length = 0;
	cout << "length= ";
	cin >> length;

	for (size_t i = 1; i <= length; i++)
	{
		ivec.push_back(i);
	}

	for_each(ivec.begin(), ivec.end(), print);
	cout << endl << endl;

	MeanValue mv = for_each(ivec.begin(), ivec.end(), MeanValue());
	cout << "Average value is: " << mv.value() << endl;

	for_each(ivec.begin(), ivec.end(), addValue<int>(*(ivec.begin())));
	for_each(ivec.begin(), ivec.end(), print);
	cout << endl<<endl;

	for_each(ivec.begin(), ivec.end(), addValue<int>(20));
	for_each(ivec.begin(), ivec.end(), print);
	cout << endl << endl;

	double result = for_each(ivec.begin(), ivec.end(), MeanValue());
	cout << "Average value is: " << result << endl;

	system("pause");
	return 0;
}