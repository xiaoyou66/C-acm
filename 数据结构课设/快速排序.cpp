/****************************************
题目描述
读入一串整数，将其使用快速排序的方法从小到大排序，并输出。 
快速排序是对冒泡排序的一种改进。它的基本思想是，通过一趟排序将待排序的记录分割成两个独立的部分，其中一部分记录的关键字均比另一部分的关键字小，在分成两个部分之后则可以分别对这两个部分继续进行排序，从而使整个序列有序。 
快速排序的算法可以描述如下：
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
在本题中，需要按照题目描述中的算法完成快速排序的算法。
快速排序是一种十分常用的排序算法，其平均时间复杂度为O(nlog2n)，其中n为待排序序列中记录的个数。大量的实际应用证明，就平均时间而言，快速排序是目前被认为最好的一种内部排序方法。
而在C语言的常用编译器中，qsort函数是一个非常常用的快速排序函数。

***************************************/
#include <iostream>
using namespace std;
#include<math.h>

void  Swap(int & a, int & b) 
{
	int c=a; 
	a=b; 
	b=c;
}

void QSort(int* a, int low, int high)
{   
    int i, j;  
    if(low>=high) return;

    Swap(a[low], a[rand()%(high-low+1)+low]); //select a pivot randomly

    i=low; j=high; 
    int temp=a[i];
	while(i<j)
	{
		while(i<j)
			if(a[j]<=temp){a[i]=a[j];i++;break;}
			else j--;
		while(i<j)
			if(a[i]>=temp){a[j]=a[i];j--;break;}
			else i++;
	}
	a[i]=temp;
    QSort(a,low,i-1);
    QSort(a,i+1,high);

}

void SortPrint(int* a, int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int * a=(int*)malloc(sizeof(int)*n);
    for (i=0; i<n; i++) scanf("%d", &a[i]);
    QSort(a,0,n-1);
    SortPrint(a,n);
	return 0;
    //system("PAUSE");
    //free(a);
}






























