

/*******************************8
题目描述
快速排序是对冒泡排序的一种改进。它的基本思想是，通过一趟排序将待排序的记录分割成两个独立的部分，其中一部分记录的关键字均比另一部分的关键字小，在分成两个部分之后则可以分别对这两个部分继续进行排序，从而使整个序列有序。 



输入
输入的第一行包含1个正整数n，表示共有n个整数需要参与排序。其中n不超过100000。
第二行包含n个用空格隔开的正整数，表示n个需要排序的整数。

输出
只有1行，包含n个整数，表示以第1个数为轴，经过第一趟快速排序后的结果序列。
请在整数间输出一个空格，并请注意行尾输出换行。

样例输入
8
49 38 65 97 76 13 27 50

样例输出
27 38 13 49 76 97 65 50

****************************/

#include <iostream>

using namespace std;


void QSort(int* a, int low, int high)
{   
    int i, j;  
    if(low>=high) return;


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

}

int main()
{
	int i,a[1000]={0},n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	QSort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<endl;
	//system("pause");
	return 0;
}
