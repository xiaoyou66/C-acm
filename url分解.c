题目描述
输入一行有效的url，输出这个url的域名部分

举例：

http://www.baidu.com/hnust.htm

http://www.hnust.com/index.htm

http://www.nuoyar.com

ftp://cs.game.com/xz.rar

其中域名应输出：

www.baidu.com

www.hnust.com

www.nuoyar.com

cs.game.com

输入
有多组测试数据

每组测试数据仅一行，为了简化问题，url只由小写字母以及符号:/.组成，不包含空格，url最长为255,且不包含端口号

输出
对于每组测试数据，输出其完整域名部分，不能包含多余的空格

样例输入
http://www.baidu.com/hnust.htm
http://www.hnust.com/index.htm
http://www.nuoyar.com
ftp://cs.game.com/xz.rar

样例输出
www.baidu.com
www.hnust.com
www.nuoyar.com
cs.game.com

提示

可以从开始位置寻找第一个://来确认域名开始位置，然后遍历输出，直到遇到第一个/或者读取到末尾。

所有测试数据都没有端口号，即不存在 http://www.abc.com:8080/index.php 这样的测试数据。















#include<stdio.h>

int main(){
	int i,j,b=0,a=0,cnt=0,n=0;
	char str[100][1000];
	memset(str,0,sizeof(str));
	while(1){
		n=0;
		a=0;
		b=0;
		char array[1000];
		memset(array,0,sizeof(array));
		gets(array);
		if(!array[0]) break;
		for(i=0;i<100;i++){
			
			if(array[i]=='/'){
				if(a==0 || b==0){
					if(array[i+1]=='/'){
						a=i;
					}else{
						if(a!=0 && i-1!=a) b=i;
					}
				}
			}
			if(a!=0 && ( i<b || b==0) && array[i+1]!='/' ){
				str[cnt][n]=array[i+1];
				n++;
			}

		}
		cnt++;
	}
	for(i=0;i<cnt;i++){
		for(j=0;j<100;j++){
			if(!str[i][j]) break;
			printf("%c",str[i][j]);
		}
		printf("\n");
	}
	return 0;
}
