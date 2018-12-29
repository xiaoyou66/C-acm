题目描述
      从键盘输入两个时刻(24小时制），输出两个时刻的间隔，间隔用“小时:分钟:秒”表示。
如：3点5分25秒应表示为--03:05:25.

输入

输入包括两行。
第一行为时刻1。

第二行为时刻2。 

保证时刻2大于时刻1。 




输出
以“小时:分钟:秒”的格式输出时间间隔。
格式参看输入输出。

样例输入
12:01:12
13:09:43

样例输出
01:08:31


#include<stdio.h>
struct date{
	int hour;
	int minter;
	int second;
}; 
int main()
{	
	struct date d1;
	struct date d2;
	struct date d3;
	scanf("%d:%d:%d",&d2.hour,&d2.minter,&d2.second);
	scanf("%d:%d:%d",&d1.hour,&d1.minter,&d1.second);
	if(d1.second<d2.second){
		d1.minter-=1;
		d1.second+=60;	
	}
	d3.second=d1.second-d2.second;
	if(d1.minter<d2.minter){
		d1.hour-=1;
		d1.minter+=60;	
	}
	d3.minter=d1.minter-d2.minter;
	d3.hour=d1.hour-d2.hour;
	printf("%02d:%02d:%02d\n",d3.hour,d3.minter,d3.second);//巧妙的补零方法 
   	return 0; 
}

