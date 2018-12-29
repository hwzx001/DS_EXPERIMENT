#pragma once
#pragma once
#include"h_name.h"
//单循环链表
template<typename T>
struct CCnode
{
	T data;
	CCnode *next;
};
template<typename T>
class single_circle
{
private:
	CCnode<T> * first;//头指针
	int length;
public:
	single_circle();
	single_circle(T a[], int n);//建立有n个元素的单链表
	~single_circle()
	{
		clear();
	};
	int get_length();
	T get(int i) const;//获取第i位元素的值
	void insert(int i, T x);//插入；
	void print() const;//遍历；
	void print(int n);//指定遍历n位元素
	void delet(int i);//删除第i号元素；
	void clear();//清空；
};
template<typename T>
inline void single_circle<T>::clear()
{

	CCnode<T> *temp = first;
	while (length)
	{
		CCnode<T> *q;
		q = temp->next;
		delete temp;
		temp = q;
		length--;

	}
}

template<typename T>
inline int single_circle<T>::get_length()
{
	return length;
}
template<typename T>
inline void single_circle<T>::delet(int i)
{
	if (i < 0 || i>length) exit(1);
	if (i == 1)
	{
		CCnode<T> *q;
		q = first->next;
		delete first;
		first = q;
		length--;
		CCnode<T> *temp = first;
		for (int j = 1;j < i ;j++)
		{
			temp = temp->next;
		}
		temp->next = first;
	}
	else if (i == length)
	{
		CCnode<T> *temp = first,*temp2;
		for (int j = 1;j < i-1;j++)
		{
			temp = temp->next;
		}
		temp2 = temp;
		temp = temp->next;
		temp2->next = first;
		delete temp;
		length--;
	}
	else
	{
		CCnode<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}
		CCnode<T> *p, *q;
		p = temp->next;
		q = p->next;
		temp->next = q;
		delete p;
		length--;
	}
}
template<typename T>
inline T single_circle<T>::get(int i) const
{
	CCnode<T> *temp = first;
	if (i < 0 || i>length) exit(1);
	for (int j = 1;j < i;j++)
	{
		temp = temp->next;
	}
	return temp->data;
}
template<typename T>
inline void single_circle<T>::insert(int i, T x)
{
	if (i < 0 || i>length + 1) exit(1);
	if (i >= 2)
	{
		CCnode<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}
		CCnode<T> *p = new CCnode<T>;
		p->data = x;
		p->next = temp->next;
		temp->next = p;
		length++;
	}
	else
	{
		CCnode<T> *temp = first;
		CCnode<T> *p = new CCnode<T>;
		p->data = x;
		p->next = temp;
		first = p;
		length++;
	}
	CCnode<T> *temp = first;
	for (int j = 1;j < i;j++)
	{
		temp = temp->next;
	}
	temp->next = first;
}

template<typename T>
inline single_circle<T>::single_circle()
{
	first = NULL;
	length = 0;
}

template<typename T>
inline single_circle<T>::single_circle(T a[], int n)
{

	CCnode<T>*temp = new CCnode<T>;
	temp->data = a[0];
	first = temp;
	for (int i = 1;i < n;i++)
	{
		CCnode<T>*temp1 = new CCnode<T>;
		temp1->data = a[i];
		temp->next = temp1;
		temp = temp1;
	}
	temp->next = first;
	length = n;
}
template<typename T>
inline void single_circle<T>::print() const
{
	if (length < 1) exit(1);
	int len = length;
	CCnode<T> *temp = first;
	while (len)
	{
		cout << temp->data << endl;
		temp = temp->next;
		len--;
	}
}

template<typename T>
inline void single_circle<T>::print(int n)
{
	if (n < 1) return;
	CCnode<T> *temp = first;
	while (n)
	{
		cout << temp->data << endl;
		temp = temp->next;
		n--;
	}
}