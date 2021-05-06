#pragma once
//值型类(深复制)
class CHasPtr
{
public:
	//构造函数
	CHasPtr(const int & p, int i) : ptr(new int(p)), val(i) {}

	//复制构造函数
	CHasPtr(const CHasPtr & orign)
		:ptr(new int(*(orign.ptr))), val(orign.val){}

	//赋值操作符声明
	CHasPtr & operator = (const CHasPtr & );

	//析构函数
	~CHasPtr()
	{
		delete ptr;
	}
	
	int * get_ptr() const
	{
		return ptr;
	}

	int get_int() const
	{
		return val;
	}

	void set_ptr(int * p)
	{
		ptr = p;
	}

	void set_int(int i)
	{
		val = i;
	}

	int get_ptr_val() const
	{
		return *ptr;
	}

	void set_ptr_val(int val) const
	{
		*ptr = val;
	}

private:
	int val;
	int * ptr;

};

//复制操作符的定义
CHasPtr & CHasPtr::operator = (const CHasPtr & rhs)
{
	*ptr = *(rhs.ptr);
	val = rhs.val;
	return *this;
}

