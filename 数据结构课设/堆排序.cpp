+/************************************
题目描述
在本题中，读入一串整数，将其使用堆排序的方法从小到大排序，并输出。 
堆排序是一种利用堆结构进行排序的方法，它只需要一个记录大小的辅助空间，每个待排序的记录仅需要占用一个存储空间。 
首先建立小根堆或大根堆，然后通过利用堆的性质即堆顶的元素是最小或最大值，从而依次得出每一个元素的位置。
堆排序的算法可以描述如下：

输入
输入的第一行包含1个正整数n，表示共有n个整数需要参与排序。其中n不超过100000。
第二行包含n个用空格隔开的正整数，表示n个需要排序的整数。

输出
只有1行，包含n个整数，表示从小到大排序完毕的所有整数。
请在每个整数后输出一个空格，并请注意行尾输出换行。

样例输入
10
2 8 4 6 1 10 7 3 5 9

样例输出
1 2 3 4 5 6 7 8 9 10 

提示
在本题中，需要按照题目描述中的算法完成堆排序的算法。
堆排序对于元素数较多的情况是非常有效的。通过对算法的分析，不难发现在建立含有n个元素的堆时，总共进行的关键字比较次数不会超过4n，且n个节点的堆深度是log2n数量级的。因此，堆排序在最坏情况下的时间复杂度是O(nlog2n)，相对于快速排序，堆排序具有同样的时间复杂度级别，但是其不会退化。堆排序较快速排序的劣势是其常数相对较大。
************************************/
#include <iostream>
using namespace std;
#define MAXSIZE 100000

typedef struct
{
	int r[MAXSIZE];
	int length;
}sqLIst;

void HeapAdjust(sqLIst &L,int s,int m)
{
	int temp,j;
	temp=L.r[s];
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m && L.r[j]<L.r[j+1]) ++j;
		if(temp>=L.r[j]) break;
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=temp;
}

void creatHeap(sqLIst &L)
{
	int i,n;
	n=L.length;
	for(i=n/2;i>0;--i)
		HeapAdjust(L,i,n);
}

void heapSort(sqLIst &L)
{
	int i,x;
	creatHeap(L);
	for(i=L.length;i>1;i--)
	{
		x=L.r[1];
		L.r[1]=L.r[i];
		L.r[i]=x;
		HeapAdjust(L,1,i-1);
	}
	
}


int main()
{
	sqLIst *L=new sqLIst;
    int n,i;
    scanf("%d", &n);
	L->length=n;
    for (i=1; i<=n; i++) cin>>L->r[i];
	heapSort(*L);
	for (i=1; i<=n; i++) cout<<L->r[i]<<" ";
	cout<<endl;
    system("PAUSE");
	return 0;
    //free(a);
}

/****************************************
算法介绍：

堆其实是一个 完全二叉树，每一个根节点都大于叶子节点

我们算法的第一个目的就是要把我们的无序的元素变成堆。这个过程叫建初堆



*******************************/
#include <iostream>
using namespace std;
#define MAXSIZE 100000

typedef struct
{
	int r[MAXSIZE];
	int length;
}sqLIst;

void printheap(sqLIst &L)
{
	for (int i=1; i<=10; i++) cout<<L.r[i]<<" ";
	cout<<endl;
}


void HeapAdjust(sqLIst &L,int s,int m)
{
	int temp,j;
	temp=L.r[s];
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m && L.r[j]<L.r[j+1]) ++j;
		if(temp>=L.r[j]) break;
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=temp;
}

void creatHeap(sqLIst &L)
{
	int i,n;
	n=L.length;
	for(i=n/2;i>0;--i)
		HeapAdjust(L,i,n);
}

void heapSort(sqLIst &L)
{
	int i,x;
	creatHeap(L);
	printheap(L);
	for(i=L.length;i>1;i--)
	{
		x=L.r[1];
		L.r[1]=L.r[i];
		L.r[i]=x;
		HeapAdjust(L,1,i-1);
	}
	
}




int main()
{
	sqLIst *L=new sqLIst;
    int n,i;
    scanf("%d", &n);
	L->length=n;
    for (i=1; i<=n; i++) cin>>L->r[i];
	heapSort(*L);
    system("PAUSE");
	return 0;
    //free(a);
}




