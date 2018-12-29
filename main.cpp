#include"h_name.h"  //常用头文件
#include"seqlist.h" //顺序表
#include"single_list.h" //单链表
#include"double_list.h" //双链表
#include"single_circle.h"  //单项循环链表
#include"double_circle.h"  //双循环链表
#include"cal_longint.h"  //长整数运算类

//以下三个函数均将将两个操作数转换为纯正数运算
void cal_plus(string a, string b)
{
	longint t;
	double_circle<char> *s3, *s4;
	if (a[0] == '-'&&b[0]=='-')//负数加负数 结果还是负数
	{
		cout << '-';
		//删除负号，变成两个纯正数相加；
		a.erase(0, 1);
		b.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.add(s3, s4);
	}
	else if (a[0]=='-'&& b[0]!='-')//负数a加上正数b 相当于b-a；
	{
		a.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.subtract( s4, s3);

	}
	else if (b[0] == '-'&& a[0] != '-')//a+负数b 相当于a-b；
	{
		b.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.subtract(s3, s4);
	}
	else //两个正数相加 
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
	if (a[0] == '-'&&b[0] == '-')//负数减负数 等价于b-a
	{
		a.erase(0, 1);
		b.erase(0, 1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.subtract(s4, s3);
	}
	else if (a[0] != '-'&&b[0] == '-')//相当于两个数相加
	{
		b.erase(0,1);
		s3 = new double_circle<char>(a);
		s4 = new double_circle<char>(b);
		t.add(s3, s4);
	}
	else if (b[0] != '-'&&a[0] == '-')//相当于两个数相加
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
//考虑到用双链表写乘法 时间复杂度较高 效率效率比较低 故将乘法单独用数组写
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
void Test1() //顺序表测试 
{
	//Seqlist Test
	//Test1 
	int a[5];
	for (int i = 0;i < 5;i++)
		a[i] = i;
	cout << "*************************顺序表测试********************\n";
	Seqlist<char> ch;
	cout << "空表长度为：\n";
	cout << ch.get_length() << endl;
	ch.insert(1, 'a');
	ch.insert(2, 'b');
	ch.insert(3, 'c');
	cout << "插入后：\n";
	ch.print();
	cout << "插入后长度为：\n";
	cout << ch.get_length() << endl;
	cout << "删除第二个元素后: \n";
	ch.delet(2);
	ch.print();
	ch.clear();
	cout << "删除所有元素后长度：\n";
	ch.clear();
	cout << ch.get_length() << endl;
	cout << "***********************\n";

	Seqlist <int> abc(a, 5);
	cout << "abc初始化为：\n";
	abc.print();
	cout << "abc第二个元素为：\n";
	cout << abc.get(2) << endl;
	cout << "*************************顺序表测试结束*****************\n";
} 
void Test2() //单链表测试
{
	int a[5];
	for (int i = 0;i < 5;i++)
		a[i] = i;
	//single list test；
	cout << "*************************单链表测试*********************\n";
	single_list<int>cc;
	cc.insert(1, 1);
	cout << "在cc首位插入1之后：\n";
	cc.print();
	single_list<int> oo(a, 5);
	cout << "将数组a中的元素转化成链表oo：\n";
	oo.print();
	cout << "在oo末尾插入123之后：\n";
	oo.insert(6, 123);
	oo.print();
	cout << "在oo首位插入10之后：\n";
	oo.insert(1, 10);
	oo.print();
	cout << "在oo第二位插入6之后：\n";
	oo.insert(2, 6);
	oo.print();
	cout << "oo第二位元素数据为：\n";
	cout << oo.get(2) << endl;
	cout << "删除oo第三位之后：\n";
	oo.delet(3);
	oo.print();
	cout << "删除oo首位之后：\n";
	oo.delet(1);
	oo.print();
	cout << "删除oo末位之后：\n";
	oo.delet(6);
	oo.print();
	cout << "清空oo之后\n";
	oo.clear();
	cout << "长度为：" << oo.get_length() << endl;
	cout << "*************************单链表测试结束*****************\n";
}
void Test3()//测试其他
{//TEST 3;
	int a[5];
	for (int i = 0;i < 5;i++)
		a[i] = i;
	cout << "*************************双向表测试*********************\n";
	double_list<int> dd;
	dd.insert(1, 1);
	dd.insert(2, 2);
	cout << "新建dd，在第一位和第二位插入1和2后：\n";
	dd.print();
	cout << "删除第一位后:\n";
	dd.delet(1);
	dd.print();
	cout << "新建ee  按逆序输出:\n";
	double_list <int> ee(a, 5);
	ee.print(1);
	cout << "获取第二位数据:\n";
	cout << ee.get(2) << endl;
	ee.insert(3, 3000);
	cout << "在第三位插入3000后：\n";
	ee.print();
	cout << "将ee清空后的长度:\n";
	ee.clear();
	cout << ee.get_length() << endl;
	cout << "*************************双向表测试结束*****************\n";
	//TEST 4
	cout << "*************************单循环表测试*******************\n";
	single_circle<int> sss;
	cout << "在sss插入10和1：\n";
	sss.insert(1, 10);
	sss.insert(2, 11);
	sss.print();
	cout << "将sss循环两遍：\n";
	sss.print(4);
	cout << "初始化rrr后：" << endl;
	single_circle<int> rrr(a, 5);
	rrr.print();
	cout << "在第六位插入10后：\n";
	rrr.insert(6, 10);
	cout << "循环打印两遍:\n";
	rrr.print(12);
	cout << "删除第4位后：\n";
	rrr.delet(4);
	rrr.print();
	cout << "*************************单循环表测试结束***************\n";
	//Test 5
	cout << "*************************双循环表测试*******************\n";
	cout << "初始化ttt：\n";
	double_circle<int>ttt(a, 5);
	ttt.print();
	cout << "循环打印13位数：\n";
	ttt.pprint(13);
	cout << "*************************双循环表测试结束***************\n";
}
int main()
{  /*
	Test1();
	Test2();
	Test3();
	*///长整数运算 
	string a;  //操作数a
	char b;  //操作符
	string c;  //操作数b
	cout << "请输入数字a"<<endl;
	cin >> a;
	cout << "请输入运算符：+ or - or * \n";
	cin >> b;
	cout << "请输入数字b：\n";
	cin>>c;
	cout << "结果为：\n";
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
