#pragma once
//智能指针类(计数类)

class U_ptr
{
	friend class  BHasPtr;
private:
	int * ip;
	size_t use;
	
	//构造函数
	U_ptr(int * p):ip(p), use(1) {}

	//析构函数
	~U_ptr()
	{
		delete ip;
	}
};

class BHasPtr
{
public:
	//构造函数
	BHasPtr(int * p, int i) : ptr(new U_ptr(p)), val(i) {}

	int * get_ptr() const
	{
		return ptr->ip;
	}

	//复制构造函数
	BHasPtr(const BHasPtr & orign):ptr(orign.ptr), val(orign.val)
	{
		++ptr->use;
	}

	//赋值操作符的声明
	BHasPtr & operator= (const BHasPtr &);

	//析构函数
	~BHasPtr()
	{
		if (-- ptr->use == 0)
		{
			delete ptr;
		}
	}

	int get_int() const
	{
		return val;
	}

	void set_ptr(int * p)
	{
		ptr->ip = p;
	}

	void set_int(int i)
	{
		val = i;
	}

	int get_ptr_val() const
	{
		return *(ptr->ip);
	}

	void set_ptr_val(int val) const
	{
		*(ptr->ip) = val;
	}

private:
	int val;
	U_ptr * ptr;

};

//赋值操作符的定义
BHasPtr & BHasPtr::operator= (const BHasPtr & rhs)
{
	++rhs.ptr->use;
	if (--ptr->use == 0)
	{
		delete ptr;
	}

	val = rhs.val;
	ptr =  rhs.ptr;
	return *this;
}
