题目描述
现有有N个学生的数据记录，每个记录包括学号、姓名、三科成绩。编写一个函数input,用来输入一个学生的数据记录。编写一个函数print,打印一个学生的数据记录。在主函数调用这两个函数，读取N条记录输入，再按要求输出。 N<100

输入
学生数量N占一行。每个学生的学号、姓名、三科成绩占一行，空格分开。

输出
每个学生的学号、姓名、三科成绩占一行，逗号分开。

样例输入
2
a100 zhblue 70 80 90
b200 newsclan 90 85 75

样例输出
a100,zhblue,70,80,90
b200,newsclan,90,85,75

#include<stdio.h>

int N=100;

struct student  

{  

 char num[6];

 char name[8];

 int score[3];  

}stu[100];



void print(struct student st)  

{  

 int i,j;

 printf("%s,%s",st.num,st.name);

 for(j=0;j<3;j++) 

  printf(",%d",st.score[j]);  

 printf("\n");  

}



void input(struct student *Pst)  

{ 

 int i,j;   

 scanf("%s %s",&Pst->num,&*Pst->name);  



 for(j=0;j<3;j++)    

  scanf("%d",&Pst->score[j]);   

}



int main()  

{  

 int i,j;

 scanf ("%d",&N);

 for(i=0;i<N;i++)  

 {        

  input(&stu[i]);



 } 
  for(i=0;i<N;i++)  

 {        



  print(stu[i]); 

 } 


 return 0;

}
