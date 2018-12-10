//可以采用交换变量法（就是新建一个临时变量）这里不写
//只接用两个变量就可以，但是只有定义了加减法数据类型才能用这个方法
#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("%d %d",a,b);
	return 0;
} 
//还有一个更决的 算法竞赛是在比谁能更好的解决问题，而不是在比谁的程序写的更高级
#include <stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d %d",b,a);
	return 0;
} 

