#include<iostream>
using namespace std;


int main()
{
	long long m,n,total=0,ten,mm,nn;
	scanf("%lld %lld",&m,&n);
	mm=m%10;
	nn=n%10;
	total+=((mm+9)*(10-mm)/2+(1+nn)*(nn)/2);
	ten=(n-n%10)-(m-m%10);
	total+=(ten/10-1)*45;
	printf("%lld",total);
	//system("pause");
}	


////后面的思路
#include<iostream>
using namespace std;


int main()
{
	long long m,n,total=0,ten,mm,nn,a,b;
	scanf("%lld %lld",&m,&n);
	mm=m%10;
	nn=n%10;
	if(mm>=0)
		total+=(mm+9)*(10-mm)/2;
	else
	{
	   mm=-mm;
	   total+=(1+mm)*(mm)/2;
	   mm=-mm;
	}
	if(nn>=0)
		total+=(1+nn)*(nn)/2;
	else
	{									
	   nn=-nn;
	   total+=(nn+9)*(10-nn)/2;
	   nn=-nn;
	}
	if(mm!=0) m=m-mm+10;
	else  m=m-mm+10;
	if(nn!=0) n=n-mm-10;
	else n=n-mm;
	total+=((n-m)/10)*45;
	//cout<<ten;
	
	printf("%lld",total);
	//system("pause");
}
