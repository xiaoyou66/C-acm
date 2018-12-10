//三位数反转(这里是320变成23)
#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int m=a%10*100+a/10%10*10+a/100;
	printf("%d\n",m);
	return 0;
} 
//三位数反转(这里是320变成023)
#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int m=a%10*100+a/10%10*10+a/100;
	printf("%03d\n",m);//这里03是保留三位数前面0会保留
	return 0;
} 
