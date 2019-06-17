/*************************
题目描述
编一程序用简单选择排序方法对n个整数排序（从大到小）。

对n个数进行降序排列，简单选择排序的算法思想如下：

1）首先通过n-1次比较，从n个元素中找出值最大的元素，将它与第一个元素交换。（第一趟排序）。

2）再通过n-2次比较，从剩余的n-1个元素中找出值次大的元素，将它与第二个元素交换。（第二趟排序）。

3）重复上述操作，共进行n-1趟排序后，排序结束。


输入
先输入整数个数n（n<=100000）

然后输入n个整数


输出
输出排序后的n个整数，整数之间由1个空格隔开。


样例输入
10
2 7 12 23 23 34 45 56 87 98

样例输出
98 87 56 45 34 23 23 12 7 2

******************************/


#include<iostream>
using namespace std;
int main()
{
	int n,i,j,max,maxp,tmp;
	int nums[100000]={0};
	cin>>n;
	for(i=0;i<n;i++) cin>>nums[i];
	for(i=0;i<n;i++)
	{
		max=0;
		for(j=i;j<n;j++)
			if(max<nums[j]){max=nums[j];maxp=j;}
		tmp=nums[maxp];
		//cout<<tmp<<" ";
		nums[maxp]=nums[i];
		nums[i]=tmp;
	}
	for(i=0;i<n;i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	//system("pause");
	return 0;
}





