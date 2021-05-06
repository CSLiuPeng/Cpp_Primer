#pragma once
//����ָ����(������)

class U_ptr
{
	friend class  BHasPtr;
private:
	int * ip;
	size_t use;
	
	//���캯��
	U_ptr(int * p):ip(p), use(1) {}

	//��������
	~U_ptr()
	{
		delete ip;
	}
};

class BHasPtr
{
public:
	//���캯��
	BHasPtr(int * p, int i) : ptr(new U_ptr(p)), val(i) {}

	int * get_ptr() const
	{
		return ptr->ip;
	}

	//���ƹ��캯��
	BHasPtr(const BHasPtr & orign):ptr(orign.ptr), val(orign.val)
	{
		++ptr->use;
	}

	//��ֵ������������
	BHasPtr & operator= (const BHasPtr &);

	//��������
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

//��ֵ�������Ķ���
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
