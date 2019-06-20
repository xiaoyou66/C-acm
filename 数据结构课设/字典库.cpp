#include <iostream>
#include<stdio.h>
using namespace std;

#define MAXSIZE 60
char book[10000][500]={""};
int wordlength[1000]={0};

//判断是否相同
bool same(char str1[],char str2[])
{
	int flag=0,i;
	for(i=0;str1[i] && str2[i];i++)
		if(str1[i] !=str2[i])
		{
			break;
			flag=1;
		}
	if(!str1[i] && !str2[i] &&!flag) return true;
	else return false;
}

//字典中是否有这个单词
bool hasitem(char item[])
{
	int i=-1;
	int length=-1;
	while(item[++length]);
	while(book[++i][0]) 
		if(book[i][0]==item[0] && wordlength[i]==length)
			if(same(book[i],item)) return true;
	return false;
}

//替换内容判断是否正确
void replace(char item[],char a[])
{
	char t;
	int i=-1;
	while(item[++i])
	{
		t=item[i];
		for(int j=0;j<26;j++)
		{
			item[i]=a[j];
			if(hasitem(item))
				printf(" %s",item);
		}
		item[i]=t;
	}
}

//添加单词
void addword(char item[],int length,int pos,char a[],char choos)
{
	for(int j=length;j>pos;j--)
		item[j]=item[j-1];
	if(choos)
	{
		item[pos]=choos;
	}
	else
	{
		for(int j=0;j<26;j++)
		{
			item[pos]=a[j];
			if(hasitem(item))
				printf(" %s",item);
		}
	}
}
//删除单词
void deleteword(char item[],int length,int pos,int choos)
{
	for(int j=pos;j<=length;j++)
		item[j]=item[j+1];
	if(choos) item[length]=0;
}

//添加判断内容是否正确
void add(char item[],char a[])
{
	int i=0;
	int length=-1;
	while(item[++length]);
	for(i=0;i<=length;i++)
	{
		addword(item,length,i,a,0);
		deleteword(item,length,i,1);
	}
}

//删除判断内容是否正确

void deletew(char item[],char a[])
{
	int i=-1;
	int length=-1;
	while(item[++length]);
	while(item[++i])
	{
		char t=item[i];
		deleteword(item,length,i,0);
		if(hasitem(item))
			printf(" %s",item);
		addword(item,length,i,a,t);
	}
}

void suggest(char item[])
{
	char a[26]={""};
	for(int i=25;i>=0;i--)
		a[i]=i+97;

	printf(":");
	//替换
	replace(item,a);
	//添加
	add(item,a);
	//删除
	deletew(item,a);
	printf("\n");
}

void coutnum()
{
	int i=-1,j;
	while(book[++i][0]!=0)
	{
		j=-1;
		while(book[i][++j]);
		wordlength[i]=j;
	}

}

int main()
{
	int booklen=0;
	while(scanf("%s",book[booklen++])!=EOF)
		if(book[booklen-1][0]=='#'){booklen--;break;}
	//计数
	coutnum();
	while(true)
	{
		char a[50]={};
		scanf("%s",a);
		if(a[0]=='#') break;
		printf("%s",a);
		if(hasitem(a)) printf(" is correct\n");
		else suggest(a);
	}
	//system("pause");
	return 0;
}
