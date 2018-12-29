#pragma once
#pragma once
#include"h_name.h"
#include"Graph.h"
#define maxsize 8

class maze
{
private:
	int map[maxsize + 2][maxsize + 2];
	char result[maxsize][maxsize];
	Graph<int>g_maze;

public:
	maze(int flag); //0表示随机  其他是手动输入
	void print_map();
	void print_result();
	vector<int> get_neib(int i, int j); //获取与之邻接的结点编号
	void get_node(); //获取结点情况
};

inline void maze::get_node()
{
	g_maze.print();

}

inline vector<int> maze::get_neib(int i, int j) 
{
	vector<int>temp,temp2;
	
	for (int k = i - 1;k <= i + 1;k++)
	{
		for (int p = j - 1;p <= j + 1;p++)
		{
			if (map[k][p] == 0)
			{
				temp.push_back( (k - 1)*maxsize + p);

			}
		}
	}

	for (int q = 0;q < temp.size();q++)
	{
		if (temp[q] != (i - 1)*maxsize + j)
		{
			temp2.push_back(temp[q]);
		}
	}
	return temp2;
}

maze::maze(int flag = 0)
{
	for (int k = 0;k < maxsize + 2;k++)
	{
		//初始化墙
		map[0][k] = 1;
		map[maxsize + 1][k] = 1;
		map[k][0] = 1;
		map[k][maxsize + 1] = 1;

	}
	if (flag == 0) //随机生成墙
	{
		srand((unsigned)time(NULL));
		for (int i = 1;i <= maxsize;i++)
		{
			for (int j = 1;j <= maxsize;j++)
			{
				map[i][j] = rand() % 2;
			}
		}
		map[1][1] = 0;      //出入口归为0
		map[maxsize][maxsize] = 0;
	}
	else
	{
		string data;

		for (int i = 1;i <= maxsize;i++)
		{
			cout << "请输入第" << i << "行(只包含1或0)" << endl;
			cin >> data;
			if (data.length() != 8) return;
			for (int j = 1;j <= maxsize;j++)
			{
				if (data[j - 1] == '0' || data[j - 1] == '1') {
					map[i][j] = data[j - 1] - 48;
				}
				else return;
			}
		}
		map[1][1] = 0;      //出入口归为0
		map[maxsize][maxsize] = 0;
	}

	for (int i = 0;i < maxsize ;i++) //初始化结果数组
	{
		for (int j = 0;j < maxsize;j++)
		{
			result[i][j] = '#';
		}
	}
	for (int i = 1;i <= maxsize;i++) //将1-64号结点插入
	{
		for (int j = 1;j <= maxsize;j++)
		{
			vector<int>temp;
			if (map[i][j] == 1) {
				g_maze.insert_v((i - 1) * maxsize + j, 1, temp);
			}
			else if (map[i][j] == 0)
			{
				temp = get_neib(i, j);
				g_maze.insert_v((i - 1) * maxsize + j, 0, temp);
			}

		}

	}
}

inline void maze::print_map()
{
	cout << "************************************************************" << endl;
	for (int i = 1;i < maxsize + 1;i++)
	{
		for (int j = 1;j < maxsize + 1;j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "************************************************************" << endl;
}


inline void maze::print_result()
{
	
	vector<int>result_path = g_maze.path_length(1, maxsize*maxsize);
	if (result_path.empty()) cout << "无通路！";
	else
	{
		for (int i = 0;i < result_path.size();i++)
		{
			int temp_x = result_path[i] / maxsize ;
			int temp_y = result_path[i] % maxsize-1;
			result[temp_x][temp_y] = '*';
		}
		for (int i = 0;i < maxsize ;i++)
		{
			for (int j = 0;j < maxsize ;j++)
			{
				cout << result[i][j];
			}
			cout << endl;
		}
	}

	
}

