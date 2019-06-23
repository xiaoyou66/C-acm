#include<iostream>
using namespace std;


int main()
{
	char word[1000]={0};
	int i=-1,num=0,zimu=0,space=0,other=0;
	scanf("%[^\n]",&word);//这个可以输入带空格的字符串
	while(word[++i]!=0)
	{
		if((word[i]>='a'&& word[i]<='z') || (word[i]>='A'&& word[i]<='Z')) zimu++;
		else if(word[i]==32) space++;
		else if(word[i]>='0' && word[i]<='9') num++;
		else other++;
	}
	printf("%d %d %d %d\n",zimu,num,space,other);
	//system("pause");
}
