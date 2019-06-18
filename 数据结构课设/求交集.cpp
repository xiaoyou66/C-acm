/************************************
 题目描述
有两个相等长度的正整数序列A和B，都是有序的(递增排序)，同时一个序列中没有重复元素，现在需要求这两个序列的交――序列C，同时打印输出。


输入
输入由多组测试用例组成。

每个测试用例一共有2*n+1行，第一行输入为数列的长度n，然后下面2~n+1行，依次输入序列A中的数。n+2~2*n+1行，依次输入序列B中的数。其中 1 <= n <= 50000 , 序列中每个数大小不会超过1000000。

当程序输入n为0时表示结束。


输出

每个测试用例输出一行，先输出序列C的长度，然后依次输出C中的整数，两个数之间间隔一个空格。注意行末不要出现空格。C中的整数递增排序。


样例输入
5
1
2
5
6
7
1
2
4
6
9
0

样例输出
3 1 2 6

****************
这个题目有两个解法
第一个就是利用两个数组来解
我们可以通过两个数组同时进行比较，注意：我们只需要用一个循环，让两个数同时比较然后让不同的位进行加和操作


************************************/



#include<iostream>
using namespace std;

int main()
{
	int a[50000],b[50000],n,i,j,clength;
	while(true)
	{
		cin>>n;
		if(!n) break;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		i=0;j=0;
		int c[50000]={0};
		clength=0;
		while(true)
		{
			if(i>=n || j>=n) break;
			if(a[i]==b[j])
			{
				c[clength++]=a[i];
				i++;j++;
			}
			else if(a[i]<b[j]) i++;
			else  j++;
		}
		cout<<clength<<" ";
		for(j=0;j<clength;j++)
			cout<<c[j]<<" ";
		cout<<endl;
	}

	//system("pause");
}

/******************************
解法2

**************************/
#include<iostream>
using namespace std;

int main()
{
	int n,i,j;
	while(true)
	{
		int a[100000]={0},b[50000]={0},blength=0;
		cin>>n;
		if(!n) break;
		for(i=0;i<n;i++)
		{
			cin>>j;
			a[j]=1;
		}
		for(i=0;i<n;i++)
		{
			cin>>j;
			if(a[j] && j<100000) b[blength++]=j;
		}
		cout<<blength<<" ";
		for(i=0;i<blength;i++)
			cout<<b[i]<<" ";
		cout<<endl;	
	}

	//system("pause");
}



