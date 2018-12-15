题目描述
回文串是从左到右或者从右到左读起来都一样的字符串，试编程判别一个字符串是否为回文串。

输入
输入一个字符串。串长度<255.

输出
判别输入的字符串是否为回文串，是输出"Y",否则输出"N"。

样例输入
abcba

样例输出
Y

#include <stdio.h>
int main(){
	int i,n=-1,j,k=0;
	char str[255];
	memset(str,0,sizeof(str));
	gets(str); 
	for(i=0;i<255;i++){
		if(str[i]==NULL) break;
		n++;
	}
	i=0;
	for(j=n;j>=0;j--){
		if(str[j]==str[i]) k++;
		i++;
	}
	if(k==n+1) printf("Y\n");
	else printf("N\n");
	return 0;
} 
