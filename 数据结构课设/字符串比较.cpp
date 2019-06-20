/********************
题目描述
 给定两个字符串，判定其是否相等。字符串相等的意义基于类似于strcmp函数，除了比较时忽略大小写，例如”999abc”和”999ABC”是相等的字符串。


输入
 一行输入，包括由空格分开的两个字符串，字符串本身不含空格，字符串长度均不超过100


输出
 如果字符串相等，输出一行”EQUAL”,否则输出一行”NOT EQUAL”


样例输入
999abc 999ABC

样例输出
EQUAL

提示
用scanf(“%s%s”,…)读入字符串

*********************/


#include <iostream>
using namespace std;

char change(char c)
{
	if(c>='a' && c<='z')
		return c-32;
	return c;
}


int main()
{
	int i,flag=0;
	char str1[100]={""},str2[100]={""};
	scanf("%s %s",&str1,&str2);
	for(i=0;str1[i] && str2[i];i++)
		if(change(str1[i])!=change(str2[i]))
		{
			break;
			flag=1;
		}

	if(!str1[i] && !str2[i] &&!flag)
		cout<<"EQUAL"<<endl;
	else
		cout<<"NOT EQUAL"<<endl;

	//system("pause");

	return 0;
	system("pause");
}
