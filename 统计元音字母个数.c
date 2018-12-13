题目描述
编写一程序，用于统计从键盘输入的字符串中的元音字母（a，A，e，E，i，I，o，O，u，U）的个数。 

输入
每行输入一字符串，串长不超过255。 

输出
输出对应字符串中元音字母的个数。 

样例输入
abcio
efgaeio
ak akkkksd

样例输出
3
5
2

#include <stdio.h>
int main(){
	int i,num=0;
	int cnt[100];
	memset(cnt,0,sizeof(cnt));
	while(1){
	char array[255]; 
	memset(array,0,sizeof(array));
	gets(array);
	if(!array[0]){
		break;
	}
	for(i=0;i<255;i++){
		switch(array[i]){
			case 65:cnt[num]++;break;
			case 69:cnt[num]++;break;
			case 73:cnt[num]++;break;
			case 79:cnt[num]++;break;
			case 85:cnt[num]++;break;	
			case 97:cnt[num]++;break;
			case 101:cnt[num]++;break;
			case 105:cnt[num]++;break;
			case 111:cnt[num]++;break;
			case 117:cnt[num]++;break;
		}
	}
	num++;
	}
	for(i=0;i<num;i++){
	printf("%d\n",cnt[i]);
	} 
	return 0;
} 
