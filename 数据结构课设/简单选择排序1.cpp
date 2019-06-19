/*****************************
在本题中，读入一串整数，将其使用简单选择排序的方法从小到大排序，并输出。 
选择排序的基本思想是：每一趟比较过程中，在n-i+1(i=1,2,...,n-1)个记录中选取关键字最小的记录作为有序序列中的第i个记录。 
在多种选择排序中，最常用且形式最为简单的是简单选择排序。
简单选择排序的算法可以描述如下： 


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
简单选择排序是一种思路非常简单，结构简洁的排序算法。它的特点是，无论记录的初始排列形式如何，所需进行的关键字间的比较次数始终相同，均为n(n-1)/2。因此，其时间复杂度也固定在O(n2)。

****************************/
#include <iostream>
using namespace std;
#define MAXSIZE 1001

typedef struct
{
	int r[MAXSIZE];
	int length;
}sqLIst;

void selectSort(sqLIst &L)
{
	int i,j,k;
	int t;
	for(i=1;i<L.length;++i)
	{
		k=i;
		for(j=i+1;j<=L.length;++j)
			if(L.r[j]<L.r[k]) k=j;
		if(k!=i)
		{
			t=L.r[i];
			L.r[i]=L.r[k];
			L.r[k]=t;
		}
	}	
}

int main()
{
	sqLIst *L=new sqLIst;
    int n,i;
    scanf("%d", &n);
	L->length=n;
    for (i=1; i<=n; i++) cin>>L->r[i];
	selectSort(*L);
	for (i=1; i<=n; i++) cout<<L->r[i]<<" ";
	cout<<endl;
    //system("PAUSE");
	return 0;
    //free(a);
}







