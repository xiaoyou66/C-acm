#include<iostream>
using namespace std;

#define MAXSIZE 105

typedef struct BiTNode
{
	
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

int front[102]={0},frontp=-1;
int cent[102]={0},centp=-1;
int back[102]={0},backp=-1;

typedef struct
{
	//结构体定义了三个变量
	//一个是栈顶指针，一个是栈底指针
	BiTree *base;
	BiTree *top;
	int stacksize;
}sqstack;

void CreateBitree(BiTree &T)
{
	int ch;
	cin>>ch; 
	if (ch == 0) T = NULL;
	else
	{
		T = new  BiTNode;
		T->data = ch;
		front[++frontp]=ch;
		CreateBitree(T->lchild);
		cent[++centp]=ch;
		CreateBitree(T->rchild);
		back[++backp]=ch;
	}
}

int main()
{
	BiTree T=new BiTNode;
	CreateBitree(T);
	if(front[0]) printf("%d",front[0]); 
	int i=0;
	while(front[++i]) printf(" %d",front[i]);
	cout<<endl;
	if(cent[0]) printf("%d",cent[0]); 
	i=0;
	while(cent[++i]) printf(" %d",cent[i]);
	cout<<endl;
	i=0;
	if(back[0]) printf("%d",back[0]); 
	while(back[++i]) printf(" %d",back[i]);
	cout<<endl;
	//system("pause");
	return 0;
}
