#pragma once
#include"h_name.h"

class Heap
{
private:
	void sink(int k, int size); //将最大的元素调整到堆顶
	void exch(int i, int j); //交换	
	vector<int> mHeap; //存储
	int move;  //记录移动次数
	int compare; //记录比较次数；
public:

	Heap();
	//~Heap();
	Heap(const vector<int> a);
	void insert(const int data);
	void print() ;
	void heapsort();
	void sort();
	unsigned int size() const;

};
Heap::Heap() 
{
	cout << "__DEBUG__" <<endl;
	mHeap.push_back(-1);
	move = 0;
	compare = 0;
}

inline Heap::Heap(const vector<int> a)
{
	move = 0;
	compare = 0;
	mHeap.push_back(-1);
	for (int i = 0;i <a.size();i++)
	{
		insert(a[i]);
	}
}

void Heap::insert(const int data) {
	mHeap.push_back(data);
}

void Heap::exch(int i, int j) {
	int tmp = mHeap[i];
	mHeap[i] = mHeap[j];
	mHeap[j] = tmp;
	move++;
}


void Heap::print()  {
	for (int i = 1; i < mHeap.size(); i++)
	{
		cout << mHeap[i] << " ";
	}
	cout << endl;
	cout << "Compare:";
	cout << compare<<endl;
	cout << "Move:" << move;
	cout << endl;
}

unsigned int Heap::size() const {
	return mHeap.size();
}

void Heap::heapsort() {
	int N = mHeap.size()-1 ;
	sort();
	while (N > 1) {
		exch(1, N--);
		sink(1, N);
	}

	if (mHeap[1] > mHeap[2])
	{
		exch(1, 2);
		move++;
	}
    if (mHeap[2] > mHeap[3])
	{
		exch(2, 3);
		move++;
	}
}

void Heap::sort()
{
	int N = mHeap.size();
	for (int k = N/2 ; k >= 1; --k)
	{
		sink(k, N);
	}
}

void Heap::sink(int k,int size)
{
	while (2 * k < size ) 
	{
	    
		int j = 2 * k; // kΪparent jΪ left child;
		compare++;
		if (j + 1 < size && mHeap[j] < mHeap[j + 1])
		{
			++j;
		}
		compare++;
		if (mHeap[k] > mHeap[j])
			break;
		exch(j, k);
		//move++;
		k = j;
	}
	
}