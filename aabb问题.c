//输出所有aabb型的四位完全平方数
#include <stdio.h>
#include <math.h>
int main(){
	int a,b;//注意这里如果加在for循环里面只有c99才可以 
	for(a=1;a<=9;a++){
		for(b=1;b<=9;b++){
			int n=a*1100+b*11;
			int m=floor(sqrt(n)+0.5);//这样做是为了准确的求出n的平方根 ，后面加0.5是为了减少误差 
			if(m*m==n) printf("%d\n",n); 
		}
	} 

	return 0;
} 
//也可以直接枚举平方根，从而避开开平方的操作
#include <stdio.h>
#include <math.h>
int main(){
  for(int i=1;;i++){//这里中间不填的话是一个死循环，所以，我们必须要想法跳出循环
    int n=i*i;
    if(n<1000) continue;//这里是直接执行下一条语句，可以减少计算量
    if(n>9999) break;
    int a=n/100;
    int b=n%100;
    if(a/10==b%10 && b/10==a10) printf(“%d\n”,n);
    
  }

	return 0;
} 
