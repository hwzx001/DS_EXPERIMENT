#pragma once
#include "Graph.h"
#include"h_name.h"
#define land 100

class save_007
{
private:
	Graph <double> crocodile;
	double crocodile_num;//鳄鱼数量
	double length;//步长
public:
	save_007();
	void set_crocodie();//设置鳄鱼；
	void print_result();//输出结果

};
inline save_007::save_007()
{
	length = 0;
	crocodile_num = 0;
}


inline void save_007::set_crocodie()
{
	double len;
	cout << "请输入007的步长:" << endl;
	cin >> len;
	length = len;
	vector<double>data_x;
	vector<double>data_y; //分别存储鳄鱼的横纵坐标
	double x,y;
	while (true)
	{
		cout << "请输入鳄鱼坐标 x y：|x|≤50 |y|≤50：x=0且y=0停止输入" << endl;
		cin >> x;cin >> y;
		if (x == 0 && y == 0) break;
		if (x > 50 || x < -50 || y>50 || y < -50)cout << "此地为湖岸！"<<endl;
		else if ((x*x + y * y) <= 56.25) cout << "此地为岛屿！" << endl;
		else
		{
			data_x.push_back(x);
			data_y.push_back(y);
		}
	}
	vector<vector<int>> ttemp;//用于构成无向图
	for (int i = 0;i < data_x.size();i++) //插入0到n-1号鳄鱼
	{
		vector<int>ad_cro;//邻接鳄鱼编号
		for (int j = 0;j < data_x.size();j++)
		{
			double distance = sqrt((data_x[i] - data_x[j])*(data_x[i] - data_x[j]) + (data_y[i] - data_y[j])*(data_y[i] - data_y[j]));
			if (distance != 0&&distance<=length)
			{
				ad_cro.push_back(j);
			}
		}
		ttemp.push_back(ad_cro);
		crocodile.insert_v(i,data_x[i],data_y[i],ad_cro); //插入鳄鱼结点；
		crocodile_num++;

	}
	//插入岛中心结点n；
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


	//插入出口结点n+1；
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
	cout << "鳄鱼结点信息：" << endl;
	cout << "id   x   y  邻接顶点编号 " << endl;
	crocodile.print();
	if (length >= 42.5) { cout << "007只需要一步就可到达岸边"<<endl; return; }
	else if (crocodile_num == 0) {
		cout << "湖中没有鳄鱼！007出不去！" << endl;
		return;
	}
	else
	{
		vector<int>result=crocodile.path_length(crocodile_num - 2, crocodile_num - 1);
		if (result.size() == 0) cout << "007出不去！" << endl;
		else
		{
			int path = ceil(7.5/length);
			cout << "路径长度为：(默认从岛边缘算起 比如步长为10 则只需一步 步长为3 则需要三步)" << endl;
			path = result.size() - 1 + path;
			cout << path;
			cout << endl;
		}
	}

}