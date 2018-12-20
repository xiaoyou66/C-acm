题目描述
#include <stdio.h>
/******************************************/
/// Write your code here,
///    beginning with "#define"... 


MOD=11；//我的结果

/******************************************/
int main()
{
    int a, b, s;
    while(~scanf("%d%d", &a, &b))
    {
        s = (a + b) % MOD;
        printf("%d\n", s);
    }
    return 0;
} 

输入
输出
样例输入
1 2
4 7
5 9

样例输出
3
0
3




