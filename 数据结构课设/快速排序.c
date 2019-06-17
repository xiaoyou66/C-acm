#include<iostream>
#include<math.h>
#define void  Swap(int & a, int & b) { c=a; a=b; b=c;}
using namespace std;

void QSort__(int* a, int low, int high)
//快速排序私有函数，供QuickSort()调用
//在a[low:high]中选择一个中心值，用该中心值将a[low:high]分割为两部分
//然后对两个部分递归地进行该操作。
{   
    int i, j;  
    if(low>=high) return;

    Swap(a[low], a[rand()%(high-low+1)+low]); //select a pivot randomly

    i=low; j=high; 
    int temp=a[i];
    // 请在此添加代码，补全函数QSort__
    /********** Begin *********/
	while(i<j)
	{
		for(;;j--)
			if(a[j]<=temp){a[i]=a[j];i++;break;}
		for(;;i++)
			if(a[j]>=temp){a[j]=a[i];j--;break;}
	}
	a[i]=temp;
    /********** End **********/
}



int main()
{
	QSort__(int* a, int low, int high)
}
