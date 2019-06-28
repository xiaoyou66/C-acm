/********************8

题目描述
读入一串整数，将其使用直接插入排序的方法从小到大排序。
插入排序是一种最简单的排序方法，它的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的且记录数增加了1的有序表。 

输入
输入的第一行包含1个正整数n，表示共有n个整数需要参与排序。其中n不超过1000。 
第二行包含n个用空格隔开的正整数，表示n个需要排序的整数。但前m-1个整数已经有序。  
第三行输入1个正整数m，表示您将要把第m个整数插入到前m-1个整数中，以保证前m个整数有序。  

输出
输出经过本次一趟插入排序后的整个序列。 
只有1行，包含n个整数，整数之间输出一个空格，并请注意行尾输出换行。 



样例输入
15
12 23 33 45 50 25 31 7 18 2 52 8 3 2 1
6

样例输出
12 23 25 33 45 50 31 7 18 2 52 8 3 2 1

*********************/






#include <iostream>
using namespace std;

#define  MAXSIZE  1000    

typedef struct
{
    int  r[MAXSIZE];         
    int  length;            
}SqList,*Link; 


void InsertSort(SqList &L)
{
  
    int i,j;
    for(i=2;i<=L.length;++i)
    if(L.r[i]<L.r[i-1])
    {    
            L.r[0]=L.r[i]; 
            L.r[i]=L.r[i-1];            
            for(j=i-2; L.r[0]<L.r[j];--j)
				L.r[j+1]=L.r[j]; 
            L.r[j+1]=L.r[0]; 
    }
} 



int main()
{
	int i,n;
	Link L=new SqList;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>L->r[i];
	cin>>L->length;
	InsertSort(*L);
	for(i=1;i<=n;i++)
		cout<<L->r[i]<<" ";
	cout<<endl;
	//system("pause");
	return 0;
}
