#pragma once
#include"h_name.h"

struct bintreenode //二叉树结点定义
{
	char data; //数据域
	bintreenode *leftChild, *rightChild;  //左结点、右结点
	bintreenode() :leftChild(NULL), rightChild(NULL) {}
	bintreenode(char x, bintreenode *l = NULL, bintreenode *r = NULL) :data(x), leftChild(l), rightChild(r) {};
};

class BinartTree
{
private:
	bintreenode * root; //树根
	queue<bintreenode*> anode; // 插入的辅助队列
	void  recursive_clear(bintreenode *&b, bintreenode *node); //清空的辅助递归函数
public:
	
	BinartTree();
	BinartTree(string a);
	~BinartTree()
	{
		clear(root);
	};
	void menu();  //菜单
	void preorder(bintreenode * root);//前序遍历
	void inorder(bintreenode * root);//中序遍历
	void postorder(bintreenode * root);//后序遍历
	int getWidth(); //宽度
	int getHeight(bintreenode * node); //深度
	int count_2(bintreenode * node); //统计度数为2的结点
	int count_1(bintreenode *node); //统计度数为1的结点
	int count_0(bintreenode *node);//统计叶子结点
	void insert(char a); //默认只能尾插
	bool find(bintreenode * node,char a);//查找是否有字符a
	bool empty(); //判空
	void delete_char(char a);//删除值为a的结点 
	void clear(bintreenode*bin); //清空
	bintreenode * getroot( ) //获取头结点
	{
		return root;
	}
	void ceng_order();//层序遍历
	void visit(bintreenode * a);//打印该节点的data
};

inline void BinartTree::ceng_order()
{
	queue<bintreenode*> ceng;
	ceng.push(root);
	while (!ceng.empty())
	{
		bintreenode *temp = ceng.front();
		visit(temp);
		if (temp->leftChild != NULL) ceng.push(temp->leftChild);
		if (temp->rightChild != NULL) ceng.push(temp->rightChild);
		ceng.pop();

	}

}

inline void BinartTree::clear(bintreenode*bin)
{
	if(root==bin)
	recursive_clear(root,bin);

}
void  BinartTree::recursive_clear(bintreenode *&b,bintreenode *node) {
	if (b == node) {
		b = NULL;
		return;
	}
	recursive_clear(b->leftChild,node);
	recursive_clear(b->rightChild,node);
}

inline void BinartTree::delete_char(char a)
{
	if (root == NULL) return;
	if (!find(root,a))
	{
		cout << "该树中没有值为"<<a<<"的元素！" << endl;
		return;
	}
	else if (root->data == a)
	{ 

		bintreenode *parent = root,*current;
		queue<bintreenode*> abc;
		root = root->leftChild;
		current = root;
		while (current->leftChild!=NULL&&current->rightChild!=NULL)
		{
			abc.push(current->leftChild);
			abc.push(current->rightChild);
			current = abc.front();
			abc.pop();
		}
		if (current->leftChild == NULL) current->leftChild = parent->rightChild;
		else
		{
			current->rightChild = parent->rightChild;
		}

	}
	else
	{
		bintreenode *parent=root,*current;
		queue<bintreenode*> abc;
		
		while (true) //先找到这个结点
		{
			if (parent->leftChild!=NULL&&parent->leftChild->data!=a)
			abc.push(parent->leftChild);
			if (parent->rightChild!=NULL &&parent->rightChild->data!=a)
			abc.push(parent->rightChild);
			if ((parent->leftChild != NULL && parent->leftChild->data == a) || (parent->rightChild != NULL && parent->rightChild->data == a))
			{
				break;
			}
			parent = abc.front();
			abc.pop();	
			
		} 
		if (parent->leftChild->data == a) //左孩子为被删结点
		{
			current = parent->leftChild;
			if (current->leftChild != NULL && current->rightChild == NULL)
				parent->leftChild = current->leftChild;
			else if (current->leftChild == NULL && current->rightChild != NULL)
				parent->leftChild = current->rightChild;
			else if (current->leftChild == NULL && current->rightChild == NULL)
				parent->leftChild = NULL;
			else
			{
				//左右子树都不空，则将左子树插上去，右子树在左子树中遍历，寻找空的位置插入
				while (!abc.empty())
				{
					abc.pop();
				}
				//置空

				bintreenode *tail = current->leftChild;
				parent->leftChild = current->leftChild;
				while (tail->leftChild!=NULL&&tail->rightChild!=NULL)
				{
					abc.push(tail->leftChild);
					abc.push(tail->rightChild);
					tail = abc.front();
					abc.pop();
				}
				if (tail->leftChild == NULL) tail->leftChild = current->rightChild;
				else tail->rightChild = current->rightChild;
			}
		}
		else //右孩子为被删结点
		{
			while (!abc.empty())
			{
				abc.pop();
			}
			current = parent->rightChild;
			if (current->leftChild != NULL && current->rightChild == NULL)
				parent->rightChild = current->leftChild;
			else if (current->leftChild == NULL && current->rightChild != NULL)
				parent->rightChild = current->rightChild;
			else if (current->leftChild == NULL && current->rightChild == NULL)
				parent->rightChild = NULL;
			else 
			{
				parent->rightChild= current->leftChild;
				bintreenode *tail = current->leftChild;
		
				while (tail->leftChild != NULL && tail->rightChild != NULL)
				{
					abc.push(tail->leftChild);
					abc.push(tail->rightChild);
					tail = abc.front();
					abc.pop();
				}
				if (tail->leftChild == NULL) tail->leftChild = current->rightChild;
				else tail->rightChild = current->rightChild;

			}
		}


	}
	
}


inline int BinartTree::getWidth()
{
	int max = 1;
	if (root==NULL) return 0;
	else
	{
		deque<bintreenode*>dnode; //双端队列
		dnode.push_back(root); //根结点入队
		while (true)
		{
			int length = dnode.size();//当前结点的个数
			if (length == 0) break; //没有结点，跳出循环
			while (length)
			{
				bintreenode *temp = dnode.front();
				dnode.pop_front();//出队；
				length--;
				if (temp->leftChild) 
				{
					dnode.push_back(temp->leftChild); //左孩子入队
				}
				if (temp->rightChild)
				{
					dnode.push_back(temp->rightChild);  //右孩子入队
				}
			}
			max = max > dnode.size() ? max : dnode.size();

		}
		return max;

	}
}

inline int BinartTree::count_2(bintreenode * node)
{
	int nodes;

    if (node == NULL) return 0;
	else if (node->leftChild == NULL && node->rightChild == NULL) return 0;
	else if (node->leftChild != NULL && node->rightChild == NULL) nodes=count_2(node->leftChild);
	else if (node->leftChild == NULL && node->rightChild != NULL) nodes = count_2(node->rightChild);
	else
		{
			nodes = 1 + count_2(node->leftChild) + count_2(node->rightChild);
		}
	return nodes;
}

inline int BinartTree::count_1(bintreenode * node)
{
	int nodes;

	if (node == NULL) return 0;
	else if (node->leftChild == NULL && node->rightChild == NULL) return 0;
	else if (node->leftChild != NULL && node->rightChild == NULL) nodes = 1 + count_1(node->leftChild);
	else if (node->leftChild == NULL && node->rightChild != NULL) nodes = 1 + count_1(node->rightChild);
	else
	{
		nodes = count_1(node->leftChild) + count_1(node->rightChild);
	}

	return nodes;
}

inline int BinartTree::count_0(bintreenode * node)
{
	int nodes=0;
	if (node == NULL)return 0;
	else if (node->leftChild == NULL && node->rightChild != NULL) nodes = count_0(node->rightChild);
	else if (node->leftChild != NULL && node->rightChild == NULL)nodes = count_0(node->leftChild);
	else if (node->leftChild != NULL && node->rightChild != NULL) nodes = count_0(node->leftChild) + count_0(node->rightChild);
	else {
		nodes ++;
	}


	return nodes;
}



inline bool BinartTree::empty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

inline BinartTree::BinartTree(string a)
{
	
	for (int i = 0;i < a.size();i++)
	{
		insert(a[i]);
	}
}

inline int BinartTree::getHeight(bintreenode * node)
{
	if (node == NULL) return 0;
	int h1 = getHeight(node->leftChild);
	int h2 = getHeight(node->rightChild);
	return 1 + (h1 > h2 ? h1 : h2);

}

inline bool BinartTree::find(bintreenode * node, char a)
{
	//遍历二叉树找值为a的结点 如果有返回1，否则返回0；
	if (node == NULL) return false; 
	if (node->data == a) { return true; }
	else if (node->leftChild!=NULL &&find(node->leftChild, a)) { return true; }
	else
	{
		if (node->rightChild != NULL && find(node->rightChild, a))
			return true;
		else
			return false;
	}
}

inline void BinartTree::visit(bintreenode * a)
{
	cout << a->data << " ";
}

BinartTree::BinartTree()
{
	root = NULL;
}

void BinartTree::insert(char a) 
{
	bintreenode *temp = new bintreenode;
	temp->data = a;
	temp->leftChild = NULL;
	temp->rightChild = NULL;
	if (root == NULL) { root = temp; 
	anode.push(root);
	}
	else
	{
		while (!anode.empty())
		{
			bintreenode *node = new bintreenode;
			node = anode.front();
			if (node->leftChild == NULL) { node->leftChild = temp;break; }
			else if (node->rightChild == NULL) {node->rightChild = temp;break;}
			else {
				anode.push(node->leftChild);
				anode.push(node->rightChild);
				anode.pop();
			}
		}
		
	}


}

inline void BinartTree::preorder(bintreenode * root)
{
	//VLR
	// 1访问树根
	// 2先序遍历左子树
	//3先序遍历右子树
	if (root == NULL) return;
	visit(root);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

inline void BinartTree::inorder(bintreenode * root)
{
	
	//LVR
	//   1中序遍历左子树
	// 2访问树根
	//3中序遍历右子树
	if (root == NULL) return;
	inorder(root->leftChild);
	visit(root);
	inorder(root->rightChild);


}

inline void BinartTree::postorder(bintreenode * root)
{
	//VLR
	
	// 1后序遍历左子树
	//2后序遍历右子树
	// 3访问树根
	if (root == NULL) return;
	postorder(root->leftChild);
	postorder(root->rightChild);
	visit(root);

}

inline void BinartTree::menu()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~二叉树~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1.插入一个字符" << endl;
	cout << "2.前序遍历输出 " << "3.中序遍历输出 "  "4.后序遍历输出 " << endl;
	cout << "5.获取树的深度 " << "6.获取树的宽度 " << endl;
	cout << "7.度为2的节点数 " << "8.度为1的节点数 " << "9.度为0的节点数" << endl;
	cout << "10.删除值为输入值的结点 " << endl;
	cout << "11.查找值为输入值的节点 " << endl;
	cout<<  "12.退出程序 " <<"13.清空" <<"14.判空"<<"15.层序遍历"<<endl;
	cout << "友情提醒：删除某个元素会改变原来的顺序哦" << endl;
	cout << endl;


}

