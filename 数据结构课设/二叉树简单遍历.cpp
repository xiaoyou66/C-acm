/**************************************8
题目描述
求二叉树的先序、中序及后序遍历序列。结点数<=100。


输入
按先序遍历的顺序建立一个二叉树，为了保证树的唯一性，并在程序中的递归出口是左右子树为空，故输入时，当某结点的左子树或右子树为空值时也要作为先序遍历的有效输入。例如一个树只有3个结点，根结点值为1，其左孩子结点值为2，其右孩子结点值为3，则输入的先序遍历序列依次为1　2　0　0  3　0　0（为空时输入0值）*/


输出
在三行上，依次输出二叉树的先序、中序及后序遍历序列。序列中各数用空格隔开。


样例输入
1 2 0 0 3 0 0

样例输出
1 2 3
2 1 3
2 3 1

提示
本题可以参考数据结构（C语言版）教材的算法6.1至算法6.4。其中，算法6.4是根据先序序列构建二叉链表，可直接参考！



这个题目本来挺简单的，但是一直内存超限，本来我以为是递归太多了，所以我就在创建链表的时候就直接把中序和后序直接存到数组里面去了。
但还是一直超时，最后老师说是类型的问题，要把char字符类型改成int。。。。。
因为char的空格也可能读进去........
************************888/




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
