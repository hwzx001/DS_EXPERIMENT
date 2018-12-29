#include"h_name.h"  //常用头文件
#include"heap.h"

void insert_sort(vector<int>a)
{
	int i, j, compare = 0, move = 0;
	int temp;
	for (i = 1;i < a.size();i++)
	{
		compare++; //比较+1
		if (a[i] < a[i - 1])
		{
			temp = a[i]; //用temp暂存，以防前面元素后移时将其覆盖
			j = i - 1;
			do {
				a[j + 1] = a[j];
				move++;
				j--;
				compare++;
			} while (j >= 0 && temp<a[j]); //从后向前依次比较,寻找插入位置
			a[j + 1] = temp; //将temp插入到空缺的位置；
			move++;
		}
	}
	cout << "比较次数：" << compare << endl;
	cout << "移动次数：" << move << endl;
	ofstream sort_1("D:\\insert_sort.txt");
	for (int i = 1; i <= a.size(); i++)
	{
		sort_1 << a[i-1];sort_1 << " ";
		if (i % 10 == 0)
			sort_1 << endl;
	}
	sort_1.close();

}

void shell_sort(vector<int>a)
{
	int i, j, compare = 0, move = 0;
	int gap = a.size();
	int temp;
	do{
		gap = gap / 3 + 1;//求下一增量值
		for (i = gap;i < a.size();i++)
		{
			compare++;
			if (a[i] < a[i - gap])
			{
				temp = a[i];
				j = i - gap;
				do
				{
					move++;
					compare++;
					a[j + gap] = a[j]; //后移元素
					j = j - gap;//再比较前一元素
				} while (j >= 0 && temp < a[j]);
				a[j + gap] = temp;//反插回去
				move++;
			}
		}
    } while (gap > 1);
	cout << "比较次数：" << compare << endl;
	cout << "移动次数：" << move << endl;
	ofstream sort_1("D:\\shell_sort.txt");
	for (int i = 1; i <= a.size(); i++)
	{
		sort_1 << a[i - 1];sort_1 << " ";
		if (i % 10 == 0)
			sort_1 << endl;
	}
	sort_1.close();
}

int partition(vector<int>&a, int low, int high, int &compare, int &move)
{
	//快速排序辅助函数
	int pivotpos = low;
	int pivot = a[low];//基准元素
	for (int i = low + 1;i <= high;i++) //检测整个序列，进行划分；
	{
		compare++;
		if (a[i] < pivot) //将小于基准元素的交换到左侧去
		{
			pivotpos++;
			if (pivotpos != i)
			{
				swap(a[pivotpos], a[i]);
				move++;
			}
		}
	}
	a[low] = a[pivotpos];
	a[pivotpos] = pivot; //将基准元素就位
	move = move + 2;
	return pivotpos;  //返回基准元素位置
}

void quick_sort(vector<int>&a,int left,int right,int &compare,int &move)
{
	if (left < right) //元素长度大于1的时候不处理
	{
		int pivotpos=partition(a,left,right,compare, move); //划分
		quick_sort(a, left, pivotpos - 1, compare, move);//对左边序列排序
		quick_sort(a, pivotpos + 1, right, compare, move);
	}

}

void select_sort(vector<int>&a)
{
	int compare = 0;
	int move = 0;
	for (int i = 0;i < a.size();i++)
	{
		int k = i;
		for (int j = i + 1;j <a.size();j++)
		{
			compare++;
			if (a[j] < a[k])
				k = j;

		}
		if (k != i)
		{
			move++;
			swap(a[i], a[k]);
		}
	}
	cout << "比较次数：" << compare << endl;
	cout << "移动次数：" << move << endl;
}


void mergeSort(vector<int>&left, vector<int>& right, vector<int>& raw_vector,int &compare,int &move)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		compare++;
		move++;
		if (left[j] < right[k]) {
			raw_vector[i] = left[j];
			j++;
		}
		else {
			raw_vector[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		move ++;
		raw_vector[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		move++;
		raw_vector[i] = right[k];
		k++; i++;
	}
}
void sort(vector<int> &bar,int &compare,int &move) {
	if (bar.size() <= 1) return; //递归终止条件

	int mid = bar.size() / 2;  //平分
	vector<int> left;   
	vector<int> right;

	for (size_t j = 0; j < mid;j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	sort(left,compare,move);
	sort(right,compare,move);
	mergeSort(left, right, bar,compare,move); //合并
}
int main()
{
	/*
	int n;
	cout << "请输入正整数n";
	cin >> n;
	if (n < 1) return 0;
	ofstream sort_1("D:\\postive.txt");
	for (int i = 1; i <= n; i++)
	{
		sort_1 << i;sort_1<< " ";
		if (i % 10 == 0)
			sort_1 << endl;
	}
	sort_1.close();
	ofstream sort_2("D:\\reverse.txt");
	for (int i = n; i >= 1; i--)
	{
		sort_2 << i;sort_2 << " ";
		if (i % 10 == 0)
			sort_2 << endl;
	}
	sort_2.close();
	srand((unsigned)time(NULL));
	ofstream sort_3("D:\\random.txt");
	for (int i = 1; i <= n; i++)
	{
		sort_3<<rand() % 1000;
		sort_3 << " ";
		if (i % 10 == 0)
			sort_3 << endl;

	}
	sort_3.close();
	
	*/
	vector<int>ve_1, ve_2, ve_3;
	int t1, t2, t3;
	string s1 = "D:\\postive.txt"; string s2 = "D:\\reverse.txt"; string s3 = "D:\\random.txt";
	ifstream infile;
	infile.open(s1); while (infile >>t1)
	{
		ve_1.push_back(t1);
	} infile.close();
	infile.open(s2); while (infile >> t2)
	{
		ve_2.push_back(t2);
	}infile.close();
	infile.open(s3); while (infile >> t3)
	{
		ve_3.push_back(t3);
	}infile.close();
	
	

	//计时
	clock_t startTime, endTime;
	/*
	for (int i = 0;i < ve_1.size();i++)
	{
		cout << ve_1[i] << " ";
	}
	cout << endl;
	*/


	
	startTime = clock();
	/*Heap fsort(ve_1);
	fsort.heapsort();
	fsort.print();*/

	//insert_sort(ve_1);
	//shell_sort(ve_1);
	//select_sort(ve_1);
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << endl;
	
	
	/*for (int i = 0;i < ve_2.size();i++)
	{
		cout << ve_2[i] << " ";
	}
	cout << endl;*/
	startTime = clock();
	/*Heap gsort(ve_2);
	gsort.heapsort();
	gsort.print();*/
	//insert_sort(ve_2);
	//shell_sort(ve_2);
	//select_sort(ve_2);
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << endl;
	


	
	startTime = clock();
	/*Heap hsort(ve_3);
	hsort.heapsort();
	hsort.print();*/
	//select_sort(ve_3);
	//insert_sort(ve_3);
	//shell_sort(ve_3);
	
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << endl;
	

	//快速排序
	
	int compare = 0, move = 0;
	startTime = clock();
	quick_sort(ve_1, 0, 249, compare, move);
	cout << "比较次数:" << compare << endl;
	cout << "移动次数：" << move << endl;
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	for (int i = 0;i < ve_1.size();i++)
	{
		cout << ve_1[i]<<" ";
	}
	cout << endl;
	cout << "****************\n";
	compare = 0, move = 0;
	startTime = clock();
	quick_sort(ve_2, 0, 249, compare, move);
	cout << "比较次数:" << compare << endl;
	cout << "移动次数：" << move << endl;
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	for (int i = 0;i < ve_2.size();i++)
	{
		cout << ve_2[i] << " ";
	}
	cout << endl;
	cout << "****************\n";
	compare = 0, move = 0;
	startTime = clock();
	quick_sort(ve_3, 0, 249, compare, move);
	cout << "比较次数:" << compare << endl;
	cout << "移动次数：" << move << endl;
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	for (int i = 0;i < ve_3.size();i++)
	{
		cout << ve_3[i] << " ";
	}
	
	// merge_sort;
    
	/*cout << "初始序列：" << endl;
	for (int i = 0;i < ve_1.size();i++)
	{
		cout << ve_1[i] << " ";
	}
	cout << endl;*/
	/*int compare = 0, move = 0;
	startTime = clock();
	sort(ve_1,compare,move);
	endTime = clock();
	cout << "比较次数:" << compare << endl;
	cout << "移动次数：" << move << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;*/
	/*cout << "排序后：" << endl;
	for (int i = 0;i < ve_1.size();i++)
	{
		cout << ve_1[i] << " ";
	}
	cout << endl<<endl;
*/

	/*cout << "初始序列：" << endl;
	for (int i = 0;i < ve_2.size();i++)
	{
		cout << ve_2[i] << " ";
	}
	cout << endl;*/
	/*compare = 0;
	move = 0;
	startTime = clock();
	sort(ve_2, compare, move);
	endTime = clock();
	cout << "比较次数:" << compare << endl;
	cout << "移动次数：" << move << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "排序后：" << endl;*/
	/*for (int i = 0;i < ve_2.size();i++)
	{
		cout << ve_2[i] << " ";
	}
	cout << endl<<endl;*/

	/*cout << "初始序列：" << endl;
	for (int i = 0;i < ve_3.size();i++)
	{
		cout << ve_3[i] << " ";
	}
	cout << endl;*/
	/*compare = 0;
	move = 0;
	startTime = clock();
	sort(ve_3, compare, move);
	endTime = clock();
	cout << "比较次数:" << compare << endl;
	cout << "移动次数：" << move << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;*/
	/*cout << "排序后：" << endl;
	for (int i = 0;i < ve_3.size();i++)
	{
		cout << ve_3[i] << " ";
	}
	cout << endl<<endl;*/
	
	system("pause");

}




