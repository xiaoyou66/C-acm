#include<iostream>
using namespace std;
#define  MAXSIZE 1000  
typedef struct
{
	int r[MAXSIZE];           
    int  length;            
}SqList,*Link; 

void Mergelist(SqList LA,SqList LB,SqList &LC)
{
	LC.length=LA.length+LB.length;
	int a=0,b=0,alast=LA.length-1,blast=LB.length-1,c=0;
	while(a<=alast && b<=blast)
	{
		if(LA.r[a]<=LB.r[b]) LC.r[c++]=LA.r[a++];
		else LC.r[c++]=LB.r[b++];
	}
	while(a<=alast) LC.r[c++]=LA.r[a++];
	while(b<=blast) LC.r[c++]=LB.r[b++];
}

void cut(SqList &LC)
{
	int i,j;
	for(i=0;i<LC.length;i++)
		if(LC.r[i]==LC.r[i+1])
		{
			LC.length--;
			for(j=i;j<LC.length;j++)
				LC.r[j]=LC.r[j+1];
		}
}


int main()
{
	Link LA=new SqList;
	Link LB=new SqList;
	Link LC=new SqList;
	int m,n,i;
	cin>>LA->length;
	for(i=0;i<LA->length;i++)
		cin>>LA->r[i];
	cin>>LB->length;
	for(i=0;i<LB->length;i++)
		cin>>LB->r[i];
	Mergelist(*LA,*LB,*LC);
	cut(*LC);
	for(i=0;i<LC->length;i++)
		cout<<LC->r[i]<<" ";
	cout<<endl;
	//system("pause");
	return 0;
}
