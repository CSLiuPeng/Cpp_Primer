#pragma once
//�Լ���������ָ��
//����ָ��Ĵ�����ʽ����
template <typename T>
class Smart_Pointer
{
private:
	T * m_pRawPointer;

public:
	//���캯��
	Smart_Pointer(T * pData):m_pRawPointer(pData) {}

	//���ƹ��캯��
//	Smart_Pointer(const Smart_Pointer & spAnother);

	//��ֵ������
//	Smart_Pointer & operator=(const Smatr_Pointer & another);

	//*���������
	/*T & operator * ( ) const
	{
		return *(m_pRawPointer);
	}*/

	//->���������
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
//	// TODO: �ڴ˴����� return ���
//}
