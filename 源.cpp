#include"h_name.h"
#include"Graphh.h"


int main()
{
	/*Graph<string> social_network;
	cout << "插入结点 id输入-1停止\n";
	while (true)
	{
		int id;
		cout << "请输入id " << endl;
		cin >> id;
		if (id == -1) break;
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		social_network.insert_v(id, name);
	}
	cout << "关系网如下：" << endl;
	social_network.print();

	cout << "是否增加边：y是 n不是" << endl;
	while (user_says_yes())
	{
		cout << "输入你想增加的边的两个结点id" << endl;
		int n1, n2;
		cin >> n1 >> n2;
		social_network.insert_e(n1, n2);
	}
	cout << "关系网如下：" << endl;
	social_network.print();

	cout << "是否计算两个人的最短路劲：y是 n不是" << endl;
	while (user_says_yes())
	{
		cout << "请输入你想找的两个人的id" << endl;
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