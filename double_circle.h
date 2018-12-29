#pragma once
#pragma once
#include"h_name.h"
//双链表

template<typename T>
struct CCCnode
{
	T data;
	CCCnode*prev;
	CCCnode*next;
};
template<typename T>
class double_circle
{
private:
	CCCnode<T> * first;//头指针
	int length;
public:
	double_circle();
	double_circle(T a[], int n);//建立有n个元素的单链表
	double_circle(string a);
	~double_circle()
	{
		clear();
	};
	int get_length();
	T get(int i) const;//获取第i位元素的值
	void insert(int i, T x);//插入；
	void print(int n = 0) const;//遍历  0 为顺序 ，其他为逆序；
	void pprint(int n);//输出n个元素；
	void longint_print(int n = 0);//无空行遍历  0 为顺序 ，其他为逆序
	void delet(int i);//删除第i号元素；
	void clear();//清空；
	void delete_now(CCCnode<T>*zero);//删除当前指针所指位置；
	CCCnode<T> *getfirst();
};


template<typename T>
inline CCCnode<T>* double_circle<T>::getfirst()
{
	return first;
}
template<typename T>
inline void double_circle<T>::clear()
{

	CCCnode<T> *temp = first;
	while (length)
	{
		CCCnode<T> *q;
		q = temp->next;
		delete temp;
		temp = q;
		length--;
	}
}

template<typename T>
inline int double_circle<T>::get_length()
{
	return length;
}
template<typename T>
inline void double_circle<T>::delet(int i)
{
	if (i < 0 || i>length) exit(1);
	if (i == 1)
	{
		CCCnode<T> *q;
		q = first->next;
		delete first;
		first = q;
		q->prev = NULL;
		length--;
	}
	else if (i == length)
	{
		CCCnode<T> *temp = first;
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
		CCCnode<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}
		CCCnode<T>*p = temp->next->next;
		temp->next = p;
		delete p->prev;
		p->prev = temp;
		length--;
	}
	CCCnode<T> *temp = first;
	for (int j = 1;j < i;j++)
	{
		temp = temp->next;
	}
	temp->next = first;
	first->prev = temp;
}
template<typename T>
inline T double_circle<T>::get(int i) const
{
	CCCnode<T> *temp = first;
	if (i < 0 || i>length) exit(1);
	for (int j = 1;j < i;j++)
	{
		temp = temp->next;
	}
	return temp->data;
}
template<typename T>
inline void double_circle<T>::insert(int i, T x)
{
	if (i < 0 || i>length + 1) exit(1);
	if (length == 0)
	{
		CCCnode<T> *p = new CCCnode<T>;
		p->data = x;
		p->next = NULL;
		p->prev = NULL;
		first = p;
		length++;
		return;

	}
	if (i == length + 1)
	{
		CCCnode<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}

		CCCnode<T> *p = new CCCnode<T>;
		temp->next = p;
		p->data = x;
		p->next = NULL;
		p->prev = temp;
		length++;
	}
	else if (i >= 2)
	{
		CCCnode<T> *temp = first;
		for (int j = 1;j < i - 1;j++)
		{
			temp = temp->next;
		}
		CCCnode<T> *p = new CCCnode<T>;
		p->data = x;
		p->next = temp->next;
		temp->next = p;
		p->prev = temp;
		p->next->prev = p;
		length++;
	}
	else
	{

		CCCnode<T> *temp = first;
		CCCnode<T> *p = new CCCnode<T>;
		p->data = x;
		temp->prev = p;
		p->next = temp;
		first = p;
		length++;

	}
	CCCnode<T> *temp = first;
	for (int j = 1;j < i;j++)
	{
		temp = temp->next;
	}
	temp->next = first;
	first->prev = temp;
	
}

template<typename T>
inline double_circle<T>::double_circle()
{
	first = NULL;
	length = 0;
}

template<typename T>
inline double_circle<T>::double_circle(T a[], int n)
{

	CCCnode<T>*temp = new CCCnode<T>;
	temp->data = a[0];
	first = temp;
	for (int i = 1;i < n;i++)
	{
		CCCnode<T>*temp1 = new CCCnode<T>;
		temp1->prev = temp;
		temp1->data = a[i];
		temp->next = temp1;
		temp = temp1;
	}
	temp->next = first;
	first->prev = temp;
	length = n;
}
template<typename T>
inline void double_circle<T>::print(int n) const
{
	if (n == 0)
	{
		if (length < 1) exit(1);
		int len = length;
		CCCnode<T> *temp = first;
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
		CCCnode<T> *temp = first;
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
template<typename T>
inline void double_circle<T>::pprint(int n)
{
	if (n < 1) return;
	CCCnode<T> *temp = first;
	while (n)
	{
		cout << temp->data << endl;
		temp = temp->next;
		n--;
	}
}
template<typename T>
inline void double_circle<T>::longint_print(int n) 
{
	if (n == 0)
	{
		if (length < 1) exit(1);
		int len = length;
		CCCnode<T> *temp = first;
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
		CCCnode<T> *temp = first;
		if (length == 1)
		{
			cout << first->data;
			return;
		}
		else
		{
			temp = temp->prev;
			int flag = 0,j=0;
			for (size_t i = 0; i < len; i++) //控制前导0 不输出
			{
				if (temp->data != 0)
				{
					flag = 1;
					break;
				}
				else
				{
					temp = temp->prev;
					j++;
				}

			}
			while (len-j)
			{
				cout << temp->data;
				temp = temp->prev;
				len--;
			}
		}
	}
}
template<typename T>
inline double_circle<T>::double_circle(string a)
{
	int n = a.size();
	CCCnode<T>*temp = new CCCnode<T>;
	temp->data = a[0];
	first = temp;
	for (int i = 1;i < n;i++)
	{
		CCCnode<T>*temp1 = new CCCnode<T>;
		temp1->prev = temp;
		temp1->data = a[i];
		temp->next = temp1;
		temp = temp1;
	}
	temp->next = first;
	first->prev = temp;
	length = n;
}