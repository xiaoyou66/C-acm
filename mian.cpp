/*************************
����

����Ҫ�жϵĶ�ά�������n��

Ȼ����������n����ά���顣

����ÿ����ά���飬������M��N��1<M,N<101������ʾ��M��N�У�Ȼ����������M*N��������Ϊ��ά�����Ԫ��ֵ��


���

���������ά�����Ƿ�ԳƵ��жϽ����


��������

3
2,2
1 2
2 1
3,3
1 2 3
3 2 1
1 2 3
10,10
1 2 3 4 5 6 7 8 9 10
2 1 2 3 4 5 6 7 8 9
3 2 1 2 3 4 5 6 7 8
4 3 2 1 2 3 4 5 6 7
5 4 3 2 1 2 3 4 5 6
6 5 4 3 2 1 2 3 4 5
7 6 5 4 3 2 1 2 3 4
8 7 6 5 4 3 2 1 2 3
9 8 7 6 5 4 3 2 1 2
10 9 8 7 6 5 4 3 2 1

�������

Yes
No
Yes

******************************/
#include<iostream>
using namespace std;
int main()
{
	int array1[101][101]={0};
	int nums,i,j,m,n;
	cin>>nums;
	while(nums--)
	{
		scanf("%d,%d",&m,&n);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&array1[i][j]);
		int flag=0;
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				if(array1[i][j]!=array1[m-i-1][n-j-1])  flag=1;
		if(flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	//system("pause");
	return 0;
}



