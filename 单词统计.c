题目描述
输入一行字符，统计其中分别有多少个单词和空格。比如输入："How are you"，有3个单词和2个空格。

输入
每行输入一字符串

输出
输出单词个数及空格个数，用逗号隔开

样例输入
How are you
 I love C language

样例输出
3,2
4,4

#include <stdio.h>
int main(){
	int i,n=0,k=0;
	int array[100][2];
	memset(array,0,sizeof(array));
	while(1){
		char str[1000];
		memset(str,0,sizeof(str));
		gets(str); 
		if(str[0]==NULL) break;
		k=0;
		for(i=0;i<1000;i++){
			if(str[i]==NULL) break;
			if(str[i] >='a' && str[i]<='z' ||  str[i]>='A' && str[i]<='Z'){
				if(k==0) 	array[n][0]++;
				k=1;	
			}else if(str[i]=32) {
				array[n][1]++;
				k=0;
			}
		}
		n++;
	}
	for(i=0;i<n;i++){
		printf("%d,%d\n",array[i][0],array[i][1]);
	}
	return 0;
} 
