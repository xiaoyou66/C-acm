/**********************************
题目描述
在教材第92页算法4-1中已经描述了定位子串的BF算法。
书中的算法思想是这样的：分别利用计数指针i和j指示主串S和模式串T中当前正待比较的字符位置。算法的基本思想是：从主串S的第pos个字符起和模式的第一个字符比较之，若相等，则继续逐个比较后续字符，否则从主串的下一个字符起再重新和模式的字符比较之。依次类推，直至模式T中的每个字符依次和主串S中的一个连续的字符序列相等，则称匹配成功，函数值为和模式T中第一个字符相等的字符在主串中的序号，否则称匹配不成功，函数值为零。


你的任务是将S中每次比较的字符输出来，并将匹配的序号输出。 


输入
3组字符串，每组字符串占一行。每行包含由空格分隔的两个字符串，字符串仅由英文小写字母组成且长度不大于100。3组字符串，每组字符串占一行。每行包含由空格分隔的两个字符串，字符串仅由英文小写字母组成且长度不大于100。


输出
每组数据输出2行，第一行是S中每次比较的字符，第二行是后一个字符串在前一个字符串中的位置，如果不匹配，则输出0。 

样例输入
string str
thisisalongstring isa
nosubstring subt

样例输出
str
1
thisisisa
5
nosubsubsttring
0

提示
数据结构和教材第90页SString定义一致。具体解法只要在书中算法4.1的算法描述中，将在每次比较时输出S中对应的字符即可，最后将函数结果存储下来并输出。

************************************/

#include <iostream>
using namespace std;


int BF(char str1[],char str2[],int str2len)
{
	int i=0,j=0;
	while(str1[i] && str2[j])
	{
		printf("%c",str1[i]);
		if(str1[i] == str2[j]){i++;j++;}
		else{i=i-j+1;j=0;}
	}
	cout<<endl;
	if(!str2[j]) return i-str2len+1;
	else return 0;
}

int main()
{
	int i,flag=0;
	char str1[200]={""},str2[200]={""};
	while(scanf("%s %s",&str1,&str2)!=EOF)
	{
		i=0;
		while(str2[++i]); 
		cout<<BF(str1,str2,i)<<endl;
	}
	//system("pause");
	return 0;
}
