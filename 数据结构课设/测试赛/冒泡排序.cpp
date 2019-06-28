#include <iostream>
using namespace std;

#define  MAXSIZE  1000    

typedef struct
{
    int  r[MAXSIZE];         
    int  length;            
}SqList,*Link; 


void bupoSort(SqList &L)
{
	int m=L.length-1,i,t;
	for(i=0;i<m;i++)
		if(L.r[i]>L.r[i+1])
		{
			t=L.r[i];L.r[i]=L.r[i+1];L.r[i+1]=t;
		}
} 



int main()
{
	int i;
	Link L=new SqList;
	cin>>L->length;
	for(i=0;i<L->length;i++)
		cin>>L->r[i];
	bupoSort(*L);
	for(i=0;i<L->length;i++)
		cout<<L->r[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}
