#pragma once
#include"h_name.h"
#define INX_MAX  2147483647  

template<typename T>
struct Vertex
{
	int id; //���
	T data; //���� 
	vector<int> ad_v; //��֮�ڽӵ㣻
	
};

//����ͼ
template<typename T>
class Graph {
private:
	int node_num;//�������
	vector<int>node_id;//���id��
	vector<Vertex<T>> node; //�������н��
public:
	Graph();
	int get_num() { return node_num; }
	void insert_v(int id, T data); //�����㣻
	void insert_e(int v1_id, int v2_id); //�����
	void print();//��������Ϣ
	void path_length(int v1_id, int v2_id); //�����v1��v2����̳���
	vector<int> get_neighbour(int id); //��ñ��id�Ľ���ڽӵ���ɵ�����


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
		cout << "�Ѿ��б��Ϊ" << id<< "�Ķ��㣡";
		return;
	}
	Vertex<T> temp;
	temp.id = id;
	temp.data = data;
	node_num++;
	node_id.push_back(id);
	int tempn;
	cout << "��������" << id << "�ڽӽ��ı��" << " ps:���벻���ڵĽ�� or -1 or�����������" << endl;
	while (true)
	{

		cin >> tempn;
		if (tempn == -1) break;
		if (tempn == id) break;
		if (find(node_id.begin(), node_id.end(), tempn) == node_id.end()) break;


		for (int i = 0;i < node_id.size();i++) //��֤��֮�ڽӵĶ�����ͼ�� ���򲻸�����
		{
			if ( tempn==node[i].id) //����ڽӽ����� ���ڽӽ��ı�Ų���temp���ڽ�������
			{
				if (find(temp.ad_v.begin(), temp.ad_v.end(), tempn) == temp.ad_v.end()) temp.ad_v.push_back(tempn);


				//���ڽӽ����ڽ�����������id ������
				if (find(node[i].ad_v.begin(), node[i].ad_v.end(),id) == node[i].ad_v.end()) node[i].ad_v.push_back(id);
				break;
			}

		}

		cout << "��һ������ţ�" << endl;
	}
	node.push_back(temp);
}

template<typename T>
inline void Graph<T>::insert_e(int v1_id, int v2_id)
{
	if (find(node_id.begin(), node_id.end(), v1_id) == node_id.end()) 
	{
		cout << "û�б��Ϊ" << v1_id << "�Ķ��㣡";
		return; 
	}
	if (find(node_id.begin(), node_id.end(), v2_id) == node_id.end())
	{
		cout << "û�б��Ϊ" << v2_id << "�Ķ��㣡";
		return;
	}
	for (int i = 0;i < node.size();i++) //��v2��Ų��뵽v1������ڽ������У�
	{

		if (node[i].id == v1_id)
		{
			if (find(node[i].ad_v.begin(), node[i].ad_v.end(), v2_id) == node[i].ad_v.end()) node[i].ad_v.push_back(v2_id);
			break;
		}
	}  
	for (int i = 0;i < node.size();i++)//��v1��Ų��뵽v2������ڽ������У�
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
	for (int i = 0;i < node.size();i++) //�ж�v1��v2�ڽӽ���Ƿ�Ϊ��
	{

		if (node[i].id == v1_id || node[i].id == v2_id)
		{
			if (node[i].ad_v.size() == 0) return;
		}
	}



	
	vector<int> path;

	int max_num = 0;
	for (int j = 0;j < node_id.size();j++) //�ҳ��������id 
	{
		if (node_id[j] > max_num)
			max_num = node_id[j];
	}
	vector<int>distance; //��ž�������� ��ʼ��ΪINT_MAX
	vector<int> visted;//���ʱ�־ ������ʹ� ��Ϊ1 
	for (int i = 0;i < max_num + 1;i++) //��ʼv1���������ľ��붼��int_max��
	{
		distance.push_back(INT_MAX);
		visted.push_back(0);
		path.push_back(-1);
	}
	distance[v1_id] = -1;
	visted[v1_id] = 1;//��ʼ��㣻
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
			//�ҳ�δ������С·����Ԫ��
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
		cout << "���������޷�ͨ��������ʶ��"<<endl;
	}
	else
	{
		cout << "���·��Ϊ��" <<res<<endl;
	}
}

