#include"h_name.h"  //����ͷ�ļ�
#include"seqlist.h" //˳���
#include"single_list.h" //������
#include"double_list.h" //˫����
#include"single_circle.h"  //����ѭ������
#include"double_circle.h"  //˫ѭ������
#include"cal_longint.h"  //������������

//����������������������������ת��Ϊ����������
void cal_plus(string a, string b)
{
	longint t;
	double_circle<char> *s3, *s4;
	if (a[0] == '-'&&b[0]=='-')//�����Ӹ��� ������Ǹ���
	{
		cout << '-';
		//ɾ�����ţ����������������ӣ�
		a.erase(0, 1);
		b.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.add(s3, s4);
	}
	else if (a[0]=='-'&& b[0]!='-')//����a��������b �൱��b-a��
	{
		a.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.subtract( s4, s3);

	}
	else if (b[0] == '-'&& a[0] != '-')//a+����b �൱��a-b��
	{
		b.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.subtract(s3, s4);
	}
	else //����������� 
	{

		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.add(s3, s4);
	}
	t.print();
} 
void cal_sub(string a, string b)
{
	longint t;
	double_circle<char> *s3, *s4;
	if (a[0] == '-'&&b[0] == '-')//���������� �ȼ���b-a
	{
		a.erase(0, 1);
		b.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.subtract(s4, s3);
	}
	else if (a[0] != '-'&&b[0] == '-')//�൱�����������
	{
		b.erase(0,1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.add(s3, s4);
	}
	else if (b[0] != '-'&&a[0] == '-')//�൱�����������
	{
		a.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.add(s3, s4);
	}
	else {

		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.subtract(s3, s4);
	}
	t.print();

}
//���ǵ���˫����д�˷� ʱ�临�ӶȽϸ� Ч��Ч�ʱȽϵ� �ʽ��˷�����������д
void cal_mul(string a, string b)
{
	if (a[0] == '-'&&b[0] == '-')
	{
		a.erase(0, 1);
		b.erase(0, 1);
	}
	else if (a[0] == '-'&&b[0] != '-')
	{
		a.erase(0, 1);
		cout << "-";
	}
	else if ( a[0] != '-' && b[0] == '-')
	{
		b.erase(0,1);
		cout << "-";
	}

	int lena = a.size();
	int lenb = b.size();
	int * tmp = new int[lena + lenb];
	for (int y = 0;y<lena + lenb;y++)
	{
		tmp[y] = 0;
	}
	int* C = new int[lena + lenb];

	for (int i = 0;i<lenb;i++)
	{
		for (int j = 0;j<lena;j++)
		{
			tmp[j + i] = tmp[j + i] + (int(b[i]) - 48)*(int(a[j]) - 48);
		}
	}
	int ii = 0;
	for (int k = lena + lenb - 2;k >= 0;k--)
	{
		if (tmp[k] >= 10 && k >= 1)
		{
			tmp[k - 1] = tmp[k - 1] + tmp[k] / 10;
			C[ii] = tmp[k] % 10;
			ii++;
		}
		else if (tmp[k]<10 && k >= 1)
		{
			C[ii] = tmp[k];
			ii++;
		}
		else
		{
			if (tmp[0] >= 10)
			{
				C[ii] = tmp[0] % 10;
				ii++;
				C[ii] = tmp[0] / 10;
			}
			else
				C[ii] = tmp[0];
		}
	}
	int tt;
	for (int h = ii;h >= 0;h--)
	{
		if (C[h] != 0)
		{
			tt = h;
			break;
		}
		tt = 0;
		
	}

	for (int h = tt;h >= 0;h--)
	{
		cout << C[h] << "";
	}
}  
void Test1() //˳������ 
{
	//Seqlist Test
	//Test1 
	int a[5];
	for (int i = 0;i < 5;i++)
		a[i] = i;
	cout << "*************************˳������********************\n";
	Seqlist<char> ch;
	cout << "�ձ���Ϊ��\n";
	cout << ch.get_length() << endl;
	ch.insert(1, 'a');
	ch.insert(2, 'b');
	ch.insert(3, 'c');
	cout << "�����\n";
	ch.print();
	cout << "����󳤶�Ϊ��\n";
	cout << ch.get_length() << endl;
	cout << "ɾ���ڶ���Ԫ�غ�: \n";
	ch.delet(2);
	ch.print();
	ch.clear();
	cout << "ɾ������Ԫ�غ󳤶ȣ�\n";
	ch.clear();
	cout << ch.get_length() << endl;
	cout << "***********************\n";

	Seqlist <int> abc(a, 5);
	cout << "abc��ʼ��Ϊ��\n";
	abc.print();
	cout << "abc�ڶ���Ԫ��Ϊ��\n";
	cout << abc.get(2) << endl;
	cout << "*************************˳�����Խ���*****************\n";
} 
void Test2() //���������
{
	int a[5];
	for (int i = 0;i < 5;i++)
		a[i] = i;
	//single list test��
	cout << "*************************���������*********************\n";
	single_list<int>cc;
	cc.insert(1, 1);
	cout << "��cc��λ����1֮��\n";
	cc.print();
	single_list<int> oo(a, 5);
	cout << "������a�е�Ԫ��ת��������oo��\n";
	oo.print();
	cout << "��ooĩβ����123֮��\n";
	oo.insert(6, 123);
	oo.print();
	cout << "��oo��λ����10֮��\n";
	oo.insert(1, 10);
	oo.print();
	cout << "��oo�ڶ�λ����6֮��\n";
	oo.insert(2, 6);
	oo.print();
	cout << "oo�ڶ�λԪ������Ϊ��\n";
	cout << oo.get(2) << endl;
	cout << "ɾ��oo����λ֮��\n";
	oo.delet(3);
	oo.print();
	cout << "ɾ��oo��λ֮��\n";
	oo.delet(1);
	oo.print();
	cout << "ɾ��ooĩλ֮��\n";
	oo.delet(6);
	oo.print();
	cout << "���oo֮��\n";
	oo.clear();
	cout << "����Ϊ��" << oo.get_length() << endl;
	cout << "*************************��������Խ���*****************\n";
}
void Test3()//��������
{//TEST 3;
	int a[5];
	for (int i = 0;i < 5;i++)
		a[i] = i;
	cout << "*************************˫������*********************\n";
	double_list<int> dd;
	dd.insert(1, 1);
	dd.insert(2, 2);
	cout << "�½�dd���ڵ�һλ�͵ڶ�λ����1��2��\n";
	dd.print();
	cout << "ɾ����һλ��:\n";
	dd.delet(1);
	dd.print();
	cout << "�½�ee  ���������:\n";
	double_list <int> ee(a, 5);
	ee.print(1);
	cout << "��ȡ�ڶ�λ����:\n";
	cout << ee.get(2) << endl;
	ee.insert(3, 3000);
	cout << "�ڵ���λ����3000��\n";
	ee.print();
	cout << "��ee��պ�ĳ���:\n";
	ee.clear();
	cout << ee.get_length() << endl;
	cout << "*************************˫�����Խ���*****************\n";
	//TEST 4
	cout << "*************************��ѭ�������*******************\n";
	single_circle<int> sss;
	cout << "��sss����10��1��\n";
	sss.insert(1, 10);
	sss.insert(2, 11);
	sss.print();
	cout << "��sssѭ�����飺\n";
	sss.print(4);
	cout << "��ʼ��rrr��" << endl;
	single_circle<int> rrr(a, 5);
	rrr.print();
	cout << "�ڵ���λ����10��\n";
	rrr.insert(6, 10);
	cout << "ѭ����ӡ����:\n";
	rrr.print(12);
	cout << "ɾ����4λ��\n";
	rrr.delet(4);
	rrr.print();
	cout << "*************************��ѭ������Խ���***************\n";
	//Test 5
	cout << "*************************˫ѭ�������*******************\n";
	cout << "��ʼ��ttt��\n";
	double_circle<int>ttt(a, 5);
	ttt.print();
	cout << "ѭ����ӡ13λ����\n";
	ttt.pprint(13);
	cout << "*************************˫ѭ������Խ���***************\n";
}
int main()
{  /*
	Test1();
	Test2();
	Test3();
	*///���������� 
	string a;  //������a
	char b;  //������
	string c;  //������b
	cout << "����������a"<<endl;
	cin >> a;
	cout << "�������������+ or - or * \n";
	cin >> b;
	cout << "����������b��\n";
	cin>>c;
	cout << "���Ϊ��\n";
	switch(b)
	{
	case '+':
		cal_plus(a, c);
		break;
	case'-':
		cal_sub(a, c);
		break;
	case'*':
		cal_mul(a, c);
		break;
	default:
		cout << "Error!"<<endl;
		break;
	}
	system("pause");

}
