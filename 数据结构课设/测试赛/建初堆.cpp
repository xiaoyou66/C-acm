/*********************
题目描述
堆排序是一种利用堆结构进行排序的方法，它只需要一个记录大小的辅助空间，每个待排序的记录仅需要占用一个存储空间。 
本题建立堆排序时的初始大根堆，堆顶的元素是最大值。

输入
输入的第一行包含1个正整数n，表示共有n个整数需要参与排序。其中n不超过100000。
第二行包含n个用空格隔开的正整数，表示n个需要排序的整数。

输出
只有1行，包含n个整数，表示初始堆建好后的整数序列。
整数间输出一个空格，并请注意行尾输出换行。

样例输入
8
49 38 65 97 76 13 27 50

样例输出
97 76 65 50 49 13 27 38
************************/
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
	for (int i=1; i<=L.length; i++) cout<<L.r[i]<<" ";
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




int main()
{
	sqLIst *L=new sqLIst;
    int n,i;
    scanf("%d", &n);
	L->length=n;
    for (i=1; i<=n; i++) cin>>L->r[i];
	creatHeap(*L);
	printheap(*L);
    //system("PAUSE");
	return 0;
    //free(a);
}
