题目描述
编一返回指针值的函数，求字符串的子串。

输入
先输入一个整数n，表示有n个测试数据，对于每个测试数据：

1）先按提示“input string:”输入字符串

2）然后按提示“i=”输入求子串的起始位置i

3）再按提示“j=”输入子串长度j

输入举例（红色的表示从键盘输入）

2
input string:I am a student
i=6
j=5
input string:ab
i=3
j=2


输出举例：





a stu
Error


输出
对应输出子串

//以后一定要看请楚为什么错了，要不然又会像今天这样浪费太多时间


#include <stdio.h>
int main(){
	int n,i,j,k,l,m,o;
	scanf("%d",&n);
	char str[n][1000];
	memset(str,0,sizeof(str));
	for(k=0;k<n;k++){
		char array[1000];
		memset(array,0,sizeof(array));
		printf("input string:"); 
		getchar();
		gets(array);
		printf("i=");
		scanf("%d",&i);
		printf("j=");
		scanf("%d",&j);
		for(l=0;l<1000;l++){
			if(array[l]==NULL){
				if(l<i+j-1 || i<=0 || j<=0 ||array[0]==NULL){
					str[k][0]=69;//注意：这里不能直接写已传，要一个一个复制，好像也不能直接输入字符 
					str[k][1]=114;
					str[k][2]=114;
					str[k][3]=111;
					str[k][4]=114;
				}else{
					o=0;
					for(m=i-1;m<i+j-1;m++){
						str[k][o]=array[m];
						o++;
					}
				}
				break;
			}	
		}
		for(j=0;j<1000;j++){
			if(str[k][j]==NULL) break;
			printf("%c",str[k][j]);	
		}
		printf("\n");
	}
	return 0;
} 





