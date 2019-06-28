#include<iostream>
using namespace std;


typedef struct BiTNode
{
	
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

typedef struct
{
	//结构体定义了三个变量
	//一个是栈顶指针，一个是栈底指针
	BiTree *base;
	BiTree *top;
	int stacksize;
}sqstack;

void CreateBitree(BiTree  &T)
{
	char ch;
	cin >> ch; 
	if (ch == '#') T = NULL;
	else
	{
		T = new  BiTNode;
		T->data = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}


int NodeCount(BiTree T)
{
	if (T == NULL) return 0;
	//else if(T->lchild && T->rchild) return 0;
	//else if(T->lchild || T->rchild) return 1;
	else return NodeCount(T->lchild) + NodeCount(T->rchild)+1;

}
int NodeCount2(BiTree T)
{
	if (T == NULL) return 0;//如果是空树则返回空
	else if (!T->lchild && !T->rchild) return 1;//如果是空树则返回空
	else return NodeCount2(T->lchild) + NodeCount2(T->rchild);

}


int main()
{
	int n,m;
	BiTree T=new BiTNode;
	CreateBitree(T);
	n=NodeCount(T);
	m=NodeCount2(T);
	cout<<(n-2*m+1)<<endl;
	//system("pause");
	return 0;
}
