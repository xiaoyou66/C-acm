#include<iostream>
using namespace std;

#define MAXSIZE 105

typedef struct BiTNode
{
	
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;


int cent[100]={0},centp=-1;
int back[100]={0},backp=-1;

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
	if (ch == '0') T = NULL;
	else
	{
		T = new  BiTNode;
		T->data = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}

void FrontTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << " ";
		FrontTraverse(T->lchild);
		cent[++centp]=T->data;
		FrontTraverse(T->rchild);
		back[++backp]=T->data;
	}
}



int main()
{
	BiTree T=new BiTNode;
	CreateBitree(T);
	FrontTraverse(T);
	cout<<endl;
	int i=-1;
	while(cent[++i]) cout<<cent[i]-48<<" ";
	cout<<endl;
	i=-1;
	while(back[++i]) cout<<back[i]-48<<" ";
	//system("pause");
	return 0;
}
