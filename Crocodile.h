#pragma once
#include "Graph.h"
#include"h_name.h"
#define land 100

class save_007
{
private:
	Graph <double> crocodile;
	double crocodile_num;//��������
	double length;//����
public:
	save_007();
	void set_crocodie();//�������㣻
	void print_result();//������

};
inline save_007::save_007()
{
	length = 0;
	crocodile_num = 0;
}


inline void save_007::set_crocodie()
{
	double len;
	cout << "������007�Ĳ���:" << endl;
	cin >> len;
	length = len;
	vector<double>data_x;
	vector<double>data_y; //�ֱ�洢����ĺ�������
	double x,y;
	while (true)
	{
		cout << "�������������� x y��|x|��50 |y|��50��x=0��y=0ֹͣ����" << endl;
		cin >> x;cin >> y;
		if (x == 0 && y == 0) break;
		if (x > 50 || x < -50 || y>50 || y < -50)cout << "�˵�Ϊ������"<<endl;
		else if ((x*x + y * y) <= 56.25) cout << "�˵�Ϊ���죡" << endl;
		else
		{
			data_x.push_back(x);
			data_y.push_back(y);
		}
	}
	vector<vector<int>> ttemp;//���ڹ�������ͼ
	for (int i = 0;i < data_x.size();i++) //����0��n-1������
	{
		vector<int>ad_cro;//�ڽ�������
		for (int j = 0;j < data_x.size();j++)
		{
			double distance = sqrt((data_x[i] - data_x[j])*(data_x[i] - data_x[j]) + (data_y[i] - data_y[j])*(data_y[i] - data_y[j]));
			if (distance != 0&&distance<=length)
			{
				ad_cro.push_back(j);
			}
		}
		ttemp.push_back(ad_cro);
		crocodile.insert_v(i,data_x[i],data_y[i],ad_cro); //���������㣻
		crocodile_num++;

	}
	//���뵺���Ľ��n��
	vector<int>ad_cro;
	for (int i = 0;i < data_x.size();i++)
	{
		double distance = sqrt(data_x[i] * data_x[i] + data_y[i] * data_y[i]);
		if (distance <= (7.5 + length))
			ad_cro.push_back(i);
	}
	crocodile.insert_v(data_x.size(), 0, 0, ad_cro);
	crocodile_num++;
	ttemp.push_back(ad_cro);


	//������ڽ��n+1��
	vector<int>ad_cro_2;
	for (int i = 0;i < data_x.size();i++)
	{
		if (data_x[i]>=50-length||data_x[i]<=length-50||data_y[i]>= 50 - length||data_y[i]<=length-50)
			ad_cro_2.push_back(i);
	}
	crocodile.insert_v(data_x.size()+1, land, land, ad_cro_2);
	crocodile_num++;
	ttemp.push_back(ad_cro_2);

	for (int i = 0;i < ttemp.size();i++)
	{
		for (int j = 0;j < ttemp[i].size();j++)
		{
			crocodile.insert_ad_v(ttemp[i][j], i);
		}

	}


	
	
}

inline void save_007::print_result()
{
	cout << "��������Ϣ��" << endl;
	cout << "id   x   y  �ڽӶ����� " << endl;
	crocodile.print();
	if (length >= 42.5) { cout << "007ֻ��Ҫһ���Ϳɵ��ﰶ��"<<endl; return; }
	else if (crocodile_num == 0) {
		cout << "����û�����㣡007����ȥ��" << endl;
		return;
	}
	else
	{
		vector<int>result=crocodile.path_length(crocodile_num - 2, crocodile_num - 1);
		if (result.size() == 0) cout << "007����ȥ��" << endl;
		else
		{
			int path = ceil(7.5/length);
			cout << "·������Ϊ��(Ĭ�ϴӵ���Ե���� ���粽��Ϊ10 ��ֻ��һ�� ����Ϊ3 ����Ҫ����)" << endl;
			path = result.size() - 1 + path;
			cout << path;
			cout << endl;
		}
	}

}