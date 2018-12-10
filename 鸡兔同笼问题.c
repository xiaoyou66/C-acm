//题目描述 鸡和兔在一起，总数为n总腿数为m 有多少兔 多少鸡
//设有a只鸡b只兔
#include <stdio.h>
int main(){
	int a,b,n,m;
	scanf("%d %d",&n,&m);
	a=(4*n-m)/2;
	b=n-a;
	if(m%2==1 || a<0 || b<0){
		printf("该题无解");	
	}else{
		printf("%d %d",a,b);
	}

	return 0;
} 
//注意：c语言中的逻辑运算符都是短路运算符，一旦可以确定整个表达式的值，就不会再次进行计算
