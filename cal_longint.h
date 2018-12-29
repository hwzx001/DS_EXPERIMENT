#pragma once
#include"h_name.h"
#include"double_circle.h"
class longint
{
private:
	double_circle<int>* lst;//保存结果
	char mark;
	int lstlength;
public:
	longint();
	void add(double_circle<char>*s1, double_circle<char>*s2);
	void subtract(double_circle<char>*s1, double_circle<char>*s2);
	void print()const;
	int get_length()const;
	
};
inline int longint::get_length() const
{
	return lstlength;
}
inline void longint::print() const
{
	if (mark == '-')cout << '-';
	double_circle<int> *ls = lst;
	ls->longint_print(1);
}
inline longint::longint()
{
	lst = new double_circle<int>();
	mark = '+';
	lstlength = 0;
}

void longint::add(double_circle<char> *s1, double_circle<char> *s2)//相加运算
{
	//两个纯正数相加
	int len1 = s1->get_length();
	int len2 = s2->get_length();
	int len = (len1 > len2) ? len2:len1;
	CCCnode<char> *temp1, *temp2;
	if (len1<len2)
	{
		int le = len1;
		len1 = len2;
		len2 = le;
	    temp1 = s2->getfirst()->prev;
		temp2 = s1->getfirst()->prev;
	}
	else
	{
		temp1 = s1->getfirst()->prev;
		temp2 = s2->getfirst()->prev;
	}
	int carry_bit = 0;//用来保存进位
	while (len-1)
	{
		int r1 = temp1->data - 48;
		int r2 = temp2->data - 48;
		int r3 = r1 + r2+carry_bit;
		if (r3<10) //没有进位
		{
			lst->insert(lstlength+1, r3);
			carry_bit = 0;
			lstlength++;
		}
		else //有进位 将尾数插入 进位改为1
		{
			int r4 = r3%10;
			lst->insert(lstlength+1, r4);
			carry_bit = 1;
			lstlength++;
		}
		temp1 = temp1->prev;
		temp2 = temp2->prev;
		len--;
	}
	int r1 = temp1->data - 48;
	int r2 = temp2->data - 48;
	int r3 = r1 + r2 + carry_bit;
	if (len1 ==len2)//如果两个数字位数相等，只需要考虑最后有没有进位；
	{
		if (r3<10) //没有进位
		{
			lst->insert(lstlength + 1, r3);
			carry_bit = 0;
			lstlength++;
		}
		else //有进位 将尾数插入 再将1插入；
		{
			int r4 = r3 % 10;
			lst->insert(lstlength + 1, r4);
			lstlength++;
		}
		if (carry_bit == 1)
		{
			lst->insert(lstlength + 1, 1);
			lstlength++;
		}
	}
	else if (len1 > len2)// 如果len1大于len2，计算剩下的数；
	{
		if (r3<10) //没有进位
		{
			lst->insert(lstlength + 1, r3);
			carry_bit = 0;
			lstlength++;
		}
		else //有进位 将尾数插入 进位标记改为1；
		{
			int r4 = r3 % 10;
			lst->insert(lstlength + 1, r4);
			carry_bit = 1;
			lstlength++;
		}
		temp1 = temp1->prev;
		while (len1-len2)//计算剩下的数
		{
			int r1 = temp1->data - 48;
			int r3 = r1  + carry_bit;
			if (r3<10)
			{
				lst->insert(lstlength + 1, r3);
				carry_bit = 0;
				lstlength++;
			}
			else
			{
				int r4 = r3 % 10;
				lst->insert(lstlength + 1, r4);
				carry_bit = 1;
				lstlength++;
			}
			temp1 = temp1->prev;
			len1--;
		}
		if (carry_bit == 1)
		{
			lst->insert(lstlength + 1, 1);
			lstlength++;
		}
	}
	
	
}

void longint::subtract(double_circle<char> *s1, double_circle<char> *s2)
{
	//减法运算
	//两个纯正数相减
	string num = "";
	int len1 = s1->get_length();
	int len2 = s2->get_length();
	CCCnode<char> *temp1, *temp2;
	if (len1==len2)
	{ 
		temp1 = s1->getfirst();
		temp2 = s2->getfirst();
		int i, len = len1;
		for (i = 0;i < len;i++)
		{
			if (temp1->data > temp2->data)
			{
				temp1 = s1->getfirst();
				temp2 = s2->getfirst();
				mark = '+';
				break;
			}
			else if (temp1->data < temp2->data)
			{
				temp1 = s2->getfirst()->prev;
				temp2 = s1->getfirst()->prev;
				mark = '-';
				break;
			}
			else
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
		if (i == len)
		{
			lst->insert(1, 0);
			lstlength++;
			return;
		}


	}
	else if (len1 < len2)  //将s1和s2交换
	{
		int le = len1;  
		len1 = len2;
		len2 = le;
		temp1 = s2->getfirst()->prev;
		temp2 = s1->getfirst()->prev;
		mark = '-';
	}
	else  //len1>len2
	{
		temp1 = s1->getfirst()->prev;
		temp2 = s2->getfirst()->prev;
	}
	int i, borrow = 0;
	for (i = 0;i < len2;i++)
	{
		int r1 = temp1->data - 48;
		int r2 = temp2->data - 48;
		int r3 = r1 - r2 + borrow;
		if (r3 >= 0)
		{
			lst->insert(lstlength + 1, r3);
			lstlength++;
			borrow = 0;
		}
		else
		{
			r3 = r3 + 10;
			lst->insert(lstlength + 1, r3);
			lstlength++;
			borrow = (-1);
		}
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	for (i = 0;i < len1 - len2;i++)
	{
		int r1 = temp1->data - 48;
		int r3 = r1 + borrow;
		if (r3 >= 0)
		{
			lst->insert(lstlength + 1, r3);
			lstlength++;
			borrow = 0;
		}
		else
		{
			r3 = r3 + 10;
			lst->insert(lstlength + 1, r3);
			lstlength++;
			borrow = (-1);
		}
		temp1 = temp1->prev;
	}
	
}
	

