#include"h_name.h"
#include"Search_list.h"

int main()
{
	double num = 0;
	int n, time; //nΪ������timeΪ���Ҵ���
	cout << "������������������" << endl;
	cin >> n;
	cout << "��������Ҵ�����" << endl;
	cin >> time;
	findtable pos_order(n, 0);
	findtable rand_order(n, 1);
	/*pos_order.print();
	cout << endl;
	rand_order.print();
	cout << endl;*/
	clock_t startTime, endTime;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		pos_order.Seq_Search((i+1)%n, num);
	}
	endTime = clock();
	cout << "˳����ҡ����ɹ��������:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "ƽ���Ƚϴ�����" << num / n << "��" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		rand_order.Seq_Search((i+1)%n, num);
	}
	endTime = clock();
	cout << "˳����ҡ����ɹ��������:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "ƽ���Ƚϴ�����" << num / n << "��" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		pos_order.Seq_Search(-1-i, num);
	}
	endTime = clock();
	cout << "˳����ҡ�-ʧ�ܣ������:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "ƽ���Ƚϴ�����" << num / n << "��" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		rand_order.Seq_Search(-(i+1), num);
	}
	endTime = clock();
	cout << "˳����ҡ���ʧ�ܣ������:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "ƽ���Ƚϴ�����" << num / n << "��" << endl;
	cout << endl;



	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		pos_order.Bin_Search(i%n, num);
	}
	endTime = clock();
	cout << "���ֲ��ң������:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "ƽ���Ƚϴ�����" << num / n << "��" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		pos_order.Bin_Sear_Rec(i%n,num,0,n-1);
	}
	endTime = clock();
	cout << "���ֵݹ���ң������:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "ƽ���Ƚϴ�����" << num / n << "��" << endl;
	cout << endl;


	//������������ 
	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		rand_order.Bin_Search(i%n, num);
	}
	endTime = clock();
	cout << "���ֲ��ң������:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "ƽ���Ƚϴ�����" << num / n << "��" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		rand_order.Bin_Sear_Rec(i%n, num, 0, n - 1);
	}
	endTime = clock();
	cout << "���ֵݹ���ң������:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "ƽ���Ƚϴ�����" << num / n << "��" << endl;
	cout << endl;








	system("pause");
}