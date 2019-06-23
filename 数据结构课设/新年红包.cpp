
/******************
题目描述
首先预祝大家新年快乐！红包多多！ 
程序员的红包与众不同，有无红包以及红包的金额隐藏的一个字符串中，请你解析。 
字符串中如果存在2个连续出现的字符'h'和'b‘（'h'和'b'不区分大小写），则紧随其后必会出现几个连续的数字字符，这几个连续数字字符表示红包的金额。请输出红包金额。 
字符串中如果不存在2个连续出现的字符'h'和'b‘（'h'和'b'不区分大小写），由输出“No red packet"。 

输入
输入仅一行字符串。字符串中的字符个数不超过100。 
字符串仅由英文字符和数字字符构成。 




输出
字符串中如果存在2个连续出现的字符'h'和'b‘（'h'和'b'不区分大小写），则紧随其后必会出现几个连续的数字字符，这几个连续数字字符表示红包的金额。请输出红包金额。 
字符串中如果不存在2个连续出现的字符'h'和'b‘（'h'和'b'不区分大小写），由输出“No red packet"。 

样例输入
abcdHb280abc68a

样例输出
280

*********************/
#include<iostream>
using namespace std;

char change(char c)
{
	if(c>='a' && c<='z')
		return c-32;
	return c;
}

int main()
{
	char zifu[10000]={0};
	int i=-1,flag=0;
	scanf("%s",&zifu);
	while (zifu[++i])
	{
		if(change(zifu[i])=='H' && change(zifu[i+1])=='B'){flag=1;i+=2;}
		if(flag)
			if(zifu[i]>='0' && zifu[i]<='9') printf("%c",zifu[i]);
			else break;
	}
	if(!flag) cout<<"No red packet";
	printf("\n");

	//system("pause");
}	
