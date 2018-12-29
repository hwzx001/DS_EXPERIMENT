#pragma once
#include"h_name.h"
//双链表

template<typename T>
struct CNode
{
	T data;
	CNode*prev;
	CNode*next;
};
template<typename T>
class double_list
{
private:
	CNode<T> * first;//头指针
	int length;
public:
	double_list();
	double_list(T a[], int n);//建立有n个元素的单链表
	~double_list()
	{
		clear();
	};
	int get_length();
	T get(int i) const;//获取第i位元素的值
	void insert(int i, T x);//插入；
	void print(int n=0 ) const;//遍历 0 为顺序 ，其他为逆序；
	void delet(int i);//删除第i号元素；
	void clear();//清空；
};
template<typename T>
inline void double_list<T>::clear()
{

	CNode<T> *temp = first;
	while (length)
	{
		CNode<T> *q;
		q = temp->next;
		delete temp;
		temp = q;
		length--;

	}
}

template<typename T>
inline int double_list<T>::get_length()
{
	return length;
}
template<typename T>
inline void double_list<T>::delet(int i)
{
	if (i < 0 || i>length) exit(1);
	if (i == 1)
	{
		CNode<T> *q;
		q = first->next;
		delete first;
		first = q;
		q->prev = NULL;
		length--;
	}
	else if (i == length)
	{
		CNode<T> *temp = first;
		for (int j = 1;j < i;j++)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		delete temp;
		length--;
	}
	else
	{
		CNode<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}
		CNode<T>*p = temp->next->next;
		temp->next = p;
		delete p->prev;
		p->prev = temp;
		length--;
	}
}
template<typename T>
inline T double_list<T>::get(int i) const
{
	CNode<T> *temp = first;
	if (i < 0 || i>length) exit(1);
	for (int j = 1;j < i;j++)
	{
		temp = temp->next;
	}
	return temp->data;
}
template<typename T>
inline void double_list<T>::insert(int i, T x)
{
	if (i < 0 || i>length + 1) exit(1);
	if (length == 0 )
	{
		CNode<T> *p = new CNode<T>;
		p->data = x;
		p->next = NULL;
		p->prev = NULL;
		first = p;
		length++;
		return;

	}
	if (i == length + 1)
	{
		CNode<T> *temp = first;
		for (int j = 1;j < i-1;j++)
		{
			temp = temp->next;
		}
	
		CNode<T> *p = new CNode<T>;
		temp->next = p;
		p->data = x;
		p->next = NULL;
		p->prev = temp;
		length++;
	}
	else if (i >= 2)
	{
		CNode<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}
		CNode<T> *p = new CNode<T>;
		p->data = x;
		p->next = temp->next;
		temp->next = p;
		p->prev = temp;
		p->next->prev = p;
		length++;
	}
	else
	{
		
			CNode<T> *temp = first;
			CNode<T> *p = new CNode<T>;
			p->data = x;
			temp->prev = p;
			p->next = temp;
			first = p;
			length++;
	
	}

}

template<typename T>
inline double_list<T>::double_list()
{
	first = NULL;
	length = 0;
}

template<typename T>
inline double_list<T>::double_list(T a[], int n)
{

	CNode<T>*temp = new CNode<T>;
	temp->data = a[0];
	first = temp;
	for (int i = 1;i < n;i++)
	{
		CNode<T>*temp1 = new CNode<T>;
		temp1->prev = temp;
		temp1->data = a[i];
		temp->next = temp1;
		temp = temp1;
	}
	temp->next = NULL;
	length = n;
}
template<typename T>
inline void double_list<T>::print(int n) const
{
	if (n== 0)
	{
		if (length < 1) exit(1);
		int len = length;
		CNode<T> *temp = first;
		while (len)
		{
			cout << temp->data << endl;
			temp = temp->next;
			len--;
		}
	}
	else
	{
		if (length < 1) exit(1);
		int len = length;
		CNode<T> *temp = first;
		for (int i = 1;i < len;i++)
		{
			temp = temp->next;
		}
		while (len)
		{
			cout << temp->data << endl;
			temp = temp->prev;
			len--;
		}
	}
}