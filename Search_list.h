#pragma once
#include"h_name.h"


class findtable
{
private:
	vector<int> data;
public:
	findtable(int n,int flag=0); // 0Ϊ˳������Ϊ����
	void print();
	int Seq_Search(int n, double& num);         //˳�����   
	int Bin_Search(int n, double& num);          //���ַ�����
	int Bin_Sear_Rec(int n, double& num, int low , int high);    //���ַ��ݹ����
	
};

inline int findtable::Bin_Sear_Rec(int n, double & num, int low, int high)
{
	if (low > high) return -1;
	int middle = low + (high - low) / 2;
	if (data[middle] > n)
	{
		num++;
		return Bin_Sear_Rec(n, num, low, middle - 1);
	}
	else if (data[middle] < n)
	{
		num++;
		return Bin_Sear_Rec(n, num,middle + 1, high);
	}
	else
	{
		num++;
		return middle;
	}

}

inline int findtable::Bin_Search(int n, double & num)
{

	int middle;
	int start = 0, end = data.size() - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		num++;
		if (data[middle] < n) start = start + 1;
		else if (data[middle] > n) end = middle - 1;
		else
		{
			return middle;
		}
	}
	//�Ҳ���
	return -1;
}


findtable::findtable(int n, int flag)
{
	if (flag == 0)
	{
		for (int i = 1;i <= n;i++) //˳��
		{
			data.push_back(i);
		}
	}
	else   
	{
		srand((unsigned)time(NULL)); //���
		for (int i = 1;i <= n;i++) 
		{
			data.push_back(rand()%n);
		}
	}

}

inline void findtable::print()
{
	for (int i = 0;i < data.size();i++)
	{
		cout << data[i]<<" ";
		if (i % 20 == 0 && i != 0)
			cout << endl;
	}
}

inline int findtable::Seq_Search(int n, double & num)
{
	for (int i = 0;i < data.size();i++)
	{
		num++;
		if (n == data[i])
			return i;
	}
	return -1;//û�ҵ�����-1��

	return 0;
}