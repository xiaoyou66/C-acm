题目描述
输入多行字符串，把这些字符串逆序且反转输出。

输入
输入多个（小于30个）字符串，每行一个字符串，字符串长度不超过30

输出
把字符串反转逆序输出。逆序指最后输入的字符串最先输出，反转指把每句话的字母都倒过来输出。


样例输入
How are you?
How is it going?
Are you happy?
样例输出
?yppah uoy erA
?gniog ti si woH
?uoy era woH
提示
#include <stdio.h>
int main(){
	int i,j,m=0,n;
	int array[100][30];
	memset(array,0,sizeof(array));
	while(1){
		n=0;
		char str[30];
		memset(str,0,sizeof(str));
		gets(str); 
		if(str[0]==NULL) break;
		for(i=0;i<30;i++){
			if(str[i]==NULL) break;
			n++;
		}	
		j=0;
		for(i=n-1;i>=0;i--){
			array[m][j]=str[i];	
			j++;
		}
		m++;
	}
	for(i=m-1;i>=0;i--){
		if(array[i][0]==NULL) break;
		for(j=0;j<30;j++){
			if(array[i][j]==NULL) break;
			printf("%c",array[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
