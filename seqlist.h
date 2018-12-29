#pragma once
#include"h_name.h"
//˳���

const int Maxsize = 20;
template<typename T>
class Seqlist 
{
private:
	T data[Maxsize];
	int length;
public:
	Seqlist();
	Seqlist(T a[], int n);//�������Ĺ��캯��
	~Seqlist()
	{
		clear();
	};
	int get_length();//��ȡ���ȣ�
	T get(int i) const ;//��ȡ��iλԪ�ص�ֵ
	void insert(int i, T x);//���룻
	void print() const;//����������
	void delet(int i);//ɾ����i��Ԫ�أ�
	void clear();//��գ�
};
template<typename T>
inline void Seqlist<T>::clear()
{
	length = 0;
}
template<typename T>
inline void Seqlist<T>::delet(int i)
{
	if (length == 0) throw double(0.55);
	if (i<1 || i>length) throw float(0.5); //�Ƿ�ɾ�����׳��쳣
	for (int j = i;j < length;j++)
	{
		data[j - 1] = data[j];  //��ǰ��λ
	}
	length--;
}
template<typename T>
int Seqlist<T>::get_length()
{
	return length;
}
template<typename T>
inline T Seqlist<T>::get(int i) const
{
	if (i<1 || i>length) throw float(0.5);
	return data[i-1];
}
template<typename T>
inline Seqlist<T>::Seqlist()
{
	length = 0;
}
template<typename T>
inline Seqlist<T>::Seqlist(T a[], int n)
{
	if (n > Maxsize) throw int(1);//������ȴ����趨���ȣ��׳��쳣
	for (int i = 0;i < n;i++)
		data[i] = a[i];
	length = n;
}
template<typename T>
inline void Seqlist<T>::insert(int i, T x)
{
	if (length >= Maxsize) throw char('a');
	if (i<1 || i>length + 1) throw float(0.5); //����λ�ò��ԣ��׳��쳣��
	for (int j = length;j >= i;j--)  
	{
		data[j] = data[j - 1];  //��iλ�Լ��Ժ��Ԫ��������λ
	}
	data[i - 1] = x;
	length++;
}
template<typename T>
inline void Seqlist<T>::print() const
{
	if (length == 0) throw double(0.55);
	for (int i = 0;i < length;i++)
		cout << data[i]<<"  ";
	cout << endl;
}