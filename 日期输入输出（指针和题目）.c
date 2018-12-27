题目描述
 有一些日期，日期格式为“YYYY MM DD”。编程将其读入然后原样输出。要求用结构定义日期类型, 输入日期用一个单独的函数完成， 输出日期另一个单独的函数完成，然后在main函数中调用。日期变量不允许定义为全局变量。本题不允许使用C++的引用特性。

          特别提醒：不用函数的程序即使AC也不会被承认。


输入
 见样例



输出
 见样例



样例输入
2013 02 21
2011 11 05

样例输出
2013 02 21
2011 11 05

#include<stdio.h>
	struct date{
		int year;
		int day;
		int month;
	} p[100];//直接定义一个结构体p 没有必要再重新定义 
char i=1;
void input(struct date *pa){
	i=scanf("%d %d %d",&pa->year,&pa->month,&pa->day);
	if(i==-1) i=0;//如果你停止输入那么就会返回-1 
	
}
void output(struct date pb){
	if(pb.month<10 && pb.day<10)  printf("%d 0%d 0%d\n",pb.year,pb.month,pb.day);
	else if(pb.month<10) printf("%d 0%d %d\n",pb.year,pb.month,pb.day);
	else if(pb.day<10) printf("%d %d 0%d\n",pb.year,pb.month,pb.day);
	else printf("%d %d %d\n",pb.year,pb.month,pb.day);
}

	

int main()
{	
	int j,n=0;
	for(j=0;j<100;j++){
		input(&p[j]);//把p的地址传给input，intput定义一个指针，然后去修改 
		if(!i) break;
		n++;
	}
	for(j=0;j<n;j++){
		output(p[j]);
	}

   	return 0; 
}

