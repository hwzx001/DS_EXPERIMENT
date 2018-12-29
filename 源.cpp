#include"class_bt.h"
#include"h_name.h"

int main()
{
	cout << "请输入一个字符串" << endl;
	string a;
	cin >> a;
	BinartTree abc(a);
	abc.menu();
	int ch=0;
	while (ch!=12)
	{
		cout << endl;
		cout << "请输入指令：" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			char s;
			cin >> s;
			abc.insert(s);
			break;
		}
		case 2:
		{
			cout << "前序遍历输出为：" << endl;
			abc.preorder(abc.getroot());
			break;
		}
		case 3:
		{
			cout << "中序遍历输出为：" << endl;
			abc.inorder(abc.getroot());
			break;
		}
		case 4:
		{
			cout << "后序遍历输出为：" << endl;
			abc.postorder(abc.getroot());
			break;
		}
		case 5:
		{
			cout << "树的深度为：" << endl;
			cout<<abc.getHeight(abc.getroot());
			break;
		}
		case 6:
		{
			cout << "树的宽度为：" << endl;
		    cout<<abc.getWidth();
		    break;

		}
		case 7:
		{
			cout << "度为2的节点数:" << endl;
			cout<<abc.count_2(abc.getroot());
			break;
		}
		case 8:
		{
			cout << "度为1的节点数:" << endl;
			cout << abc.count_1(abc.getroot());
			break;
		}
		case 9:
		{
			cout << "度为0的节点数:" << endl;
			cout << abc.count_0(abc.getroot());
			break;
		}
		case 10:
		{
			cout << "请输入要删除的元素" << endl;
			char t;
			cin >> t;
			abc.delete_char(t);
			break;
		}
		case 11:
		{
			cout<< "请输入要查找的元素" << endl;
			char p;
			cin >> p;
			bool flag = abc.find(abc.getroot(),p);
			if (flag== 0)
			{
				cout << "查无此人！" << endl;
			}
			else
			{
				cout << "这个元素在树中" << endl;
			}
			break;
		}
		case 12:
		{
			cout << "byebye" << endl;
			break;
		}
		case 13:
		{
			abc.clear(abc.getroot());
			break;
		}
		case 14:
		{
			int em= abc.empty() ;
			if (em == 1) cout << "空树" << endl;
			else cout << "非空树" << endl;
			break;
		}
		case 15:
		{
			abc.ceng_order();
			cout << endl;
			break;
		}
		default:
			cout << "请输入正确的指令" << endl;
			break;
		}

	}
-	system("pause");

}


