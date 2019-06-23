#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef struct BiTNode
{
	//二叉树的存储结构
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
	//就是先给根节点赋值，然后在遍历创建左子树，最后再遍历创建右子树
	char ch;
	scanf("%c",&ch);
	//printf("%c",ch);
	if (ch == '#') T = NULL;
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
		//先序遍历其实和中序遍历的代码差别不大，就是改变一下顺序即可
		cout << T->data << " ";
		FrontTraverse(T->lchild);
		FrontTraverse(T->rchild);
	}
}
int main()
{	
	BiTree T = new BiTNode;
	CreateBitree(T); 
	FrontTraverse(T);
	system("pause");
}
/*********第二次******************/
#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef struct BiTNode
{
	//二叉树的存储结构
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;



bool CreateBitree(BiTree  &T)
{
	char ch;
	if(scanf("%c",&ch)==EOF) return true;
	getchar();
	if (ch == '#') T = NULL;
	else
	{
		T = new  BiTNode;
		T->data = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
	return false;
}

void FrontTraverse(BiTree T,char num[])
{
	if (T)
	{
		int i=-1;
		FrontTraverse(T->lchild,num);
		while(num[++i]);
		num[i]=T->data;
		FrontTraverse(T->rchild,num);
	}
}

int change(char a)
{
	 if(a=='A') return 1;
	 else if(a=='J') return 11;
	 else if(a=='Q') return 12;
	 else if(a=='K') return 13;
	 else return a-48;
}


int main()
{	
	while (true)
	{
		BiTree T = new BiTNode;
		char num[7]={0};
		int sum;
		bool flag=CreateBitree(T);
		if(flag) break;
		FrontTraverse(T,num);
		//for(int i=0;i<7;i++)
		//	cout<<num[i];
		switch(num[1])
		{
			case '+':
				sum=change(num[0])+change(num[2]);break;
			case '-':
				sum=change(num[0])-change(num[2]);break;
			case '*':
				sum=change(num[0])*change(num[2]);break;
			case '/':
				sum=change(num[0])/change(num[2]);break;
		}
		switch(num[3])
		{
			case '+':
				sum=sum+change(num[4]);break;
			case '-':
				sum=sum-change(num[4]);break;
			case '*':
				sum=sum*change(num[4]);break;
			case '/':
				sum=sum/change(num[4]);break;
		}
		switch(num[5])
		{
			case '+':
				sum=sum+change(num[6]);break;
			case '-':
				sum=sum-change(num[6]);break;
			case '*':
				sum=sum*change(num[6]);break;
			case '/':
				sum=sum/change(num[6]);break;
		}
		if(sum==24)
			printf("(((%c%c%c)%c%c)%c%c)=24\n",num[0],num[1],num[2],num[3],num[4],num[5],num[6]);
		else
			printf("NO\n");
	}	
	//system("pause");
}
