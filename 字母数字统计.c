题目描述
输入一字符串，求该字符串中字母与数字的总个数。

输入
每行输入一个字符串，包括空格。

输出
对应输入，每行输出字母与数字的总个数。

样例输入
abcd 234,ABCD?<88**&dfgGy
dfg 56,?

样例输出
18
5

#include <stdio.h>
int main(){
	int i,n=0;
	int array[100];
	memset(array,0,sizeof(array));
	while(1){
		char str[1000];
		memset(str,0,sizeof(str));
		gets(str); 
		if(str[0]==NULL) break;
		for(i=0;i<1000;i++){
			if(str[i]==NULL) break;
			if(str[i] >='a' && str[i]<='z' ||  str[i]>='A' && str[i]<='Z' ||str[i]>=48 && str[i]<=57 ){
				 array[n]++;
			}
		}
		n++;
	}
	for(i=0;i<n;i++){
		printf("%d\n",array[i]);
	}
	return 0;
} 
