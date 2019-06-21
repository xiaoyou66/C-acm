/*********************
问题 O: 单词检查(Ⅰ)- 顺序表实现
时间限制: 1 Sec  内存限制: 128 MB
提交: 1173  解决: 383
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述
许多应用程序，如字处理软件，邮件客户端等，都包含了单词检查特性。单词检查是根据字典，找出输入文本中拼错的单词，我们认为凡是不出现在字典中的单词都是错误单词。不仅如此，一些检查程序还能给出类似拼错单词的修改建议单词。 例如字典由下面几个单词组成：
 bake cake main rain vase
如果输入文件中有词vake ，检查程序就能发现其是一个错误的单词，并且给出 bake, cake或vase做为修改建议单词。
修改建议单词可以采用如下生成技术：
 (1)在每一个可能位置插入‘a-'z'中的一者
 (2)删除单词中的一个字符
 (3)用‘a'-'z'中的一者取代单词中的任一字符
   很明显拼写检查程序的核心操作是在字典中查找某个单词，如果字典很大，性能无疑是非常关键的。
   你写的程序要求读入字典文件，然后对一个输入文件的单词进行检查，列出其中的错误单词并给出修改建议。

课程设计必须采用如下技术完成并进行复杂度分析及性能比较。
(1)朴素的算法,用线性表维护字典
(2)使用二叉排序树维护字典
(3)采用hash技术维护字典

本题要求使用顺序表实现。




输入
输入分为两部分。
第一部分是字典，每个单词占据一行，最后以仅包含'#'的一行表示结束。所有的单词都是不同的，字典中最多10000个单词。

输入的第二部分包含了所有待检测的单词，单词数目不超过50。每个单词占据一行，最后以仅包含'#'的一行表示结束。

字典中的单词和待检测的单词均由小写字母组成，并且单词最大长度为15。

输出
按照检查次序每个单词输出一行，该行首先输出单词自身。如果单词在字典中出现，接着输出" is correct"。如果单词是错误的，那么接着输出':'，如果字典中有建议修改单词，则按照字典中出现的先后次序输出所有的建议修改单词（每个前面都添加一个空格），如果无建议修改单词，在':'后直接换行。

样例输入
i
is
has
have
be
my
more
contest
me
too
if
award
#
me
aware
m
contest
hav
oo
or
i
fi
mre
#

样例输出
me is correct
aware: award
m: i my me
contest is correct
hav: has have
oo: too
or:
i is correct
fi: i
mre: more me

***********************8/

/**************

这个题目刚开始是正向思维，所以一直搞了半天没出来。。。。

后面老师说这个题目要逆向思维，就是直接扫描字典库
****************/



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




/*************************8
************************/

#include <iostream>
#include<stdio.h>
using namespace std;

#define MAXSIZE 60
char book[10000][500]={""};
int wordlength[10000]={0};

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


void suggest(char item[])
{
	printf(":");
	int length=-1;
	while(item[++length]);
	int i=-1;
	while(book[++i][0])
	{
		//插入
		if(wordlength[i]==length+1)
		{
			int j=0,k=0,n=0;
			while(j<length+1)
			{
				if(book[i][j]==item[k])
				{k++;n++;}
				j++;
			}
				
			if(n==length)printf(" %s",book[i]);
		}
		//删除
		if(wordlength[i]==length-1)
		{
			int j=0,k=0,n=0;
			while(j<length)
			{
				if(book[i][k]==item[j])
				{k++;n++;}
				j++;
			}	
			if(n==length-1) printf(" %s",book[i]);
		}
		//添加
		if(wordlength[i]==length)
		{
		   int j=0;
		   for(int k=0;k<length;k++)
			  if(item[k]==book[i][k]) ++j;
		   if(j==length-1) 	printf(" %s",book[i]);	   
		}
	}

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
		if(book[booklen-1][0]=='#'){book[booklen-1][0]=0;booklen--;break;}
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
