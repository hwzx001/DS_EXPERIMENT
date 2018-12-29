#pragma once
#include"h_name.h"

struct bintreenode //��������㶨��
{
	char data; //������
	bintreenode *leftChild, *rightChild;  //���㡢�ҽ��
	bintreenode() :leftChild(NULL), rightChild(NULL) {}
	bintreenode(char x, bintreenode *l = NULL, bintreenode *r = NULL) :data(x), leftChild(l), rightChild(r) {};
};

class BinartTree
{
private:
	bintreenode * root; //����
	queue<bintreenode*> anode; // ����ĸ�������
	void  recursive_clear(bintreenode *&b, bintreenode *node); //��յĸ����ݹ麯��
public:
	
	BinartTree();
	BinartTree(string a);
	~BinartTree()
	{
		clear(root);
	};
	void menu();  //�˵�
	void preorder(bintreenode * root);//ǰ�����
	void inorder(bintreenode * root);//�������
	void postorder(bintreenode * root);//�������
	int getWidth(); //���
	int getHeight(bintreenode * node); //���
	int count_2(bintreenode * node); //ͳ�ƶ���Ϊ2�Ľ��
	int count_1(bintreenode *node); //ͳ�ƶ���Ϊ1�Ľ��
	int count_0(bintreenode *node);//ͳ��Ҷ�ӽ��
	void insert(char a); //Ĭ��ֻ��β��
	bool find(bintreenode * node,char a);//�����Ƿ����ַ�a
	bool empty(); //�п�
	void delete_char(char a);//ɾ��ֵΪa�Ľ�� 
	void clear(bintreenode*bin); //���
	bintreenode * getroot( ) //��ȡͷ���
	{
		return root;
	}
	void ceng_order();//�������
	void visit(bintreenode * a);//��ӡ�ýڵ��data
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
		cout << "������û��ֵΪ"<<a<<"��Ԫ�أ�" << endl;
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
		
		while (true) //���ҵ�������
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
		if (parent->leftChild->data == a) //����Ϊ��ɾ���
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
				//�������������գ�������������ȥ�����������������б�����Ѱ�ҿյ�λ�ò���
				while (!abc.empty())
				{
					abc.pop();
				}
				//�ÿ�

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
		else //�Һ���Ϊ��ɾ���
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
		deque<bintreenode*>dnode; //˫�˶���
		dnode.push_back(root); //��������
		while (true)
		{
			int length = dnode.size();//��ǰ���ĸ���
			if (length == 0) break; //û�н�㣬����ѭ��
			while (length)
			{
				bintreenode *temp = dnode.front();
				dnode.pop_front();//���ӣ�
				length--;
				if (temp->leftChild) 
				{
					dnode.push_back(temp->leftChild); //�������
				}
				if (temp->rightChild)
				{
					dnode.push_back(temp->rightChild);  //�Һ������
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
	//������������ֵΪa�Ľ�� ����з���1�����򷵻�0��
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
	// 1��������
	// 2�������������
	//3�������������
	if (root == NULL) return;
	visit(root);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

inline void BinartTree::inorder(bintreenode * root)
{
	
	//LVR
	//   1�������������
	// 2��������
	//3�������������
	if (root == NULL) return;
	inorder(root->leftChild);
	visit(root);
	inorder(root->rightChild);


}

inline void BinartTree::postorder(bintreenode * root)
{
	//VLR
	
	// 1�������������
	//2�������������
	// 3��������
	if (root == NULL) return;
	postorder(root->leftChild);
	postorder(root->rightChild);
	visit(root);

}

inline void BinartTree::menu()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~������~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1.����һ���ַ�" << endl;
	cout << "2.ǰ�������� " << "3.���������� "  "4.���������� " << endl;
	cout << "5.��ȡ������� " << "6.��ȡ���Ŀ�� " << endl;
	cout << "7.��Ϊ2�Ľڵ��� " << "8.��Ϊ1�Ľڵ��� " << "9.��Ϊ0�Ľڵ���" << endl;
	cout << "10.ɾ��ֵΪ����ֵ�Ľ�� " << endl;
	cout << "11.����ֵΪ����ֵ�Ľڵ� " << endl;
	cout<<  "12.�˳����� " <<"13.���" <<"14.�п�"<<"15.�������"<<endl;
	cout << "�������ѣ�ɾ��ĳ��Ԫ�ػ�ı�ԭ����˳��Ŷ" << endl;
	cout << endl;


}

