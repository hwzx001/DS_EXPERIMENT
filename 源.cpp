#include"class_bt.h"
#include"h_name.h"

int main()
{
	cout << "������һ���ַ���" << endl;
	string a;
	cin >> a;
	BinartTree abc(a);
	abc.menu();
	int ch=0;
	while (ch!=12)
	{
		cout << endl;
		cout << "������ָ�" << endl;
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
			cout << "ǰ��������Ϊ��" << endl;
			abc.preorder(abc.getroot());
			break;
		}
		case 3:
		{
			cout << "����������Ϊ��" << endl;
			abc.inorder(abc.getroot());
			break;
		}
		case 4:
		{
			cout << "����������Ϊ��" << endl;
			abc.postorder(abc.getroot());
			break;
		}
		case 5:
		{
			cout << "�������Ϊ��" << endl;
			cout<<abc.getHeight(abc.getroot());
			break;
		}
		case 6:
		{
			cout << "���Ŀ��Ϊ��" << endl;
		    cout<<abc.getWidth();
		    break;

		}
		case 7:
		{
			cout << "��Ϊ2�Ľڵ���:" << endl;
			cout<<abc.count_2(abc.getroot());
			break;
		}
		case 8:
		{
			cout << "��Ϊ1�Ľڵ���:" << endl;
			cout << abc.count_1(abc.getroot());
			break;
		}
		case 9:
		{
			cout << "��Ϊ0�Ľڵ���:" << endl;
			cout << abc.count_0(abc.getroot());
			break;
		}
		case 10:
		{
			cout << "������Ҫɾ����Ԫ��" << endl;
			char t;
			cin >> t;
			abc.delete_char(t);
			break;
		}
		case 11:
		{
			cout<< "������Ҫ���ҵ�Ԫ��" << endl;
			char p;
			cin >> p;
			bool flag = abc.find(abc.getroot(),p);
			if (flag== 0)
			{
				cout << "���޴��ˣ�" << endl;
			}
			else
			{
				cout << "���Ԫ��������" << endl;
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
			if (em == 1) cout << "����" << endl;
			else cout << "�ǿ���" << endl;
			break;
		}
		case 15:
		{
			abc.ceng_order();
			cout << endl;
			break;
		}
		default:
			cout << "��������ȷ��ָ��" << endl;
			break;
		}

	}
-	system("pause");

}


