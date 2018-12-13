题目描述
求二维数组的最大值。 

练习时，可以直接在main()函数中求解；也可以将求最大值封装成一个函数；还可以用指向数组元素的指针（如*p）或用指向数组的指针（如(*p)[100]）对数组元素进行访问。 

输入
先输入m和n，表示二维数组有m行n列。m或n为0，则结束。（1<=m,n<=100) 

然后输入m*n个整数，即输入各个二维数组元素。 

输出
对应输出二维数组的最大值。 

样例输入
2,3
1 2 3
4 5 6
3,4
23 4 5 34
23 6 4 45
11 2 33 18
0,0
样例输出
6
45

#include <stdio.h>
int main(){
	int n,m,i,j,num=0;
	int max[100];
	memset(max,0,sizeof(max));//把数组清空
	
	while(1){
	scanf("%d,%d",&m,&n);
	if(n==0 || m==0 || n>100){
	break;}
	int great[m][n];
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d",&great[i][j]);
			}
		}
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(max[num]<great[i][j]){
					max[num]=great[i][j];					
				}
			}
		}
		num++;	
	}
    for(i=0;i<num;i++){
    
	printf("%d\n",max[i]);
	}
	return 0;
} 
