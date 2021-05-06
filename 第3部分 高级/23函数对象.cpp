#include<iostream>
#include<system_error>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
#include<iterator>
#include<set>
using namespace std;

class absInt
{
public:
	int operator()(int val);
};

//定义函数对象
template <typename elementType>
class DispElement
{
public:
	int m_nCount;

public:
	DispElement() :m_nCount(0) {}

	void operator()(const elementType & elements) 
	{
		++m_nCount;
		cout << elements << " ";
	}
};

//定义普通的函数
template <typename elementType>
void function(const elementType & elements) 
{
	cout << elements << " ";
}

template<typename numberType>
class isMultiple
{
public:
	numberType m_Divisor;
	isMultiple() = default;

	isMultiple(const numberType & divisor)
	{
		m_Divisor = divisor;
	}
	//一元谓词
	bool operator()(const numberType & elements) const
	{
		return((elements % m_Divisor) == 0);
	}
};

template <typename elementType>
class Cmultiply
{
public:
	elementType operator()
		(const elementType & elem1, const elementType & elem2)
	{
		return elem1 * elem2;
	}
};

class c_CompareStringNoCase
{
public:
	//定义二元谓词
	bool operator()(const string & str1, const string & str2)const
	{
		string strLowCase1;
		strLowCase1.resize(str1.size());
		transform(str1.begin(), str1.end(), strLowCase1.begin(), tolower);

		string strLowCase2;
		strLowCase2.resize(str2.size());
		transform(str2.begin(), str2.end(), strLowCase1.begin(), tolower);

		return (strLowCase1 < strLowCase2);
	}
};

int main()
{
	int i = -42;
	absInt  absObj;
	unsigned int ui = absObj(i);
	cout << ui << endl;

	vector<int> a;
	for (size_t i = 0; i < 10; i++)
	{
		a.push_back(i);
	}

	list<char> b;
	for (char c = 'a';  c < 'k';  c++)
	{
		b.push_back(c);
	}

	for_each(a.begin(), a.end(), DispElement<int>());
	cout << endl;

	DispElement<int> result;
	result = for_each(a.begin(), a.end(),  result);
	cout << "结果是:" << result.m_nCount << endl;

	for_each(b.begin(), b.end(), DispElement<char>());
	cout << endl;

	cout << "----------------------------------------------" << endl<<endl;
	vector<int> ivec;

	for (size_t i = 1; i <= 100 ; i++)
	{
		ivec.push_back(i);
	}

	vector<int>::iterator iElements;
	//isMultiple<int> a1(4);
	//iElements = find_if(ivec.begin(), ivec.end(), a1);

	//匿名调用函数对象
	iElements = find_if(ivec.begin(), ivec.end(), isMultiple<int>(4));

	if (iElements != ivec.end())
	{
		cout << "第一个被整除的数是: " << *iElements << endl;
	}

	cout << "----------------------------------------------" << endl<<endl;

	vector<int> iveca, ivecb;
	for (size_t i = 0; i < 10; i++)
	{
		iveca.push_back(i);
	}

	for (size_t j = 100; j < 110; j++)
	{
		ivecb.push_back(j);
	}

	vector<int> ivecResult;
	ivecResult.resize(10);

	transform(iveca.begin(), iveca.end(), ivecb.begin(),
		ivecResult.begin(), Cmultiply<int>());

	for (size_t i = 0; i < ivecResult.size() ; i++)
	{
		cout << ivecResult[i] << " ";
	}
	cout << endl;

	cout << "----------------------------------------------" << endl << endl;

	set<string, c_CompareStringNoCase> names;

	names.insert("James");
	names.insert("Tomas");
	names.insert("Robert");
	names.insert("Wallimes");
	names.insert("Susan");
	names.insert("Phoenix");

	set<string>::iterator iNameFound = names.find("Tomajs");
	if (iNameFound != names.end())
	{
		cout << "Found it" << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}
	system("pause");
	return 0;
}

int absInt::operator()(int val)
{
	return val < 0 ? -val : val;
}
