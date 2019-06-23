/***********************
题目描述
24点游戏的玩法是这样的：任取一幅牌中的 4张牌(不含大小王），每张牌上有数字（其中A 代表1，J 代表11，Q 代表 12，K代表13），你可以利用数学中的加、减、乘、除以及括号想办法得到24，每张牌只能用一次。例如有四张6，那么6+6+6+6=24，也可以6*6-6-6=24。但是有些牌是无法得到24的，比如两张 A 和两张2。

读入表达式树的先序遍历字符串, 这里的表达式树是来自24点游戏的真实场景，也就是对应四个数字（值在1到13之间）组成的表达式，问该表达式树能不能得到24？



输入
输入由多组测试数据组成。

每组数据包含一行字符串，即24点游戏的表达式树的先序遍历序列。

输出
对于每组数据，输出一行。如果不能得到24，输出“NO”。如果能得到24，按样例输出。

样例输入
+ + + 6 # # 6 # # 6 # # 6 # #
- - * 6 # # 6 # # 6 # # 6 # #
* * 1 # # 2 # # * 1 # # 2 # #

样例输出
(((6+6)+6)+6)=24
(((6*6)-6)-6)=24
NO



解释：这个题目的关键部分就是在于怎么计算。先序建立二叉树很简单，直接通过输入的内容进行创建即可。

难的部分在于怎么计算是否为24，这里我们是通过递归来实现的，运算符号在头结点上，如果运算符号是+那么就是左结点+右结点，其他的依此类推

还有一个难得地方就是如何把表达式打印出来，这里我是通过cout<<"(";FrontTraverse(T->lchild);cout<<"+";FrontTraverse(T->rchild);cout<<")";break;
来实现的，这个要慢慢理解

还有一个地方就是怎么判断浮点数是否为相应的值，这里我们需要使用fabs(calFrontTraverse(T)-24)<=0.0000001来进行判断
****************************/
#include<iostream>
#include<math.h>
#include<stdio.h>
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
	//cout<<ch;
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

int change(char a)
{
	 if(a=='A') return 1;
	 else if(a=='J') return 11;
	 else if(a=='Q') return 12;
	 else if(a=='K') return 13;
	 else return a-48;
}

//return FrontTraverse(T->lchild)+FrontTraverse(T->rchild);
void FrontTraverse(BiTree T)
{
	if (T)
	{
		switch (T->data)
		{
		case '+': cout<<"(";FrontTraverse(T->lchild);cout<<"+";FrontTraverse(T->rchild);cout<<")";break;
		case '-': cout<<"(";FrontTraverse(T->lchild);cout<<"-";FrontTraverse(T->rchild);cout<<")";break;
		case '*': cout<<"(";FrontTraverse(T->lchild);cout<<"*";FrontTraverse(T->rchild);cout<<")";break;
		case '/': cout<<"(";FrontTraverse(T->lchild);cout<<"/";FrontTraverse(T->rchild);cout<<")";break;
		default: cout<<change(T->data);break;
		}
	}
}

double calFrontTraverse(BiTree T)
{
   	if (T)
	{
		switch (T->data)
		{
		case '+': return calFrontTraverse(T->lchild)+calFrontTraverse(T->rchild);
		case '-': return calFrontTraverse(T->lchild)-calFrontTraverse(T->rchild);
		case '*': return calFrontTraverse(T->lchild)*calFrontTraverse(T->rchild);
		case '/': return calFrontTraverse(T->lchild)/calFrontTraverse(T->rchild);
		default: return change(T->data);
		}
	}
}

int main()
{
	while (true)
	{
		BiTree T = new BiTNode;
		char num[7]={0};
		bool flag=CreateBitree(T);
		if(flag) break;
		//getchar();
		//printf("%lf",calFrontTraverse(T));
		if(fabs(calFrontTraverse(T)-24)<=0.0000001)
		{
			FrontTraverse(T);
			cout<<"=24";
		}
		else
			cout<<"NO";
		cout<<endl;
	}
	//system("pause");
}


