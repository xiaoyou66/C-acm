题目描述
定义一个结构体变量（包括年、月、日）。计算该日在本年中是第几天，注意闰年问题。 
输入
年月日
输出
当年第几天
样例输入
2000 12 31
样例输出
366              //我那样做是没有考虑可能超过12月，所以会出现巨大的问题
#include<stdio.h>
	struct Date
	{
		int year;
		int month;
		int day;
	};
 
int main()
{
  struct Date p;
  scanf("%d %d %d",&p.year,&p.month,&p.day); 
  int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int sum,i;
            sum=p.day;
	        for(i=0;i<p.month-1;i++)
  	        sum+=a[i]; 
  if(((p.year%4==0&&p.year%100!=0)||p.year%400==0)&&p.month>2)
       printf("%d\n",sum+1);   
  else 
   printf("%d\n",sum); 
   
   return 0; 
}

