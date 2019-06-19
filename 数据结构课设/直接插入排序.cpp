
/****************************

题目描述
读入一串整数，将其使用直接插入排序或折半插入排序的方法从小到大排序，并输出。
插入排序是一种最简单的排序方法，它的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的且记录数增加了1的有序表。 
直接插入排序 与 折半插入排序的区别“是在已排序序列中寻找插入位置的方法不同”。 
直接插入排序 用 顺序查找法 寻找插入位置。 
折半插入排序 用 折半查找法 寻找插入位置。 
其算法分别描述如下：  
//算法8.1 直接插入排序
#include <iostream>
using namespace std;
#define  MAXSIZE  20          //顺序表的最大长度
typedef struct
{
    int key;
    char *otherinfo;
}ElemType;
//顺序表的存储结构                         
typedef struct
{
    ElemType *r;           //存储空间的基地址
    int  length;            //顺序表长度
}SqList; //顺序表类型

void InsertSort(SqList &L)
{
   //对顺序表L做直接插入排序
    int i,j;
    for(i=2;i<=L.length;++i)
    if(L.r[i].key<L.r[i-1].key)
    {    //"<"，需将r[i]插入有序子表
            L.r[0]=L.r[i]; //将待插入的记录暂存到监视哨中
            L.r[i]=L.r[i-1];             //r[i-1]后移
            for(j=i-2; L.r[0].key<L.r[j].key;--j) //从后向前寻找插入位置
            L.r[j+1]=L.r[j]; //记录逐个后移，直到找到插入位置
            L.r[j+1]=L.r[0]; //将r[0]即原r[i]，插入到正确位置
    } //if
} 


//算法8.2 折半插入排序
void BInsertSort(SqList &L){
    //对顺序表L做折半插入排序
    int i,j,low,high,m;
    for(i=2;i<=L.length;++i)
    {
        L.r[0]=L.r[i];          //将待插入的记录暂存到监视哨中
        low=1; high=i-1;        //置查找区间初值
        while(low<=high)
        { //在r[low..high]中折半查找插入的位置
            m=(low+high)/2;              //折半
            if(L.r[0].key<L.r[m].key)  high=m-1; //插入点在前一子表
            else  low=m+1;     //插入点在后一子表
        }//while
        for(j=i-1;j>=high+1;--j)  L.r[j+1]=L.r[j]; //记录后移
        L.r[high+1]=L.r[0]; //将r[0]即原r[i]，插入到正确位置
    } //for
}


输入
输入的第一行包含1个正整数n，表示共有n个整数需要参与排序。其中n不超过1000。
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
在本题中，需要按照题目描述中的算法完成直接插入排序或折半插入排序的算法。 
尽管折半查找比顺序查找插入位置快一些，但折半或直接插入排序的时间复杂度均为O(n2)，两种方法均不是一种高效的排序方法。

*********************************/


#include <iostream>
using namespace std;
#define  MAXSIZE  1000          //顺序表的最大长度

//顺序表的存储结构                         
typedef struct
{
    int  r[MAXSIZE];           //存储空间的基地址
    int  length;            //顺序表长度
}SqList,*Link; //顺序表类型

void InsertSort(SqList &L)
{
   //对顺序表L做直接插入排序
    int i,j;
    for(i=2;i<=L.length;++i)
    if(L.r[i]<L.r[i-1])
    {    //"<"，需将r[i]插入有序子表
            L.r[0]=L.r[i]; //将待插入的记录暂存到监视哨中
            L.r[i]=L.r[i-1];             //r[i-1]后移
            for(j=i-2; L.r[0]<L.r[j];--j) //从后向前寻找插入位置
            L.r[j+1]=L.r[j]; //记录逐个后移，直到找到插入位置
            L.r[j+1]=L.r[0]; //将r[0]即原r[i]，插入到正确位置
    } //if
} 

int main()
{
	Link L=new SqList;
	int n,i;
	cin>>n;
	L->length=n;
	for(i=1;i<=n;i++)
		cin>>L->r[i];
	InsertSort(*L);
	for(i=1;i<=n;i++)
		cout<<L->r[i]<<" ";
	cout<<endl;
	//system("pause");
	return 0;
}


