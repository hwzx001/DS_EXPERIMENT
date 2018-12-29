#include"h_name.h"  //����ͷ�ļ�
#include"heap.h"

void insert_sort(vector<int>a)
{
	int i, j, compare = 0, move = 0;
	int temp;
	for (i = 1;i < a.size();i++)
	{
		compare++; //�Ƚ�+1
		if (a[i] < a[i - 1])
		{
			temp = a[i]; //��temp�ݴ棬�Է�ǰ��Ԫ�غ���ʱ���串��
			j = i - 1;
			do {
				a[j + 1] = a[j];
				move++;
				j--;
				compare++;
			} while (j >= 0 && temp<a[j]); //�Ӻ���ǰ���αȽ�,Ѱ�Ҳ���λ��
			a[j + 1] = temp; //��temp���뵽��ȱ��λ�ã�
			move++;
		}
	}
	cout << "�Ƚϴ�����" << compare << endl;
	cout << "�ƶ�������" << move << endl;
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
		gap = gap / 3 + 1;//����һ����ֵ
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
					a[j + gap] = a[j]; //����Ԫ��
					j = j - gap;//�ٱȽ�ǰһԪ��
				} while (j >= 0 && temp < a[j]);
				a[j + gap] = temp;//�����ȥ
				move++;
			}
		}
    } while (gap > 1);
	cout << "�Ƚϴ�����" << compare << endl;
	cout << "�ƶ�������" << move << endl;
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
	//��������������
	int pivotpos = low;
	int pivot = a[low];//��׼Ԫ��
	for (int i = low + 1;i <= high;i++) //����������У����л��֣�
	{
		compare++;
		if (a[i] < pivot) //��С�ڻ�׼Ԫ�صĽ��������ȥ
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
	a[pivotpos] = pivot; //����׼Ԫ�ؾ�λ
	move = move + 2;
	return pivotpos;  //���ػ�׼Ԫ��λ��
}

void quick_sort(vector<int>&a,int left,int right,int &compare,int &move)
{
	if (left < right) //Ԫ�س��ȴ���1��ʱ�򲻴���
	{
		int pivotpos=partition(a,left,right,compare, move); //����
		quick_sort(a, left, pivotpos - 1, compare, move);//�������������
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
	cout << "�Ƚϴ�����" << compare << endl;
	cout << "�ƶ�������" << move << endl;
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
	if (bar.size() <= 1) return; //�ݹ���ֹ����

	int mid = bar.size() / 2;  //ƽ��
	vector<int> left;   
	vector<int> right;

	for (size_t j = 0; j < mid;j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	sort(left,compare,move);
	sort(right,compare,move);
	mergeSort(left, right, bar,compare,move); //�ϲ�
}
int main()
{
	/*
	int n;
	cout << "������������n";
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
	
	

	//��ʱ
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
	

	//��������
	
	int compare = 0, move = 0;
	startTime = clock();
	quick_sort(ve_1, 0, 249, compare, move);
	cout << "�Ƚϴ���:" << compare << endl;
	cout << "�ƶ�������" << move << endl;
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
	cout << "�Ƚϴ���:" << compare << endl;
	cout << "�ƶ�������" << move << endl;
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
	cout << "�Ƚϴ���:" << compare << endl;
	cout << "�ƶ�������" << move << endl;
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	for (int i = 0;i < ve_3.size();i++)
	{
		cout << ve_3[i] << " ";
	}
	
	// merge_sort;
    
	/*cout << "��ʼ���У�" << endl;
	for (int i = 0;i < ve_1.size();i++)
	{
		cout << ve_1[i] << " ";
	}
	cout << endl;*/
	/*int compare = 0, move = 0;
	startTime = clock();
	sort(ve_1,compare,move);
	endTime = clock();
	cout << "�Ƚϴ���:" << compare << endl;
	cout << "�ƶ�������" << move << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;*/
	/*cout << "�����" << endl;
	for (int i = 0;i < ve_1.size();i++)
	{
		cout << ve_1[i] << " ";
	}
	cout << endl<<endl;
*/

	/*cout << "��ʼ���У�" << endl;
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
	cout << "�Ƚϴ���:" << compare << endl;
	cout << "�ƶ�������" << move << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;
	cout << "�����" << endl;*/
	/*for (int i = 0;i < ve_2.size();i++)
	{
		cout << ve_2[i] << " ";
	}
	cout << endl<<endl;*/

	/*cout << "��ʼ���У�" << endl;
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
	cout << "�Ƚϴ���:" << compare << endl;
	cout << "�ƶ�������" << move << endl;
	cout << "Totle Time : " << (double)(endTime - startTime) / 1000 << "s" << endl;*/
	/*cout << "�����" << endl;
	for (int i = 0;i < ve_3.size();i++)
	{
		cout << ve_3[i] << " ";
	}
	cout << endl<<endl;*/
	
	system("pause");

}




