
/******************8
题目描述
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
例如如下的先序遍历字符串：
ABC##DE#G##F###
其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树的总结点数和度为2的结点数进行统计，并输出。 


下面提供代码框架，请同学完成指定的部分。 
//算法5.3 先序遍历的的顺序建立二叉链表
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef char TElemType;
//二叉树的二叉链表存储表示
typedef struct BiTNode {
   TElemType data;                      //结点数据域
   struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T)
{
   //按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
   TElemType ch;

   //此处和教材的不同是，要处理多组数据，输入ch如果遇到EOF，应该结束程序
   //所以main函数用while(1)
   if(!(cin >> ch)) exit(0);       //用此行替换教材上的语句：cin>>ch;   实现若输入遇到EOF（即-1）就退出，避免死循环。
   /****在此下面完成代码***************/

   /***********************************/
}   //CreateBiTree

//用算法5.6 统计二叉树的结点个数
int NodeCount(BiTree T)
{
   //统计二叉树的结点个数
   /****在此下面完成代码***************/

   /***********************************/
} 


//用算法5.6_2 统计二叉树中度为2的结点个数
int NodeCount2(BiTree T)
{
   //统计二叉树中度为2的结点个数
   /****在此下面完成代码***************/ 


   /***********************************/
}

void DestroyBitree(BiTree& T)
{
   /****在此下面完成代码***************/

   /***********************************/
}

int main()
{
   BiTree tree;
   while(1) {
      CreateBiTree(tree);
      cout << NodeCount(tree) << ' ' << NodeCount2(tree);
      cout << endl;
      DestroyBitree(tree);
   }
}

输入
输入有多组测试数据。 
每组数据为一行字符串，长度不超过100。  

输出
可能有多组测试数据，对于每组数据，
每个输出结果占一行，即输出对应二叉树的总结点数和度为2的结点数，空格分隔。 

样例输入
a#b#cdef#####
a##

样例输出
6 0
1 0


******************/



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
	if(!(cin >> ch)) exit(0); 
	if (ch == '#') T = NULL;
	else
	{
		T = new  BiTNode;
		T->data = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}

//计算节点个数
int NodeCount(BiTree T)
{
	if (T == NULL) return 0;//如果是空树则返回空
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
	BiTree T=new BiTNode;
	while(true)
	{
		CreateBitree(T);
		cout<<NodeCount(T)<<" "<<NodeCount2(T)-1<<endl;
	}
	//system("pause");
	return 0;
}
