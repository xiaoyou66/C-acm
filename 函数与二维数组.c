用3行4列的二维数组存储学生成绩，编写输入函数input()、二维数组输出函数output()、找最大值函数findMax()、找最小值函数findMin()、求平均值函数findAverage()，实现通过调用函数从键盘输入数组，然后调用函数完成二维数组输出，然后调用函数求最大成绩、最小成绩和平均成绩并输出。 

输入
输入12个成绩（float型数据） 

输出
按3行4列输出成绩，每个数据占10位宽，精确到小数点后面2位。 

然后按样例输出最大、最小及平均成绩，精确到小数点后面2位。 

样例输入
1 2 3 4 5 6 7 8 9 10 11 12.12
样例输出
      1.00      2.00      3.00      4.00
      5.00      6.00      7.00      8.00
      9.00     10.00     11.00     12.12
max score is:12.12
min score is:1.00
average score is:6.51
提示


本题可参考教材例5.9，重点练习一下用数组作函数形参或实参时的参数传递。


另外，形参或实参也可以定义成指针。

#include <stdio.h>
float findmax(float a[12]){
	int i;
	float max=0;
	for(i=0;i<12;i++){
		if(max<a[i]){
			max=a[i];
		}	
	}
	return max;
}
float findmin(float a[12]){
	int i;
	float min=100;
	for(i=0;i<12;i++){
		if(min>a[i]){
			min=a[i];
		}	
	}
	return min;
}
float findaverge(float a[12]){
	int i;
	float all=0;
	for(i=0;i<12;i++){
		all+=a[i];	
	}
	all=all/12;
	return all;
}
int main(){
	float great[12];
	float max,min,averge;
	int i,j,k=0;
	for(i=0;i<12;i++){
		scanf("%f",&great[i]);		
	}
	max=findmax(great);
	min=findmin(great);
	averge=findaverge(great);
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%10.2f",great[k]);
			k++;
		}
		printf("\n");
	}
	printf("max score is:%.2f\n",max);
	printf("min score is:%.2f\n",min);
	printf("average score is:%.2f\n",averge);
	return 0;
} 


