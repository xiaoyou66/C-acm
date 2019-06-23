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
