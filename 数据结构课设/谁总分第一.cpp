/********************************************
题目描述
有N个学生，每个学生的数据包括学号、姓名、3门课的成绩，从键盘输入N个学生的数据，要求找出总分第一且没有单科不及格的学生的数据（包括学号、姓名、3门课成绩）并输出。
结构体类型及结构体数组的定义可参考如下定义。题目没有明确说明的，均没有严格限制。
#define N 100 
struct student
{
  char num[10];
  char name[10];
  int score[4];
  int total;
}stu[N];

输入
先输入学生数量N
然后每行输入一个学生的数据，包括学号、姓名、三科成绩，空格分开。

输出
总分第一且没有单科不及格的学生的数据（包括学号、姓名、3门课成绩），如果存在并列总分第一的，只输出从前往后查找遇到的第一个学生的数据。

样例输入
4
1101 clan 80 70 60
1102 blue 90 80 70
1103 xds  59 99 98
1104 bred 80 80 80

样例输出
1102 blue 90 80 70
************************************/
#include<iostream>
using namespace std;

#define N 100
struct student
{
	char num[10];
	char name[10];
	int score[4];
	int total;
};


int main()
{
	int n,i,max=0,maxp;
	struct student stu[N]; 
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%s %s %d %d %d",&stu[i].num,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
	for(i=0;i<n;i++)
		stu[i].total=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
	for(i=0;i<n;i++)
		if(stu[i].score[0]>=60 &&stu[i].score[1]>=60&&stu[i].score[2]>=60)
		   if(stu[i].total>max)
		   {
			   max=stu[i].total;
			   maxp=i;
		   }
	printf("%s %s %d %d %d\n",stu[maxp].num,stu[maxp].name,stu[maxp].score[0],stu[maxp].score[1],stu[maxp].score[2]);
	//system("pause");
	return 0;
}
