#include <iostream>
#include<stdio.h>
using namespace std;

#define MAXSIZE 60
char book[10000][500]={""};

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
	while(book[++i][0]) 
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
void addword(char item[],int length,int pos,char a[],int choos)
{
	for(int j=length;j>pos;j--)
		item[j]=item[j-1];
	for(int j=0;j<26;j++)
	{
		item[pos]=a[j];
		printf("%s\n",item);
		if(hasitem(item))
			printf(" %s",item);
	}
}
//删除单词
void deleteword(char item[],int length,int pos,char a[],int choos)
{
	for(int j=pos;j<=length;j++)
		item[j]=item[j+1];
	item[length]=" ";
}

//添加判断内容是否正确
void add(char item[],char a[])
{
	int i=-1;
	int length=0;
	while(item[++length]);
	while(item[++i])
	{
		addword(item,length,i,a);
		deleteword(item,length,i,a)
	}
}

//删除判断内容是否正确


void suggest(char item[])
{
	char a[26]={""};
	for(int i=0;i<26;i++)
		a[i]=i+97;

	printf(":");
	//替换
	replace(item,a);
	//添加
	add(item,a);

	//删除
	printf("\n");
}


int main()
{
	int booklen=0;
	while(scanf("%s",book[booklen++]))
		if(book[booklen-1][0]=='#'){booklen--;break;}
	while(true)
	{
		char a[50]={};
		scanf("%s",a);
		if(a[0]=='#') break;
		printf("%s",a);
		if(hasitem(a)) printf(" is correct\n");
		else suggest(a);
	}

	system("pause");
	return 0;
}
