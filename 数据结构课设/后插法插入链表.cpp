/*************************

题目描述
拷贝如下的代码，完成CreateList_R函数。

#include<iostream>
#include<iomanip>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

typedef struct LNode {
   ElemType data; //结点的数据域
   struct LNode *next; //结点的指针域
} LNode, *LinkList; //LinkList为指向结构体LNode的指针类型

void CreateList_R(LinkList &L, int n) //算法2.12 后插法创建单链表
{
   /****在此下面完成代码***************/
   
   /***********************************/
}

void ListPrint(LinkList L)
{
   LNode *p;
   for(p = L->next; p; p = p->next)
      cout << p->data << (p->next ? ' ' : '\n');
}

int main()
{
   LinkList L;
   int n;

   cin >> n;
   CreateList_R(L, n);
   ListPrint(L);
}




输入
输入包括两行。

第一行是一个整数n，表示链表中的元素个数。

第二行是n个空格分开的整数，为各元素值。


输出
输出链表，见样例。

样例输入
5
1 2 3 4 5

样例输出
1 2 3 4 5


************************/


#include<iostream>
#include<iomanip>
using namespace std;


typedef struct LNode {
   int data; //结点的数据域
   struct LNode *next; //结点的指针域
} LNode, *LinkList; //LinkList为指向结构体LNode的指针类型

void CreateList_R(LinkList &L, int n) //算法2.12 后插法创建单链表
{
   /****在此下面完成代码***************/
   	L=new  LNode;
	L->next=NULL;
	LinkList q=L;
	for(int i=0;i<n;i++)
	{
	   	LinkList p=new LNode;
		scanf("%d",&p->data);
		p->next=NULL;
		q->next=p;
		q=q->next;
	}
   /***********************************/
}

void ListPrint(LinkList L)
{
   LNode *p;
   for(p = L->next; p; p = p->next)
      cout << p->data << (p->next ? ' ' : '\n');
}

int main()
{
   LinkList L;
   int n;
   cin >> n;
   CreateList_R(L, n);
   ListPrint(L);
   //system("pause");
   return 0;
}




