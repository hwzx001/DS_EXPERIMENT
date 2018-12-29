#pragma once
#include"h_name.h"
//顺序表

const int Maxsize = 20;
template<typename T>
class Seqlist 
{
private:
	T data[Maxsize];
	int length;
public:
	Seqlist();
	Seqlist(T a[], int n);//带参数的构造函数
	~Seqlist()
	{
		clear();
	};
	int get_length();//获取长度；
	T get(int i) const ;//获取第i位元素的值
	void insert(int i, T x);//插入；
	void print() const;//遍历操作；
	void delet(int i);//删除第i号元素；
	void clear();//清空；
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
	if (i<1 || i>length) throw float(0.5); //非法删除，抛出异常
	for (int j = i;j < length;j++)
	{
		data[j - 1] = data[j];  //往前移位
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
	if (n > Maxsize) throw int(1);//如果长度大于设定长度，抛出异常
	for (int i = 0;i < n;i++)
		data[i] = a[i];
	length = n;
}
template<typename T>
inline void Seqlist<T>::insert(int i, T x)
{
	if (length >= Maxsize) throw char('a');
	if (i<1 || i>length + 1) throw float(0.5); //插入位置不对，抛出异常；
	for (int j = length;j >= i;j--)  
	{
		data[j] = data[j - 1];  //将i位以及以后的元素往后移位
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