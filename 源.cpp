#include"h_name.h"
#include"Search_list.h"

int main()
{
	double num = 0;
	int n, time; //n为个数，time为查找次数
	cout << "请输入存放正数个数：" << endl;
	cin >> n;
	cout << "请输入查找次数：" << endl;
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
	cout << "顺序查找——成功（有序表）:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "平均比较次数：" << num / n << "次" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		rand_order.Seq_Search((i+1)%n, num);
	}
	endTime = clock();
	cout << "顺序查找——成功（无序表）:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "平均比较次数：" << num / n << "次" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		pos_order.Seq_Search(-1-i, num);
	}
	endTime = clock();
	cout << "顺序查找—-失败（有序表）:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "平均比较次数：" << num / n << "次" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		rand_order.Seq_Search(-(i+1), num);
	}
	endTime = clock();
	cout << "顺序查找——失败（无序表）:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "平均比较次数：" << num / n << "次" << endl;
	cout << endl;



	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		pos_order.Bin_Search(i%n, num);
	}
	endTime = clock();
	cout << "二分查找（有序表）:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "平均比较次数：" << num / n << "次" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		pos_order.Bin_Sear_Rec(i%n,num,0,n-1);
	}
	endTime = clock();
	cout << "二分递归查找（有序表）:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "平均比较次数：" << num / n << "次" << endl;
	cout << endl;


	//补充两个测试 
	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		rand_order.Bin_Search(i%n, num);
	}
	endTime = clock();
	cout << "二分查找（无序表）:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "平均比较次数：" << num / n << "次" << endl;
	cout << endl;

	num = 0;
	startTime = clock();
	for (int i = 0;i < time;i++)
	{
		rand_order.Bin_Sear_Rec(i%n, num, 0, n - 1);
	}
	endTime = clock();
	cout << "二分递归查找（无序表）:" << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "平均比较次数：" << num / n << "次" << endl;
	cout << endl;








	system("pause");
}