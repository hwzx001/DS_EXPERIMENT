#pragma once
#include"h_name.h"
#define INX_MAX  2147483647  

template<typename T>
struct Vertex
{
	int id; //编号
	T data; //数据 
	vector<int> ad_v; //与之邻接点；
	
};

//无向图
template<typename T>
class Graph {
private:
	int node_num;//结点数量
	vector<int>node_id;//结点id；
	vector<Vertex<T>> node; //保存所有结点
public:
	Graph();
	int get_num() { return node_num; }
	void insert_v(int id, T data); //插入结点；
	void insert_e(int v1_id, int v2_id); //插入边
	void print();//输出结点信息
	void path_length(int v1_id, int v2_id); //计算出v1到v2的最短长度
	vector<int> get_neighbour(int id); //获得编号id的结点邻接点组成的向量


};


template<typename T>
inline vector<int> Graph<T>::get_neighbour(int id)
{
	vector<int> temp;
	for (int i = 0;i < node.size();i++)
	{
		if (node[i].id == id)
		{
			temp = node[i].ad_v;
			return temp;
		}
	}
	
}

template<typename T>
inline Graph<T>::Graph()
{
	node_num=0;
}


template<typename T>
inline void Graph<T>::insert_v(int id, T data)
{
	bool e_id = find(node_id.begin(), node_id.end(), id) != node_id.end();
	if (e_id== true )
	{
		cout << "已经有编号为" << id<< "的顶点！";
		return;
	}
	Vertex<T> temp;
	temp.id = id;
	temp.data = data;
	node_num++;
	node_id.push_back(id);
	int tempn;
	cout << "请输入与" << id << "邻接结点的编号" << " ps:输入不存在的结点 or -1 or自身结束输入" << endl;
	while (true)
	{

		cin >> tempn;
		if (tempn == -1) break;
		if (tempn == id) break;
		if (find(node_id.begin(), node_id.end(), tempn) == node_id.end()) break;


		for (int i = 0;i < node_id.size();i++) //保证与之邻接的顶点在图中 否则不给插入
		{
			if ( tempn==node[i].id) //如果邻接结点存在 将邻接结点的编号插入temp的邻接向量中
			{
				if (find(temp.ad_v.begin(), temp.ad_v.end(), tempn) == temp.ad_v.end()) temp.ad_v.push_back(tempn);


				//将邻接结点的邻接向量中增加id 这个结点
				if (find(node[i].ad_v.begin(), node[i].ad_v.end(),id) == node[i].ad_v.end()) node[i].ad_v.push_back(id);
				break;
			}

		}

		cout << "下一个结点编号：" << endl;
	}
	node.push_back(temp);
}

template<typename T>
inline void Graph<T>::insert_e(int v1_id, int v2_id)
{
	if (find(node_id.begin(), node_id.end(), v1_id) == node_id.end()) 
	{
		cout << "没有编号为" << v1_id << "的顶点！";
		return; 
	}
	if (find(node_id.begin(), node_id.end(), v2_id) == node_id.end())
	{
		cout << "没有编号为" << v2_id << "的顶点！";
		return;
	}
	for (int i = 0;i < node.size();i++) //将v2编号插入到v1顶点的邻接向量中；
	{

		if (node[i].id == v1_id)
		{
			if (find(node[i].ad_v.begin(), node[i].ad_v.end(), v2_id) == node[i].ad_v.end()) node[i].ad_v.push_back(v2_id);
			break;
		}
	}  
	for (int i = 0;i < node.size();i++)//将v1编号插入到v2顶点的邻接向量中；
	{
		if (node[i].id == v2_id)
		{
			if (find(node[i].ad_v.begin(), node[i].ad_v.end(), v1_id) == node[i].ad_v.end()) node[i].ad_v.push_back(v1_id);
			break;
		}
	}
}

template<typename T>
inline void Graph<T>::print()
{
	for (int i = 0;i < node_num;i++)
	{
		cout << node[i].id << "  ";
		cout << node[i].data << "  ";
		for (int j = 0;j < node[i].ad_v.size();j++)
		{
			cout << node[i].ad_v[j]<<" ";

		}
		cout << endl;
	}
	cout << endl;
}


template<typename T>
inline void Graph<T>::path_length(int v1_id, int v2_id)
{
	for (int i = 0;i < node.size();i++) //判断v1和v2邻接结点是否为空
	{

		if (node[i].id == v1_id || node[i].id == v2_id)
		{
			if (node[i].ad_v.size() == 0) return;
		}
	}



	
	vector<int> path;

	int max_num = 0;
	for (int j = 0;j < node_id.size();j++) //找出编号最大的id 
	{
		if (node_id[j] > max_num)
			max_num = node_id[j];
	}
	vector<int>distance; //存放距离的向量 初始均为INT_MAX
	vector<int> visted;//访问标志 如果访问过 则为1 
	for (int i = 0;i < max_num + 1;i++) //初始v1距离其他的距离都是int_max；
	{
		distance.push_back(INT_MAX);
		visted.push_back(0);
		path.push_back(-1);
	}
	distance[v1_id] = -1;
	visted[v1_id] = 1;//初始结点；
	vector<int>temp_ve = get_neighbour(v1_id);
	for (int q = 0;q < temp_ve.size();q++)
	{
		distance[temp_ve[q]] = 1;
		path[temp_ve[q]] = v1_id;
	}
	int min;
	for (int i = 0;i < node_num - 1;i++)
	{
		int min_distance = INT_MAX;
		if (visted[i] != 1)
		{
			for (int k = 0;k < max_num + 1;k++)
			{
				if (visted[k] != 1 && distance[k] < min_distance)
				{
					min_distance = distance[k];
					min = k;
				}
			}
			visted[min] = 1;
			//找出未访问最小路径的元素
			int last_path = distance[min];
			vector<int> min_vec = get_neighbour(min);
			for (int p = 0;p < min_vec.size();p++)
			{

				if (visted[min_vec[p]] != 1 && (last_path + 1) < distance[min_vec[p]])
				{
					distance[min_vec[p]] = last_path + 1;
					path[min_vec[p]] = min;
				}
			}
		}

	}
	cout << "path:" << endl;
	vector<int> res_path;
	int a=v2_id;
	while (true)
	{
		
		if (path[a] == -1) break;
		res_path.push_back(path[a]);
		a = path[a];
	}
	for (int i = res_path.size()-1;i>=0;i--)
	{
		cout << res_path[i]<<" ";
	}
	cout << v2_id<< endl;
	int res=distance[v2_id];
	if (res == INT_MAX)
	{
		cout << "这两个人无法通过他人认识！"<<endl;
	}
	else
	{
		cout << "最短路径为：" <<res<<endl;
	}
}

