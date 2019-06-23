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
