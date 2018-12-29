#pragma once
#include"h_name.h"
//单链表
template<typename T>
struct Node
{
	T data;
	Node*next;
};
template<typename T>
class single_list
{
private:
	Node<T> * first;//头指针
	int length;
public:
	single_list();
	single_list(T a[], int n);//建立有n个元素的单链表
	~single_list()
	{
		clear();
	};
	int get_length();
	T get(int i) const;//获取第i位元素的值
	void insert(int i, T x);//插入；
	void print() const;//遍历；
	void delet(int i);//删除第i号元素；
	void clear();//清空；
};
template<typename T>
inline void single_list<T>::clear()
{
	
	Node<T> *temp = first;
	while (length)
	{
		Node<T> *q;
		q = temp->next;
		delete temp;
		temp = q;
		length--;

	}
}

template<typename T>
inline int single_list<T>::get_length()
{
	return length;
}
template<typename T>
inline void single_list<T>::delet(int i)
{
	if (i < 0 || i>length) exit(1); //非法删除，抛出异常
	if (i == 1)   //首位删除，改变了头结点
	{
		Node<T> *q;
		q = first->next;
		delete first;
		first = q;
		length--;
	}
	else if (i == length)  //尾删除 
	{
		Node<T> *temp = first;
		for (int j = 1;j < i ;j++)
		{
			temp = temp->next;
		}
		delete temp;
		length--;
	}
	else   //中间删除
	{
		Node<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}
		Node<T> *p, *q;
		p = temp->next;
		q=p->next;
		temp->next = q;
		delete p;
		length--;
	}
}
template<typename T>
inline T single_list<T>::get(int i) const
{
	Node<T> *temp = first;
	if (i < 0 || i>length ) exit(1);
	for (int j = 1;j < i ;j++)
	{
		temp = temp->next;
	}
	return temp->data;
}
template<typename T>
inline void single_list<T>::insert(int i, T x)
{
	if (i < 0||i>length+1) exit(1);  //非法插入 
	if (i >= 2) //非头插
	{
		Node<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}
		Node<T> *p = new Node<T>;
		p->data = x;
		p->next = temp->next;
		temp->next = p;
		length++;
	}
	else   //头插
	{
		Node<T> *temp = first;
		Node<T> *p = new Node<T>;
		p->data = x;
		p->next = temp;
		first = p;
		length++;
	}
	
}

template<typename T>
inline single_list<T>::single_list()
{
	first = NULL;
	length = 0;
}

template<typename T>
inline single_list<T>::single_list(T a[], int n)
{

	Node<T>*temp = new Node<T>;
	temp->data = a[0];
	first = temp;
	for (int i = 1;i < n;i++)
	{
		Node<T>*temp1 = new Node<T>;
		temp1->data = a[i];
		temp->next = temp1;
		temp = temp1;
	}
	temp->next = NULL;
	length = n;
}
template<typename T>
inline void single_list<T>::print() const
{
	if (length < 1) exit(1);
	int len = length;
	Node<T> *temp = first;
	while (len)
	{
		cout << temp->data << endl;
		temp = temp->next;
		len--;
	}
}