#include"h_name.h"
#include"Graphh.h"


int main()
{
	/*Graph<string> social_network;
	cout << "������ id����-1ֹͣ\n";
	while (true)
	{
		int id;
		cout << "������id " << endl;
		cin >> id;
		if (id == -1) break;
		string name;
		cout << "������������" << endl;
		cin >> name;
		social_network.insert_v(id, name);
	}
	cout << "��ϵ�����£�" << endl;
	social_network.print();

	cout << "�Ƿ����ӱߣ�y�� n����" << endl;
	while (user_says_yes())
	{
		cout << "�����������ӵıߵ��������id" << endl;
		int n1, n2;
		cin >> n1 >> n2;
		social_network.insert_e(n1, n2);
	}
	cout << "��ϵ�����£�" << endl;
	social_network.print();

	cout << "�Ƿ���������˵����·����y�� n����" << endl;
	while (user_says_yes())
	{
		cout << "�����������ҵ������˵�id" << endl;
		int n1, n2;
		cin >> n1 >> n2;
		social_network.path_length(n1, n2);
	}
	
*/

	//test
	Graph<string> test;

	test.insert_v(0,"Big Zhang");
	test.insert_v(2, "Small Pig");
	test.insert_v(4, "Ning Li");
	test.insert_v(6, "Yexin Shen");
	test.insert_v(7, "Yang Fang");
	test.print();

	test.path_length(2, 7);
	
	system("pause");

}