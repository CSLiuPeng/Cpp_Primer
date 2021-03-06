#pragma once
//常规指针类(浅复制)
class AHasPtr
{
public:
	//构造函数
	AHasPtr(int * p, int i) : ptr(p), val(i) {}

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

