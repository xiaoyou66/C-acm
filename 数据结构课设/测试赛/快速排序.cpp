#include <iostream>
#include <math.h>
using namespace std;


void  Swap(int & a, int & b) 
{
	int c=a; 
	a=b; 
	b=c;
}

void QSort(int* a, int low, int high)
{   
    int i, j;  
    if(low>=high) return;

    Swap(a[low], a[rand()%(high-low+1)+low]);

    i=low; j=high; 
    int temp=a[i];
	while(i<j)
	{
		while(i<j)
			if(a[j]<=temp){a[i]=a[j];i++;break;}
			else j--;
		while(i<j)
			if(a[i]>=temp){a[j]=a[i];j--;break;}
			else i++;
	}
	a[i]=temp;
    //QSort(a,low,i-1);
    //QSort(a,i+1,high);

}




int main()
{
	int i,a[1000]={0},n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	QSort(a,0,n);
		for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<endl;
	system("pause");
	return 0;
}
