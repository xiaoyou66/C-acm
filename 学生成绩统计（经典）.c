题目描述
有N个学生，每个学生的数据包括学号、姓名、3门课的成绩，从键盘输入N个学生的数据，要求打印出3门课的总平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩）

输入
学生数量N占一行。每个学生的学号、姓名、三科成绩占一行，空格分开。

输出
各门课的平均成绩（整型数据），及总分最高的学生的数据（包括学号、姓名、3门课成绩）


样例输入
2
1 blue 90 80 70
b clan 80 70 60
样例输出
85 75 65
1 blue 90 80 70


#include<stdio.h>
int main(){
	int n,i,max=0,num,j,al,k=0;
	int averge[3];
	scanf("%d",&n);
	char name[n][2][100];
	memset(name,0,sizeof(name));
	int score[n][3];
	for(i=0;i<n;i++){
		scanf("%s %s %d %d %d",&name[i][0],&name[i][1],&score[i][0],&score[i][1],&score[i][2]);
		getchar();
	}

	for(i=0;i<3;i++){
		al=0;
		for(j=0;j<n;j++){
			al+=score[j][i];	
		}
		averge[i]=al/n;
	}
	for(i=0;i<n;i++){
		al=0;
		for(j=0;j<3;j++){
			al+=score[i][j];
		}
		if(max<al){
			max=al;
			num=i;
		}
	}
	for(i=0;i<3;i++){
		printf("%d ",averge[i]);		
	}
	printf("\n");
	for(i=0;i<100;i++){
		if(name[num][0][i]==NULL) break;
		printf("%c",name[num][0][i]);
	}	
	printf(" ");
	for(i=0;i<100;i++){
		if(name[num][1][i]==NULL) break;
		printf("%c",name[num][1][i]);
	}
	printf(" %d %d %d\n",score[num][0],score[num][1],score[num][2]);
	return 0;
}
