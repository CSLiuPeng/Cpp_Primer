#pragma once
//自己创建智能指针
//智能指针的创建方式如下
template <typename T>
class Smart_Pointer
{
private:
	T * m_pRawPointer;

public:
	//构造函数
	Smart_Pointer(T * pData):m_pRawPointer(pData) {}

	//复制构造函数
//	Smart_Pointer(const Smart_Pointer & spAnother);

	//赋值操作符
//	Smart_Pointer & operator=(const Smatr_Pointer & another);

	//*运算符重载
	/*T & operator * ( ) const
	{
		return *(m_pRawPointer);
	}*/

	//->运算符重载
	/*T & operator ->() const
	{
		return m_pRawPointer;
	}*/

};

//template<typename T>
//inline Smart_Pointer<T>::Smart_Pointer(const Smart_Pointer & spAnother)
//{
//}
//
//template<typename T>
//inline Smart_Pointer & Smart_Pointer<T>::operator=(const Smatr_Pointer & another)
//{
//	// TODO: 在此处插入 return 语句
//}
