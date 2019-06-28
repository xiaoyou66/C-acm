#include<iostream>
#include <math.h>
using namespace std;


void process(char a[],double n)
{
	int i;
	double sum=1.0;
	for(i=2;a[i];i++)
	{
		//printf("%c ",a[i]);
		if(a[i]=='n' && a[i+2]=='n')
		{
			sum*=n*n;
			i++;
		}
		if(a[i]=='n' && a[i+2]!='n')
		{
			sum*=n;
			i++;
		}
		if(a[i]=='s')
		{
			sum*=sqrt(n);
			i+=6;
		}
		if(a[i]=='l')
		{
			sum*=log(n);
			i+=4;
		}
	}
	if(sum>100000000)
		printf("TLE\n");
	else
		printf("%.2lf\n",sum);
}

int main()
{
	int i,m;
	double n;
	char a[100];
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		scanf("%s",&a);
		process(a,n);
	}
	//system("pause");
	return 0;
}
