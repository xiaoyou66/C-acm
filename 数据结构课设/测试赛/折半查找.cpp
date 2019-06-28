/***************************
题目描述
在一个升序排列的整数数字序列中查找，并输出相应的结果。

输入
只有一组测试数据，由3行组成： 
第一行是1个整数n（1<=n<=1000000）。 
第二行一共有n个int类型整数，代表升序排列的有序序列。 
第三行是1个int类型整数m，表示要在前面n个整数有序序列中查找的数。 

输出
对于待查询的数m，输出它在有序序列中依次比较的数，然后输出“OK”（若查找成功）或输出“SORRY”（若查找失败）。

样例输入
11
5 16 20 27 30 36 44 55 60 67 71
27

样例输出
36 20 27 OK

提示


**********************/

#include<iostream>
using namespace std;
long long a[1000000];
bool middlefind(long long value,int length)
{
	int low=0,heigh=length;
	while(low<=heigh)
	{
		int mid=(low+heigh)/2;
		cout<<a[mid]<<" ";
		if(a[mid]==value){cout<<"OK";return true;}
		else if(value<a[mid]) heigh=mid-1;
		else low=mid+1;
	}
	cout<<"SORRY";
	return false;
}

int main()
{
	int m,n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	middlefind(m,n-1);
	cout<<endl;
	system("pause");
	return 0;
}
