#include "21Pointer.h"
#include<iostream>
#include<cstring>

Pointer::Pointer():ptr(0){}

Pointer::Pointer(String const & n)
{
	ptr = new String(n);
}

Pointer::~Pointer()
{
	delete ptr;
}

String & Pointer::operator*()
{
	// TODO: 在此处插入 return 语句
	if (!ptr)
	{
		throw errorMessage;
	}
	return *ptr;
}

String * Pointer::operator->() const
{
	if (!ptr)
	{
		throw errorMessage;
	}
	return ptr;
}

String Pointer::errorMessage("out of range");

