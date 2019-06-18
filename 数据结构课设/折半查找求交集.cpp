/*************************************
题目描述
在一个升序排列的整数数字序列中查找，并返回相应的查找结果。

输入
每个测试用例由多行组成，第一行是两个整数n和m，其中，1<=n,m<=1000000。
自第二行起一共有n+m个整数，其中前面n个整数代表升序排列的有序序列，随后的m个整数是待查询的数。n+m个整数的取值在范围1到10^12(10的12次方)之间。

输出
对于每个待查询的数，如果在有序序列中则输出"yes"，否则输出"no"，每行输出一个查询结果。

样例输入
5 3
6 23 45 56 586
33 66 6

样例输出
no
no
yes

提示
1、本题的数据超过了int的表示范围，要用64位数据。 
1）在VC6中调试，变量定义用__int64类型，输入输出格式用%I64d。（__int64前是2条下划线，%I64d中的I是字母i的大写） 
2）在windows版的Codeblocks中调试，变量定义用__int64类型或long long，输入输出格式用%I64d 
3）在linux环境下的Codeblocks中调试或在OJ上提交时，变量定义只能用long long类型，输入输出格式用%lld 
2、数组占内存超过1M，请开全局数组 

这个题目其实就是利用折半查找的原理，所以只需要了解折半查找的知识即可
********************************/



#include<iostream>
using namespace std;
long long a[1000000];
long long b[1000000];
bool middlefind(long long value,int length)
{
	int low=0,heigh=length;
	while(low<=heigh)
	{
		int mid=(low+heigh)/2;
		if(a[mid]==value) return true;
		else if(value<a[mid]) heigh=mid-1;
		else low=mid+1;
	}
	return false;
}

int main()
{
	int m,n,i;
	cin>>n>>m;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(i=0;i<m;i++)
		if(middlefind(b[i],n)) cout<<"yes"<<endl;
		else cout<<"no"<<endl; 
	system("pause");
}

















